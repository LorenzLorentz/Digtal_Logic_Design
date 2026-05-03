// =====================================================================
// io_top.sv  --  io subsystem top
// ---------------------------------------------------------------------
// Wires the three io stages together:
//
//   ps2_clk/ps2_data ─▶ io_ps2_phy ─byte─▶ io_ps2_decoder ─event─▶ FIFO ─▶ backend
//
// External interfaces:
//   - PS/2 pins: asynchronous, idle-high (caller wires to chat_top pins).
//   - Backend handshake: io_key_valid / io_key_ready / io_key_type /
//     io_key_ascii, matching the contract used by be_top.
//
// Buffering:
//   - 16-deep handshake_fifo between decoder and backend. With PS/2 at
//     ~10 keys/sec and backend handling each event in << 1 us, this is
//     vastly more than enough; overflow drops events silently. Decoder
//     produces 1-cycle pulses with no back-pressure (it can't pause
//     PS/2), so the dropping convention is correct here.
//
// Frame errors at the phy are not propagated; phy never raises
// byte_valid for a corrupted frame, so the decoder simply doesn't see
// the stale bit pattern.
// =====================================================================

`ifndef IO_TOP_SV
`define IO_TOP_SV

module io_top
    import chat_pkg::*;
(
    input  logic        clk,
    input  logic        rst_n,

    // Async PS/2 pins
    input  logic        ps2_clk,
    input  logic        ps2_data,

    // Backend handshake
    output logic        io_key_valid,
    input  logic        io_key_ready,
    output logic [2:0]  io_key_type,
    output byte_t       io_key_ascii
);

    // ---- phy -> decoder ----
    logic         phy_byte_valid;
    byte_t        phy_byte_data;

    // ---- decoder -> fifo ----
    logic         dec_ev_valid;
    logic [2:0]   dec_ev_type;
    byte_t        dec_ev_ascii;

    /* verilator lint_off PINCONNECTEMPTY */
    io_ps2_phy u_phy (
        .clk         (clk),
        .rst_n       (rst_n),
        .ps2_clk     (ps2_clk),
        .ps2_data    (ps2_data),
        .byte_valid  (phy_byte_valid),
        .byte_data   (phy_byte_data),
        .frame_error (/* unused: phy already gates byte_valid */)
    );

    io_ps2_decoder u_decoder (
        .clk        (clk),
        .rst_n      (rst_n),
        .byte_valid (phy_byte_valid),
        .byte_data  (phy_byte_data),
        .ev_valid   (dec_ev_valid),
        .ev_type    (dec_ev_type),
        .ev_ascii   (dec_ev_ascii)
    );

    // 11-bit FIFO entry: {key_type[2:0], ascii[7:0]}.
    handshake_fifo #(
        .WIDTH (3 + 8),
        .DEPTH (16)
    ) u_fifo (
        .clk       (clk),
        .rst_n     (rst_n),
        .in_valid  (dec_ev_valid),
        .in_ready  (/* decoder doesn't check; full -> drop */),
        .in_data   ({dec_ev_type, dec_ev_ascii}),
        .out_valid (io_key_valid),
        .out_ready (io_key_ready),
        .out_data  ({io_key_type, io_key_ascii})
    );
    /* verilator lint_on PINCONNECTEMPTY */

endmodule

`endif  // IO_TOP_SV
