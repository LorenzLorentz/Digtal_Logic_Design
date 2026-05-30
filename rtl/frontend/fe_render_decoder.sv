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
//   msg_key_row_q[]     {side,msg_id} lookup so RENDER_UPDATE_STATUS can
//                       find the row that owns a specific local/remote msg.
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
#(
    parameter int LOCAL_NAME_LEN = 5,
    parameter logic [MAX_NAME_LEN*8-1:0] LOCAL_NAME_PACKED =
        128'h00000000_00000000_00000065_63696c41
)
(
    input  logic                       clk,
    input  logic                       rst_n,

    // backend -> frontend command stream
    input  logic                       be_render_valid,
    output logic                       be_render_ready,
    input  logic [3:0]                 be_render_cmd,
    input  msg_id_t                    be_render_msg_id,
    input  logic [$clog2(MAX_MSG_NUM)-1:0] be_render_store_idx,
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
    output logic [1:0]                 wr_attr,

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
    output logic [N_HIST_STORED*2-1:0] hist_avatar_attr_obs,
    output logic [N_HIST_STORED-1:0]   hist_owner_valid_obs,
    output logic [N_HIST_STORED*$clog2(MAX_MSG_NUM)-1:0]
                                            hist_owner_store_idx_obs,
    output logic [N_HIST_STORED*2-1:0] hist_owner_side_obs,
    output logic [N_HIST_STORED*FE_COL_W-1:0]
                                            hist_owner_width_obs,

    // for fe_scan: 2-D cursor position within the multi-row input
    // window, plus the current input scroll offset.
    output logic [INPUT_LINE_W-1:0]    input_cursor_row_obs,
    output msg_len_t                   input_cursor_col_obs,
    output logic [INPUT_N_LINES_W-1:0] input_n_lines_obs,
    output logic [INPUT_SCROLL_W-1:0]  input_scroll_offset_obs,

    // Quote indicator: 1 = active quote, show ">" marker
    input  logic                       has_quote
);

    // -----------------------------------------------------------------
    // FSM
    // -----------------------------------------------------------------
    typedef enum logic [3:0] {
        S_IDLE          = 4'd0,
        S_HIST_CLEAR    = 4'd1,
        S_TITLEBAR      = 4'd2,
        // Input edit pipeline:
        //   INSERT  -> S_INPUT_INSERT  -> S_INPUT_PARSE -> S_INPUT_REDRAW
        //   DELETE  -> S_INPUT_DELETE  -> S_INPUT_PARSE -> S_INPUT_REDRAW
        //   MOVE_CURSOR / UPDATE_INPUT_LINE -> S_INPUT_PARSE -> _REDRAW
        // The two shift states walk input_line_q one byte per cycle so
        // Vivado doesn't have to unroll a MAX_LINE_LEN-wide parallel
        // shift. PARSE walks the buffer one byte per cycle too.
        S_INPUT_INSERT  = 4'd3,
        S_INPUT_DELETE  = 4'd4,
        S_INPUT_PARSE   = 4'd5,
        S_INPUT_REDRAW  = 4'd6,
        // History payload pipeline: STORE writes bytes into the
        // payload BRAM one byte per cycle (also runs newline parse);
        // LOAD reads them back into payload_q for UPDATE_STATUS.
        S_HIST_STORE    = 4'd7,
        S_HIST_LOAD     = 4'd8,
        S_HIST_WRITE    = 4'd9,
        S_UPDATE_STATUS = 4'd10,
        S_INPUT_LOAD    = 4'd11
    } state_e;

    state_e state_q, state_d;

    // -----------------------------------------------------------------
    // Width helpers (declared up-front so the multi-line state declarations
    // below can use them without triggering Vivado's "identifier used
    // before its declaration" warning).
    // -----------------------------------------------------------------
    localparam int NAME_IDX_W = $clog2(MAX_NAME_LEN);
    localparam int LINE_IDX_W = $clog2(MAX_LINE_LEN);
    localparam int STORE_IDX_W = $clog2(MAX_MSG_NUM);

    // -----------------------------------------------------------------
    // Counters / latched-on-accept registers
    // -----------------------------------------------------------------
    logic [FE_COL_W-1:0]              col_cnt_q;
    logic [HIST_W-1:0]                row_cnt_q;
    logic [INPUT_LINE_W-1:0]          input_row_cnt_q;  // S_INPUT_REDRAW
    logic [FE_ROW_W-1:0]              target_row_q;    // S_HIST_WRITE / S_UPDATE_STATUS

    logic [1:0]                       side_q;
    logic [1:0]                       status_q;
    logic [STORE_IDX_W-1:0]           store_idx_q;
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

    // Big-emoji bubble state. When the stored payload is a single byte
    // in [BIG_EMOJI_BASE, BIG_EMOJI_END_EXCL), the parse latches a fixed
    // N_ROWS x N_COLS bubble layout and the hist_cell mux generates tile
    // codes from (cur_line_q, payload_idx) instead of reading payload_q.
    // fe_scan recognises tile codes and routes the pixel through the
    // big-emoji colour ROMs.
    logic                             is_big_emoji_q;
    byte_t                            big_emoji_anchor_q;

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

    // Multi-cycle INSERT/DELETE walk counter + the post-edit ascii.
    // (BE side has the analogous shift_idx_q.)
    logic [LEN_WIDTH-1:0]             input_shift_idx_q;
    byte_t                            input_shift_ascii_q;
    msg_len_t                         input_shift_cursor_q;  // be_render_cursor_pos (post-edit)

    // Multi-cycle parse accumulators (replaces the old single-cycle
    // 128-iteration for-loop in S_INPUT_PARSE).
    logic [LINE_IDX_W-1:0]            parse_idx_q;       // byte cursor
    logic [LINE_CNT_W-1:0]            parse_n_lines_q;   // lines seen so far
    logic [LINE_IDX_W-1:0]            parse_line_start_q;
    logic [INPUT_LINE_W-1:0]          parse_cursor_row_q;
    msg_len_t                         parse_cursor_col_q;
    // Narrow aliases for indexing input_ml_*_q[].
    // parse_line_sel    = parse_n_lines_q       (the next line index)
    // parse_last_sel    = parse_n_lines_q - 1   (current "open" line)
    /* verilator lint_off UNUSEDSIGNAL */
    logic [LINE_CNT_W-1:0]            parse_last_idx;
    /* verilator lint_on UNUSEDSIGNAL */
    logic [INPUT_LINE_W-1:0]          parse_line_sel;
    logic [INPUT_LINE_W-1:0]          parse_last_sel;
    assign parse_last_idx = parse_n_lines_q - LINE_CNT_W'(1);
    assign parse_line_sel = parse_n_lines_q[INPUT_LINE_W-1:0];
    assign parse_last_sel = parse_last_idx[INPUT_LINE_W-1:0];

    logic [HIST_W-1:0]                hist_wr_row_q;
    logic [SCROLL_W-1:0]              scroll_offset_q;
    // Total text-ram rows actually written for the current peer. Caps
    // at N_HIST_STORED (the ring fills). Used to clamp scroll_offset_q
    // so the user can't scroll up past the oldest stored message into
    // empty ring slots. Width = HIST_W + 1 so the literal N_HIST_STORED
    // (== 1 << HIST_W) fits without wrapping back to 0.
    logic [HIST_W:0]                  used_hist_rows_q;

    // {side,msg_id} -> ring slot lookup. Both peers allocate msg_id from 0,
    // so side is part of the key to avoid LOCAL/REMOTE collisions.
    localparam int MSG_LOOKUP_KEY_W = 2 + MSG_ID_WIDTH;
    localparam int MSG_LOOKUP_N     = 1 << MSG_LOOKUP_KEY_W;
    logic [HIST_W-1:0]                msg_key_row_q      [MSG_LOOKUP_N];
    logic                             msg_key_valid_q    [MSG_LOOKUP_N];

    // Per-ring-slot metadata used by RENDER_UPDATE_STATUS to redraw the
    // entire bubble row. side and len are kept as register arrays
    // (small: 2-bit and 16-bit per slot); the payload moved into BRAM
    // (fe_msg_payload_ram) to free the LUTs.
    logic [1:0]                       slot_side_q     [N_HIST_STORED];
    msg_id_t                          slot_msg_id_q   [N_HIST_STORED];
    logic                             slot_msg_valid_q[N_HIST_STORED];
    msg_len_t                         slot_len_q      [N_HIST_STORED];
    logic [LINE_CNT_W-1:0]            slot_n_lines_q  [N_HIST_STORED];
    logic [1:0]                       slot_avatar_attr_q [N_HIST_STORED];

    logic                             slot_owner_valid_q [N_HIST_STORED];
    logic [STORE_IDX_W-1:0]           slot_owner_store_idx_q [N_HIST_STORED];
    logic [1:0]                       slot_owner_side_q [N_HIST_STORED];
    logic [FE_COL_W-1:0]              slot_owner_width_q [N_HIST_STORED];

    genvar attr_i;
    generate
        for (attr_i = 0; attr_i < N_HIST_STORED; attr_i++) begin : g_hist_avatar_attr_obs
            assign hist_avatar_attr_obs[attr_i*2 +: 2] = slot_avatar_attr_q[attr_i];
            assign hist_owner_valid_obs[attr_i] = slot_owner_valid_q[attr_i];
            assign hist_owner_store_idx_obs[attr_i*STORE_IDX_W +: STORE_IDX_W]
                = slot_owner_store_idx_q[attr_i];
            assign hist_owner_side_obs[attr_i*2 +: 2] = slot_owner_side_q[attr_i];
            assign hist_owner_width_obs[attr_i*FE_COL_W +: FE_COL_W]
                = slot_owner_width_q[attr_i];
        end
    endgenerate

    // -----------------------------------------------------------------
    // Payload BRAM ports + multi-cycle STORE/LOAD walk state.
    // -----------------------------------------------------------------
    localparam int MSG_BYTE_IDX_W = $clog2(MAX_MSG_LEN);

    logic                       msg_bram_wr_en;
    logic [HIST_W-1:0]          msg_bram_wr_slot;
    logic [MSG_BYTE_IDX_W-1:0]  msg_bram_wr_byte;
    byte_t                      msg_bram_wr_data;
    logic [HIST_W-1:0]          msg_bram_rd_slot;
    logic [MSG_BYTE_IDX_W-1:0]  msg_bram_rd_byte;
    byte_t                      msg_bram_rd_data;

    fe_msg_payload_ram u_slot_payload_ram (
        .wr_clk      (clk),
        .wr_en       (msg_bram_wr_en),
        .wr_slot     (msg_bram_wr_slot),
        .wr_byte_idx (msg_bram_wr_byte),
        .wr_data     (msg_bram_wr_data),
        .rd_clk      (clk),
        .rd_slot     (msg_bram_rd_slot),
        .rd_byte_idx (msg_bram_rd_byte),
        .rd_data     (msg_bram_rd_data)
    );

    // Maximum visible bubble inner width (in characters). Soft-wrap
    // kicks in at this many bytes per visual row. Must fit on the
    // smaller side: local bubble has bubble_left = BUBBLE_RIGHT_EDGE -
    // W - 1, which must be >= 0 (W <= 96). 80 leaves visual margin.
    localparam int MAX_BUBBLE_INNER_W = 80;

    // Input area soft-wrap width. text_ram is FE_N_COLS = 128 wide,
    // but the pixel-side data_enable only covers HSIZE = 800 pixels
    // (= 100 char cols), so cols 100..127 of text_ram are NEVER
    // displayed. We further align the input's right edge with
    // BUBBLE_RIGHT_EDGE (= 97) so what the user sees while typing
    // matches the bubble that gets rendered on Enter.
    //   Row 0 :  "> " at cols 0..1, content at cols 2..97 (96 chars).
    //   Row 1+:  no prefix, content at cols 0..95 (also 96 chars, so
    //            the wrap logic is uniform across rows).
    // Hitting the 96th content byte wraps the cursor onto a new
    // visual row at col 0, keeping it on-screen.
    localparam int INPUT_SOFT_WRAP_W = BUBBLE_RIGHT_EDGE
                                        - INPUT_PREFIX_LEN + 1;

    // Byte counter shared by S_HIST_STORE and S_HIST_LOAD. STORE walks
    // 0..msg_total_len_q-1; LOAD walks 0..msg_total_len_q to absorb the
    // BRAM read pipeline's 1-cycle latency.
    logic [MSG_BYTE_IDX_W:0]    byte_walk_idx_q;   // 1 extra bit for "== len" sentinel
    msg_len_t                   msg_total_len_q;
    logic [HIST_W-1:0]          msg_target_slot_q;

    // Multi-cycle newline-parse accumulators (mirrors the input-parse
    // accumulators added in Step B; used during S_HIST_STORE /
    // S_HIST_LOAD to populate ml_offset_q[] / ml_len_q[]).
    logic [LINE_CNT_W-1:0]      msg_parse_n_lines_q;
    logic [LINE_IDX_W-1:0]      msg_parse_line_start_q;
    // Running maximum of all line lengths seen so far in the current
    // message. Used as the bubble's inner width so every sub-line of
    // a multi-line / soft-wrapped message shares the same border
    // alignment ("single bubble" look).
    msg_len_t                   msg_max_sub_len_q;
    /* verilator lint_off UNUSEDSIGNAL */
    logic [LINE_CNT_W-1:0]      msg_parse_last_idx;
    /* verilator lint_on UNUSEDSIGNAL */
    logic [LINE_SEL_W-1:0]      msg_parse_line_sel;
    logic [LINE_SEL_W-1:0]      msg_parse_last_sel;
    assign msg_parse_last_idx = msg_parse_n_lines_q - LINE_CNT_W'(1);
    assign msg_parse_line_sel = msg_parse_n_lines_q[LINE_SEL_W-1:0];
    assign msg_parse_last_sel = msg_parse_last_idx[LINE_SEL_W-1:0];

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

    function automatic logic [1:0] bubble_attr_for_side(input logic [1:0] side);
        if (side == 2'(MSG_REMOTE))
            bubble_attr_for_side = BUBBLE_ATTR_REMOTE;
        else if (side == 2'(MSG_LOCAL))
            bubble_attr_for_side = BUBBLE_ATTR_LOCAL;
        else
            bubble_attr_for_side = BUBBLE_ATTR_NONE;
    endfunction

    function automatic logic is_big_emoji_tile_code(input byte_t code);
        is_big_emoji_tile_code = (code >= byte_t'(BIG_EMOJI_BASE))
                              && (code <  byte_t'(BIG_EMOJI_END_EXCL));
    endfunction

    // Effective scroll caps. Both grow with actual content (rather
    // than the buffer size), so the user can't scroll up past the
    // oldest stored row of history or the last typed input row.
    logic [SCROLL_W-1:0]       hist_scroll_max;
    logic [INPUT_SCROLL_W-1:0] input_scroll_max;
    function automatic logic [HIST_W:0] hist_used_after_append(
        input logic [HIST_W:0]       used_rows,
        input logic [LINE_CNT_W-1:0] added_rows
    );
        automatic logic [HIST_W+1:0] sum;
        begin
            sum = {1'b0, used_rows} + (HIST_W+2)'(added_rows);
            if (sum >= (HIST_W+2)'(N_HIST_STORED))
                hist_used_after_append = (HIST_W+1)'(N_HIST_STORED);
            else
                hist_used_after_append = sum[HIST_W:0];
        end
    endfunction

    function automatic logic [SCROLL_W-1:0] hist_scroll_max_for_used(
        input logic [HIST_W:0] used_rows
    );
        begin
            if (used_rows > (HIST_W+1)'(N_HIST_VISIBLE))
                hist_scroll_max_for_used = SCROLL_W'(
                    used_rows - (HIST_W+1)'(N_HIST_VISIBLE));
            else
                hist_scroll_max_for_used = '0;
        end
    endfunction

    function automatic logic [SCROLL_W-1:0] hist_scroll_after_append(
        input logic [SCROLL_W-1:0]    cur_scroll,
        input logic [HIST_W:0]        next_used_rows,
        input logic [LINE_CNT_W-1:0]  added_rows
    );
        automatic logic [SCROLL_W-1:0] next_scroll_max;
        automatic logic [SCROLL_W:0]   wanted_scroll;
        begin
            next_scroll_max = hist_scroll_max_for_used(next_used_rows);
            wanted_scroll   = {1'b0, cur_scroll} + (SCROLL_W+1)'(added_rows);

            // scroll_offset==0 is the live bottom. Once the user has
            // scrolled up, preserve the absolute history window while
            // newly appended rows advance the ring head.
            if (cur_scroll == '0)
                hist_scroll_after_append = cur_scroll;
            else if (wanted_scroll > {1'b0, next_scroll_max})
                hist_scroll_after_append = next_scroll_max;
            else
                hist_scroll_after_append = wanted_scroll[SCROLL_W-1:0];
        end
    endfunction

    always_comb begin
        hist_scroll_max = hist_scroll_max_for_used(used_hist_rows_q);

        if (input_n_lines_q > LINE_CNT_W'(N_INPUT_VISIBLE))
            input_scroll_max = INPUT_SCROLL_W'(input_n_lines_q
                                              - LINE_CNT_W'(N_INPUT_VISIBLE));
        else
            input_scroll_max = '0;
    end

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

    localparam int RECALLED_TEXT_LEN = 10;
    function automatic byte_t recalled_text_byte(input int unsigned idx);
        case (idx)
            0:       recalled_text_byte = "[";
            1:       recalled_text_byte = "r";
            2:       recalled_text_byte = "e";
            3:       recalled_text_byte = "c";
            4:       recalled_text_byte = "a";
            5:       recalled_text_byte = "l";
            6:       recalled_text_byte = "l";
            7:       recalled_text_byte = "e";
            8:       recalled_text_byte = "d";
            9:       recalled_text_byte = "]";
            default: recalled_text_byte = " ";
        endcase
    endfunction

    // Compute cell value at the current col_cnt_q for each multi-cycle
    // state. Only one is selected by wr_code below based on state_q.
    // (NAME_IDX_W / LINE_IDX_W localparams are declared near the top.)

    logic [FE_COL_W-1:0] title_name_idx;
    logic [FE_COL_W-1:0] input_idx;

    byte_t titlebar_cell, legend_cell, hist_cell, input_cell;
    logic [1:0] hist_attr;

    // Bubble geometry for history rows
    logic              show_fail;
    logic [FE_COL_W-1:0] bubble_left, bubble_right, payload_start;
    logic [LINE_IDX_W-1:0] payload_idx;
    logic              payload_in_range;
    msg_len_t          cur_sub_len;
    // X-mark column for failed local messages: drawn one column to the
    // left of the bubble's BL, on the first visual row only, so a fail
    // is visible at a glance. bubble_left is always >= 16 (the soft-wrap
    // caps message width at MAX_BUBBLE_INNER_W = 80), so the -1 is safe.
    logic [FE_COL_W-1:0] fail_x_col;
    logic              hist_in_bubble_span;

    assign show_fail = (side_q == 2'(MSG_LOCAL)) && (status_q == 2'(MSG_FAIL));
    assign cur_sub_len = ml_len_q[cur_line_sel];
    assign fail_x_col  = bubble_left - FE_COL_W'(1);
    assign hist_in_bubble_span = (col_cnt_q >= bubble_left)
                               && (col_cnt_q <= bubble_right);

    // Bubble inner width is the message-wide max sub-line length. Every
    // sub-line of the same message uses the same width (shorter lines
    // are padded with spaces inside the bubble), so the left and right
    // borders line up vertically -- visually "one balloon" instead of
    // a stack of independent bubbles per logical line. The width is
    // also already capped at MAX_BUBBLE_INNER_W by the parser's
    // soft-wrap, so the geometry never overflows the screen.
    always_comb begin
        if (side_q == 2'(MSG_REMOTE)) begin
            // Left-aligned: bubble starts at BUBBLE_MARGIN_L
            bubble_left   = FE_COL_W'(BUBBLE_MARGIN_L);
            payload_start = FE_COL_W'(BUBBLE_MARGIN_L + 1);
            bubble_right  = FE_COL_W'(BUBBLE_MARGIN_L + 1)
                            + FE_COL_W'(msg_max_sub_len_q);
        end else begin
            // Right-aligned: bubble ends at BUBBLE_RIGHT_EDGE
            bubble_right  = FE_COL_W'(BUBBLE_RIGHT_EDGE);
            bubble_left   = FE_COL_W'(BUBBLE_RIGHT_EDGE)
                            - FE_COL_W'(msg_max_sub_len_q) - FE_COL_W'(1);
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

        // legend row under the titlebar.
        begin
            automatic int unsigned local_start;
            automatic int unsigned sep_start;
            automatic int unsigned peer_start;
            automatic int unsigned col_u;
            automatic int unsigned idx_u;
            local_start = 4;
            sep_start   = local_start + LOCAL_NAME_LEN;
            peer_start  = sep_start + 9;
            col_u       = int'(col_cnt_q);
            idx_u       = 0;

            legend_cell = " ";
            if (col_u == 0) legend_cell = "M";
            else if (col_u == 1) legend_cell = "e";
            else if (col_u == 2) legend_cell = ":";
            else if (col_u == 3) legend_cell = " ";
            else if ((col_u >= local_start)
                  && (col_u < local_start + LOCAL_NAME_LEN)
                  && (col_u - local_start < MAX_NAME_LEN)) begin
                idx_u = col_u - local_start;
                legend_cell = LOCAL_NAME_PACKED[idx_u*8 +: 8];
            end else if (col_u == sep_start + 0) legend_cell = " ";
            else if (col_u == sep_start + 1) legend_cell = "|";
            else if (col_u == sep_start + 2) legend_cell = " ";
            else if (col_u == sep_start + 3) legend_cell = "P";
            else if (col_u == sep_start + 4) legend_cell = "e";
            else if (col_u == sep_start + 5) legend_cell = "e";
            else if (col_u == sep_start + 6) legend_cell = "r";
            else if (col_u == sep_start + 7) legend_cell = ":";
            else if (col_u == sep_start + 8) legend_cell = " ";
            else if ((col_u >= peer_start)
                  && (LEN_WIDTH'(col_u - peer_start) < peer_name_len_q)
                  && (col_u - peer_start < MAX_NAME_LEN)) begin
                idx_u = col_u - peer_start;
                legend_cell = peer_name_q[idx_u*8 +: 8];
            end
        end

        // history row -- bubble layout (multi-line aware). Failed local
        // messages get an explicit X mark in the first visual row at
        // col bubble_left - 1.
        hist_attr = (!is_big_emoji_q && hist_in_bubble_span)
                    ? bubble_attr_for_side(side_q)
                    : BUBBLE_ATTR_NONE;
        // For single-line bubbles (n_lines_q == 1) use the existing
        // single-cell SPRITE_BL/BR (or FBL/FBR for fail). For multi-
        // line bubbles, swap in the stack-aware TOP/MID/BOT sprite so
        // the cells visually form one tall (...) bracket spanning the
        // whole message. Fail multi-line uses the same TOP/MID/BOT
        // rounded sprites + the X mark to signal failure.
        if (show_fail && (cur_line_q == '0) && (col_cnt_q == fail_x_col))
            hist_cell = SPRITE_FAIL_X;
        else if (col_cnt_q == bubble_left) begin
            if (n_lines_q == LINE_CNT_W'(1))
                hist_cell = show_fail ? SPRITE_FBL : SPRITE_BL;
            else if (cur_line_q == '0)
                hist_cell = SPRITE_BL_TOP;
            else if (cur_line_q == n_lines_q - LINE_CNT_W'(1))
                hist_cell = SPRITE_BL_BOT;
            else
                hist_cell = SPRITE_BL_MID;
        end
        else if (col_cnt_q == bubble_right) begin
            if (n_lines_q == LINE_CNT_W'(1))
                hist_cell = show_fail ? SPRITE_FBR : SPRITE_BR;
            else if (cur_line_q == '0)
                hist_cell = SPRITE_BR_TOP;
            else if (cur_line_q == n_lines_q - LINE_CNT_W'(1))
                hist_cell = SPRITE_BR_BOT;
            else
                hist_cell = SPRITE_BR_MID;
        end
        else if (payload_in_range) begin
            if (is_big_emoji_q) begin
                // Tile code = anchor + cur_line_q * N_COLS + payload_idx.
                // cur_line_q is bounded to BIG_EMOJI_N_ROWS - 1 (=2) and
                // payload_idx to BIG_EMOJI_N_COLS - 1 (=5), so the offset
                // is at most 17 -> always fits the per-emoji 18-tile range.
                automatic byte_t tile_off;
                tile_off = 8'(cur_line_q) * 8'(BIG_EMOJI_N_COLS)
                           + 8'(payload_idx);
                hist_cell = big_emoji_anchor_q + tile_off;
            end else begin
                automatic byte_t payload_byte;
                payload_byte = payload_q[abs_idx[LINE_IDX_W-1:0]*8 +: 8];
                hist_cell = is_big_emoji_tile_code(payload_byte)
                    ? " "
                    : payload_byte;
            end
        end
        else
            hist_cell = " ";

        // input row. col_cnt_q only sweeps 0..FE_N_COLS-1=127. Row 0 of
        // the input area carries the "> " prefix; rows 1..n_lines-1
        // start at col 0. Rows past n_lines are blanked so a buffer
        // that shrunk (e.g. Enter-commit) doesn't leave stale content.
        // Logical newline bytes are layout controls only; they are not
        // painted into the input box.
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
        if ((input_n_lines_q >= LINE_CNT_W'(MAX_INPUT_LINES))
         && (input_row_cnt_q == INPUT_LINE_W'(MAX_INPUT_LINES - 1))
         && (col_cnt_q == FE_COL_W'(INPUT_LIMIT_MARK_COL))) begin
            input_cell = "!";
        end
        if (has_quote
         && (input_row_cnt_q == INPUT_LINE_W'(MAX_INPUT_LINES - 1))
         && (col_cnt_q == FE_COL_W'(QUOTE_MARK_COL))) begin
            input_cell = ">";
        end
    end

    // -----------------------------------------------------------------
    // Payload BRAM signal drivers (single port write / single port read)
    // -----------------------------------------------------------------
    logic [MSG_BYTE_IDX_W-1:0] byte_walk_idx_short;
    assign byte_walk_idx_short = byte_walk_idx_q[MSG_BYTE_IDX_W-1:0];

    always_comb begin
        msg_bram_wr_en   = 1'b0;
        msg_bram_wr_slot = '0;
        msg_bram_wr_byte = '0;
        msg_bram_wr_data = 8'h00;
        msg_bram_rd_slot = msg_target_slot_q;
        msg_bram_rd_byte = byte_walk_idx_short;

        if (state_q == S_HIST_STORE) begin
            msg_bram_wr_en   = 1'b1;
            msg_bram_wr_slot = msg_target_slot_q;
            msg_bram_wr_byte = byte_walk_idx_short;
            msg_bram_wr_data = payload_q[
                {byte_walk_idx_short, 3'b000} +: 8];
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
        wr_attr = BUBBLE_ATTR_NONE;
        unique case (state_q)
            S_HIST_CLEAR: begin
                wr_en   = 1'b1;
                wr_row  = FE_ROW_W'(HIST_ROW_START) + FE_ROW_W'(row_cnt_q);
                wr_code = 8'h20;
            end
            S_TITLEBAR: begin
                wr_en   = 1'b1;
                wr_row  = FE_ROW_W'(TITLE_ROW) + FE_ROW_W'(row_cnt_q);
                wr_code = (row_cnt_q == '0) ? titlebar_cell : legend_cell;
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
                wr_attr = hist_attr;
            end
            S_UPDATE_STATUS: begin
                wr_en   = 1'b1;
                wr_row  = target_row_q;
                wr_code = hist_cell;
                wr_attr = hist_attr;
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
                        RENDER_SCROLL_DOWN,
                        RENDER_INPUT_SCROLL_UP,
                        RENDER_INPUT_SCROLL_DOWN:
                            // single-cycle: just latch, stay idle
                            state_d = S_IDLE;

                        RENDER_CONN_STATE: begin
                            if (be_render_conn_state == 2'(CONN_CONNECTED))
                                state_d = peer_changed ? S_HIST_CLEAR : S_TITLEBAR;
                            else
                                state_d = S_IDLE;
                        end

                        // History APPEND: write the payload to BRAM
                        // (and run newline parse) in S_HIST_STORE, then
                        // render the bubble in S_HIST_WRITE.
                        RENDER_APPEND_LOCAL_PENDING,
                        RENDER_APPEND_REMOTE:
                            state_d = S_HIST_STORE;

                        // UPDATE_STATUS: BRAM-load the stored payload
                        // back into payload_q (also re-parses newlines)
                        // before rewriting the bubble row.
                        RENDER_UPDATE_STATUS:
                            state_d = msg_key_valid_q[
                                          {be_render_side, be_render_msg_id}
                                      ]
                                      ? ((be_render_status == 2'(MSG_RECALLED))
                                         ? S_UPDATE_STATUS : S_HIST_LOAD)
                                      : S_IDLE;

                        // Input edit pipeline. INSERT / DELETE first
                        // walk input_line_q one byte per cycle in
                        // S_INPUT_INSERT / _DELETE; everyone funnels
                        // through S_INPUT_PARSE (also multi-cycle) and
                        // ends in the multi-row S_INPUT_REDRAW.
                        RENDER_INSERT_AT_CURSOR:
                            state_d = S_INPUT_INSERT;
                        RENDER_DELETE_AT_CURSOR:
                            state_d = S_INPUT_DELETE;
                        RENDER_UPDATE_INPUT_LINE:
                            state_d = (be_render_len != '0)
                                      ? S_INPUT_LOAD : S_INPUT_PARSE;
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
                if (at_last_col && (row_cnt_q != '0))
                    state_d = chain_input_q ? S_INPUT_PARSE : S_IDLE;
            end

            // Multi-cycle input shift: stay until shift_idx_q lands at
            // the insert / delete position, then fall through to PARSE.
            // INSERT walks DOWN from input_len_q (pre-insert) to
            // input_shift_cursor_q - 1 (the insert slot).
            // DELETE walks UP from input_shift_cursor_q to input_len_q - 1
            // (the last shifted slot).
            S_INPUT_INSERT: begin
                if (input_shift_idx_q == input_shift_cursor_q
                                         - LEN_WIDTH'(1))
                    state_d = S_INPUT_PARSE;
            end
            S_INPUT_DELETE: begin
                if (input_shift_idx_q >= input_len_q - LEN_WIDTH'(1))
                    state_d = S_INPUT_PARSE;
            end
            S_INPUT_LOAD: begin
                if (input_shift_idx_q >= input_len_q)
                    state_d = S_INPUT_PARSE;
            end

            // S_INPUT_PARSE now walks input_line_q one byte per cycle.
            // Exits when we've scanned past input_len_q or hit the
            // buffer limit. The exit logic is in the sequential block
            // (it has to look at parse_idx_q vs input_len_q anyway).
            S_INPUT_PARSE: begin
                if ((LEN_WIDTH'(parse_idx_q) >= input_len_q)
                 || (parse_idx_q >= LINE_IDX_W'(MAX_LINE_LEN - 1)))
                    state_d = S_INPUT_REDRAW;
            end

            S_INPUT_REDRAW: begin
                if (at_last_col) begin
                    if (LINE_CNT_W'(input_row_cnt_q) + LINE_CNT_W'(1)
                        < LINE_CNT_W'(MAX_INPUT_LINES))
                        state_d = S_INPUT_REDRAW;
                    else
                        state_d = S_IDLE;
                end
            end

            S_HIST_STORE: begin
                // STORE writes one byte per cycle while the parse
                // tracks newlines on the same byte. Exit when we've
                // written byte msg_total_len_q - 1 (last data byte).
                // Use the full MSG_BYTE_IDX_W+1 bits of msg_total_len_q
                // so MAX_MSG_LEN itself (== 1<<MSG_BYTE_IDX_W) doesn't
                // truncate to 0 and exit before any byte is stored.
                if (byte_walk_idx_q + 1 >= msg_total_len_q[MSG_BYTE_IDX_W:0])
                    state_d = S_HIST_WRITE;
            end

            S_HIST_LOAD: begin
                // LOAD walks one extra cycle past msg_total_len_q to
                // absorb the BRAM's 1-cycle read latency. Exit when
                // byte_walk_idx_q == msg_total_len_q (we just captured
                // byte msg_total_len_q - 1). Full width compare so
                // value MAX_MSG_LEN doesn't truncate to 0.
                if (byte_walk_idx_q >= msg_total_len_q[MSG_BYTE_IDX_W:0])
                    state_d = S_UPDATE_STATUS;
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
    // Synchronous reset: registers in this module (target_row_q,
    // row_cnt_q, input_row_cnt_q, state_q, ...) drive fe_text_ram's
    // BRAM address inputs (via wr_row). Xilinx BRAM ADDRARDADDR pins
    // do not tolerate asynchronous resets on the registers that drive
    // them -- when rst_n asserts, the address can briefly glitch and
    // corrupt the BRAM contents. (Vivado DRC REQP-1839.) Same logic
    // and reset values as before, just sampled synchronously.
    logic entering_new_state;
    assign entering_new_state = (state_d != state_q);

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            state_q           <= S_IDLE;
            col_cnt_q         <= '0;
            row_cnt_q         <= '0;
            input_row_cnt_q   <= '0;
            target_row_q      <= '0;
            side_q            <= 2'(MSG_LOCAL);
            status_q          <= 2'(MSG_PENDING);
            store_idx_q       <= '0;
            payload_q         <= '0;
            cur_line_q        <= '0;
            n_lines_q         <= LINE_CNT_W'(1);
            for (int i = 0; i < MAX_LINES; i++) begin
                ml_offset_q[i] <= '0;
                ml_len_q[i]    <= '0;
            end
            is_big_emoji_q     <= 1'b0;
            big_emoji_anchor_q <= '0;

            conn_state_curr_q <= 2'(CONN_BOOT);
            peer_name_q       <= '0;
            peer_name_len_q   <= '0;

            input_len_q       <= '0;
            input_cursor_q    <= '0;
            for (int i = 0; i < MAX_LINE_LEN; i++)
                input_line_q[i] <= 8'h20;
            input_n_lines_q       <= LINE_CNT_W'(1);
            for (int i = 0; i < MAX_INPUT_LINES; i++) begin
                input_ml_offset_q[i]  <= '0;
                input_ml_len_q[i]     <= '0;
            end
            input_cursor_row_q    <= '0;
            input_cursor_col_q    <= '0;
            input_scroll_offset_q <= '0;

            input_shift_idx_q     <= '0;
            input_shift_ascii_q   <= 8'h20;
            input_shift_cursor_q  <= '0;
            parse_idx_q           <= '0;
            parse_n_lines_q       <= LINE_CNT_W'(1);
            parse_line_start_q    <= '0;
            parse_cursor_row_q    <= '0;
            parse_cursor_col_q    <= '0;

            byte_walk_idx_q        <= '0;
            msg_total_len_q        <= '0;
            msg_target_slot_q      <= '0;
            msg_parse_n_lines_q    <= LINE_CNT_W'(1);
            msg_parse_line_start_q <= '0;
            msg_max_sub_len_q      <= '0;

            hist_wr_row_q     <= '0;
            scroll_offset_q   <= '0;
            used_hist_rows_q  <= '0;
            for (int i = 0; i < MSG_LOOKUP_N; i++) begin
                msg_key_row_q[i]   <= '0;
                msg_key_valid_q[i] <= 1'b0;
            end
            for (int i = 0; i < N_HIST_STORED; i++) begin
                slot_side_q[i]        <= 2'(MSG_LOCAL);
                slot_msg_id_q[i]      <= '0;
                slot_msg_valid_q[i]   <= 1'b0;
                slot_len_q[i]         <= '0;
                slot_n_lines_q[i]     <= LINE_CNT_W'(1);
                slot_avatar_attr_q[i] <= BUBBLE_ATTR_NONE;
                slot_owner_valid_q[i] <= 1'b0;
                slot_owner_store_idx_q[i] <= '0;
                slot_owner_side_q[i]  <= 2'(MSG_LOCAL);
                slot_owner_width_q[i] <= '0;
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
                if (state_d == S_TITLEBAR)      row_cnt_q       <= '0;
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
                        if (col_cnt_q == FE_COL_W'(FE_N_COLS-1)) begin
                            if (row_cnt_q == '0) begin
                                col_cnt_q <= '0;
                                row_cnt_q <= row_cnt_q + 1'b1;
                            end
                        end else begin
                            col_cnt_q <= col_cnt_q + 1'b1;
                        end
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
                                hist_wr_row_q    <= '0;
                                scroll_offset_q  <= '0;
                                used_hist_rows_q <= '0;
                                for (int i = 0; i < MSG_LOOKUP_N; i++)
                                    msg_key_valid_q[i] <= 1'b0;
                                for (int i = 0; i < N_HIST_STORED; i++) begin
                                    slot_side_q[i]        <= 2'(MSG_LOCAL);
                                    slot_msg_id_q[i]      <= '0;
                                    slot_msg_valid_q[i]   <= 1'b0;
                                    slot_len_q[i]         <= '0;
                                    slot_n_lines_q[i]     <= LINE_CNT_W'(1);
                                    slot_avatar_attr_q[i] <= BUBBLE_ATTR_NONE;
                                    slot_owner_valid_q[i] <= 1'b0;
                                    slot_owner_store_idx_q[i] <= '0;
                                    slot_owner_side_q[i]  <= 2'(MSG_LOCAL);
                                    slot_owner_width_q[i] <= '0;
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
                        // Latch metadata + working payload register.
                        // The actual byte-by-byte BRAM store + newline
                        // parse runs in S_HIST_STORE. hist_wr_row_q
                        // advance happens at the END of S_HIST_STORE
                        // once we know n_lines from the parse.
                        side_q        <= be_render_side;
                        status_q      <= be_render_status;
                        store_idx_q   <= be_render_store_idx;
                        payload_q     <= be_render_payload;
                        target_row_q  <= FE_ROW_W'(HIST_ROW_START)
                                         + FE_ROW_W'(hist_wr_row_q);
                        if (slot_msg_valid_q[hist_wr_row_q]) begin
                            msg_key_valid_q[
                                {slot_side_q[hist_wr_row_q],
                                 slot_msg_id_q[hist_wr_row_q]}
                            ] <= 1'b0;
                        end
                        msg_key_row_q[{be_render_side, be_render_msg_id}]
                            <= hist_wr_row_q;
                        msg_key_valid_q[{be_render_side, be_render_msg_id}]
                            <= 1'b1;
                        slot_side_q[hist_wr_row_q]       <= be_render_side;
                        slot_msg_id_q[hist_wr_row_q]     <= be_render_msg_id;
                        slot_msg_valid_q[hist_wr_row_q]  <= 1'b1;
                        slot_len_q[hist_wr_row_q]        <= be_render_len;
                        msg_total_len_q                  <= be_render_len;
                        msg_target_slot_q                <= hist_wr_row_q;
                    end

                    RENDER_UPDATE_STATUS: begin
                        if (msg_key_valid_q[
                            {be_render_side, be_render_msg_id}
                        ]) begin
                            // Snapshot the ring slot owning this msg_id
                            // and latch its meta; payload load happens
                            // in S_HIST_LOAD (BRAM walk + parse).
                            automatic logic [HIST_W-1:0] slot;
                            slot = msg_key_row_q[
                                {be_render_side, be_render_msg_id}
                            ];

                            status_q          <= be_render_status;
                            target_row_q      <= FE_ROW_W'(HIST_ROW_START)
                                                 + FE_ROW_W'(slot);
                            side_q            <= slot_side_q[slot];
                            msg_target_slot_q <= slot;
                            if (be_render_status == 2'(MSG_RECALLED)) begin
                                payload_q       <= '0;
                                for (int i = 0; i < RECALLED_TEXT_LEN; i++)
                                    payload_q[i*8 +: 8] <= recalled_text_byte(i);
                                msg_total_len_q  <= msg_len_t'(RECALLED_TEXT_LEN);
                                msg_max_sub_len_q <= msg_len_t'(RECALLED_TEXT_LEN);
                                n_lines_q        <= slot_n_lines_q[slot];
                                cur_line_q       <= '0;
                                is_big_emoji_q   <= 1'b0;
                                for (int i = 0; i < MAX_LINES; i++) begin
                                    ml_offset_q[i] <= '0;
                                    ml_len_q[i]    <= (i == 0)
                                                      ? msg_len_t'(RECALLED_TEXT_LEN)
                                                      : '0;
                                end
                            end else begin
                                msg_total_len_q <= slot_len_q[slot];
                            end
                        end
                    end

                    RENDER_UPDATE_INPUT_LINE: begin
                        input_len_q    <= be_render_len;
                        input_cursor_q <= be_render_cursor_pos;
                        payload_q      <= be_render_payload;
                    end

                    RENDER_INSERT_AT_CURSOR: begin
                        // Latch the ASCII + post-edit cursor; the actual
                        // line_buf shift runs in S_INPUT_INSERT one byte
                        // per cycle. cursor_q advances now so PARSE sees
                        // the new cursor address. input_len_q is updated
                        // at the END of S_INPUT_INSERT (mirrors be_top's
                        // KEY_CHAR pattern).
                        input_shift_ascii_q  <= be_render_ascii;
                        input_shift_cursor_q <= be_render_cursor_pos;
                        input_cursor_q       <= be_render_cursor_pos;
                    end

                    RENDER_DELETE_AT_CURSOR: begin
                        // Same idea, S_INPUT_DELETE does the shift +
                        // input_len_q decrement.
                        input_shift_cursor_q <= be_render_cursor_pos;
                        input_cursor_q       <= be_render_cursor_pos;
                    end

                    RENDER_MOVE_CURSOR: begin
                        input_cursor_q <= be_render_cursor_pos;
                    end

                    RENDER_SCROLL_UP: begin
                        // Dynamic cap: can't scroll past the oldest
                        // stored row. (Pre-fill ring: cap is 0 so
                        // scroll up is a no-op.)
                        if (scroll_offset_q < hist_scroll_max)
                            scroll_offset_q <= scroll_offset_q + 1'b1;
                    end

                    RENDER_INPUT_SCROLL_UP: begin
                        // Input rows render with text_ram row =
                        // INPUT_ROW_START + input_scroll_offset + r
                        // (see fe_scan), so a smaller offset shows the
                        // EARLIER lines of the input buffer. "Up" =
                        // see earlier content => decrement.
                        if (input_scroll_offset_q != '0)
                            input_scroll_offset_q <= input_scroll_offset_q - 1'b1;
                    end

                    RENDER_INPUT_SCROLL_DOWN: begin
                        // "Down" = see later content => increment.
                        // Dynamic cap: can't scroll past the last typed
                        // input line.
                        if (input_scroll_offset_q < input_scroll_max)
                            input_scroll_offset_q <= input_scroll_offset_q + 1'b1;
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
            // S_INPUT_INSERT: walk input_line_q one byte per cycle.
            // shift_idx_q starts at input_len_q (the old, pre-insert
            // length, == post-insert top index) and counts DOWN to
            // (input_shift_cursor_q - 1), the insert position. On the
            // exit cycle we drop input_shift_ascii_q and bump
            // input_len_q. (Mirrors be_top S_LINE_INSERT.)
            // -----------------------------------------------------------
            if (state_q == S_IDLE && state_d == S_INPUT_INSERT)
                input_shift_idx_q <= input_len_q;
            if (state_q == S_INPUT_INSERT) begin
                if (input_shift_idx_q == input_shift_cursor_q
                                         - LEN_WIDTH'(1)) begin
                    input_line_q[input_shift_idx_q[LINE_IDX_W-1:0]]
                        <= input_shift_ascii_q;
                    input_len_q <= input_len_q + LEN_WIDTH'(1);
                end else begin
                    input_line_q[input_shift_idx_q[LINE_IDX_W-1:0]]
                        <= input_line_q[LINE_IDX_W'(
                            input_shift_idx_q - LEN_WIDTH'(1))];
                    input_shift_idx_q <= input_shift_idx_q - LEN_WIDTH'(1);
                end
            end

            // -----------------------------------------------------------
            // S_INPUT_DELETE: walk input_line_q[cursor..len-1] left by
            // one and clear the now-invalid tail cell. shift_idx_q
            // starts at input_shift_cursor_q (the post-edit cursor ==
            // insert position) and counts UP. On the exit cycle (when
            // shift_idx_q == old input_len_q - 1, the topmost cell that
            // needed shifting) we decrement input_len_q and blank the
            // now-invalid tail.
            // -----------------------------------------------------------
            if (state_q == S_IDLE && state_d == S_INPUT_DELETE)
                input_shift_idx_q <= be_render_cursor_pos;
            if (state_q == S_INPUT_DELETE) begin
                if (input_shift_idx_q >= input_len_q - LEN_WIDTH'(1)) begin
                    // No more shifts left -- finish up.
                    input_len_q <= input_len_q - LEN_WIDTH'(1);
                    if (input_len_q != '0)
                        input_line_q[LINE_IDX_W'(input_len_q - LEN_WIDTH'(1))]
                            <= 8'h20;
                end else begin
                    input_line_q[input_shift_idx_q[LINE_IDX_W-1:0]]
                        <= input_line_q[LINE_IDX_W'(
                            input_shift_idx_q + LEN_WIDTH'(1))];
                    input_shift_idx_q <= input_shift_idx_q + LEN_WIDTH'(1);
                end
            end

            if (state_q == S_IDLE && state_d == S_INPUT_LOAD)
                input_shift_idx_q <= '0;
            if (state_q == S_INPUT_LOAD) begin
                if (input_shift_idx_q < input_len_q) begin
                    input_line_q[input_shift_idx_q[LINE_IDX_W-1:0]]
                        <= payload_q[
                            input_shift_idx_q[LINE_IDX_W-1:0]*8 +: 8
                        ];
                    input_shift_idx_q <= input_shift_idx_q + LEN_WIDTH'(1);
                end
            end

            // -----------------------------------------------------------
            // S_INPUT_PARSE (multi-cycle): walk input_line_q one byte
            // per cycle looking for 0x0A. Accumulates into
            // input_ml_offset_q[] / input_ml_len_q[] / input_n_lines_q
            // and resolves input_cursor_q into the 2-D (row, col).
            // -----------------------------------------------------------
            // Entry to S_INPUT_PARSE from S_IDLE (MOVE_CURSOR /
            // UPDATE_INPUT_LINE accept). input_cursor_q is being
            // non-blocking-updated to be_render_cursor_pos on this same
            // cycle, so we have to use be_render_cursor_pos directly
            // (not input_cursor_q which still reads old value).
            if (state_q == S_IDLE && state_d == S_INPUT_PARSE) begin
                parse_idx_q          <= '0;
                parse_n_lines_q      <= LINE_CNT_W'(1);
                parse_line_start_q   <= '0;
                input_ml_offset_q[0] <= '0;
                parse_cursor_row_q   <= '0;
                parse_cursor_col_q   <= be_render_cursor_pos;
            end
            // Entry from S_INPUT_INSERT / _DELETE: input_cursor_q has
            // already settled to the post-edit cursor, so it's safe to
            // sample here.
            if ((state_q == S_INPUT_INSERT || state_q == S_INPUT_DELETE)
                 && state_d == S_INPUT_PARSE) begin
                parse_idx_q          <= '0;
                parse_n_lines_q      <= LINE_CNT_W'(1);
                parse_line_start_q   <= '0;
                input_ml_offset_q[0] <= '0;
                parse_cursor_row_q   <= '0;
                parse_cursor_col_q   <= input_cursor_q;
            end
            if (state_q == S_INPUT_LOAD && state_d == S_INPUT_PARSE) begin
                parse_idx_q          <= '0;
                parse_n_lines_q      <= LINE_CNT_W'(1);
                parse_line_start_q   <= '0;
                input_ml_offset_q[0] <= '0;
                parse_cursor_row_q   <= '0;
                parse_cursor_col_q   <= input_cursor_q;
            end
            if (state_q == S_INPUT_PARSE) begin
                automatic byte_t cur_byte;
                automatic logic  cur_byte_valid;
                automatic logic  have_room;
                automatic logic [LINE_IDX_W-1:0] cur_line_pos;
                automatic logic  is_nl;
                automatic logic  is_wrap;
                automatic logic  is_break;
                automatic msg_len_t new_line_len;
                cur_byte       = input_line_q[parse_idx_q];
                cur_byte_valid = (LEN_WIDTH'(parse_idx_q) < input_len_q);
                have_room      = (parse_n_lines_q
                                  < LINE_CNT_W'(MAX_INPUT_LINES));
                cur_line_pos   = parse_idx_q - parse_line_start_q;
                is_nl  = cur_byte_valid
                         && (cur_byte == 8'h0A)
                         && have_room;
                // Soft-wrap: the wrap byte itself stays on the current
                // visual line (it's the last content char); a newline
                // takes precedence and consumes the byte. We wrap even
                // when this is the last byte typed so the cursor lands
                // on a new empty row instead of off-screen at col 128.
                is_wrap = cur_byte_valid
                          && !is_nl
                          && have_room
                          && (cur_line_pos
                              == LINE_IDX_W'(INPUT_SOFT_WRAP_W - 1));
                is_break = is_nl || is_wrap;
                new_line_len = is_nl
                    ? msg_len_t'(cur_line_pos)
                    : msg_len_t'(INPUT_SOFT_WRAP_W);

                if (is_break) begin
                    input_ml_len_q[parse_last_sel] <= new_line_len;
                    input_ml_offset_q[parse_line_sel]
                        <= parse_idx_q + LINE_IDX_W'(1);
                    if (input_cursor_q > msg_len_t'(parse_idx_q)) begin
                        parse_cursor_row_q <= parse_line_sel;
                        parse_cursor_col_q <= input_cursor_q
                            - (msg_len_t'(parse_idx_q) + msg_len_t'(1));
                    end
                    parse_n_lines_q    <= parse_n_lines_q + LINE_CNT_W'(1);
                    parse_line_start_q <= parse_idx_q + LINE_IDX_W'(1);
                end

                // Finalise when we've scanned through input_len_q (or
                // hit the MAX_LINE_LEN cap). State transition already
                // happens in the next-state logic; here we just commit
                // the final line length, n_lines, cursor and run
                // auto-follow.
                if ((LEN_WIDTH'(parse_idx_q) >= input_len_q)
                 || (parse_idx_q >= LINE_IDX_W'(MAX_LINE_LEN - 1))) begin
                    automatic logic [INPUT_SCROLL_W-1:0] new_scroll;
                    automatic logic [INPUT_SCROLL_W-1:0] new_scroll_max;

                    input_ml_len_q[parse_last_sel]
                        <= input_len_q - msg_len_t'(parse_line_start_q);
                    input_n_lines_q    <= parse_n_lines_q;
                    input_cursor_row_q <= parse_cursor_row_q;
                    input_cursor_col_q <= parse_cursor_col_q;

                    // Single computed write of input_scroll_offset_q so
                    // auto-follow and the post-edit clamp don't fight.
                    // Auto-follow keeps the cursor visible; the clamp
                    // pins the scroll to "actually-typed rows" so a
                    // delete that drops input_n_lines doesn't leave a
                    // window scrolled past the last typed row.
                    if (LINE_CNT_W'(parse_cursor_row_q)
                        < LINE_CNT_W'(input_scroll_offset_q)) begin
                        new_scroll = INPUT_SCROLL_W'(parse_cursor_row_q);
                    end else if (LINE_CNT_W'(parse_cursor_row_q)
                                 >= LINE_CNT_W'(input_scroll_offset_q)
                                  + LINE_CNT_W'(N_INPUT_VISIBLE)) begin
                        new_scroll = INPUT_SCROLL_W'(
                            LINE_CNT_W'(parse_cursor_row_q)
                            - LINE_CNT_W'(N_INPUT_VISIBLE - 1));
                    end else begin
                        new_scroll = input_scroll_offset_q;
                    end

                    if (parse_n_lines_q > LINE_CNT_W'(N_INPUT_VISIBLE))
                        new_scroll_max = INPUT_SCROLL_W'(
                            parse_n_lines_q
                            - LINE_CNT_W'(N_INPUT_VISIBLE));
                    else
                        new_scroll_max = '0;

                    if (new_scroll > new_scroll_max)
                        input_scroll_offset_q <= new_scroll_max;
                    else
                        input_scroll_offset_q <= new_scroll;
                end else begin
                    parse_idx_q <= parse_idx_q + LINE_IDX_W'(1);
                end
            end

            // -----------------------------------------------------------
            // S_HIST_STORE: BRAM byte walk + concurrent newline parse.
            // On the cycle we enter from S_IDLE, init the walk counter
            // and parse accumulators. Each cycle in S_HIST_STORE writes
            // payload_q[i*8 +: 8] into the BRAM (combinationally via
            // msg_bram_*) AND tests that byte for 0x0A. The exit cycle
            // (byte_walk_idx_q + 1 == msg_total_len_q) commits the
            // final line length, ml_*_q, and the hist_wr_row_q advance.
            // -----------------------------------------------------------
            if (state_q == S_IDLE
                && (state_d == S_HIST_STORE)) begin
                byte_walk_idx_q        <= '0;
                msg_parse_n_lines_q    <= LINE_CNT_W'(1);
                msg_parse_line_start_q <= '0;
                msg_max_sub_len_q      <= '0;
                ml_offset_q[0]         <= '0;
            end
            if (state_q == S_HIST_STORE) begin
                automatic byte_t                  cur_byte;
                automatic logic                   is_nl;
                automatic logic                   is_last_byte;
                automatic logic                   is_wrap;
                automatic logic                   is_break;
                automatic logic                   have_room;
                automatic logic [LINE_IDX_W-1:0]  cur_line_pos;
                automatic msg_len_t               new_line_len;

                cur_byte = payload_q[{byte_walk_idx_short, 3'b000} +: 8];
                cur_line_pos = LINE_IDX_W'(byte_walk_idx_short)
                                - msg_parse_line_start_q;
                have_room = (msg_parse_n_lines_q
                             < LINE_CNT_W'(MAX_LINES));
                is_nl = ({1'b0, byte_walk_idx_short}
                            < msg_total_len_q[MSG_BYTE_IDX_W:0])
                        && (cur_byte == 8'h0A)
                        && have_room;
                is_last_byte = (byte_walk_idx_q + 1
                    >= msg_total_len_q[MSG_BYTE_IDX_W:0]);
                // Soft-wrap: close current visual line and open the
                // next when we've filled MAX_BUBBLE_INNER_W content
                // bytes of this line, unless the current byte is also
                // a newline (the newline takes precedence and is not
                // counted into the line content) or there's nothing
                // after this byte to put on the new line.
                is_wrap = (cur_line_pos
                           == LINE_IDX_W'(MAX_BUBBLE_INNER_W - 1))
                          && !is_nl
                          && !is_last_byte
                          && have_room;
                is_break = is_nl || is_wrap;
                new_line_len = is_nl
                    ? msg_len_t'(cur_line_pos)
                    : msg_len_t'(MAX_BUBBLE_INNER_W);

                if (is_break) begin
                    ml_len_q[msg_parse_last_sel] <= new_line_len;
                    ml_offset_q[msg_parse_line_sel]
                        <= LINE_IDX_W'(byte_walk_idx_short)
                           + LINE_IDX_W'(1);
                    msg_parse_n_lines_q
                        <= msg_parse_n_lines_q + LINE_CNT_W'(1);
                    msg_parse_line_start_q
                        <= LINE_IDX_W'(byte_walk_idx_short)
                           + LINE_IDX_W'(1);
                    if (new_line_len > msg_max_sub_len_q)
                        msg_max_sub_len_q <= new_line_len;
                end

                if (is_last_byte) begin
                    automatic byte_t                 first_byte;
                    automatic logic                  is_big;
                    first_byte = payload_q[7:0];
                    // Single-byte payload whose byte falls in the big-emoji
                    // anchor range: lay the bubble out as a fixed N_ROWS x
                    // N_COLS tile grid and skip the text-bubble metadata.
                    is_big = (msg_total_len_q == msg_len_t'(1))
                          && (first_byte >= byte_t'(BIG_EMOJI_BASE))
                          && (first_byte <  byte_t'(BIG_EMOJI_END_EXCL));

                    if (is_big) begin
                        automatic logic [HIST_W:0] next_used_rows;
                        next_used_rows = hist_used_after_append(
                            used_hist_rows_q,
                            LINE_CNT_W'(BIG_EMOJI_N_ROWS));

                        is_big_emoji_q     <= 1'b1;
                        big_emoji_anchor_q <= first_byte;
                        n_lines_q          <= LINE_CNT_W'(BIG_EMOJI_N_ROWS);
                        cur_line_q         <= '0;
                        msg_max_sub_len_q  <= msg_len_t'(BIG_EMOJI_N_COLS);
                        for (int i = 0; i < BIG_EMOJI_N_ROWS; i++) begin
                            ml_offset_q[i] <= '0;
                            ml_len_q[i]    <= msg_len_t'(BIG_EMOJI_N_COLS);
                        end
                        slot_n_lines_q[msg_target_slot_q] <=
                            LINE_CNT_W'(BIG_EMOJI_N_ROWS);
                        for (int i = 0; i < MAX_LINES; i++) begin
                            if (i < BIG_EMOJI_N_ROWS) begin
                                slot_avatar_attr_q[
                                    (msg_target_slot_q + HIST_W'(i))
                                    & HIST_W'(N_HIST_STORED - 1)
                                ] <= (i == 0) ? bubble_attr_for_side(side_q)
                                              : BUBBLE_ATTR_NONE;
                                slot_owner_valid_q[
                                    (msg_target_slot_q + HIST_W'(i))
                                    & HIST_W'(N_HIST_STORED - 1)
                                ] <= 1'b1;
                                slot_owner_store_idx_q[
                                    (msg_target_slot_q + HIST_W'(i))
                                    & HIST_W'(N_HIST_STORED - 1)
                                ] <= store_idx_q;
                                slot_owner_side_q[
                                    (msg_target_slot_q + HIST_W'(i))
                                    & HIST_W'(N_HIST_STORED - 1)
                                ] <= side_q;
                                slot_owner_width_q[
                                    (msg_target_slot_q + HIST_W'(i))
                                    & HIST_W'(N_HIST_STORED - 1)
                                ] <= FE_COL_W'(BIG_EMOJI_N_COLS);
                            end
                        end
                        // Advance hist pointer by N_ROWS (bubble is that
                        // many text_ram rows tall).
                        hist_wr_row_q <= (hist_wr_row_q
                            + HIST_W'(BIG_EMOJI_N_ROWS))
                            & HIST_W'(N_HIST_STORED - 1);
                        used_hist_rows_q <= next_used_rows;
                        scroll_offset_q  <= hist_scroll_after_append(
                            scroll_offset_q,
                            next_used_rows,
                            LINE_CNT_W'(BIG_EMOJI_N_ROWS));
                    end else begin
                        automatic logic [LINE_CNT_W-1:0] final_n_lines;
                        automatic msg_len_t             final_line_len;
                        automatic logic [FE_COL_W-1:0]  final_width;
                        automatic logic [LINE_SEL_W-1:0] final_last_sel;
                        automatic logic [HIST_W:0]       next_used_rows;
                        is_big_emoji_q <= 1'b0;
                        final_n_lines = msg_parse_n_lines_q
                                        + (is_break ? LINE_CNT_W'(1)
                                                    : LINE_CNT_W'(0));
                        // If we broke this cycle the new (trailing) line
                        // starts at byte_walk_idx_q + 1 == msg_total_len,
                        // i.e. it's empty. Otherwise the still-open line's
                        // content length is cur_line_pos + 1.
                        final_line_len = is_break
                            ? msg_len_t'(0)
                            : msg_len_t'(cur_line_pos) + msg_len_t'(1);
                        final_last_sel = is_break
                            ? msg_parse_line_sel
                            : msg_parse_last_sel;
                        final_width = FE_COL_W'(
                            (!is_break && final_line_len > msg_max_sub_len_q)
                            ? final_line_len : msg_max_sub_len_q);

                        ml_len_q[final_last_sel] <= final_line_len;
                        n_lines_q  <= final_n_lines;
                        cur_line_q <= '0;
                        if (!is_break && final_line_len > msg_max_sub_len_q)
                            msg_max_sub_len_q <= final_line_len;
                        slot_n_lines_q[msg_target_slot_q] <= final_n_lines;
                        for (int i = 0; i < MAX_LINES; i++) begin
                            if (LINE_CNT_W'(i) < final_n_lines) begin
                                slot_avatar_attr_q[
                                    (msg_target_slot_q + HIST_W'(i))
                                    & HIST_W'(N_HIST_STORED - 1)
                                ] <= (i == 0) ? bubble_attr_for_side(side_q)
                                              : BUBBLE_ATTR_NONE;
                                slot_owner_valid_q[
                                    (msg_target_slot_q + HIST_W'(i))
                                    & HIST_W'(N_HIST_STORED - 1)
                                ] <= 1'b1;
                                slot_owner_store_idx_q[
                                    (msg_target_slot_q + HIST_W'(i))
                                    & HIST_W'(N_HIST_STORED - 1)
                                ] <= store_idx_q;
                                slot_owner_side_q[
                                    (msg_target_slot_q + HIST_W'(i))
                                    & HIST_W'(N_HIST_STORED - 1)
                                ] <= side_q;
                                slot_owner_width_q[
                                    (msg_target_slot_q + HIST_W'(i))
                                    & HIST_W'(N_HIST_STORED - 1)
                                ] <= final_width;
                            end
                        end
                        next_used_rows = hist_used_after_append(
                            used_hist_rows_q, final_n_lines);
                        // Advance hist write pointer by the (final) line
                        // count. & N_HIST_STORED-1 for ring wrap.
                        hist_wr_row_q <= (hist_wr_row_q
                            + HIST_W'(final_n_lines))
                            & HIST_W'(N_HIST_STORED - 1);
                        // Track total rows ever written for the current
                        // peer, capped at N_HIST_STORED. Drives the
                        // dynamic hist_scroll_max.
                        used_hist_rows_q <= next_used_rows;
                        scroll_offset_q  <= hist_scroll_after_append(
                            scroll_offset_q,
                            next_used_rows,
                            final_n_lines);
                    end
                end else begin
                    byte_walk_idx_q <= byte_walk_idx_q + 1'b1;
                end
            end

            // -----------------------------------------------------------
            // S_HIST_LOAD: walk BRAM addresses for the slot and capture
            // bytes into payload_q. The BRAM has a 1-cycle read pipe,
            // so byte_walk_idx_q drives the next address and we capture
            // byte (byte_walk_idx_q - 1) here.
            // -----------------------------------------------------------
            if ((state_q == S_IDLE) && (state_d == S_HIST_LOAD)) begin
                byte_walk_idx_q        <= '0;
                msg_parse_n_lines_q    <= LINE_CNT_W'(1);
                msg_parse_line_start_q <= '0;
                msg_max_sub_len_q      <= '0;
                ml_offset_q[0]         <= '0;
            end
            if (state_q == S_HIST_LOAD) begin
                automatic logic [MSG_BYTE_IDX_W-1:0] cap_idx;
                automatic byte_t                    cap_byte;
                automatic logic                     have_cap;
                automatic logic                     is_nl;
                automatic logic                     is_last_cap;
                automatic logic                     is_wrap;
                automatic logic                     is_break;
                automatic logic                     have_room;
                automatic logic [LINE_IDX_W-1:0]    cap_line_pos;
                automatic msg_len_t                 new_line_len;

                have_cap = (byte_walk_idx_q != '0);
                cap_idx  = byte_walk_idx_short - 1'b1;
                cap_byte = msg_bram_rd_data;
                cap_line_pos = LINE_IDX_W'(cap_idx)
                                - msg_parse_line_start_q;
                have_room = (msg_parse_n_lines_q
                             < LINE_CNT_W'(MAX_LINES));
                is_nl = have_cap
                        && ({1'b0, cap_idx} < msg_total_len_q[MSG_BYTE_IDX_W:0])
                        && (cap_byte == 8'h0A)
                        && have_room;
                is_last_cap = have_cap
                              && (byte_walk_idx_q
                                  >= msg_total_len_q[MSG_BYTE_IDX_W:0]);
                is_wrap = have_cap
                          && (cap_line_pos
                              == LINE_IDX_W'(MAX_BUBBLE_INNER_W - 1))
                          && !is_nl
                          && !is_last_cap
                          && have_room;
                is_break = is_nl || is_wrap;
                new_line_len = is_nl
                    ? msg_len_t'(cap_line_pos)
                    : msg_len_t'(MAX_BUBBLE_INNER_W);

                if (have_cap) begin
                    payload_q[{cap_idx, 3'b000} +: 8] <= cap_byte;
                end

                if (is_break) begin
                    ml_len_q[msg_parse_last_sel] <= new_line_len;
                    ml_offset_q[msg_parse_line_sel]
                        <= LINE_IDX_W'(cap_idx) + LINE_IDX_W'(1);
                    msg_parse_n_lines_q
                        <= msg_parse_n_lines_q + LINE_CNT_W'(1);
                    msg_parse_line_start_q
                        <= LINE_IDX_W'(cap_idx) + LINE_IDX_W'(1);
                    if (new_line_len > msg_max_sub_len_q)
                        msg_max_sub_len_q <= new_line_len;
                end

                if (byte_walk_idx_q
                    >= msg_total_len_q[MSG_BYTE_IDX_W:0]) begin
                    // All bytes captured. Commit last line. For a single
                    // captured byte in the big-emoji range, override to
                    // the fixed N_ROWS x N_COLS bubble layout. (Use
                    // cap_byte rather than payload_q[7:0]: the latter is
                    // being assigned this same cycle and isn't readable
                    // yet.) hist_wr_row_q / used_hist_rows_q are NOT
                    // re-advanced here -- they were locked in by the
                    // original S_HIST_STORE.
                    automatic byte_t                 first_byte;
                    automatic logic                  is_big;
                    first_byte = cap_byte;
                    is_big = (msg_total_len_q == msg_len_t'(1))
                          && (first_byte >= byte_t'(BIG_EMOJI_BASE))
                          && (first_byte <  byte_t'(BIG_EMOJI_END_EXCL));

                    if (is_big) begin
                        is_big_emoji_q     <= 1'b1;
                        big_emoji_anchor_q <= first_byte;
                        n_lines_q          <= LINE_CNT_W'(BIG_EMOJI_N_ROWS);
                        cur_line_q         <= '0;
                        msg_max_sub_len_q  <= msg_len_t'(BIG_EMOJI_N_COLS);
                        for (int i = 0; i < BIG_EMOJI_N_ROWS; i++) begin
                            ml_offset_q[i] <= '0;
                            ml_len_q[i]    <= msg_len_t'(BIG_EMOJI_N_COLS);
                        end
                    end else begin
                        automatic logic [LINE_CNT_W-1:0] final_n_lines;
                        automatic msg_len_t             final_line_len;
                        automatic logic [LINE_SEL_W-1:0] final_last_sel;
                        is_big_emoji_q <= 1'b0;
                        final_n_lines = msg_parse_n_lines_q
                                        + (is_break ? LINE_CNT_W'(1)
                                                    : LINE_CNT_W'(0));
                        final_line_len = is_break
                            ? msg_len_t'(0)
                            : (msg_total_len_q
                               - msg_len_t'(msg_parse_line_start_q));
                        final_last_sel = is_break
                            ? msg_parse_line_sel
                            : msg_parse_last_sel;

                        ml_len_q[final_last_sel] <= final_line_len;
                        n_lines_q  <= final_n_lines;
                        cur_line_q <= '0;
                        if (!is_break && final_line_len > msg_max_sub_len_q)
                            msg_max_sub_len_q <= final_line_len;
                    end
                end else begin
                    byte_walk_idx_q <= byte_walk_idx_q + 1'b1;
                end
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
    assign input_n_lines_obs        = input_n_lines_q;
    assign input_scroll_offset_obs  = input_scroll_offset_q;

endmodule

`endif  // FE_RENDER_DECODER_SV
