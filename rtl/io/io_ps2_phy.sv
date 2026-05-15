// =====================================================================
// io_ps2_phy.sv  --  PS/2 device-to-host frame deserialiser
// ---------------------------------------------------------------------
// PS/2 (set 2 / receive direction) frame:
//   [start=0] [d0] [d1] [d2] [d3] [d4] [d5] [d6] [d7] [parity_odd] [stop=1]
//
// The device drives both PS/2 CLK and DATA. Both lines idle high. The
// host samples DATA on each FALLING edge of CLK. PS/2 CLK is 10-16.7
// kHz so we treat both pins as fully asynchronous w.r.t. our 100 MHz
// clock and feed them through a 2-FF synchroniser before edge-detect.
//
// What this module does:
//   - 2-FF sync ps2_clk / ps2_data into the local domain.
//   - Detect ps2_clk falling edges.
//   - On each falling edge, shift the synced ps2_data into a 11-bit
//     register (LSB-first as the device sends them).
//   - On the 11th edge, validate start bit (must be 0), stop bit (must
//     be 1), and odd parity over the 8 data bits. If valid, pulse
//     byte_valid for one local cycle with byte_data; otherwise pulse
//     frame_error.
//
// Inter-bit watchdog:
//   If the device stalls mid-frame longer than TIMEOUT_CYCLES local
//   cycles, we abandon the partial frame (bit_count_q / shift_q both
//   clear to 0). Without this the FSM stays stuck partway and the next
//   real start bit gets interpreted as a stale data bit, sometimes
//   producing a parity-passing garbage byte. Default ~100 us @ 100 MHz;
//   must exceed the slowest expected PS/2 bit time (~83 us @ 12 kHz).
//
// Notably out of scope:
//   - Host-to-device direction (LED command, set rate). The user has
//     confirmed receive-only is fine.
// =====================================================================

`ifndef IO_PS2_PHY_SV
`define IO_PS2_PHY_SV

module io_ps2_phy
    import chat_pkg::*;
#(
    parameter int TIMEOUT_CYCLES = 10000
) (
    input  logic    clk,
    input  logic    rst_n,

    // Asynchronous PS/2 pins from the device
    input  logic    ps2_clk,
    input  logic    ps2_data,

    // Synchronous byte stream out
    output logic    byte_valid,    // 1-cycle pulse with byte_data
    output byte_t   byte_data,
    output logic    frame_error    // 1-cycle pulse on a bad frame
);

    // -----------------------------------------------------------------
    // Synchronisers (PS/2 lines idle high -> RST_VAL=1).
    // -----------------------------------------------------------------
    logic ps2_clk_s, ps2_data_s;

    sync_2ff #(.RST_VAL(1'b1)) u_sync_clk (
        .clk      (clk),
        .rst_n    (rst_n),
        .async_in (ps2_clk),
        .sync_out (ps2_clk_s)
    );

    sync_2ff #(.RST_VAL(1'b1)) u_sync_data (
        .clk      (clk),
        .rst_n    (rst_n),
        .async_in (ps2_data),
        .sync_out (ps2_data_s)
    );

    // -----------------------------------------------------------------
    // Falling-edge detector on the synchronised PS/2 CLK.
    // -----------------------------------------------------------------
    logic ps2_clk_prev;
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) ps2_clk_prev <= 1'b1;
        else        ps2_clk_prev <= ps2_clk_s;
    end

    logic ps2_clk_fall;
    assign ps2_clk_fall = ps2_clk_prev && !ps2_clk_s;

    // -----------------------------------------------------------------
    // Shift register and bit counter.
    //
    // shift_q stores positions 10..1 of the frame (10 bits). On each
    // falling edge we form shift_next = {new_bit, shift_q[10:1]} as an
    // 11-bit value; this is the FULL window we validate against, and
    // its bottom bit shift_next[0] catches the start bit just as it
    // would fall off the chain. shift_q itself never needs a slot 0
    // (the start bit isn't stored after validation).
    //
    // Layout of shift_next at the 11th falling edge:
    //   shift_next[10] = stop bit (just arrived, must be 1)
    //   shift_next[9]  = parity bit (must satisfy odd parity)
    //   shift_next[8:1]= data byte (LSB of byte at [1], MSB at [8])
    //   shift_next[0]  = start bit (must be 0)
    // -----------------------------------------------------------------
    logic [10:1] shift_q;
    logic [3:0]  bit_count_q;

    logic [10:0] shift_next;
    assign shift_next = {ps2_data_s, shift_q[10:1]};

    // Inter-bit watchdog. Counts local-clock cycles since the last
    // ps2_clk falling edge; if it expires mid-frame, abandon the frame.
    localparam int TIMEOUT_W = $clog2(TIMEOUT_CYCLES + 1);
    logic [TIMEOUT_W-1:0] timeout_cnt_q;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            shift_q       <= '0;
            bit_count_q   <= '0;
            timeout_cnt_q <= '0;
            byte_valid    <= 1'b0;
            byte_data     <= '0;
            frame_error   <= 1'b0;
        end else begin
            byte_valid  <= 1'b0;
            frame_error <= 1'b0;

            if (ps2_clk_fall) begin
                timeout_cnt_q <= '0;
                shift_q       <= shift_next[10:1];

                if (bit_count_q == 4'd10) begin
                    // 11th bit just arrived; check the assembled frame.
                    if ((shift_next[0]  == 1'b0)
                     && (shift_next[10] == 1'b1)
                     && (shift_next[9]  == ~^shift_next[8:1])) begin
                        byte_valid <= 1'b1;
                        byte_data  <= shift_next[8:1];
                    end else begin
                        frame_error <= 1'b1;
                    end
                    bit_count_q <= '0;
                end else begin
                    bit_count_q <= bit_count_q + 4'd1;
                end
            end else if (bit_count_q != '0) begin
                // Mid-frame stall. Count up; on expiry abandon the
                // partial frame so the next start bit lands cleanly.
                if (timeout_cnt_q == TIMEOUT_W'(TIMEOUT_CYCLES - 1)) begin
                    shift_q       <= '0;
                    bit_count_q   <= '0;
                    timeout_cnt_q <= '0;
                end else begin
                    timeout_cnt_q <= timeout_cnt_q + 1'b1;
                end
            end
        end
    end

endmodule

`endif  // IO_PS2_PHY_SV
