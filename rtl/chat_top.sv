// =====================================================================
// chat_top.sv  --  Board-level top: io + backend + comm + fe stub
// ---------------------------------------------------------------------
// Synthesis target. Pins are board-friendly: a single reset push-button
// (active-high), the PS/2 keyboard pair, and a TTL UART pair (PMOD).
// HDMI pins are deliberately omitted -- the frontend is still a stub
// that drains render commands but does not produce video. They will
// be added when fe_top grows a real implementation.
//
// Per-board identity:
//   MY_NAME_LEN, MY_NAME_PACKED are parameters with "Alice" defaults.
//   For board B, override the parameter at the synthesis tool (e.g.
//   `set_property generic { MY_NAME_LEN=3 MY_NAME_PACKED=...626f42 } ...`)
//   or keep two separate top-level wrappers per the README.
//
// Reset bridge:
//   btn_rst is the dev-board push-button (active-high, momentary). The
//   sync_2ff serves as a reset synchroniser: while btn_rst is held,
//   the chain is held at 0 (rst_n=0); after the button is released,
//   1's shift in over two clocks giving a clean synchronous release.
// =====================================================================

`ifndef CHAT_TOP_SV
`define CHAT_TOP_SV

module chat_top
    import chat_pkg::*;
    import fe_pkg::*;
#(
    // ---- Identity (override per board) ----
    parameter int MY_NAME_LEN = 5,
    // Packed little-endian: byte 0 at [7:0]. Default: "Alice".
    parameter logic [MAX_NAME_LEN*8-1:0] MY_NAME_PACKED =
        128'h00000000_00000000_00000065_63696c41,

    // ---- Link parameters ----
    parameter int CLK_FREQ_HZ    = CLK_FREQ_HZ_DEFAULT,    // 100 MHz
    parameter int BAUD           = UART_BAUD_DEFAULT,      // 115200 8N1
    parameter int TIMEOUT_CYCLES = 2_000_000,              // 20 ms ARQ timeout
    parameter bit ENABLE_SRAM_ASSETS = 1'b0
) (
    input  logic clk,           // 100 MHz from board oscillator
    input  logic btn_rst,       // active-high momentary push-button
    input  logic clk_pix,       // pixel clock (e.g. 50 MHz from PLL)

    // ---- PS/2 keyboard ----
    input  logic ps2_clk,
    input  logic ps2_data,

    // ---- PS/2 mouse (bidirectional for host-to-device init) ----
    inout  logic ps2_mouse_clk,
    inout  logic ps2_mouse_data,

    // ---- UART (PMOD, TTL) ----
    input  logic uart_rxd,
    output logic uart_txd,

    // ---- Video out (synchronous to clk_pix; feed ip_rgb2dvi at the
    //       board wrapper).
    output logic [7:0] video_red,
    output logic [7:0] video_green,
    output logic [7:0] video_blue,
    output logic       video_hsync,
    output logic       video_vsync,
    output logic       video_de,

    // Read-only SRAM asset bus used by the frontend for uploaded
    // background / avatar images.
    output logic [19:0] asset_sram_addr,
    input  logic [31:0] asset_sram_data
);

    // -----------------------------------------------------------------
    // Reset synchroniser:  btn_rst (async, active-high)  ->  rst_n
    // -----------------------------------------------------------------
    logic rst_n;
    sync_2ff #(.RST_VAL(1'b0)) u_rst_sync (
        .clk      (clk),
        .rst_n    (~btn_rst),       // async reset asserted when button pressed
        .async_in (1'b1),
        .sync_out (rst_n)
    );

    // -----------------------------------------------------------------
    // io -> backend
    // -----------------------------------------------------------------
    logic         io_key_valid;
    logic         io_key_ready;
    logic [2:0]   io_key_type;
    byte_t        io_key_ascii;

    // -----------------------------------------------------------------
    // PS/2 mouse
    // -----------------------------------------------------------------
    logic [9:0] mouse_x, mouse_y;
    logic       mouse_scroll_up, mouse_scroll_down, mouse_left_click;
    /* verilator lint_off UNUSEDSIGNAL */
    logic       mouse_click_ready_unused;
    /* verilator lint_on UNUSEDSIGNAL */

    io_mouse #(
        .CLK_FREQ_HZ (CLK_FREQ_HZ),
        .SCREEN_W    (800),
        .SCREEN_H    (600)
    ) u_mouse (
        .clk         (clk),
        .rst_n       (rst_n),
        .ps2_clk     (ps2_mouse_clk),
        .ps2_data    (ps2_mouse_data),
        .mouse_x     (mouse_x),
        .mouse_y     (mouse_y),
        .scroll_up   (mouse_scroll_up),
        .scroll_down (mouse_scroll_down),
        .left_click  (mouse_left_click)
    );

    // Determine mouse region for scroll routing
    logic mouse_in_input_area;
    assign mouse_in_input_area = ({6'd0, mouse_y} >= 16'(INPUT_PIXEL_Y_LO))
                              && ({6'd0, mouse_y} <= 16'(INPUT_PIXEL_Y_HI));

    io_top u_io (
        .clk                  (clk),
        .rst_n                (rst_n),
        .ps2_clk              (ps2_clk),
        .ps2_data             (ps2_data),
        .mouse_scroll_up      (mouse_scroll_up),
        .mouse_scroll_down    (mouse_scroll_down),
        .mouse_scroll_in_input(mouse_in_input_area),
        .io_key_valid         (io_key_valid),
        .io_key_ready         (io_key_ready),
        .io_key_type          (io_key_type),
        .io_key_ascii         (io_key_ascii)
    );

    // -----------------------------------------------------------------
    // backend <-> comm
    // -----------------------------------------------------------------
    logic                          be_tx_valid, be_tx_ready;
    logic [2:0]                    be_tx_frame_type;
    msg_id_t                       be_tx_msg_id;
    msg_len_t                      be_tx_len;
    logic [MAX_MSG_LEN*8-1:0]      be_tx_payload;

    logic                          cm_rx_valid, cm_rx_ready;
    logic [2:0]                    cm_rx_frame_type;
    seq_t                          cm_rx_seq;
    msg_len_t                      cm_rx_len;
    logic [MAX_MSG_LEN*8-1:0]      cm_rx_payload;

    logic                          cm_status_valid, cm_status_ready;
    msg_id_t                       cm_status_msg_id;
    logic [1:0]                    cm_status_code;

    // -----------------------------------------------------------------
    // backend -> frontend
    // -----------------------------------------------------------------
    logic                          be_render_valid, be_render_ready;
    logic [3:0]                    be_render_cmd;
    msg_id_t                       be_render_msg_id;
    logic [1:0]                    be_render_side, be_render_status;
    msg_len_t                      be_render_len;
    logic [MAX_MSG_LEN*8-1:0]      be_render_payload;
    msg_len_t                      be_render_cursor_pos;
    byte_t                         be_render_ascii;
    logic [1:0]                    be_render_conn_state;
    msg_len_t                      be_render_peer_name_len;
    logic [MAX_NAME_LEN*8-1:0]     be_render_peer_name;

    logic                          ui_popup_active;
    logic [1:0]                    ui_popup_type;
    logic [9:0]                    ui_popup_x, ui_popup_y;

    // -----------------------------------------------------------------
    // be_top observability ports -- unused at chip top level. Tied off
    // so the chip-level netlist stays clean. lint_off so verilator
    // doesn't complain about unused output bits.
    // -----------------------------------------------------------------
    /* verilator lint_off UNUSEDSIGNAL */
    byte_t                         be_line_rd_data;
    logic [LEN_WIDTH-1:0]          be_line_len, be_cursor_pos;
    logic                          be_enter_committed;
    logic                          be_store_rd_valid;
    msg_id_t                       be_store_rd_msg_id;
    logic [1:0]                    be_store_rd_side, be_store_rd_status;
    msg_len_t                      be_store_rd_len;
    logic [MAX_MSG_LEN*8-1:0]      be_store_rd_payload;
    logic [1:0]                    be_conn_state;
    /* verilator lint_on UNUSEDSIGNAL */

    be_top #(
        .MY_NAME_LEN    (MY_NAME_LEN),
        .MY_NAME_PACKED (MY_NAME_PACKED)
    ) u_be (
        .clk                    (clk),
        .rst_n                  (rst_n),
        .io_key_valid           (io_key_valid),
        .io_key_ready           (io_key_ready),
        .io_key_type            (io_key_type),
        .io_key_ascii           (io_key_ascii),
        .io_mouse_click_valid   (mouse_left_click),
        .io_mouse_click_ready   (mouse_click_ready_unused),
        .io_mouse_click_x       (mouse_x),
        .io_mouse_click_y       (mouse_y),
        .fe_input_scroll_offset (fe_input_scroll_offset_obs),
        .fe_input_at_limit      (fe_input_at_limit),
        .ui_popup_active        (ui_popup_active),
        .ui_popup_type          (ui_popup_type),
        .ui_popup_x             (ui_popup_x),
        .ui_popup_y             (ui_popup_y),
        .cm_rx_valid            (cm_rx_valid),
        .cm_rx_ready            (cm_rx_ready),
        .cm_rx_frame_type       (cm_rx_frame_type),
        .cm_rx_seq              (cm_rx_seq),
        .cm_rx_len              (cm_rx_len),
        .cm_rx_payload          (cm_rx_payload),
        .cm_status_valid        (cm_status_valid),
        .cm_status_ready        (cm_status_ready),
        .cm_status_msg_id       (cm_status_msg_id),
        .cm_status_code         (cm_status_code),
        .be_tx_valid            (be_tx_valid),
        .be_tx_ready            (be_tx_ready),
        .be_tx_frame_type       (be_tx_frame_type),
        .be_tx_msg_id           (be_tx_msg_id),
        .be_tx_len              (be_tx_len),
        .be_tx_payload          (be_tx_payload),
        .be_render_valid        (be_render_valid),
        .be_render_ready        (be_render_ready),
        .be_render_cmd          (be_render_cmd),
        .be_render_msg_id       (be_render_msg_id),
        .be_render_side         (be_render_side),
        .be_render_status       (be_render_status),
        .be_render_len          (be_render_len),
        .be_render_payload      (be_render_payload),
        .be_render_cursor_pos   (be_render_cursor_pos),
        .be_render_ascii        (be_render_ascii),
        .be_render_conn_state   (be_render_conn_state),
        .be_render_peer_name_len(be_render_peer_name_len),
        .be_render_peer_name    (be_render_peer_name),
        .line_rd_idx            ({$clog2(MAX_LINE_LEN){1'b0}}),
        .line_rd_data           (be_line_rd_data),
        .line_len               (be_line_len),
        .cursor_pos             (be_cursor_pos),
        .enter_committed        (be_enter_committed),
        .store_rd_idx           ({$clog2(MAX_MSG_NUM){1'b0}}),
        .store_rd_valid         (be_store_rd_valid),
        .store_rd_msg_id        (be_store_rd_msg_id),
        .store_rd_side          (be_store_rd_side),
        .store_rd_status        (be_store_rd_status),
        .store_rd_len           (be_store_rd_len),
        .store_rd_payload       (be_store_rd_payload),
        .conn_state_obs         (be_conn_state)
    );

    comm_top #(
        .CLK_FREQ_HZ    (CLK_FREQ_HZ),
        .BAUD           (BAUD),
        .TIMEOUT_CYCLES (TIMEOUT_CYCLES)
    ) u_comm (
        .clk              (clk),
        .rst_n            (rst_n),
        .uart_rxd         (uart_rxd),
        .uart_txd         (uart_txd),
        .be_tx_valid      (be_tx_valid),
        .be_tx_ready      (be_tx_ready),
        .be_tx_frame_type (be_tx_frame_type),
        .be_tx_msg_id     (be_tx_msg_id),
        .be_tx_len        (be_tx_len),
        .be_tx_payload    (be_tx_payload),
        .cm_rx_valid      (cm_rx_valid),
        .cm_rx_ready      (cm_rx_ready),
        .cm_rx_frame_type (cm_rx_frame_type),
        .cm_rx_seq        (cm_rx_seq),
        .cm_rx_len        (cm_rx_len),
        .cm_rx_payload    (cm_rx_payload),
        .cm_status_valid  (cm_status_valid),
        .cm_status_ready  (cm_status_ready),
        .cm_status_msg_id (cm_status_msg_id),
        .cm_status_code   (cm_status_code)
    );

    // -----------------------------------------------------------------
    // Frontend
    // -----------------------------------------------------------------
    // Pixel-domain clock: a 50 MHz pixel clock from a board PLL is
    // wanted for real HDMI; until the PLL lands we feed the chat
    // clock into both ports of the dual-port text_ram.
    // -----------------------------------------------------------------
    // Frontend video signals -- exposed for HDMI integration. Not yet
    // pinned out at the chat_top boundary; an outer wrapper that
    // instantiates ip_pll (-> 50 MHz clk_pix) and ip_rgb2dvi (-> TMDS
    // pads) will consume these. Kept un-driven downstream for now.
    // -----------------------------------------------------------------
    /* verilator lint_off UNUSEDSIGNAL */
    byte_t                                       fe_rd_code;
    logic [1:0]                                  fe_conn_state_obs;
    msg_len_t                                    fe_input_len_obs;
    msg_len_t                                    fe_input_cursor_obs;
    logic [MAX_NAME_LEN*8-1:0]                   fe_peer_name_obs;
    msg_len_t                                    fe_peer_name_len_obs;
    logic [HIST_W-1:0]                           fe_hist_wr_row_obs;
    logic [SCROLL_W-1:0]                         fe_scroll_offset_obs;
    logic [INPUT_LINE_W-1:0]                     fe_input_cursor_row_obs;
    msg_len_t                                    fe_input_cursor_col_obs;
    logic [INPUT_N_LINES_W-1:0]                  fe_input_n_lines_obs;
    /* verilator lint_on UNUSEDSIGNAL */
    logic [INPUT_SCROLL_W-1:0]                   fe_input_scroll_offset_obs;
    logic                                        fe_input_at_limit;
    assign fe_input_at_limit =
        (fe_input_n_lines_obs >= INPUT_N_LINES_W'(MAX_INPUT_LINES));

    fe_top #(
        .LOCAL_NAME_LEN   (MY_NAME_LEN),
        .LOCAL_NAME_PACKED(MY_NAME_PACKED),
        .ENABLE_SRAM_ASSETS(ENABLE_SRAM_ASSETS)
    ) u_fe (
        .clk                     (clk),
        .rst_n                   (rst_n),
        .clk_pix                 (clk_pix),
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
        .video_red               (video_red),
        .video_green             (video_green),
        .video_blue              (video_blue),
        .video_hsync             (video_hsync),
        .video_vsync             (video_vsync),
        .video_de                (video_de),
        .asset_sram_addr         (asset_sram_addr),
        .asset_sram_data         (asset_sram_data),
        .mouse_x                 (mouse_x),
        .mouse_y                 (mouse_y),
        .ui_popup_active         (ui_popup_active),
        .ui_popup_type           (ui_popup_type),
        .ui_popup_x              (ui_popup_x),
        .ui_popup_y              (ui_popup_y),
        .rd_row                  ('0),
        .rd_col                  ('0),
        .rd_code                 (fe_rd_code),
        .conn_state_obs          (fe_conn_state_obs),
        .input_len_obs           (fe_input_len_obs),
        .input_cursor_obs        (fe_input_cursor_obs),
        .peer_name_obs           (fe_peer_name_obs),
        .peer_name_len_obs       (fe_peer_name_len_obs),
        .hist_wr_row_obs         (fe_hist_wr_row_obs),
        .scroll_offset_obs       (fe_scroll_offset_obs),
        .input_cursor_row_obs    (fe_input_cursor_row_obs),
        .input_cursor_col_obs    (fe_input_cursor_col_obs),
        .input_n_lines_obs       (fe_input_n_lines_obs),
        .input_scroll_offset_obs (fe_input_scroll_offset_obs)
    );

endmodule

`endif  // CHAT_TOP_SV
