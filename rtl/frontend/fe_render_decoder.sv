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
//   0xF3 SPRITE_BL  -- normal left border (rounded)
//   0xF4 SPRITE_BR  -- normal right border (rounded)
//   0xF6 SPRITE_FBL -- fail left border (square)
//   0xF7 SPRITE_FBR -- fail right border (square)
//
// History-row bubble layout:
//   Remote (MSG_REMOTE): left-aligned,  [payload]  starting at col 2
//   Local  (MSG_LOCAL) : right-aligned, [payload]  ending at col 97
//   Failed local messages use square-corner sprites instead of rounded.
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
    output logic [SCROLL_W-1:0]        scroll_offset_obs,

    // for fe_scan: 2-D cursor position within the multi-row input
    // window, plus the current input scroll offset.
    output logic [INPUT_LINE_W-1:0]    input_cursor_row_obs,
    output msg_len_t                   input_cursor_col_obs,
    output logic [INPUT_SCROLL_W-1:0]  input_scroll_offset_obs
);

    // -----------------------------------------------------------------
    // FSM
    // -----------------------------------------------------------------
    typedef enum logic [3:0] {
        S_IDLE          = 4'd0,
        S_HIST_CLEAR    = 4'd1,
        S_TITLEBAR      = 4'd2,
        // Input edit pipeline: PARSE re-scans input_line_q for newlines
        // (one cycle), then REDRAW sweeps every cell of the multi-row
        // input window. INSERT/DELETE/UPDATE_INPUT_LINE/MOVE_CURSOR all
        // funnel through this.
        S_INPUT_PARSE   = 4'd3,
        S_INPUT_REDRAW  = 4'd4,
        S_HIST_WRITE    = 4'd5,
        S_UPDATE_STATUS = 4'd6
    } state_e;

    state_e state_q, state_d;

    // -----------------------------------------------------------------
    // Counters / latched-on-accept registers
    // -----------------------------------------------------------------
    logic [FE_COL_W-1:0]              col_cnt_q;
    logic [HIST_W-1:0]                row_cnt_q;
    logic [INPUT_LINE_W-1:0]          input_row_cnt_q;  // S_INPUT_REDRAW
    logic [FE_ROW_W-1:0]              target_row_q;    // S_HIST_WRITE / S_UPDATE_STATUS

    logic [1:0]                       side_q;
    logic [1:0]                       status_q;
    logic [MAX_MSG_LEN*8-1:0]         payload_q;

    // Multi-line parsing state.
    // LINE_CNT_W must hold the value MAX_LINES itself (not just MAX_LINES-1)
    // so that n_lines_q can latch "saturated at MAX_LINES" after the parse
    // loop without wrapping to 0. LINE_IDX_BITS sizes the array index port
    // (always one bit narrower than LINE_CNT_W when MAX_LINES is a power of
    // two, so we slice cur_line_q below for array reads).
    // Sized so a typical 640-byte payload (~40 chars/line * 16 lines)
    // never overflows; the parser absorbs further newlines into the last
    // bubble row.
    localparam int MAX_LINES     = 16;
    localparam int LINE_CNT_W    = $clog2(MAX_LINES + 1);
    localparam int LINE_SEL_W    = (MAX_LINES <= 1) ? 1 : $clog2(MAX_LINES);

    logic [LINE_CNT_W-1:0]            cur_line_q;
    logic [LINE_CNT_W-1:0]            n_lines_q;
    logic [LINE_IDX_W-1:0]            ml_offset_q [MAX_LINES];
    msg_len_t                          ml_len_q    [MAX_LINES];

    // cur_line_q is bounded by FSM to 0..MAX_LINES-1, so it is safe to
    // address the ml_*_q arrays with its low LINE_SEL_W bits.
    logic [LINE_SEL_W-1:0]            cur_line_sel;
    assign cur_line_sel = cur_line_q[LINE_SEL_W-1:0];

    // -----------------------------------------------------------------
    // Persistent UI state
    // -----------------------------------------------------------------
    logic [1:0]                       conn_state_curr_q;
    logic [MAX_NAME_LEN*8-1:0]        peer_name_q;
    msg_len_t                         peer_name_len_q;

    byte_t                            input_line_q [MAX_LINE_LEN];
    msg_len_t                         input_len_q;
    msg_len_t                         input_cursor_q;

    // Input-side multi-line state. Parsed from input_line_q on every
    // accept that modifies the buffer (INSERT / DELETE / UPDATE_INPUT_LINE)
    // or the cursor (MOVE_CURSOR). Cursor row/col are 2D coordinates of
    // input_cursor_q so the scan side can highlight the cursor cell.
    logic [LINE_CNT_W-1:0]            input_n_lines_q;
    logic [LINE_IDX_W-1:0]            input_ml_offset_q [MAX_INPUT_LINES];
    msg_len_t                         input_ml_len_q    [MAX_INPUT_LINES];
    logic [INPUT_LINE_W-1:0]          input_cursor_row_q;
    msg_len_t                         input_cursor_col_q;
    logic [INPUT_SCROLL_W-1:0]        input_scroll_offset_q;

    logic [HIST_W-1:0]                hist_wr_row_q;
    logic [SCROLL_W-1:0]              scroll_offset_q;

    // msg_id -> ring slot lookup (small: 256 entries, HIST_W+1 bits each)
    logic [HIST_W-1:0]                msg_id_row_q      [256];
    logic                             msg_id_valid_q    [256];

    // Per-ring-slot metadata used by RENDER_UPDATE_STATUS to redraw the
    // entire bubble row (border position depends on payload length, and
    // the FAIL border swap needs the original payload). Indexed by ring
    // slot rather than by msg_id so it stays at N_HIST_STORED entries
    // even as MAX_MSG_LEN grows -- e.g. with MAX_MSG_LEN=640 and 64
    // slots, this is ~41 KB instead of the 164 KB a 256-deep table
    // would consume.
    logic [1:0]                       slot_side_q     [N_HIST_STORED];
    logic [MAX_MSG_LEN*8-1:0]         slot_payload_q  [N_HIST_STORED];
    msg_len_t                         slot_len_q      [N_HIST_STORED];

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
    logic [FE_COL_W-1:0] input_idx;

    byte_t titlebar_cell, hist_cell, input_cell;

    // Bubble geometry for history rows
    logic              show_fail;
    logic [FE_COL_W-1:0] bubble_left, bubble_right, payload_start;
    logic [LINE_IDX_W-1:0] payload_idx;
    logic              payload_in_range;
    msg_len_t          cur_sub_len;

    assign show_fail = (side_q == 2'(MSG_LOCAL)) && (status_q == 2'(MSG_FAIL));
    assign cur_sub_len = ml_len_q[cur_line_sel];

    always_comb begin
        if (side_q == 2'(MSG_REMOTE)) begin
            // Left-aligned: bubble starts at BUBBLE_MARGIN_L
            bubble_left   = FE_COL_W'(BUBBLE_MARGIN_L);
            payload_start = FE_COL_W'(BUBBLE_MARGIN_L + 1);
            bubble_right  = FE_COL_W'(BUBBLE_MARGIN_L + 1)
                            + FE_COL_W'(cur_sub_len);
        end else begin
            // Right-aligned: bubble ends at BUBBLE_RIGHT_EDGE
            bubble_right  = FE_COL_W'(BUBBLE_RIGHT_EDGE);
            bubble_left   = FE_COL_W'(BUBBLE_RIGHT_EDGE)
                            - FE_COL_W'(cur_sub_len) - FE_COL_W'(1);
            payload_start = bubble_left + FE_COL_W'(1);
        end
    end

    // Comparisons widen both sides to LEN_WIDTH (8b > FE_COL_W=7b for the
    // default 128-col layout), so peer_name_len_q / payload_len_q /
    // input_len_q can be compared directly.
    logic [LINE_IDX_W-1:0] abs_idx;
    always_comb begin
        title_name_idx = col_cnt_q - FE_COL_W'(TITLE_PREFIX_LEN);
        input_idx      = col_cnt_q - FE_COL_W'(INPUT_PREFIX_LEN);
        payload_idx    = LINE_IDX_W'(col_cnt_q - payload_start);
        payload_in_range = (col_cnt_q >= payload_start)
                           && (LEN_WIDTH'(col_cnt_q - payload_start) < cur_sub_len);
        abs_idx = ml_offset_q[cur_line_sel] + payload_idx;

        // titlebar
        if (col_cnt_q < FE_COL_W'(TITLE_PREFIX_LEN))
            titlebar_cell = title_prefix_byte(int'(col_cnt_q));
        else if (LEN_WIDTH'(title_name_idx) < peer_name_len_q)
            titlebar_cell = peer_name_q[title_name_idx[NAME_IDX_W-1:0]*8 +: 8];
        else
            titlebar_cell = " ";

        // history row -- bubble layout (multi-line aware)
        if (col_cnt_q == bubble_left)
            hist_cell = show_fail ? SPRITE_FBL : SPRITE_BL;
        else if (col_cnt_q == bubble_right)
            hist_cell = show_fail ? SPRITE_FBR : SPRITE_BR;
        else if (payload_in_range)
            hist_cell = payload_q[abs_idx[LINE_IDX_W-1:0]*8 +: 8];
        else
            hist_cell = " ";

        // input row. col_cnt_q only sweeps 0..FE_N_COLS-1=127. Row 0 of
        // the input area carries the "> " prefix; rows 1..n_lines-1
        // start at col 0. Rows past n_lines are blanked so a buffer
        // that shrunk (e.g. Enter-commit) doesn't leave stale content.
        if (LINE_CNT_W'(input_row_cnt_q) >= input_n_lines_q) begin
            input_cell = " ";
        end else if (input_row_cnt_q == '0) begin
            if (col_cnt_q < FE_COL_W'(INPUT_PREFIX_LEN))
                input_cell = input_prefix_byte(int'(col_cnt_q));
            else if (LEN_WIDTH'(input_idx) < input_ml_len_q[0])
                input_cell = input_line_q[LINE_IDX_W'(input_idx)];
            else
                input_cell = " ";
        end else begin
            // Subsequent input lines: no prefix, content starts at col 0
            if (LEN_WIDTH'(col_cnt_q) < input_ml_len_q[input_row_cnt_q])
                input_cell = input_line_q[
                    input_ml_offset_q[input_row_cnt_q]
                    + LINE_IDX_W'(col_cnt_q)];
            else
                input_cell = " ";
        end
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
                wr_row  = FE_ROW_W'(INPUT_ROW_START)
                          + FE_ROW_W'(input_row_cnt_q);
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
                wr_code = hist_cell;
            end
            // S_INPUT_PARSE writes no cells -- it just runs the
            // newline-scan and falls through to S_INPUT_REDRAW.
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

                        // Any input-related update funnels through the
                        // parse-then-redraw pipeline so newline boundaries
                        // and cursor row/col are recomputed and the
                        // entire input region is refreshed in one go.
                        RENDER_UPDATE_INPUT_LINE,
                        RENDER_INSERT_AT_CURSOR,
                        RENDER_DELETE_AT_CURSOR,
                        RENDER_MOVE_CURSOR:
                            state_d = S_INPUT_PARSE;

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
                    state_d = chain_input_q ? S_INPUT_PARSE : S_IDLE;
            end

            // S_INPUT_PARSE is a single-cycle parse-of-input_line_q step
            // that always falls through to the full multi-row redraw.
            S_INPUT_PARSE: state_d = S_INPUT_REDRAW;

            S_INPUT_REDRAW: begin
                if (at_last_col) begin
                    if (LINE_CNT_W'(input_row_cnt_q) + LINE_CNT_W'(1)
                        < LINE_CNT_W'(MAX_INPUT_LINES))
                        state_d = S_INPUT_REDRAW;
                    else
                        state_d = S_IDLE;
                end
            end

            S_HIST_WRITE: begin
                if (at_last_col) begin
                    if (cur_line_q + 1 < n_lines_q)
                        state_d = S_HIST_WRITE;
                    else
                        state_d = S_IDLE;
                end
            end
            S_UPDATE_STATUS: begin
                if (at_last_col) begin
                    if (cur_line_q + 1 < n_lines_q)
                        state_d = S_UPDATE_STATUS;
                    else
                        state_d = S_IDLE;
                end
            end

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
            input_row_cnt_q   <= '0;
            target_row_q      <= '0;
            side_q            <= 2'(MSG_LOCAL);
            status_q          <= 2'(MSG_PENDING);
            payload_q         <= '0;
            cur_line_q        <= '0;
            n_lines_q         <= LINE_CNT_W'(1);
            for (int i = 0; i < MAX_LINES; i++) begin
                ml_offset_q[i] <= '0;
                ml_len_q[i]    <= '0;
            end

            conn_state_curr_q <= 2'(CONN_BOOT);
            peer_name_q       <= '0;
            peer_name_len_q   <= '0;

            input_len_q       <= '0;
            input_cursor_q    <= '0;
            for (int i = 0; i < MAX_LINE_LEN; i++)
                input_line_q[i] <= 8'h20;
            input_n_lines_q       <= LINE_CNT_W'(1);
            for (int i = 0; i < MAX_INPUT_LINES; i++) begin
                input_ml_offset_q[i] <= '0;
                input_ml_len_q[i]    <= '0;
            end
            input_cursor_row_q    <= '0;
            input_cursor_col_q    <= '0;
            input_scroll_offset_q <= '0;

            hist_wr_row_q     <= '0;
            scroll_offset_q   <= '0;
            for (int i = 0; i < 256; i++) begin
                msg_id_row_q[i]   <= '0;
                msg_id_valid_q[i] <= 1'b0;
            end
            for (int i = 0; i < N_HIST_STORED; i++) begin
                slot_side_q[i]    <= 2'(MSG_LOCAL);
                slot_payload_q[i] <= '0;
                slot_len_q[i]     <= '0;
            end

            chain_titlebar_q  <= 1'b0;
            chain_input_q     <= 1'b0;
        end else begin
            state_q <= state_d;

            // -----------------------------------------------------------
            // Counter advancement (col_cnt_q / row_cnt_q)
            // -----------------------------------------------------------
            if (entering_new_state) begin
                col_cnt_q <= '0;
                if (state_d == S_HIST_CLEAR)    row_cnt_q       <= '0;
                if (state_d == S_INPUT_REDRAW)  input_row_cnt_q <= '0;
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
                    S_TITLEBAR: begin
                        if (col_cnt_q != FE_COL_W'(FE_N_COLS-1))
                            col_cnt_q <= col_cnt_q + 1'b1;
                    end
                    S_INPUT_REDRAW: begin
                        if (col_cnt_q == FE_COL_W'(FE_N_COLS-1)) begin
                            // Advance to the next input row (we'll stop
                            // before MAX_INPUT_LINES via state_d).
                            if (LINE_CNT_W'(input_row_cnt_q) + LINE_CNT_W'(1)
                                < LINE_CNT_W'(MAX_INPUT_LINES)) begin
                                col_cnt_q       <= '0;
                                input_row_cnt_q <= input_row_cnt_q + 1'b1;
                            end
                        end else begin
                            col_cnt_q <= col_cnt_q + 1'b1;
                        end
                    end
                    S_HIST_WRITE,
                    S_UPDATE_STATUS: begin
                        if (col_cnt_q == FE_COL_W'(FE_N_COLS-1)) begin
                            if (cur_line_q + 1 < n_lines_q) begin
                                col_cnt_q   <= '0;
                                cur_line_q  <= cur_line_q + 1'b1;
                                // Wrap target_row within the history ring
                                // (rows HIST_ROW_START..HIST_ROW_END). Without
                                // this a multi-line message starting near
                                // HIST_ROW_END spills into the sep row and
                                // INPUT_ROW below.
                                if (target_row_q == FE_ROW_W'(HIST_ROW_END))
                                    target_row_q <= FE_ROW_W'(HIST_ROW_START);
                                else
                                    target_row_q <= target_row_q + 1'b1;
                            end
                        end else begin
                            col_cnt_q <= col_cnt_q + 1'b1;
                        end
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
                                for (int i = 0; i < N_HIST_STORED; i++) begin
                                    slot_side_q[i] <= 2'(MSG_LOCAL);
                                    slot_len_q[i]  <= '0;
                                end
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
                        target_row_q  <= FE_ROW_W'(HIST_ROW_START)
                                         + FE_ROW_W'(hist_wr_row_q);
                        msg_id_row_q[be_render_msg_id]   <= hist_wr_row_q;
                        msg_id_valid_q[be_render_msg_id] <= 1'b1;
                        slot_side_q[hist_wr_row_q]       <= be_render_side;
                        slot_payload_q[hist_wr_row_q]    <= be_render_payload;
                        slot_len_q[hist_wr_row_q]        <= be_render_len;
                        // Multi-line parsing. Cap at MAX_LINES so we
                        // never write ml_*_q[MAX_LINES..] (OOB) and never
                        // truncate n_lines_q via narrow-cast wrap. Bytes
                        // after the MAX_LINES-th newline (including any
                        // further 0x0A bytes) accumulate into the final
                        // line's length -- they will render with 0x0A
                        // glyphs (returned-arrow) in the bubble.
                        begin
                            int n_lines, line_start;
                            n_lines = 1;
                            ml_offset_q[0] <= '0;
                            line_start = 0;
                            for (int i = 0; i < MAX_MSG_LEN; i++) begin
                                if (i < int'(be_render_len)
                                    && be_render_payload[i*8 +: 8] == 8'h0A
                                    && n_lines < MAX_LINES) begin
                                    ml_len_q[n_lines - 1]
                                        <= msg_len_t'(i - line_start);
                                    ml_offset_q[n_lines]
                                        <= LINE_IDX_W'(i + 1);
                                    n_lines = n_lines + 1;
                                    line_start = i + 1;
                                end
                            end
                            ml_len_q[n_lines - 1]
                                <= msg_len_t'(int'(be_render_len) - line_start);
                            n_lines_q  <= LINE_CNT_W'(n_lines);
                            cur_line_q <= '0;
                            hist_wr_row_q <= (hist_wr_row_q
                                + HIST_W'(n_lines)) & HIST_W'(N_HIST_STORED - 1);
                        end
                    end

                    RENDER_UPDATE_STATUS: begin
                        if (msg_id_valid_q[be_render_msg_id]) begin
                            // Snapshot the ring slot owning this msg_id
                            // once; both target_row_q and slot_*_q reads
                            // use it.
                            automatic logic [HIST_W-1:0] slot;
                            slot = msg_id_row_q[be_render_msg_id];

                            status_q     <= be_render_status;
                            target_row_q <= FE_ROW_W'(HIST_ROW_START)
                                            + FE_ROW_W'(slot);
                            side_q       <= slot_side_q[slot];
                            payload_q    <= slot_payload_q[slot];
                            // Re-parse multi-line boundaries. Same
                            // MAX_LINES cap as the APPEND path.
                            begin
                                int n_lines, line_start;
                                n_lines = 1;
                                ml_offset_q[0] <= '0;
                                line_start = 0;
                                for (int i = 0; i < MAX_MSG_LEN; i++) begin
                                    if (i < int'(slot_len_q[slot])
                                        && slot_payload_q[slot][i*8 +: 8]
                                           == 8'h0A
                                        && n_lines < MAX_LINES) begin
                                        ml_len_q[n_lines - 1]
                                            <= msg_len_t'(i - line_start);
                                        ml_offset_q[n_lines]
                                            <= LINE_IDX_W'(i + 1);
                                        n_lines = n_lines + 1;
                                        line_start = i + 1;
                                    end
                                end
                                ml_len_q[n_lines - 1]
                                    <= msg_len_t'(int'(slot_len_q[slot])
                                                  - line_start);
                                n_lines_q  <= LINE_CNT_W'(n_lines);
                                cur_line_q <= '0;
                            end
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
                        input_len_q    <= input_len_q + LEN_WIDTH'(1);
                        input_cursor_q <= be_render_cursor_pos;
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
                            input_line_q[LINE_IDX_W'(input_len_q - LEN_WIDTH'(1))] <= 8'h20;

                        input_len_q    <= input_len_q - LEN_WIDTH'(1);
                        input_cursor_q <= be_render_cursor_pos;
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
            if (state_q == S_TITLEBAR && state_d == S_INPUT_PARSE)
                chain_input_q <= 1'b0;

            // -----------------------------------------------------------
            // S_INPUT_PARSE: with input_line_q / input_len_q / input_cursor_q
            // now reflecting the post-accept state, walk the buffer to find
            // newline boundaries, line lengths, and the 2-D cursor address.
            // Same MAX_INPUT_LINES cap behaviour as the bubble parser.
            // -----------------------------------------------------------
            if (state_q == S_INPUT_PARSE) begin
                int n_lines, line_start, cur_pos;
                logic [INPUT_LINE_W-1:0] cursor_row;
                msg_len_t                cursor_col;

                n_lines    = 1;
                line_start = 0;
                input_ml_offset_q[0] <= '0;
                cur_pos    = int'(input_cursor_q);
                cursor_row = '0;
                cursor_col = msg_len_t'(cur_pos);

                for (int i = 0; i < MAX_LINE_LEN; i++) begin
                    if (i < int'(input_len_q)
                        && input_line_q[i] == 8'h0A
                        && n_lines < MAX_INPUT_LINES) begin
                        input_ml_len_q[n_lines - 1]
                            <= msg_len_t'(i - line_start);
                        input_ml_offset_q[n_lines]
                            <= LINE_IDX_W'(i + 1);
                        if (cur_pos > i) begin
                            cursor_row = INPUT_LINE_W'(n_lines);
                            cursor_col = msg_len_t'(cur_pos - (i + 1));
                        end
                        n_lines    = n_lines + 1;
                        line_start = i + 1;
                    end
                end
                input_ml_len_q[n_lines - 1]
                    <= msg_len_t'(int'(input_len_q) - line_start);
                input_n_lines_q    <= LINE_CNT_W'(n_lines);
                input_cursor_row_q <= cursor_row;
                input_cursor_col_q <= cursor_col;
            end
        end
    end

    // -----------------------------------------------------------------
    // Observability
    // -----------------------------------------------------------------
    assign conn_state_obs           = conn_state_curr_q;
    assign input_len_obs            = input_len_q;
    assign input_cursor_obs         = input_cursor_q;
    assign peer_name_obs            = peer_name_q;
    assign peer_name_len_obs        = peer_name_len_q;
    assign hist_wr_row_obs          = hist_wr_row_q;
    assign scroll_offset_obs        = scroll_offset_q;
    assign input_cursor_row_obs     = input_cursor_row_q;
    assign input_cursor_col_obs     = input_cursor_col_q;
    assign input_scroll_offset_obs  = input_scroll_offset_q;

endmodule

`endif  // FE_RENDER_DECODER_SV
