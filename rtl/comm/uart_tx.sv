// =====================================================================
// uart_tx.sv  --  Asynchronous serial transmitter (8N1)
// ---------------------------------------------------------------------
// 8 data bits, no parity, 1 stop bit. LSB first. tx idles high.
//
// Bit cadence is derived from CLK_FREQ_HZ / BAUD: each bit lasts
// BAUD_DIV clock cycles (=868 for 100 MHz / 115200). Tests can shrink
// BAUD_DIV by overriding either parameter.
//
// Frame layout (10 bits, LSB first on the wire):
//
//   [start=0] [d0] [d1] ... [d7] [stop=1]
//        ^---- driven for BAUD_DIV cycles each ----^
//
// Handshake:
//   - in_ready high while idle. A producer asserts in_valid + in_data;
//     the byte latches on the cycle in_valid && in_ready, after which
//     the FSM drives the wire for 10 * BAUD_DIV cycles.
//   - in_ready falls during transmission and rises again the cycle
//     after the stop bit completes.
//
// Implementation:
//   - 10-bit packet register (LSB=start, MSB=stop), bit_idx_q indexes
//     the bit currently on tx. cnt_q holds the cycle counter inside
//     the current bit. tx_q is registered to avoid combinational
//     glitches on the pin.
// =====================================================================

`ifndef UART_TX_SV
`define UART_TX_SV

module uart_tx
    import chat_pkg::*;
#(
    parameter int CLK_FREQ_HZ = CLK_FREQ_HZ_DEFAULT,
    parameter int BAUD        = UART_BAUD_DEFAULT
) (
    input  logic     clk,
    input  logic     rst_n,

    input  logic     in_valid,
    output logic     in_ready,
    input  byte_t    in_data,

    output logic     tx
);

    localparam int BAUD_DIV = CLK_FREQ_HZ / BAUD;
    localparam int CNT_W    = (BAUD_DIV <= 2) ? 1 : $clog2(BAUD_DIV);

    typedef enum logic [0:0] { S_IDLE, S_BUSY } st_e;
    st_e             state_q;

    logic [9:0]      packet_q;     // {stop=1, d7..d0, start=0}
    logic [3:0]      bit_idx_q;    // 0..9
    logic [CNT_W-1:0] cnt_q;
    logic            tx_q;

    assign in_ready = (state_q == S_IDLE);
    assign tx       = tx_q;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state_q   <= S_IDLE;
            packet_q  <= 10'b1111111111;
            bit_idx_q <= 4'd0;
            cnt_q     <= '0;
            tx_q      <= 1'b1;
        end else begin
            unique case (state_q)
                S_IDLE: begin
                    tx_q <= 1'b1;
                    if (in_valid) begin
                        packet_q  <= {1'b1, in_data, 1'b0};
                        tx_q      <= 1'b0;          // start bit on the wire
                        bit_idx_q <= 4'd0;
                        cnt_q     <= '0;
                        state_q   <= S_BUSY;
                    end
                end
                S_BUSY: begin
                    if (cnt_q == CNT_W'(BAUD_DIV - 1)) begin
                        cnt_q <= '0;
                        if (bit_idx_q == 4'd9) begin
                            // Stop bit just finished -- back to idle.
                            state_q <= S_IDLE;
                            tx_q    <= 1'b1;
                        end else begin
                            bit_idx_q <= bit_idx_q + 4'd1;
                            tx_q      <= packet_q[bit_idx_q + 4'd1];
                        end
                    end else begin
                        cnt_q <= cnt_q + 1'b1;
                    end
                end
            endcase
        end
    end

endmodule

`endif  // UART_TX_SV
