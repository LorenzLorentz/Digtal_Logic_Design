// =====================================================================
// uart_rx.sv  --  Asynchronous serial receiver (8N1)
// ---------------------------------------------------------------------
// 8 data bits, no parity, 1 stop bit. LSB first.
//
// Sampling strategy ("16x oversample equivalent"):
//   - 2-FF synchroniser on the rx pin, RST_VAL=1 to match line idle.
//   - When rx_s drops to 0 in IDLE, that's a candidate start bit.
//     Wait BAUD_DIV/2 cycles and re-sample to catch glitches; if still
//     0, lock into the bit cadence.
//   - From there, sample at the centre of each subsequent bit (every
//     BAUD_DIV cycles). This gives ~half-bit timing tolerance.
//   - At the end of the stop-bit window, if rx_s == 1 emit byte_valid
//     for one cycle with byte_data. If rx_s == 0, emit frame_error
//     instead and drop the byte.
//
// One-cycle pulse outputs; downstream uses `byte_valid` like the io
// stack does for ev_valid (no back-pressure).
// =====================================================================

`ifndef UART_RX_SV
`define UART_RX_SV

module uart_rx
    import chat_pkg::*;
#(
    parameter int CLK_FREQ_HZ = CLK_FREQ_HZ_DEFAULT,
    parameter int BAUD        = UART_BAUD_DEFAULT
) (
    input  logic     clk,
    input  logic     rst_n,

    input  logic     rx,                  // async pin

    output logic     byte_valid,          // 1-cycle pulse
    output byte_t    byte_data,
    output logic     frame_error          // 1-cycle pulse on bad stop
);

    localparam int BAUD_DIV = CLK_FREQ_HZ / BAUD;
    localparam int HALF_DIV = BAUD_DIV / 2;
    localparam int CNT_W    = (BAUD_DIV <= 2) ? 1 : $clog2(BAUD_DIV);

    // -----------------------------------------------------------------
    // Synchroniser (idle-high)
    // -----------------------------------------------------------------
    logic rx_s;
    sync_2ff #(.RST_VAL(1'b1)) u_sync (
        .clk      (clk),
        .rst_n    (rst_n),
        .async_in (rx),
        .sync_out (rx_s)
    );

    // -----------------------------------------------------------------
    // Receive FSM
    // -----------------------------------------------------------------
    typedef enum logic [1:0] {
        S_IDLE,
        S_START,
        S_DATA,
        S_STOP
    } st_e;

    st_e               state_q;
    logic [CNT_W-1:0]  cnt_q;
    logic [2:0]        bit_idx_q;
    logic [7:0]        shift_q;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state_q     <= S_IDLE;
            cnt_q       <= '0;
            bit_idx_q   <= 3'd0;
            shift_q     <= 8'd0;
            byte_valid  <= 1'b0;
            byte_data   <= 8'd0;
            frame_error <= 1'b0;
        end else begin
            byte_valid  <= 1'b0;
            frame_error <= 1'b0;

            unique case (state_q)
                S_IDLE: begin
                    // Synced rx low = candidate start.
                    if (rx_s == 1'b0) begin
                        state_q <= S_START;
                        cnt_q   <= '0;
                    end
                end

                S_START: begin
                    // Re-sample at the centre of the start bit.
                    if (cnt_q == CNT_W'(HALF_DIV - 1)) begin
                        cnt_q <= '0;
                        if (rx_s == 1'b0) begin
                            state_q   <= S_DATA;
                            bit_idx_q <= 3'd0;
                        end else begin
                            // Glitch -- abort, return to idle.
                            state_q <= S_IDLE;
                        end
                    end else begin
                        cnt_q <= cnt_q + 1'b1;
                    end
                end

                S_DATA: begin
                    if (cnt_q == CNT_W'(BAUD_DIV - 1)) begin
                        cnt_q   <= '0;
                        // LSB first: rotate new bit into the MSB and
                        // shift right; after 8 samples, shift_q[7:0]
                        // = data byte LSB at bit 0.
                        shift_q <= {rx_s, shift_q[7:1]};
                        if (bit_idx_q == 3'd7) begin
                            state_q <= S_STOP;
                        end else begin
                            bit_idx_q <= bit_idx_q + 3'd1;
                        end
                    end else begin
                        cnt_q <= cnt_q + 1'b1;
                    end
                end

                S_STOP: begin
                    if (cnt_q == CNT_W'(BAUD_DIV - 1)) begin
                        cnt_q   <= '0;
                        state_q <= S_IDLE;
                        if (rx_s == 1'b1) begin
                            byte_valid <= 1'b1;
                            byte_data  <= shift_q;
                        end else begin
                            frame_error <= 1'b1;
                        end
                    end else begin
                        cnt_q <= cnt_q + 1'b1;
                    end
                end
            endcase
        end
    end

endmodule

`endif  // UART_RX_SV
