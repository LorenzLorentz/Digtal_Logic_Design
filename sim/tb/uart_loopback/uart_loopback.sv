// =====================================================================
// uart_loopback.sv  --  Test-only wrapper: uart_tx -> uart_rx loopback
// ---------------------------------------------------------------------
// Connects the tx output pin straight to the rx input pin so that
// bytes pushed into tx pop out of rx after a full UART frame. Confirms
// the tx and rx sides agree on bit cadence, polarity, and 8N1 framing.
//
// Lives only under sim/.
// =====================================================================

`ifndef UART_LOOPBACK_SV
`define UART_LOOPBACK_SV

module uart_loopback
    import chat_pkg::*;
#(
    parameter int CLK_FREQ_HZ = 160,
    parameter int BAUD        = 10
) (
    input  logic     clk,
    input  logic     rst_n,

    // tx-side handshake
    input  logic     tx_in_valid,
    output logic     tx_in_ready,
    input  byte_t    tx_in_data,

    // rx-side observation
    output logic     rx_byte_valid,
    output byte_t    rx_byte_data,
    output logic     rx_frame_error,

    // expose the wire for VCD
    output logic     wire_tx
);

    logic line;

    uart_tx #(
        .CLK_FREQ_HZ (CLK_FREQ_HZ),
        .BAUD        (BAUD)
    ) u_tx (
        .clk      (clk),
        .rst_n    (rst_n),
        .in_valid (tx_in_valid),
        .in_ready (tx_in_ready),
        .in_data  (tx_in_data),
        .tx       (line)
    );

    uart_rx #(
        .CLK_FREQ_HZ (CLK_FREQ_HZ),
        .BAUD        (BAUD)
    ) u_rx (
        .clk         (clk),
        .rst_n       (rst_n),
        .rx          (line),
        .byte_valid  (rx_byte_valid),
        .byte_data   (rx_byte_data),
        .frame_error (rx_frame_error)
    );

    assign wire_tx = line;

endmodule

`endif  // UART_LOOPBACK_SV
