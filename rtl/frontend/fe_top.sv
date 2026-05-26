// =====================================================================
// fe_top.sv  --  Frontend top
// ---------------------------------------------------------------------
// Wires the protocol-side decoder, the character-grid text_ram, and
// the pixel-side scan pipeline (video_timing + glyph_rom + scan).
//
// All layout / timing / palette / sprite / font-path constants come
// from fe_pkg. Tweak fe_pkg in one place to retune the whole frontend.
//
// Two clock domains:
//   clk        chat clock   (decoder + text_ram write port)
//   clk_pix    pixel clock  (text_ram read port A + scan + glyph_rom)
//
// Outward ports:
//   be_render_*           BE-side command stream (consumed)
//   video_red/green/blue  RGB to the HDMI encoder
//   video_hsync/vsync/de  HDMI sync + data-enable
//   rd_*                  observability read port (registered, on
//                         clk_pix); used by sim only -- it taps the
//                         text_ram via a second BRAM read port that
//                         is independent of the scan pipeline.
//   *_obs                 internal counters useful for both sim and
//                         the scan side.
// =====================================================================

`ifndef FE_TOP_SV
`define FE_TOP_SV

module fe_top
    import chat_pkg::*;
    import fe_pkg::*;
#(
    parameter int LOCAL_NAME_LEN = 5,
    parameter logic [MAX_NAME_LEN*8-1:0] LOCAL_NAME_PACKED =
        128'h00000000_00000000_00000065_63696c41,
    parameter bit ENABLE_SRAM_ASSETS = 1'b0
)
(
    input  logic                       clk,        // chat-domain clock
    input  logic                       rst_n,
    input  logic                       clk_pix,    // pixel-domain clock

    // backend -> frontend: render command stream
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

    // Pixel-side video out (to ip_rgb2dvi or equivalent)
    output logic [7:0]                 video_red,
    output logic [7:0]                 video_green,
    output logic [7:0]                 video_blue,
    output logic                       video_hsync,
    output logic                       video_vsync,
    output logic                       video_de,

    // Read-only SRAM asset bus. Board wrapper maps this to BaseRAM;
    // simulations can tie asset_sram_data to 0 for a black background.
    output logic [19:0]                asset_sram_addr,
    input  logic [31:0]                asset_sram_data,

    // Mouse pointer (chat-clock domain; CDC'd to pixel clock below).
    // Tie to '0 in sims that don't model a mouse.
    input  logic [9:0]                 mouse_x,
    input  logic [9:0]                 mouse_y,

    // Popup overlay state (chat-clock domain; CDC'd to pixel clock below).
    input  logic                       ui_popup_active,
    input  logic [1:0]                 ui_popup_type,
    input  logic [9:0]                 ui_popup_x,
    input  logic [9:0]                 ui_popup_y,

    // Observability read port (independent BRAM port, used by sim).
    input  logic [FE_ROW_W-1:0]        rd_row,
    input  logic [FE_COL_W-1:0]        rd_col,
    output byte_t                      rd_code,

    // Decoder observability for tests / scan use
    output logic [1:0]                 conn_state_obs,
    output msg_len_t                   input_len_obs,
    output msg_len_t                   input_cursor_obs,
    output logic [MAX_NAME_LEN*8-1:0]  peer_name_obs,
    output msg_len_t                   peer_name_len_obs,
    output logic [HIST_W-1:0]          hist_wr_row_obs,
    output logic [SCROLL_W-1:0]        scroll_offset_obs,
    output logic [INPUT_LINE_W-1:0]    input_cursor_row_obs,
    output msg_len_t                   input_cursor_col_obs,
    output logic [INPUT_SCROLL_W-1:0]  input_scroll_offset_obs
);

    // -----------------------------------------------------------------
    // Decoder -> text_ram write port
    // -----------------------------------------------------------------
    logic                  wr_en;
    logic [FE_ROW_W-1:0]   wr_row;
    logic [FE_COL_W-1:0]   wr_col;
    byte_t                 wr_code;
    logic [1:0]            wr_attr;

    logic [HIST_W-1:0]     hist_wr_row_dec;
    logic [SCROLL_W-1:0]   scroll_offset_dec;
    logic [N_HIST_STORED*2-1:0] hist_avatar_attr_dec;

    assign hist_wr_row_obs   = hist_wr_row_dec;
    assign scroll_offset_obs = scroll_offset_dec;

    // fe_render_decoder uses synchronous reset (its FFs drive
    // fe_text_ram's BRAM address pins, and Xilinx BRAM doesn't tolerate
    // async-reset on those inputs). Synchronise the raw rst_n into the
    // chat clock so we don't mix sync + async reset domains.
    logic rst_n_sync;
    sync_2ff #(.RST_VAL(1'b0)) u_sync_rst (
        .clk     (clk),
        .rst_n   (rst_n),
        .async_in(1'b1),
        .sync_out(rst_n_sync)
    );

    fe_render_decoder #(
        .LOCAL_NAME_LEN   (LOCAL_NAME_LEN),
        .LOCAL_NAME_PACKED(LOCAL_NAME_PACKED)
    ) u_decoder (
        .clk                    (clk),
        .rst_n                  (rst_n_sync),
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
        .wr_en                  (wr_en),
        .wr_row                 (wr_row),
        .wr_col                 (wr_col),
        .wr_code                (wr_code),
        .wr_attr                (wr_attr),
        .conn_state_obs         (conn_state_obs),
        .input_len_obs          (input_len_obs),
        .input_cursor_obs       (input_cursor_obs),
        .peer_name_obs          (peer_name_obs),
        .peer_name_len_obs      (peer_name_len_obs),
        .hist_wr_row_obs        (hist_wr_row_dec),
        .scroll_offset_obs      (scroll_offset_dec),
        .hist_avatar_attr_obs   (hist_avatar_attr_dec),
        .input_cursor_row_obs   (input_cursor_row_obs),
        .input_cursor_col_obs   (input_cursor_col_obs),
        .input_scroll_offset_obs(input_scroll_offset_obs)
    );

    // -----------------------------------------------------------------
    // Pixel-side glue: video_timing -> scan -> text_ram + glyph_rom
    // -----------------------------------------------------------------
    logic [HWIDTH-1:0] hdata, vdata;
    logic              vt_hsync, vt_vsync, vt_de;

    fe_video_timing u_video_timing (
        .clk         (clk_pix),
        .rst_n       (rst_n),
        .hdata       (hdata),
        .vdata       (vdata),
        .hsync       (vt_hsync),
        .vsync       (vt_vsync),
        .data_enable (vt_de)
    );

    // Scan-side text_ram read port (port A)
    logic [FE_ROW_W-1:0]   scan_rd_row;
    logic [FE_COL_W-1:0]   scan_rd_col;
    byte_t                 scan_rd_code;
    logic [1:0]            scan_rd_attr;

    // glyph_rom (combinational read)
    byte_t              glyph_code;
    logic [3:0]         glyph_gy;
    logic [7:0]         glyph_row;

    fe_glyph_rom u_glyph_rom (
        .code      (glyph_code),
        .gy        (glyph_gy),
        .glyph_row (glyph_row)
    );

    // CDC: small slow-changing signals from chat domain to pixel
    // domain. Each bit gets a two-flop sync; multi-bit busses can
    // briefly look inconsistent during a transition, but visible
    // glitches are at most one frame and only on cells that are about
    // to be updated anyway, so they are not noticeable.
    logic [1:0]                conn_state_pix;
    logic [HIST_W-1:0]         hist_wr_row_pix;
    logic [SCROLL_W-1:0]       scroll_offset_pix;
    logic [N_HIST_STORED*2-1:0] hist_avatar_attr_pix;
    logic [INPUT_LINE_W-1:0]   input_cursor_row_pix;
    // Cursor col only needs FE_COL_W bits on the scan side (off-screen
    // cols never match anyway). Narrowing here keeps fe_scan from
    // dragging in 9 unused MSBs.
    logic [FE_COL_W-1:0]       input_cursor_col_pix;
    logic [INPUT_SCROLL_W-1:0] input_scroll_offset_pix;
    logic [9:0]                mouse_x_pix;
    logic [9:0]                mouse_y_pix;
    logic                      ui_popup_active_pix;
    logic [1:0]                ui_popup_type_pix;
    logic [9:0]                ui_popup_x_pix;
    logic [9:0]                ui_popup_y_pix;

    sync_2ff #(.RST_VAL(1'b0)) u_sync_cs0 (
        .clk(clk_pix), .rst_n(rst_n),
        .async_in(conn_state_obs[0]), .sync_out(conn_state_pix[0])
    );
    sync_2ff #(.RST_VAL(1'b0)) u_sync_cs1 (
        .clk(clk_pix), .rst_n(rst_n),
        .async_in(conn_state_obs[1]), .sync_out(conn_state_pix[1])
    );
    genvar gi;
    generate
        for (gi = 0; gi < HIST_W; gi++) begin : g_sync_hist
            sync_2ff #(.RST_VAL(1'b0)) u_sync_hist (
                .clk(clk_pix), .rst_n(rst_n),
                .async_in(hist_wr_row_dec[gi]),
                .sync_out(hist_wr_row_pix[gi])
            );
        end
        for (gi = 0; gi < SCROLL_W; gi++) begin : g_sync_scroll
            sync_2ff #(.RST_VAL(1'b0)) u_sync_scroll (
                .clk(clk_pix), .rst_n(rst_n),
                .async_in(scroll_offset_dec[gi]),
                .sync_out(scroll_offset_pix[gi])
            );
        end
        for (gi = 0; gi < N_HIST_STORED*2; gi++) begin : g_sync_avatar_attr
            sync_2ff #(.RST_VAL(1'b0)) u_sync_avatar_attr (
                .clk(clk_pix), .rst_n(rst_n),
                .async_in(hist_avatar_attr_dec[gi]),
                .sync_out(hist_avatar_attr_pix[gi])
            );
        end
        for (gi = 0; gi < INPUT_LINE_W; gi++) begin : g_sync_icrow
            sync_2ff #(.RST_VAL(1'b0)) u_sync_icrow (
                .clk(clk_pix), .rst_n(rst_n),
                .async_in(input_cursor_row_obs[gi]),
                .sync_out(input_cursor_row_pix[gi])
            );
        end
        for (gi = 0; gi < FE_COL_W; gi++) begin : g_sync_iccol
            sync_2ff #(.RST_VAL(1'b0)) u_sync_iccol (
                .clk(clk_pix), .rst_n(rst_n),
                .async_in(input_cursor_col_obs[gi]),
                .sync_out(input_cursor_col_pix[gi])
            );
        end
        for (gi = 0; gi < INPUT_SCROLL_W; gi++) begin : g_sync_iscr
            sync_2ff #(.RST_VAL(1'b0)) u_sync_iscr (
                .clk(clk_pix), .rst_n(rst_n),
                .async_in(input_scroll_offset_obs[gi]),
                .sync_out(input_scroll_offset_pix[gi])
            );
        end
        for (gi = 0; gi < 10; gi++) begin : g_sync_mx
            sync_2ff #(.RST_VAL(1'b0)) u_sync_mx (
                .clk(clk_pix), .rst_n(rst_n),
                .async_in(mouse_x[gi]),
                .sync_out(mouse_x_pix[gi])
            );
        end
        for (gi = 0; gi < 10; gi++) begin : g_sync_my
            sync_2ff #(.RST_VAL(1'b0)) u_sync_my (
                .clk(clk_pix), .rst_n(rst_n),
                .async_in(mouse_y[gi]),
                .sync_out(mouse_y_pix[gi])
            );
        end
        for (gi = 0; gi < 2; gi++) begin : g_sync_popup_type
            sync_2ff #(.RST_VAL(1'b0)) u_sync_popup_type (
                .clk(clk_pix), .rst_n(rst_n),
                .async_in(ui_popup_type[gi]),
                .sync_out(ui_popup_type_pix[gi])
            );
        end
        for (gi = 0; gi < 10; gi++) begin : g_sync_popup_x
            sync_2ff #(.RST_VAL(1'b0)) u_sync_popup_x (
                .clk(clk_pix), .rst_n(rst_n),
                .async_in(ui_popup_x[gi]),
                .sync_out(ui_popup_x_pix[gi])
            );
        end
        for (gi = 0; gi < 10; gi++) begin : g_sync_popup_y
            sync_2ff #(.RST_VAL(1'b0)) u_sync_popup_y (
                .clk(clk_pix), .rst_n(rst_n),
                .async_in(ui_popup_y[gi]),
                .sync_out(ui_popup_y_pix[gi])
            );
        end
    endgenerate

    sync_2ff #(.RST_VAL(1'b0)) u_sync_popup_active (
        .clk(clk_pix), .rst_n(rst_n),
        .async_in(ui_popup_active),
        .sync_out(ui_popup_active_pix)
    );

    fe_scan #(
        .ENABLE_SRAM_ASSETS(ENABLE_SRAM_ASSETS)
    ) u_scan (
        .clk_pix       (clk_pix),
        .rst_n         (rst_n),
        .hdata         (hdata),
        .vdata         (vdata),
        .hsync         (vt_hsync),
        .vsync         (vt_vsync),
        .data_enable   (vt_de),
        .rd_row        (scan_rd_row),
        .rd_col        (scan_rd_col),
        .rd_code       (scan_rd_code),
        .rd_attr       (scan_rd_attr),
        .glyph_code    (glyph_code),
        .glyph_gy      (glyph_gy),
        .glyph_row     (glyph_row),
        .asset_sram_addr(asset_sram_addr),
        .asset_sram_data(asset_sram_data),
        .conn_state         (conn_state_pix),
        .hist_wr_row        (hist_wr_row_pix),
        .scroll_offset      (scroll_offset_pix),
        .hist_avatar_attr   (hist_avatar_attr_pix),
        .input_cursor_row   (input_cursor_row_pix),
        .input_cursor_col   (input_cursor_col_pix),
        .input_scroll_offset(input_scroll_offset_pix),
        .mouse_x            (mouse_x_pix),
        .mouse_y            (mouse_y_pix),
        .popup_active       (ui_popup_active_pix),
        .popup_type         (ui_popup_type_pix),
        .popup_x            (ui_popup_x_pix),
        .popup_y            (ui_popup_y_pix),
        .video_red     (video_red),
        .video_green   (video_green),
        .video_blue    (video_blue),
        .video_hsync   (video_hsync),
        .video_vsync   (video_vsync),
        .video_de      (video_de)
    );

    // text_ram with two read ports: A=scan, B=test/observability.
    fe_text_ram u_text_ram (
        .wr_clk   (clk),
        .wr_en    (wr_en),
        .wr_row   (wr_row),
        .wr_col   (wr_col),
        .wr_code  (wr_code),
        .wr_attr  (wr_attr),
        .rd_clk   (clk_pix),
        .rd_row   (scan_rd_row),
        .rd_col   (scan_rd_col),
        .rd_code  (scan_rd_code),
        .rd_attr  (scan_rd_attr),
        .rd2_clk  (clk_pix),
        .rd2_row  (rd_row),
        .rd2_col  (rd_col),
        .rd2_code (rd_code)
    );

endmodule

`endif  // FE_TOP_SV
