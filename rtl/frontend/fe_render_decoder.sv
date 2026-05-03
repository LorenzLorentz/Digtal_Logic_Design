// =====================================================================
// fe_render_decoder.sv  --  Frontend render-command decoder
// ---------------------------------------------------------------------
// Consumes the be_render_* command stream and writes a character-grid
// text_ram one cell per cycle (single write port). Asserts
// be_render_ready=1 only in S_IDLE; multi-cycle write states stall
// the backend until done.
//
// Layout (parameters):
//   row TITLE_ROW                         titlebar "Chat with: <peer>"
//   rows HIST_ROW_START..HIST_ROW_END     chat history (one msg/row)
//   row INPUT_ROW                         "> <input line>"
//
// Sprite codes (in 0xF0..0xFF range, decoded by glyph ROM):
//   0xF0 PENDING, 0xF1 SUCCESS, 0xF2 FAIL
//
// Persistent state we maintain ourselves:
//   conn_state_curr_q   2-bit, latched from RENDER_CONN_STATE/REDRAW
//   peer_name_q         latched from be_render_peer_name on CONN_STATE
//   input_line_q[]      mirror of backend's input line; we shift it on
//                       INSERT/DELETE so the input row can be redrawn
//                       from a known buffer.
//   input_cursor_q      cursor position (used by scan for highlight)
//   hist_wr_row_q       next slot in history ring. Wraps; v1 has no
//                       scrolling -- oldest message gets overwritten
//                       in place. TODO: add scrolling.
//   msg_id_row_q[]      256-deep lookup so RENDER_UPDATE_STATUS can
//                       find the row that owns a given msg_id.
//
// REDRAW_ALL is a near no-op (text_ram already inits to spaces); it
// just latches conn_state_curr_q. Scan side picks the layout based on
// conn_state_curr_q (boot/handshake/connected/disconnected splash vs.
// the connected text_ram view).
// =====================================================================

`ifndef FE_RENDER_DECODER_SV
`define FE_RENDER_DECODER_SV

module fe_render_decoder
    import chat_pkg::*;
    import fe_pkg::*;
(
    input  logic                       clk,
    input  logic                       rst_n,

    // backend -> frontend command stream
    input  logic                       be_render_valid,
    output logic                       be_render_ready,
    input  logic [3:0]                 be_render_cmd,
    input  msg_id_t                    be_render_msg_id,
    input  logic [1:0]                 be_render_side,
    input  logic [1:0]                 be_render_status,
    input  msg_len_t                   be_render_len,
    input  logic [MAX_MSG_LEN*8-1:0]   be_render_payload,
    input  msg_len_t                   be_render_cursor_pos,
    input  byte_t                      be_render_ascii,
    input  logic [1:0]                 be_render_conn_state,
    input  msg_len_t                   be_render_peer_name_len,
    input  logic [MAX_NAME_LEN*8-1:0]  be_render_peer_name,

    // -> text_ram write port
    output logic                       wr_en,
    output logic [FE_ROW_W-1:0]        wr_row,
    output logic [FE_COL_W-1:0]        wr_col,
    output byte_t                      wr_code,

    // observability for scan & test
    output logic [1:0]                 conn_state_obs,
    output msg_len_t                   input_len_obs,
    output msg_len_t                   input_cursor_obs,
    output logic [MAX_NAME_LEN*8-1:0]  peer_name_obs,
    output msg_len_t                   peer_name_len_obs,

    // for fe_scan: ring head + scroll position so it can map screen
    // rows to text_ram rows without snooping internal state.
    output logic [HIST_W-1:0]          hist_wr_row_obs,
    output logic [SCROLL_W-1:0]        scroll_offset_obs
);

    // -----------------------------------------------------------------
    // FSM
    // -----------------------------------------------------------------
    typedef enum logic [3:0] {
        S_IDLE          = 4'd0,
        S_HIST_CLEAR    = 4'd1,
        S_TITLEBAR      = 4'd2,
        S_INPUT_REDRAW  = 4'd3,
        S_HIST_WRITE    = 4'd4,
        S_UPDATE_STATUS = 4'd5,
        S_INPUT_EDIT    = 4'd6
    } state_e;

    state_e state_q, state_d;

    // -----------------------------------------------------------------
    // Counters / latched-on-accept registers
    // -----------------------------------------------------------------
    logic [FE_COL_W-1:0]                 col_cnt_q;
    logic [HIST_W-1:0]                row_cnt_q;
    logic [FE_COL_W-1:0]                 pos_start_q;   // S_INPUT_EDIT start col
    logic [FE_COL_W-1:0]                 pos_end_q;     // S_INPUT_EDIT last col (incl)
    logic [FE_ROW_W-1:0]                 target_row_q;  // S_HIST_WRITE / S_UPDATE_STATUS

    logic [1:0]                       side_q;
    logic [1:0]                       status_q;
    logic [MAX_MSG_LEN*8-1:0]         payload_q;
    msg_len_t                         payload_len_q;

    // -----------------------------------------------------------------
    // Persistent UI state
    // -----------------------------------------------------------------
    logic [1:0]                       conn_state_curr_q;
    logic [MAX_NAME_LEN*8-1:0]        peer_name_q;
    msg_len_t                         peer_name_len_q;

    byte_t                            input_line_q [MAX_LINE_LEN];
    msg_len_t                         input_len_q;
    msg_len_t                         input_cursor_q;

    logic [HIST_W-1:0]                hist_wr_row_q;
    logic [SCROLL_W-1:0]              scroll_offset_q;

    // msg_id -> row offset (within history region) lookup
    logic [HIST_W-1:0]                msg_id_row_q   [256];
    logic                             msg_id_valid_q [256];

    // chained transitions (set on CONN_STATE accept that needs a
    // multi-step redraw)
    logic                             chain_titlebar_q;
    logic                             chain_input_q;

    // -----------------------------------------------------------------
    // Combinational helpers
    // -----------------------------------------------------------------
    assign be_render_ready = (state_q == S_IDLE);

    logic accept;
    assign accept = be_render_valid && be_render_ready;

    // Peer-name change detection (used at CONN_STATE accept).
    logic peer_changed;
    always_comb begin
        peer_changed = (be_render_peer_name_len != peer_name_len_q);
        for (int i = 0; i < MAX_NAME_LEN; i++) begin
            if (i < int'(be_render_peer_name_len) &&
                be_render_peer_name[i*8 +: 8] != peer_name_q[i*8 +: 8])
                peer_changed = 1'b1;
        end
    end

    // -----------------------------------------------------------------
    // Cell-content lookups (combinational, indexed by col_cnt_q)
    // -----------------------------------------------------------------
    function automatic byte_t title_prefix_byte(input int unsigned idx);
        case (idx)
            0:       title_prefix_byte = "C";
            1:       title_prefix_byte = "h";
            2:       title_prefix_byte = "a";
            3:       title_prefix_byte = "t";
            4:       title_prefix_byte = " ";
            5:       title_prefix_byte = "w";
            6:       title_prefix_byte = "i";
            7:       title_prefix_byte = "t";
            8:       title_prefix_byte = "h";
            9:       title_prefix_byte = ":";
            10:      title_prefix_byte = " ";
            default: title_prefix_byte = " ";
        endcase
    endfunction
    localparam int TITLE_PREFIX_LEN = 11;

    function automatic byte_t hist_prefix_byte(input logic [1:0] side,
                                                input int unsigned idx);
        if (side == 2'(MSG_LOCAL)) begin
            case (idx)
                0:       hist_prefix_byte = "m";
                1:       hist_prefix_byte = "e";
                2:       hist_prefix_byte = ":";
                default: hist_prefix_byte = " ";
            endcase
        end else begin
            // peer or system -> "peer: "
            case (idx)
                0:       hist_prefix_byte = "p";
                1:       hist_prefix_byte = "e";
                2:       hist_prefix_byte = "e";
                3:       hist_prefix_byte = "r";
                4:       hist_prefix_byte = ":";
                default: hist_prefix_byte = " ";
            endcase
        end
    endfunction

    function automatic byte_t status_sprite(input logic [1:0] s);
        case (s)
            2'(MSG_PENDING): status_sprite = SPRITE_PENDING;
            2'(MSG_SUCCESS): status_sprite = SPRITE_SUCCESS;
            2'(MSG_FAIL):    status_sprite = SPRITE_FAIL;
            default:         status_sprite = " ";
        endcase
    endfunction

    function automatic byte_t input_prefix_byte(input int unsigned idx);
        case (idx)
            0:       input_prefix_byte = ">";
            1:       input_prefix_byte = " ";
            default: input_prefix_byte = " ";
        endcase
    endfunction

    // Compute cell value at the current col_cnt_q for each multi-cycle
    // state. Only one is selected by wr_code below based on state_q.

    localparam int NAME_IDX_W = $clog2(MAX_NAME_LEN);
    localparam int LINE_IDX_W = $clog2(MAX_LINE_LEN);

    logic [FE_COL_W-1:0] title_name_idx;
    logic [FE_COL_W-1:0] payload_idx;
    logic [FE_COL_W-1:0] input_idx;

    byte_t titlebar_cell, hist_cell, input_cell;

    // Comparisons widen both sides to LEN_WIDTH (8b > FE_COL_W=7b for the
    // default 128-col layout), so peer_name_len_q / payload_len_q /
    // input_len_q can be compared directly.
    always_comb begin
        title_name_idx = col_cnt_q - FE_COL_W'(TITLE_PREFIX_LEN);
        payload_idx    = col_cnt_q - FE_COL_W'(PREFIX_LEN);
        input_idx      = col_cnt_q - FE_COL_W'(INPUT_PREFIX_LEN);

        // titlebar
        if (col_cnt_q < FE_COL_W'(TITLE_PREFIX_LEN))
            titlebar_cell = title_prefix_byte(int'(col_cnt_q));
        else if (LEN_WIDTH'(title_name_idx) < peer_name_len_q)
            titlebar_cell = peer_name_q[title_name_idx[NAME_IDX_W-1:0]*8 +: 8];
        else
            titlebar_cell = " ";

        // history row
        if (col_cnt_q < FE_COL_W'(PREFIX_LEN))
            hist_cell = hist_prefix_byte(side_q, int'(col_cnt_q));
        else if (LEN_WIDTH'(payload_idx) < payload_len_q)
            hist_cell = payload_q[payload_idx[LINE_IDX_W-1:0]*8 +: 8];
        else if ((col_cnt_q == FE_COL_W'(STATUS_COL))
                 && (side_q == 2'(MSG_LOCAL)))
            hist_cell = status_sprite(status_q);
        else
            hist_cell = " ";

        // input row
        if (col_cnt_q < FE_COL_W'(INPUT_PREFIX_LEN))
            input_cell = input_prefix_byte(int'(col_cnt_q));
        else if (LEN_WIDTH'(input_idx) < input_len_q)
            input_cell = input_line_q[input_idx[LINE_IDX_W-1:0]];
        else
            input_cell = " ";
    end

    // -----------------------------------------------------------------
    // Output drivers (wr_en / wr_row / wr_col / wr_code)
    // -----------------------------------------------------------------
    always_comb begin
        wr_en   = 1'b0;
        wr_row  = '0;
        wr_col  = col_cnt_q;
        wr_code = 8'h20;
        unique case (state_q)
            S_HIST_CLEAR: begin
                wr_en   = 1'b1;
                wr_row  = FE_ROW_W'(HIST_ROW_START) + FE_ROW_W'(row_cnt_q);
                wr_code = 8'h20;
            end
            S_TITLEBAR: begin
                wr_en   = 1'b1;
                wr_row  = FE_ROW_W'(TITLE_ROW);
                wr_code = titlebar_cell;
            end
            S_INPUT_REDRAW: begin
                wr_en   = 1'b1;
                wr_row  = FE_ROW_W'(INPUT_ROW);
                wr_code = input_cell;
            end
            S_HIST_WRITE: begin
                wr_en   = 1'b1;
                wr_row  = target_row_q;
                wr_code = hist_cell;
            end
            S_UPDATE_STATUS: begin
                wr_en   = 1'b1;
                wr_row  = target_row_q;
                wr_col  = FE_COL_W'(STATUS_COL);
                wr_code = status_sprite(status_q);
            end
            S_INPUT_EDIT: begin
                wr_en   = 1'b1;
                wr_row  = FE_ROW_W'(INPUT_ROW);
                wr_code = input_cell;
            end
            default: ;
        endcase
    end

    // -----------------------------------------------------------------
    // Next-state logic
    // -----------------------------------------------------------------
    logic at_last_col;
    logic at_last_hist_clear_cell;
    assign at_last_col = (col_cnt_q == FE_COL_W'(FE_N_COLS-1));
    assign at_last_hist_clear_cell =
        (col_cnt_q == FE_COL_W'(FE_N_COLS-1))
        && (row_cnt_q == HIST_W'(N_HIST_STORED - 1));

    always_comb begin
        state_d = state_q;
        unique case (state_q)
            S_IDLE: begin
                if (be_render_valid) begin
                    unique case (render_cmd_e'(be_render_cmd))
                        RENDER_REDRAW_ALL,
                        RENDER_CLEAR_SCREEN,
                        RENDER_MOVE_CURSOR,
                        RENDER_SCROLL_UP,
                        RENDER_SCROLL_DOWN:
                            // single-cycle: just latch, stay idle
                            state_d = S_IDLE;

                        RENDER_CONN_STATE: begin
                            if (be_render_conn_state == 2'(CONN_CONNECTED))
                                state_d = peer_changed ? S_HIST_CLEAR : S_TITLEBAR;
                            else
                                state_d = S_IDLE;
                        end

                        RENDER_APPEND_LOCAL_PENDING,
                        RENDER_APPEND_REMOTE:
                            state_d = S_HIST_WRITE;

                        RENDER_UPDATE_STATUS:
                            // Skip silently if msg_id not in our table.
                            state_d = msg_id_valid_q[be_render_msg_id]
                                      ? S_UPDATE_STATUS : S_IDLE;

                        RENDER_UPDATE_INPUT_LINE:
                            state_d = S_INPUT_REDRAW;

                        RENDER_INSERT_AT_CURSOR,
                        RENDER_DELETE_AT_CURSOR:
                            state_d = S_INPUT_EDIT;

                        default: state_d = S_IDLE;
                    endcase
                end
            end

            S_HIST_CLEAR: begin
                if (at_last_hist_clear_cell)
                    state_d = chain_titlebar_q ? S_TITLEBAR : S_IDLE;
            end

            S_TITLEBAR: begin
                if (at_last_col)
                    state_d = chain_input_q ? S_INPUT_REDRAW : S_IDLE;
            end

            S_INPUT_REDRAW:  if (at_last_col)             state_d = S_IDLE;
            S_HIST_WRITE:    if (at_last_col)             state_d = S_IDLE;
            S_UPDATE_STATUS:                              state_d = S_IDLE;
            S_INPUT_EDIT:    if (col_cnt_q == pos_end_q)  state_d = S_IDLE;

            default: state_d = S_IDLE;
        endcase
    end

    // -----------------------------------------------------------------
    // Sequential logic
    // -----------------------------------------------------------------
    logic entering_new_state;
    assign entering_new_state = (state_d != state_q);

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state_q           <= S_IDLE;
            col_cnt_q         <= '0;
            row_cnt_q         <= '0;
            pos_start_q       <= '0;
            pos_end_q         <= '0;
            target_row_q      <= '0;
            side_q            <= 2'(MSG_LOCAL);
            status_q          <= 2'(MSG_PENDING);
            payload_q         <= '0;
            payload_len_q     <= '0;

            conn_state_curr_q <= 2'(CONN_BOOT);
            peer_name_q       <= '0;
            peer_name_len_q   <= '0;

            input_len_q       <= '0;
            input_cursor_q    <= '0;
            for (int i = 0; i < MAX_LINE_LEN; i++)
                input_line_q[i] <= 8'h20;

            hist_wr_row_q     <= '0;
            scroll_offset_q   <= '0;
            for (int i = 0; i < 256; i++) begin
                msg_id_row_q[i]   <= '0;
                msg_id_valid_q[i] <= 1'b0;
            end

            chain_titlebar_q  <= 1'b0;
            chain_input_q     <= 1'b0;
        end else begin
            state_q <= state_d;

            // -----------------------------------------------------------
            // Counter advancement (col_cnt_q / row_cnt_q)
            // -----------------------------------------------------------
            if (entering_new_state) begin
                unique case (state_d)
                    S_INPUT_EDIT: col_cnt_q <= pos_start_q;
                    default:      col_cnt_q <= '0;
                endcase
                if (state_d == S_HIST_CLEAR) row_cnt_q <= '0;
            end else begin
                unique case (state_q)
                    S_HIST_CLEAR: begin
                        if (col_cnt_q == FE_COL_W'(FE_N_COLS-1)) begin
                            col_cnt_q <= '0;
                            row_cnt_q <= row_cnt_q + 1'b1;
                        end else begin
                            col_cnt_q <= col_cnt_q + 1'b1;
                        end
                    end
                    S_TITLEBAR,
                    S_INPUT_REDRAW,
                    S_HIST_WRITE: begin
                        if (col_cnt_q != FE_COL_W'(FE_N_COLS-1))
                            col_cnt_q <= col_cnt_q + 1'b1;
                    end
                    S_INPUT_EDIT: begin
                        if (col_cnt_q != pos_end_q)
                            col_cnt_q <= col_cnt_q + 1'b1;
                    end
                    default: ;
                endcase
            end

            // -----------------------------------------------------------
            // Accept handshake: latch cmd-specific state
            // -----------------------------------------------------------
            if (accept) begin
                unique case (render_cmd_e'(be_render_cmd))

                    RENDER_REDRAW_ALL: begin
                        conn_state_curr_q <= be_render_conn_state;
                        chain_titlebar_q  <= 1'b0;
                        chain_input_q     <= 1'b0;
                    end

                    RENDER_CLEAR_SCREEN: begin
                        // No-op (BE doesn't currently emit it).
                    end

                    RENDER_CONN_STATE: begin
                        conn_state_curr_q <= be_render_conn_state;
                        if (be_render_conn_state == 2'(CONN_CONNECTED)) begin
                            peer_name_q     <= be_render_peer_name;
                            peer_name_len_q <= be_render_peer_name_len;
                            chain_input_q    <= 1'b1;
                            chain_titlebar_q <= peer_changed;
                            if (peer_changed) begin
                                hist_wr_row_q   <= '0;
                                scroll_offset_q <= '0;
                                for (int i = 0; i < 256; i++)
                                    msg_id_valid_q[i] <= 1'b0;
                            end
                        end else begin
                            // Leaving connected: drop in-flight input
                            // line so reconnect doesn't show stale typing.
                            input_len_q    <= '0;
                            input_cursor_q <= '0;
                            for (int i = 0; i < MAX_LINE_LEN; i++)
                                input_line_q[i] <= 8'h20;
                            chain_input_q    <= 1'b0;
                            chain_titlebar_q <= 1'b0;
                        end
                    end

                    RENDER_APPEND_LOCAL_PENDING,
                    RENDER_APPEND_REMOTE: begin
                        side_q        <= be_render_side;
                        status_q      <= be_render_status;
                        payload_q     <= be_render_payload;
                        payload_len_q <= be_render_len;
                        target_row_q  <= FE_ROW_W'(HIST_ROW_START)
                                         + FE_ROW_W'(hist_wr_row_q);
                        msg_id_row_q[be_render_msg_id]   <= hist_wr_row_q;
                        msg_id_valid_q[be_render_msg_id] <= 1'b1;
                        if (hist_wr_row_q == HIST_W'(N_HIST_STORED - 1))
                            hist_wr_row_q <= '0;
                        else
                            hist_wr_row_q <= hist_wr_row_q + 1'b1;
                    end

                    RENDER_UPDATE_STATUS: begin
                        if (msg_id_valid_q[be_render_msg_id]) begin
                            status_q     <= be_render_status;
                            target_row_q <= FE_ROW_W'(HIST_ROW_START)
                                            + FE_ROW_W'(msg_id_row_q[be_render_msg_id]);
                        end
                    end

                    RENDER_UPDATE_INPUT_LINE: begin
                        // BE only emits this on Enter-commit (len=0).
                        input_len_q    <= be_render_len;
                        input_cursor_q <= be_render_cursor_pos;
                        if (be_render_len == '0) begin
                            for (int i = 0; i < MAX_LINE_LEN; i++)
                                input_line_q[i] <= 8'h20;
                        end
                    end

                    RENDER_INSERT_AT_CURSOR: begin
                        // be_render_cursor_pos is POST-edit; insert pos
                        // is cursor_pos - 1. Parallel shift right
                        // matches be_top KEY_CHAR pattern.
                        for (int i = 0; i < MAX_LINE_LEN; i++) begin
                            if (i == int'(be_render_cursor_pos) - 1) begin
                                input_line_q[i] <= be_render_ascii;
                            end else if ((i > int'(be_render_cursor_pos) - 1)
                                      && (i <= int'(input_len_q))) begin
                                input_line_q[i] <= input_line_q[i-1];
                            end
                        end
                        input_len_q    <= input_len_q + 8'd1;
                        input_cursor_q <= be_render_cursor_pos;

                        // Redraw cells from (insert_pos) through
                        // (old_input_len_q), inclusive, in the input row.
                        pos_start_q <= FE_COL_W'(INPUT_PREFIX_LEN)
                                       + FE_COL_W'(be_render_cursor_pos)
                                       - FE_COL_W'(1);
                        pos_end_q   <= FE_COL_W'(INPUT_PREFIX_LEN)
                                       + FE_COL_W'(input_len_q);
                    end

                    RENDER_DELETE_AT_CURSOR: begin
                        // be_render_cursor_pos is POST-edit; delete pos
                        // == cursor_pos. Parallel shift left matches
                        // be_top KEY_BACKSPACE pattern.
                        for (int i = 0; i < MAX_LINE_LEN; i++) begin
                            if ((i >= int'(be_render_cursor_pos))
                             && (i + 1 < int'(input_len_q))) begin
                                input_line_q[i] <= input_line_q[i+1];
                            end
                        end
                        // Clear the now-invalid old tail cell so the
                        // input_cell lookup writes a space there.
                        if (input_len_q > 0)
                            input_line_q[LINE_IDX_W'(input_len_q - 8'd1)] <= 8'h20;

                        input_len_q    <= input_len_q - 8'd1;
                        input_cursor_q <= be_render_cursor_pos;

                        pos_start_q <= FE_COL_W'(INPUT_PREFIX_LEN)
                                       + FE_COL_W'(be_render_cursor_pos);
                        pos_end_q   <= FE_COL_W'(INPUT_PREFIX_LEN)
                                       + FE_COL_W'(input_len_q)
                                       - FE_COL_W'(1);
                    end

                    RENDER_MOVE_CURSOR: begin
                        input_cursor_q <= be_render_cursor_pos;
                    end

                    RENDER_SCROLL_UP: begin
                        if (scroll_offset_q < SCROLL_W'(SCROLL_MAX))
                            scroll_offset_q <= scroll_offset_q + 1'b1;
                    end

                    RENDER_SCROLL_DOWN: begin
                        if (scroll_offset_q != '0)
                            scroll_offset_q <= scroll_offset_q - 1'b1;
                    end

                    default: ;
                endcase
            end

            // -----------------------------------------------------------
            // Clear chain flags as we consume them
            // -----------------------------------------------------------
            if (state_q == S_HIST_CLEAR && state_d == S_TITLEBAR)
                chain_titlebar_q <= 1'b0;
            if (state_q == S_TITLEBAR && state_d == S_INPUT_REDRAW)
                chain_input_q <= 1'b0;
        end
    end

    // -----------------------------------------------------------------
    // Observability
    // -----------------------------------------------------------------
    assign conn_state_obs    = conn_state_curr_q;
    assign input_len_obs     = input_len_q;
    assign input_cursor_obs  = input_cursor_q;
    assign peer_name_obs     = peer_name_q;
    assign peer_name_len_obs = peer_name_len_q;
    assign hist_wr_row_obs   = hist_wr_row_q;
    assign scroll_offset_obs = scroll_offset_q;

endmodule

`endif  // FE_RENDER_DECODER_SV
