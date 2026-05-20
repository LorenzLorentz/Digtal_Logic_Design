// =====================================================================
// chat_top_board.sv  --  Board-level wrapper (Vivado synthesis only)
// ---------------------------------------------------------------------
// SYNTHESIS-ONLY. Verilator cannot elaborate this file because it
// instantiates two Xilinx IPs (ip_pll, ip_rgb2dvi) that are generated
// inside the Vivado project. Keep this file out of every sim deps.txt.
//
// What this module does:
//   1. Takes the raw 100 MHz board oscillator and active-high
//      push-button reset.
//   2. Spins up a 50 MHz pixel clock via ip_pll (Clocking Wizard).
//   3. Instantiates chat_top, feeding it both the chat clock
//      (clk_100m) and the pixel clock from the PLL.
//   4. Pushes chat_top's video signals through ip_rgb2dvi to
//      produce HDMI TMDS pad outputs.
//
// Two IPs to add to the Vivado project before this builds:
//   - ip_pll       : Clocking Wizard, in=100 MHz, out=50 MHz (use the
//                    same instance as example/project-template-xilinx).
//   - ip_rgb2dvi   : The rgb2dvi IP from example/ip_repo (digilent).
//                    Already vendored in this repo at example/ip_repo.
//
// Per-board identity (the chat user name shown on the titlebar): set
// MY_NAME_LEN / MY_NAME_PACKED here at instantiation -- A board and B
// board must build different bitstreams with different defaults.
//
// Pin map: see constraints/chat_top_board.xdc.
// =====================================================================

`ifndef CHAT_TOP_BOARD_SV
`define CHAT_TOP_BOARD_SV

module chat_top_board
    import chat_pkg::*;
#(
    parameter int MY_NAME_LEN = 5,
    parameter logic [MAX_NAME_LEN*8-1:0] MY_NAME_PACKED =
        128'h00000000_00000000_00000065_63696c41,   // "Alice"

    parameter int CLK_FREQ_HZ    = CLK_FREQ_HZ_DEFAULT,
    parameter int BAUD           = UART_BAUD_DEFAULT,
    parameter int TIMEOUT_CYCLES = 2_000_000
) (
    // ---- Board clock + reset ----
    input  logic        clk_100m,
    input  logic        btn_rst,            // active-high, momentary

    // ---- PS/2 keyboard (port names match example/io.xdc) ----
    input  logic        ps2_keyboard_clk,
    input  logic        ps2_keyboard_data,

    // ---- PS/2 mouse (bidirectional for host-to-device init) ----
    inout  logic        ps2_mouse_clk,
    inout  logic        ps2_mouse_data,

    // ---- UART (PMOD, TTL) ----
    input  logic        uart_rxd,
    output logic        uart_txd,

    // ---- HDMI (TMDS differential pads) ----
    output logic [2:0]  hdmi_tmds_p,
    output logic [2:0]  hdmi_tmds_n,
    output logic        hdmi_tmds_c_p,
    output logic        hdmi_tmds_c_n
);

    // -----------------------------------------------------------------
    // PLL: 100 MHz (chat / system) -> 40 MHz (pixel for 800x600@60Hz)
    // -----------------------------------------------------------------
    logic clk_pix;
    logic clk_locked;
    ip_pll u_ip_pll (
        .clk_in1  (clk_100m),
        .reset    (btn_rst),     // active-high reset
        .clk_out1 (clk_pix),
        .locked   (clk_locked)
    );

    // -----------------------------------------------------------------
    // chat_top -- everything functional. Same module Verilator tests.
    // -----------------------------------------------------------------
    logic [7:0] video_red, video_green, video_blue;
    logic       video_hsync, video_vsync, video_de;
    /* verilator lint_off UNUSEDSIGNAL */
    logic [19:0] asset_sram_addr_unused;
    /* verilator lint_on UNUSEDSIGNAL */

    chat_top #(
        .MY_NAME_LEN    (MY_NAME_LEN),
        .MY_NAME_PACKED (MY_NAME_PACKED),
        .CLK_FREQ_HZ    (CLK_FREQ_HZ),
        .BAUD           (BAUD),
        .TIMEOUT_CYCLES (TIMEOUT_CYCLES)
    ) u_chat (
        .clk         (clk_100m),
        .btn_rst     (btn_rst),
        .clk_pix     (clk_pix),
        .ps2_clk     (ps2_keyboard_clk),
        .ps2_data    (ps2_keyboard_data),
        .ps2_mouse_clk  (ps2_mouse_clk),
        .ps2_mouse_data (ps2_mouse_data),
        .uart_rxd    (uart_rxd),
        .uart_txd    (uart_txd),
        .video_red   (video_red),
        .video_green (video_green),
        .video_blue  (video_blue),
        .video_hsync (video_hsync),
        .video_vsync (video_vsync),
        .video_de    (video_de),
        .asset_sram_addr(asset_sram_addr_unused),
        .asset_sram_data(32'h0000_0000)
    );

    // -----------------------------------------------------------------
    // RGB -> TMDS encoder. Pin / colour-channel ordering matches
    // example/project-template-xilinx (R, B, G into vid_pData).
    // -----------------------------------------------------------------
    ip_rgb2dvi u_ip_rgb2dvi (
        .PixelClk   (clk_pix),
        .vid_pVDE   (video_de),
        .vid_pHSync (video_hsync),
        .vid_pVSync (video_vsync),
        .vid_pData  ({video_red, video_blue, video_green}),
        .aRst       (~clk_locked),

        .TMDS_Clk_p  (hdmi_tmds_c_p),
        .TMDS_Clk_n  (hdmi_tmds_c_n),
        .TMDS_Data_p (hdmi_tmds_p),
        .TMDS_Data_n (hdmi_tmds_n)
    );

endmodule

`endif  // CHAT_TOP_BOARD_SV
