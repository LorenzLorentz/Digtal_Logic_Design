// =====================================================================
// io_be_integration.sv  --  Test-only wrapper: io_top + be_top
// ---------------------------------------------------------------------
// Glues io_top.io_key_* directly to be_top.io_key_* and exposes
// everything else (PS/2 pins, backend's downstream interfaces, all
// be_top observability ports) on the module boundary so the C++ TB
// can drive / inspect both sides without poking module internals.
//
// This module exists only under sim/ -- it is not part of the
// synthesisable RTL tree. The eventual chat_top.sv will do the same
// wiring plus the comm and frontend instantiations and board-level
// pin-out.
// =====================================================================

`ifndef IO_BE_INTEGRATION_SV
`define IO_BE_INTEGRATION_SV

module io_be_integration
    import chat_pkg::*;
#(
    parameter int LINE_IDX_W  = $clog2(MAX_LINE_LEN),
    parameter int STORE_IDX_W = $clog2(MAX_MSG_NUM),
    parameter int MY_NAME_LEN = 4,
    parameter logic [MAX_NAME_LEN*8-1:0] MY_NAME_PACKED =
        128'h00000000_00000000_00000000_63696c41   // "Alic"
) (
    input  logic                       clk,
    input  logic                       rst_n,

    // ---- PS/2 raw pins ----
    input  logic                       ps2_clk,
    input  logic                       ps2_data,

    // ---- backend -> comm: tx ----
    output logic                       be_tx_valid,
    input  logic                       be_tx_ready,
    output logic [2:0]                 be_tx_frame_type,
    output msg_id_t                    be_tx_msg_id,
    output msg_len_t                   be_tx_len,
    output logic [MAX_MSG_LEN*8-1:0]   be_tx_payload,

    // ---- comm -> backend: rx ----
    input  logic                       cm_rx_valid,
    output logic                       cm_rx_ready,
    input  logic [2:0]                 cm_rx_frame_type,
    input  seq_t                       cm_rx_seq,
    input  msg_len_t                   cm_rx_len,
    input  logic [MAX_MSG_LEN*8-1:0]   cm_rx_payload,

    // ---- comm -> backend: status ----
    input  logic                       cm_status_valid,
    output logic                       cm_status_ready,
    input  msg_id_t                    cm_status_msg_id,
    input  logic [1:0]                 cm_status_code,

    // ---- backend -> frontend: render ----
    output logic                       be_render_valid,
    input  logic                       be_render_ready,
    output logic [3:0]                 be_render_cmd,
    output msg_id_t                    be_render_msg_id,
    output logic [1:0]                 be_render_side,
    output logic [1:0]                 be_render_status,
    output msg_len_t                   be_render_len,
    output logic [MAX_MSG_LEN*8-1:0]   be_render_payload,
    output msg_len_t                   be_render_cursor_pos,
    output byte_t                      be_render_ascii,
    output logic [1:0]                 be_render_conn_state,
    output msg_len_t                   be_render_peer_name_len,
    output logic [MAX_NAME_LEN*8-1:0]  be_render_peer_name,

    // ---- backend observability ----
    input  logic [LINE_IDX_W-1:0]      line_rd_idx,
    output byte_t                      line_rd_data,
    output logic [LEN_WIDTH-1:0]       line_len,
    output logic [LEN_WIDTH-1:0]       cursor_pos,
    output logic                       enter_committed,

    input  logic [STORE_IDX_W-1:0]     store_rd_idx,
    output logic                       store_rd_valid,
    output msg_id_t                    store_rd_msg_id,
    output logic [1:0]                 store_rd_side,
    output logic [1:0]                 store_rd_status,
    output msg_len_t                   store_rd_len,
    output logic [MAX_MSG_LEN*8-1:0]   store_rd_payload,

    output logic [1:0]                 conn_state_obs
);

    // ---- The io <-> backend handshake bus, hidden from outside. ----
    logic        io_key_valid;
    logic        io_key_ready;
    logic [2:0]  io_key_type;
    byte_t       io_key_ascii;
    /* verilator lint_off UNUSEDSIGNAL */
    logic        io_mouse_click_ready_unused;
    logic        ui_popup_active_unused;
    logic [1:0]  ui_popup_type_unused;
    logic [9:0]  ui_popup_x_unused;
    logic [9:0]  ui_popup_y_unused;
    logic        emoji_suggest_active_unused;
    logic [EMOJI_SUGGEST_COUNT_W-1:0] emoji_suggest_count_unused;
    logic [EMOJI_SUGGEST_MAX*EMOJI_TOKEN_ID_W-1:0] emoji_suggest_ids_unused;
    msg_len_t    emoji_suggest_anchor_unused;
    /* verilator lint_on UNUSEDSIGNAL */

    io_top u_io (
        .clk                  (clk),
        .rst_n                (rst_n),
        .ps2_clk              (ps2_clk),
        .ps2_data             (ps2_data),
        .mouse_scroll_up      (1'b0),
        .mouse_scroll_down    (1'b0),
        .mouse_scroll_in_input(1'b0),
        .io_key_valid         (io_key_valid),
        .io_key_ready         (io_key_ready),
        .io_key_type          (io_key_type),
        .io_key_ascii         (io_key_ascii)
    );

    be_top #(
        .MY_NAME_LEN    (MY_NAME_LEN),
        .MY_NAME_PACKED (MY_NAME_PACKED)
    ) u_be (
        .clk                     (clk),
        .rst_n                   (rst_n),

        .io_key_valid            (io_key_valid),
        .io_key_ready            (io_key_ready),
        .io_key_type             (io_key_type),
        .io_key_ascii            (io_key_ascii),
        .io_mouse_click_valid    (1'b0),
        .io_mouse_click_ready    (io_mouse_click_ready_unused),
        .io_mouse_click_x        (10'd0),
        .io_mouse_click_y        (10'd0),
        .fe_input_scroll_offset  ('0),
        .fe_input_at_limit       (1'b0),
        .ui_popup_active         (ui_popup_active_unused),
        .ui_popup_type           (ui_popup_type_unused),
        .ui_popup_x              (ui_popup_x_unused),
        .ui_popup_y              (ui_popup_y_unused),
        .emoji_suggest_active    (emoji_suggest_active_unused),
        .emoji_suggest_count     (emoji_suggest_count_unused),
        .emoji_suggest_ids       (emoji_suggest_ids_unused),
        .emoji_suggest_anchor_pos(emoji_suggest_anchor_unused),

        .cm_rx_valid             (cm_rx_valid),
        .cm_rx_ready             (cm_rx_ready),
        .cm_rx_frame_type        (cm_rx_frame_type),
        .cm_rx_seq               (cm_rx_seq),
        .cm_rx_len               (cm_rx_len),
        .cm_rx_payload           (cm_rx_payload),

        .cm_status_valid         (cm_status_valid),
        .cm_status_ready         (cm_status_ready),
        .cm_status_msg_id        (cm_status_msg_id),
        .cm_status_code          (cm_status_code),

        .be_tx_valid             (be_tx_valid),
        .be_tx_ready             (be_tx_ready),
        .be_tx_frame_type        (be_tx_frame_type),
        .be_tx_msg_id            (be_tx_msg_id),
        .be_tx_len               (be_tx_len),
        .be_tx_payload           (be_tx_payload),

        .be_render_valid         (be_render_valid),
        .be_render_ready         (be_render_ready),
        .be_render_cmd           (be_render_cmd),
        .be_render_msg_id        (be_render_msg_id),
        .be_render_side          (be_render_side),
        .be_render_status        (be_render_status),
        .be_render_len           (be_render_len),
        .be_render_payload       (be_render_payload),
        .be_render_cursor_pos    (be_render_cursor_pos),
        .be_render_ascii         (be_render_ascii),
        .be_render_conn_state    (be_render_conn_state),
        .be_render_peer_name_len (be_render_peer_name_len),
        .be_render_peer_name     (be_render_peer_name),

        .line_rd_idx             (line_rd_idx),
        .line_rd_data            (line_rd_data),
        .line_len                (line_len),
        .cursor_pos              (cursor_pos),
        .enter_committed         (enter_committed),

        .store_rd_idx            (store_rd_idx),
        .store_rd_valid          (store_rd_valid),
        .store_rd_msg_id         (store_rd_msg_id),
        .store_rd_side           (store_rd_side),
        .store_rd_status         (store_rd_status),
        .store_rd_len            (store_rd_len),
        .store_rd_payload        (store_rd_payload),

        .conn_state_obs          (conn_state_obs)
    );

endmodule

`endif  // IO_BE_INTEGRATION_SV
