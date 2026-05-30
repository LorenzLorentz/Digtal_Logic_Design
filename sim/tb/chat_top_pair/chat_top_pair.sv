// =====================================================================
// chat_top_pair.sv  --  Two backends + comms cross-wired through UART
// ---------------------------------------------------------------------
// Test-only wrapper. Instantiates two be_top instances (Alice on the
// "A" side, Bob on the "B" side) and two comm_top instances; the
// UART pins are crossed (A.tx -> B.rx, B.tx -> A.rx).
//
// Frontend uses the existing fe_top stub (drains render commands) so
// backends can advance.
//
// io_key inputs are exposed per-side so the C++ TB can synthesise key
// events directly without going through PS/2.
//
// Observability: conn_state, peer_name, store readout per side.
// =====================================================================

`ifndef CHAT_TOP_PAIR_SV
`define CHAT_TOP_PAIR_SV

module chat_top_pair
    import chat_pkg::*;
    import fe_pkg::*;
#(
    parameter int CLK_FREQ_HZ    = 160,
    parameter int BAUD           = 10,
    parameter int TIMEOUT_CYCLES = 8000,

    parameter int A_NAME_LEN = 5,
    parameter logic [MAX_NAME_LEN*8-1:0] A_NAME_PACKED =
        128'h00000000_00000000_00000065_63696c41,    // "Alice"

    parameter int B_NAME_LEN = 3,
    parameter logic [MAX_NAME_LEN*8-1:0] B_NAME_PACKED =
        128'h00000000_00000000_00000000_00626f42     // "Bob"
) (
    input  logic                       clk,
    input  logic                       rst_n,

    // ---- A-side io key events ----
    input  logic                       a_io_key_valid,
    output logic                       a_io_key_ready,
    input  logic [2:0]                 a_io_key_type,
    input  byte_t                      a_io_key_ascii,

    // ---- B-side io key events ----
    input  logic                       b_io_key_valid,
    output logic                       b_io_key_ready,
    input  logic [2:0]                 b_io_key_type,
    input  byte_t                      b_io_key_ascii,

    // ---- Observability ----
    output logic [1:0]                 a_conn_state,
    output logic [1:0]                 b_conn_state,
    output msg_len_t                   a_peer_name_len,
    output logic [MAX_NAME_LEN*8-1:0]  a_peer_name,
    output msg_len_t                   b_peer_name_len,
    output logic [MAX_NAME_LEN*8-1:0]  b_peer_name,

    // store readout per side (caller picks idx to inspect a slot)
    input  logic [$clog2(MAX_MSG_NUM)-1:0] a_store_rd_idx,
    output logic                       a_store_rd_valid,
    output msg_id_t                    a_store_rd_msg_id,
    output logic [1:0]                 a_store_rd_side,
    output logic [1:0]                 a_store_rd_status,
    output msg_len_t                   a_store_rd_len,
    output logic [MAX_MSG_LEN*8-1:0]   a_store_rd_payload,

    input  logic [$clog2(MAX_MSG_NUM)-1:0] b_store_rd_idx,
    output logic                       b_store_rd_valid,
    output msg_id_t                    b_store_rd_msg_id,
    output logic [1:0]                 b_store_rd_side,
    output logic [1:0]                 b_store_rd_status,
    output msg_len_t                   b_store_rd_len,
    output logic [MAX_MSG_LEN*8-1:0]   b_store_rd_payload
);

    // ---- Cross-wired UART ----
    logic line_a_to_b;
    logic line_b_to_a;

    // -----------------------------------------------------------------
    // A-side wires
    // -----------------------------------------------------------------
    logic                          a_be_tx_valid, a_be_tx_ready;
    logic [2:0]                    a_be_tx_frame_type;
    msg_id_t                       a_be_tx_msg_id;
    msg_len_t                      a_be_tx_len;
    logic [MAX_MSG_LEN*8-1:0]      a_be_tx_payload;

    logic                          a_cm_rx_valid, a_cm_rx_ready;
    logic [2:0]                    a_cm_rx_frame_type;
    seq_t                          a_cm_rx_seq;
    msg_len_t                      a_cm_rx_len;
    logic [MAX_MSG_LEN*8-1:0]      a_cm_rx_payload;

    logic                          a_cm_status_valid, a_cm_status_ready;
    msg_id_t                       a_cm_status_msg_id;
    logic [1:0]                    a_cm_status_code;

    logic                          a_be_render_valid, a_be_render_ready;
    logic [3:0]                    a_be_render_cmd;
    msg_id_t                       a_be_render_msg_id;
    logic [$clog2(MAX_MSG_NUM)-1:0] a_be_render_store_idx;
    logic [1:0]                    a_be_render_side, a_be_render_status;
    msg_len_t                      a_be_render_len;
    logic [MAX_MSG_LEN*8-1:0]      a_be_render_payload;
    msg_len_t                      a_be_render_cursor_pos;
    byte_t                         a_be_render_ascii;
    logic [1:0]                    a_be_render_conn_state;
    msg_len_t                      a_be_render_peer_name_len;
    logic [MAX_NAME_LEN*8-1:0]     a_be_render_peer_name;
    logic                          a_be_has_quote;

    /* verilator lint_off UNUSEDSIGNAL */
    byte_t                         a_line_rd_data;
    logic [LEN_WIDTH-1:0]          a_line_len, a_cursor_pos;
    logic                          a_enter_committed;
    logic                          a_mouse_click_ready_unused;
    logic                          a_ui_popup_active;
    logic [1:0]                    a_ui_popup_type;
    logic [9:0]                    a_ui_popup_x, a_ui_popup_y;
    logic                          a_emoji_suggest_active;
    logic [EMOJI_SUGGEST_COUNT_W-1:0] a_emoji_suggest_count;
    logic [EMOJI_SUGGEST_MAX*EMOJI_TOKEN_ID_W-1:0] a_emoji_suggest_ids;
    msg_len_t                      a_emoji_suggest_anchor_pos;
    logic [N_HIST_STORED-1:0]      a_fe_hist_owner_valid;
    logic [N_HIST_STORED*$clog2(MAX_MSG_NUM)-1:0] a_fe_hist_owner_store_idx;
    logic [N_HIST_STORED*2-1:0]    a_fe_hist_owner_side;
    logic [N_HIST_STORED*FE_COL_W-1:0] a_fe_hist_owner_width;
    /* verilator lint_on UNUSEDSIGNAL */

    be_top #(
        .MY_NAME_LEN    (A_NAME_LEN),
        .MY_NAME_PACKED (A_NAME_PACKED)
    ) u_a_be (
        .clk                    (clk),
        .rst_n                  (rst_n),
        .io_key_valid           (a_io_key_valid),
        .io_key_ready           (a_io_key_ready),
        .io_key_type            (a_io_key_type),
        .io_key_ascii           (a_io_key_ascii),
        .io_mouse_click_valid   (1'b0),
        .io_mouse_right_click_valid(1'b0),
        .io_mouse_click_ready   (a_mouse_click_ready_unused),
        .io_mouse_click_x       (10'd0),
        .io_mouse_click_y       (10'd0),
        .fe_input_scroll_offset ('0),
        .fe_input_at_limit      (a_fe_input_at_limit),
        .fe_hist_wr_row         (a_fe_hist_wr_row),
        .fe_hist_scroll_offset  (a_fe_scroll_offset),
        .fe_hist_owner_valid    (a_fe_hist_owner_valid),
        .fe_hist_owner_store_idx(a_fe_hist_owner_store_idx),
        .fe_hist_owner_side     (a_fe_hist_owner_side),
        .fe_hist_owner_width    (a_fe_hist_owner_width),
        .ui_popup_active        (a_ui_popup_active),
        .ui_popup_type          (a_ui_popup_type),
        .ui_popup_x             (a_ui_popup_x),
        .ui_popup_y             (a_ui_popup_y),
        .emoji_suggest_active   (a_emoji_suggest_active),
        .emoji_suggest_count    (a_emoji_suggest_count),
        .emoji_suggest_ids      (a_emoji_suggest_ids),
        .emoji_suggest_anchor_pos(a_emoji_suggest_anchor_pos),
        .cm_rx_valid            (a_cm_rx_valid),
        .cm_rx_ready            (a_cm_rx_ready),
        .cm_rx_frame_type       (a_cm_rx_frame_type),
        .cm_rx_seq              (a_cm_rx_seq),
        .cm_rx_len              (a_cm_rx_len),
        .cm_rx_payload          (a_cm_rx_payload),
        .cm_status_valid        (a_cm_status_valid),
        .cm_status_ready        (a_cm_status_ready),
        .cm_status_msg_id       (a_cm_status_msg_id),
        .cm_status_code         (a_cm_status_code),
        .be_tx_valid            (a_be_tx_valid),
        .be_tx_ready            (a_be_tx_ready),
        .be_tx_frame_type       (a_be_tx_frame_type),
        .be_tx_msg_id           (a_be_tx_msg_id),
        .be_tx_len              (a_be_tx_len),
        .be_tx_payload          (a_be_tx_payload),
        .be_render_valid        (a_be_render_valid),
        .be_render_ready        (a_be_render_ready),
        .be_render_cmd          (a_be_render_cmd),
        .be_render_msg_id       (a_be_render_msg_id),
        .be_render_store_idx    (a_be_render_store_idx),
        .be_render_side         (a_be_render_side),
        .be_render_status       (a_be_render_status),
        .be_render_len          (a_be_render_len),
        .be_render_payload      (a_be_render_payload),
        .be_render_cursor_pos   (a_be_render_cursor_pos),
        .be_render_ascii        (a_be_render_ascii),
        .be_render_conn_state   (a_be_render_conn_state),
        .be_render_peer_name_len(a_be_render_peer_name_len),
        .be_render_peer_name    (a_be_render_peer_name),
        .be_has_quote           (a_be_has_quote),
        .line_rd_idx            ({$clog2(MAX_LINE_LEN){1'b0}}),
        .line_rd_data           (a_line_rd_data),
        .line_len               (a_line_len),
        .cursor_pos             (a_cursor_pos),
        .enter_committed        (a_enter_committed),
        .store_rd_idx           (a_store_rd_idx),
        .store_rd_valid         (a_store_rd_valid),
        .store_rd_msg_id        (a_store_rd_msg_id),
        .store_rd_side          (a_store_rd_side),
        .store_rd_status        (a_store_rd_status),
        .store_rd_len           (a_store_rd_len),
        .store_rd_payload       (a_store_rd_payload),
        .conn_state_obs         (a_conn_state)
    );

    // A-side comm: tx -> line_a_to_b, rx <- line_b_to_a
    comm_top #(
        .CLK_FREQ_HZ    (CLK_FREQ_HZ),
        .BAUD           (BAUD),
        .TIMEOUT_CYCLES (TIMEOUT_CYCLES)
    ) u_a_comm (
        .clk              (clk),
        .rst_n            (rst_n),
        .uart_rxd         (line_b_to_a),
        .uart_txd         (line_a_to_b),
        .be_tx_valid      (a_be_tx_valid),
        .be_tx_ready      (a_be_tx_ready),
        .be_tx_frame_type (a_be_tx_frame_type),
        .be_tx_msg_id     (a_be_tx_msg_id),
        .be_tx_len        (a_be_tx_len),
        .be_tx_payload    (a_be_tx_payload),
        .cm_rx_valid      (a_cm_rx_valid),
        .cm_rx_ready      (a_cm_rx_ready),
        .cm_rx_frame_type (a_cm_rx_frame_type),
        .cm_rx_seq        (a_cm_rx_seq),
        .cm_rx_len        (a_cm_rx_len),
        .cm_rx_payload    (a_cm_rx_payload),
        .cm_status_valid  (a_cm_status_valid),
        .cm_status_ready  (a_cm_status_ready),
        .cm_status_msg_id (a_cm_status_msg_id),
        .cm_status_code   (a_cm_status_code)
    );

    // A-side frontend (drains renders + writes its own text_ram).
    /* verilator lint_off UNUSEDSIGNAL */
    byte_t                                       a_fe_rd_code;
    logic [1:0]                                  a_fe_conn_state;
    msg_len_t                                    a_fe_input_len, a_fe_input_cursor;
    logic [MAX_NAME_LEN*8-1:0]                   a_fe_peer_name;
    msg_len_t                                    a_fe_peer_name_len;
    logic [7:0]                                  a_video_red, a_video_green, a_video_blue;
    logic                                        a_video_hsync, a_video_vsync, a_video_de;
    logic [HIST_W-1:0]                           a_fe_hist_wr_row;
    logic [SCROLL_W-1:0]                         a_fe_scroll_offset;
    logic [INPUT_LINE_W-1:0]                     a_fe_input_cursor_row;
    msg_len_t                                    a_fe_input_cursor_col;
    logic [INPUT_N_LINES_W-1:0]                  a_fe_input_n_lines;
    logic [INPUT_SCROLL_W-1:0]                   a_fe_input_scroll_offset;
    logic                                        a_fe_input_at_limit;
    logic [19:0]                                 a_asset_sram_addr;
    /* verilator lint_on UNUSEDSIGNAL */
    assign a_fe_input_at_limit =
        (a_fe_input_n_lines >= INPUT_N_LINES_W'(MAX_INPUT_LINES));

    fe_top u_a_fe (
        .clk                     (clk),
        .rst_n                   (rst_n),
        .clk_pix                 (clk),
        .be_render_valid         (a_be_render_valid),
        .be_render_ready         (a_be_render_ready),
        .be_render_cmd           (a_be_render_cmd),
        .be_render_msg_id        (a_be_render_msg_id),
        .be_render_store_idx     (a_be_render_store_idx),
        .be_render_side          (a_be_render_side),
        .be_render_status        (a_be_render_status),
        .be_render_len           (a_be_render_len),
        .be_render_payload       (a_be_render_payload),
        .be_render_cursor_pos    (a_be_render_cursor_pos),
        .be_render_ascii         (a_be_render_ascii),
        .be_render_conn_state    (a_be_render_conn_state),
        .be_render_peer_name_len (a_be_render_peer_name_len),
        .be_render_peer_name     (a_be_render_peer_name),
        .be_has_quote            (a_be_has_quote),
        .video_red               (a_video_red),
        .video_green             (a_video_green),
        .video_blue              (a_video_blue),
        .video_hsync             (a_video_hsync),
        .video_vsync             (a_video_vsync),
        .video_de                (a_video_de),
        .asset_sram_addr         (a_asset_sram_addr),
        .asset_sram_data         (32'h0000_0000),
        .mouse_x                 (10'd0),
        .mouse_y                 (10'd0),
        .ui_popup_active         (a_ui_popup_active),
        .ui_popup_type           (a_ui_popup_type),
        .ui_popup_x              (a_ui_popup_x),
        .ui_popup_y              (a_ui_popup_y),
        .emoji_suggest_active    (a_emoji_suggest_active),
        .emoji_suggest_count     (a_emoji_suggest_count),
        .emoji_suggest_ids       (a_emoji_suggest_ids),
        .rd_row                  ('0),
        .rd_col                  ('0),
        .rd_code                 (a_fe_rd_code),
        .conn_state_obs          (a_fe_conn_state),
        .input_len_obs           (a_fe_input_len),
        .input_cursor_obs        (a_fe_input_cursor),
        .peer_name_obs           (a_fe_peer_name),
        .peer_name_len_obs       (a_fe_peer_name_len),
        .hist_wr_row_obs         (a_fe_hist_wr_row),
        .scroll_offset_obs       (a_fe_scroll_offset),
        .hist_owner_valid_obs    (a_fe_hist_owner_valid),
        .hist_owner_store_idx_obs(a_fe_hist_owner_store_idx),
        .hist_owner_side_obs     (a_fe_hist_owner_side),
        .hist_owner_width_obs    (a_fe_hist_owner_width),
        .input_cursor_row_obs    (a_fe_input_cursor_row),
        .input_cursor_col_obs    (a_fe_input_cursor_col),
        .input_n_lines_obs       (a_fe_input_n_lines),
        .input_scroll_offset_obs (a_fe_input_scroll_offset)
    );

    assign a_peer_name     = a_be_render_peer_name;
    assign a_peer_name_len = a_be_render_peer_name_len;

    // -----------------------------------------------------------------
    // B-side wires (mirror of A)
    // -----------------------------------------------------------------
    logic                          b_be_tx_valid, b_be_tx_ready;
    logic [2:0]                    b_be_tx_frame_type;
    msg_id_t                       b_be_tx_msg_id;
    msg_len_t                      b_be_tx_len;
    logic [MAX_MSG_LEN*8-1:0]      b_be_tx_payload;

    logic                          b_cm_rx_valid, b_cm_rx_ready;
    logic [2:0]                    b_cm_rx_frame_type;
    seq_t                          b_cm_rx_seq;
    msg_len_t                      b_cm_rx_len;
    logic [MAX_MSG_LEN*8-1:0]      b_cm_rx_payload;

    logic                          b_cm_status_valid, b_cm_status_ready;
    msg_id_t                       b_cm_status_msg_id;
    logic [1:0]                    b_cm_status_code;

    logic                          b_be_render_valid, b_be_render_ready;
    logic [3:0]                    b_be_render_cmd;
    msg_id_t                       b_be_render_msg_id;
    logic [$clog2(MAX_MSG_NUM)-1:0] b_be_render_store_idx;
    logic [1:0]                    b_be_render_side, b_be_render_status;
    msg_len_t                      b_be_render_len;
    logic [MAX_MSG_LEN*8-1:0]      b_be_render_payload;
    msg_len_t                      b_be_render_cursor_pos;
    byte_t                         b_be_render_ascii;
    logic [1:0]                    b_be_render_conn_state;
    msg_len_t                      b_be_render_peer_name_len;
    logic [MAX_NAME_LEN*8-1:0]     b_be_render_peer_name;
    logic                          b_be_has_quote;

    /* verilator lint_off UNUSEDSIGNAL */
    byte_t                         b_line_rd_data;
    logic [LEN_WIDTH-1:0]          b_line_len, b_cursor_pos;
    logic                          b_enter_committed;
    logic                          b_mouse_click_ready_unused;
    logic                          b_ui_popup_active;
    logic [1:0]                    b_ui_popup_type;
    logic [9:0]                    b_ui_popup_x, b_ui_popup_y;
    logic                          b_emoji_suggest_active;
    logic [EMOJI_SUGGEST_COUNT_W-1:0] b_emoji_suggest_count;
    logic [EMOJI_SUGGEST_MAX*EMOJI_TOKEN_ID_W-1:0] b_emoji_suggest_ids;
    msg_len_t                      b_emoji_suggest_anchor_pos;
    logic [N_HIST_STORED-1:0]      b_fe_hist_owner_valid;
    logic [N_HIST_STORED*$clog2(MAX_MSG_NUM)-1:0] b_fe_hist_owner_store_idx;
    logic [N_HIST_STORED*2-1:0]    b_fe_hist_owner_side;
    logic [N_HIST_STORED*FE_COL_W-1:0] b_fe_hist_owner_width;
    /* verilator lint_on UNUSEDSIGNAL */

    be_top #(
        .MY_NAME_LEN    (B_NAME_LEN),
        .MY_NAME_PACKED (B_NAME_PACKED)
    ) u_b_be (
        .clk                    (clk),
        .rst_n                  (rst_n),
        .io_key_valid           (b_io_key_valid),
        .io_key_ready           (b_io_key_ready),
        .io_key_type            (b_io_key_type),
        .io_key_ascii           (b_io_key_ascii),
        .io_mouse_click_valid   (1'b0),
        .io_mouse_right_click_valid(1'b0),
        .io_mouse_click_ready   (b_mouse_click_ready_unused),
        .io_mouse_click_x       (10'd0),
        .io_mouse_click_y       (10'd0),
        .fe_input_scroll_offset ('0),
        .fe_input_at_limit      (b_fe_input_at_limit),
        .fe_hist_wr_row         (b_fe_hist_wr_row),
        .fe_hist_scroll_offset  (b_fe_scroll_offset),
        .fe_hist_owner_valid    (b_fe_hist_owner_valid),
        .fe_hist_owner_store_idx(b_fe_hist_owner_store_idx),
        .fe_hist_owner_side     (b_fe_hist_owner_side),
        .fe_hist_owner_width    (b_fe_hist_owner_width),
        .ui_popup_active        (b_ui_popup_active),
        .ui_popup_type          (b_ui_popup_type),
        .ui_popup_x             (b_ui_popup_x),
        .ui_popup_y             (b_ui_popup_y),
        .emoji_suggest_active   (b_emoji_suggest_active),
        .emoji_suggest_count    (b_emoji_suggest_count),
        .emoji_suggest_ids      (b_emoji_suggest_ids),
        .emoji_suggest_anchor_pos(b_emoji_suggest_anchor_pos),
        .cm_rx_valid            (b_cm_rx_valid),
        .cm_rx_ready            (b_cm_rx_ready),
        .cm_rx_frame_type       (b_cm_rx_frame_type),
        .cm_rx_seq              (b_cm_rx_seq),
        .cm_rx_len              (b_cm_rx_len),
        .cm_rx_payload          (b_cm_rx_payload),
        .cm_status_valid        (b_cm_status_valid),
        .cm_status_ready        (b_cm_status_ready),
        .cm_status_msg_id       (b_cm_status_msg_id),
        .cm_status_code         (b_cm_status_code),
        .be_tx_valid            (b_be_tx_valid),
        .be_tx_ready            (b_be_tx_ready),
        .be_tx_frame_type       (b_be_tx_frame_type),
        .be_tx_msg_id           (b_be_tx_msg_id),
        .be_tx_len              (b_be_tx_len),
        .be_tx_payload          (b_be_tx_payload),
        .be_render_valid        (b_be_render_valid),
        .be_render_ready        (b_be_render_ready),
        .be_render_cmd          (b_be_render_cmd),
        .be_render_msg_id       (b_be_render_msg_id),
        .be_render_store_idx    (b_be_render_store_idx),
        .be_render_side         (b_be_render_side),
        .be_render_status       (b_be_render_status),
        .be_render_len          (b_be_render_len),
        .be_render_payload      (b_be_render_payload),
        .be_render_cursor_pos   (b_be_render_cursor_pos),
        .be_render_ascii        (b_be_render_ascii),
        .be_render_conn_state   (b_be_render_conn_state),
        .be_render_peer_name_len(b_be_render_peer_name_len),
        .be_render_peer_name    (b_be_render_peer_name),
        .be_has_quote           (b_be_has_quote),
        .line_rd_idx            ({$clog2(MAX_LINE_LEN){1'b0}}),
        .line_rd_data           (b_line_rd_data),
        .line_len               (b_line_len),
        .cursor_pos             (b_cursor_pos),
        .enter_committed        (b_enter_committed),
        .store_rd_idx           (b_store_rd_idx),
        .store_rd_valid         (b_store_rd_valid),
        .store_rd_msg_id        (b_store_rd_msg_id),
        .store_rd_side          (b_store_rd_side),
        .store_rd_status        (b_store_rd_status),
        .store_rd_len           (b_store_rd_len),
        .store_rd_payload       (b_store_rd_payload),
        .conn_state_obs         (b_conn_state)
    );

    // B-side comm: tx -> line_b_to_a, rx <- line_a_to_b
    comm_top #(
        .CLK_FREQ_HZ    (CLK_FREQ_HZ),
        .BAUD           (BAUD),
        .TIMEOUT_CYCLES (TIMEOUT_CYCLES)
    ) u_b_comm (
        .clk              (clk),
        .rst_n            (rst_n),
        .uart_rxd         (line_a_to_b),
        .uart_txd         (line_b_to_a),
        .be_tx_valid      (b_be_tx_valid),
        .be_tx_ready      (b_be_tx_ready),
        .be_tx_frame_type (b_be_tx_frame_type),
        .be_tx_msg_id     (b_be_tx_msg_id),
        .be_tx_len        (b_be_tx_len),
        .be_tx_payload    (b_be_tx_payload),
        .cm_rx_valid      (b_cm_rx_valid),
        .cm_rx_ready      (b_cm_rx_ready),
        .cm_rx_frame_type (b_cm_rx_frame_type),
        .cm_rx_seq        (b_cm_rx_seq),
        .cm_rx_len        (b_cm_rx_len),
        .cm_rx_payload    (b_cm_rx_payload),
        .cm_status_valid  (b_cm_status_valid),
        .cm_status_ready  (b_cm_status_ready),
        .cm_status_msg_id (b_cm_status_msg_id),
        .cm_status_code   (b_cm_status_code)
    );

    /* verilator lint_off UNUSEDSIGNAL */
    byte_t                                       b_fe_rd_code;
    logic [1:0]                                  b_fe_conn_state;
    msg_len_t                                    b_fe_input_len, b_fe_input_cursor;
    logic [MAX_NAME_LEN*8-1:0]                   b_fe_peer_name;
    msg_len_t                                    b_fe_peer_name_len;
    logic [7:0]                                  b_video_red, b_video_green, b_video_blue;
    logic                                        b_video_hsync, b_video_vsync, b_video_de;
    logic [HIST_W-1:0]                           b_fe_hist_wr_row;
    logic [SCROLL_W-1:0]                         b_fe_scroll_offset;
    logic [INPUT_LINE_W-1:0]                     b_fe_input_cursor_row;
    msg_len_t                                    b_fe_input_cursor_col;
    logic [INPUT_N_LINES_W-1:0]                  b_fe_input_n_lines;
    logic [INPUT_SCROLL_W-1:0]                   b_fe_input_scroll_offset;
    logic                                        b_fe_input_at_limit;
    logic [19:0]                                 b_asset_sram_addr;
    /* verilator lint_on UNUSEDSIGNAL */
    assign b_fe_input_at_limit =
        (b_fe_input_n_lines >= INPUT_N_LINES_W'(MAX_INPUT_LINES));

    fe_top u_b_fe (
        .clk                     (clk),
        .rst_n                   (rst_n),
        .clk_pix                 (clk),
        .be_render_valid         (b_be_render_valid),
        .be_render_ready         (b_be_render_ready),
        .be_render_cmd           (b_be_render_cmd),
        .be_render_msg_id        (b_be_render_msg_id),
        .be_render_store_idx     (b_be_render_store_idx),
        .be_render_side          (b_be_render_side),
        .be_render_status        (b_be_render_status),
        .be_render_len           (b_be_render_len),
        .be_render_payload       (b_be_render_payload),
        .be_render_cursor_pos    (b_be_render_cursor_pos),
        .be_render_ascii         (b_be_render_ascii),
        .be_render_conn_state    (b_be_render_conn_state),
        .be_render_peer_name_len (b_be_render_peer_name_len),
        .be_render_peer_name     (b_be_render_peer_name),
        .be_has_quote            (b_be_has_quote),
        .video_red               (b_video_red),
        .video_green             (b_video_green),
        .video_blue              (b_video_blue),
        .video_hsync             (b_video_hsync),
        .video_vsync             (b_video_vsync),
        .video_de                (b_video_de),
        .asset_sram_addr         (b_asset_sram_addr),
        .asset_sram_data         (32'h0000_0000),
        .mouse_x                 (10'd0),
        .mouse_y                 (10'd0),
        .ui_popup_active         (b_ui_popup_active),
        .ui_popup_type           (b_ui_popup_type),
        .ui_popup_x              (b_ui_popup_x),
        .ui_popup_y              (b_ui_popup_y),
        .emoji_suggest_active    (b_emoji_suggest_active),
        .emoji_suggest_count     (b_emoji_suggest_count),
        .emoji_suggest_ids       (b_emoji_suggest_ids),
        .rd_row                  ('0),
        .rd_col                  ('0),
        .rd_code                 (b_fe_rd_code),
        .conn_state_obs          (b_fe_conn_state),
        .input_len_obs           (b_fe_input_len),
        .input_cursor_obs        (b_fe_input_cursor),
        .peer_name_obs           (b_fe_peer_name),
        .peer_name_len_obs       (b_fe_peer_name_len),
        .hist_wr_row_obs         (b_fe_hist_wr_row),
        .scroll_offset_obs       (b_fe_scroll_offset),
        .hist_owner_valid_obs    (b_fe_hist_owner_valid),
        .hist_owner_store_idx_obs(b_fe_hist_owner_store_idx),
        .hist_owner_side_obs     (b_fe_hist_owner_side),
        .hist_owner_width_obs    (b_fe_hist_owner_width),
        .input_cursor_row_obs    (b_fe_input_cursor_row),
        .input_cursor_col_obs    (b_fe_input_cursor_col),
        .input_n_lines_obs       (b_fe_input_n_lines),
        .input_scroll_offset_obs (b_fe_input_scroll_offset)
    );

    assign b_peer_name     = b_be_render_peer_name;
    assign b_peer_name_len = b_be_render_peer_name_len;

endmodule

`endif  // CHAT_TOP_PAIR_SV
