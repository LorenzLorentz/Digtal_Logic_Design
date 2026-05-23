// =====================================================================
// io_ps2_tx.sv  --  PS/2 host-to-device transmitter (one byte)
// ---------------------------------------------------------------------
// Sends a single command byte over the PS/2 bus using the standard
// host-to-device protocol:
//   1. Inhibit: hold CLK low for INHIBIT_US (~150 us).
//   2. Request-to-send: pull DATA low, release CLK.
//   3. Device starts clocking; on each falling CLK edge we present the
//      next data bit (LSB first).  Total 11 host-clocked bits:
//        start(0), d0..d7, parity(odd), stop(1).
//   4. Device acknowledges by pulling DATA low and pulsing CLK once;
//      we sample DATA on that 12th falling edge.
//
// Tri-state convention (open-drain w/ external pull-up):
//   _oe = 1  =>  high-Z (not driving, pulled high)
//   _oe = 0  =>  driving low
//
// After sending, cmd_ready pulses for one clk cycle and the module
// transits through S_DONE (one cycle, cmd_ready=0) before returning to
// S_IDLE. The S_DONE cooldown gives upstream a cycle to deassert
// cmd_valid before S_IDLE re-checks it; without it the combinational
// cmd_valid from io_mouse re-fires the same byte (each command would
// be transmitted twice).
//
// S_IDLE additionally requires the bus to be idle (both lines high for
// IDLE_STABLE_US continuous us) before launching, so a transmission
// cannot collide with the mouse's power-on BAT (~750 ms 0xAA 0x00) or
// any in-flight device->host frame.
// =====================================================================

`ifndef IO_PS2_TX_SV
`define IO_PS2_TX_SV

module io_ps2_tx
    import chat_pkg::*;
#(
    parameter int CLK_FREQ_HZ      = 100_000_000,
    parameter int INHIBIT_US       = 150,
    parameter int INHIBIT_TICKS    = CLK_FREQ_HZ / 1_000_000 * INHIBIT_US,
    // Per-edge timeout used as a loose watchdog for the device's
    // clocked phases (RTS start, ACK). Real PS/2 CLK period is
    // 60-125 us, so a few ms is plenty.
    parameter int EDGE_TIMEOUT_US  = 5_000,
    parameter int EDGE_TIMEOUT_TICKS = CLK_FREQ_HZ / 1_000_000 * EDGE_TIMEOUT_US,
    // Bus must be idle this long before S_IDLE accepts a new cmd.
    parameter int IDLE_STABLE_US   = 1_000,
    parameter int IDLE_STABLE_TICKS = CLK_FREQ_HZ / 1_000_000 * IDLE_STABLE_US
) (
    input  logic clk,
    input  logic rst_n,

    // Command interface
    input  logic       cmd_valid,
    output logic       cmd_ready,
    input  logic [7:0] cmd_data,

    // PS/2 tri-state pins (open-drain, external pull-up)
    inout  logic       ps2_clk,
    inout  logic       ps2_data
);

    // Ensure tick counts >= 1 so cnt comparisons aren't constant-zero
    // when CLK_FREQ_HZ is overridden to a tiny value in simulation.
    localparam int L_INHIBIT     = (INHIBIT_TICKS    > 0) ? INHIBIT_TICKS    : 1;
    localparam int L_EDGE_TO     = (EDGE_TIMEOUT_TICKS > 0) ? EDGE_TIMEOUT_TICKS : 1;
    localparam int L_IDLE_STABLE = (IDLE_STABLE_TICKS > 0) ? IDLE_STABLE_TICKS : 1;

    // Wide enough for the largest of the three timeouts.
    localparam int CNT_W      = $clog2((L_INHIBIT > L_EDGE_TO ? L_INHIBIT : L_EDGE_TO) + 2);
    localparam int IDLE_CNT_W = $clog2(L_IDLE_STABLE + 2);

    // -----------------------------------------------------------------
    // FSM
    // -----------------------------------------------------------------
    typedef enum logic [2:0] {
        S_IDLE     = 3'd0,
        S_INHIBIT  = 3'd1,
        S_RTS      = 3'd2,
        S_SHIFT    = 3'd3,
        S_STOP     = 3'd4,
        S_ACK      = 3'd5,
        S_DONE     = 3'd6   // 1-cycle cooldown so cmd_valid can drop
    } state_e;

    state_e state_q;

    logic [CNT_W-1:0]      cnt_q;
    logic [IDLE_CNT_W-1:0] idle_cnt_q;
    logic                  idle_stable_q;

    // Shift register: holds {parity, d7..d0, start_bit}.
    /* verilator lint_off UNUSEDSIGNAL */
    logic [9:0]  shift_q;
    /* verilator lint_on UNUSEDSIGNAL */
    logic [3:0]  bit_cnt_q;

    // Tri-state controls: 1 = high-Z (released), 0 = drive low.
    logic clk_oe, data_oe;
    assign ps2_clk  = clk_oe  ? 1'bz : 1'b0;
    assign ps2_data = data_oe ? 1'bz : 1'b0;

    // Synchronisers (idle high -> RST_VAL=1)
    logic clk_s, data_s;
    sync_2ff #(.RST_VAL(1'b1)) u_sync_clk (
        .clk(clk), .rst_n(rst_n), .async_in(ps2_clk),  .sync_out(clk_s)
    );
    sync_2ff #(.RST_VAL(1'b1)) u_sync_data (
        .clk(clk), .rst_n(rst_n), .async_in(ps2_data), .sync_out(data_s)
    );

    // Falling-edge detector on synchronised CLK.
    logic clk_prev;
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) clk_prev <= 1'b1;
        else        clk_prev <= clk_s;
    end
    logic clk_fall;
    assign clk_fall = clk_prev && !clk_s;

    // Shift: LSB first.
    logic [9:0] shift_next;
    assign shift_next = {1'b0, shift_q[9:1]};

    // -----------------------------------------------------------------
    // Idle-line tracker (independent of state).
    // Counts how long both lines have been high. idle_stable_q latches
    // high once the count saturates, drops the moment either line dips.
    // -----------------------------------------------------------------
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            idle_cnt_q    <= '0;
            idle_stable_q <= 1'b0;
        end else if (clk_s && data_s) begin
            if (idle_cnt_q == IDLE_CNT_W'(L_IDLE_STABLE - 1)) begin
                idle_stable_q <= 1'b1;
            end else begin
                idle_cnt_q <= idle_cnt_q + IDLE_CNT_W'(1);
            end
        end else begin
            idle_cnt_q    <= '0;
            idle_stable_q <= 1'b0;
        end
    end

    // -----------------------------------------------------------------
    // TX FSM
    // -----------------------------------------------------------------
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state_q    <= S_IDLE;
            cnt_q      <= '0;
            shift_q    <= '0;
            bit_cnt_q  <= '0;
            cmd_ready  <= 1'b0;
            clk_oe     <= 1'b1;
            data_oe    <= 1'b1;
        end else begin
            cmd_ready <= 1'b0;

            case (state_q)
                // ---------------------------------------------------------
                // S_IDLE: bus released. Wait for cmd_valid AND a stably
                // idle bus before launching. Without idle_stable_q the
                // host can clobber the mouse's BAT output on power-up.
                // ---------------------------------------------------------
                S_IDLE: begin
                    clk_oe  <= 1'b1;
                    data_oe <= 1'b1;
                    if (cmd_valid && idle_stable_q) begin
                        shift_q   <= {~(^cmd_data), cmd_data, 1'b0};
                        bit_cnt_q <= '0;
                        cnt_q     <= '0;
                        clk_oe    <= 1'b0;     // pull CLK low: inhibit
                        data_oe   <= 1'b1;
                        state_q   <= S_INHIBIT;
                    end
                end

                // ---------------------------------------------------------
                // S_INHIBIT: hold CLK low for >=100 us. After expiry, pull
                // DATA low (start bit on the bus) and release CLK.
                // ---------------------------------------------------------
                S_INHIBIT: begin
                    if (cnt_q == CNT_W'(L_INHIBIT - 1)) begin
                        data_oe <= 1'b0;
                        clk_oe  <= 1'b1;
                        cnt_q   <= '0;
                        state_q <= S_RTS;
                    end else begin
                        cnt_q <= cnt_q + CNT_W'(1);
                    end
                end

                // ---------------------------------------------------------
                // S_RTS: wait for the device's first falling clk edge
                // (it samples our start bit then). On that edge, present
                // d0 on DATA for the *next* edge -- this is the bit that
                // used to be dropped (data_oe was being held at the
                // start-bit value across the high-CLK gap between edge 1
                // and edge 2, so the device sampled the start bit again
                // instead of d0).
                // ---------------------------------------------------------
                S_RTS: begin
                    if (clk_fall) begin
                        data_oe   <= shift_q[1];  // d0 -- FIX vs. old code
                        shift_q   <= shift_next;
                        bit_cnt_q <= bit_cnt_q + 4'd1;
                        cnt_q     <= '0;
                        state_q   <= S_SHIFT;
                    end else if (cnt_q == CNT_W'(L_EDGE_TO - 1)) begin
                        // Device never clocked -- bail out.
                        clk_oe    <= 1'b1;
                        data_oe   <= 1'b1;
                        cmd_ready <= 1'b1;
                        state_q   <= S_DONE;
                    end else begin
                        cnt_q <= cnt_q + CNT_W'(1);
                    end
                end

                // ---------------------------------------------------------
                // S_SHIFT: drive d1..d7 then parity on each successive
                // falling edge. On the edge where bit_cnt==9 (parity has
                // just been sampled), release DATA for the stop bit.
                // ---------------------------------------------------------
                S_SHIFT: begin
                    if (clk_fall) begin
                        if (bit_cnt_q == 4'd9) begin
                            data_oe <= 1'b1;       // stop bit
                            state_q <= S_STOP;
                        end else begin
                            data_oe   <= shift_q[1];
                            shift_q   <= shift_next;
                            bit_cnt_q <= bit_cnt_q + 4'd1;
                        end
                    end
                end

                // ---------------------------------------------------------
                // S_STOP: stop bit is on the bus; one more falling edge
                // and the device samples it.
                // ---------------------------------------------------------
                S_STOP: begin
                    if (clk_fall) begin
                        cnt_q   <= '0;
                        state_q <= S_ACK;
                    end
                end

                // ---------------------------------------------------------
                // S_ACK: device pulls DATA low and pulses CLK once. Wait
                // for that falling edge before declaring done so we don't
                // re-arm S_IDLE while the bus is still mid-ACK. Times out
                // gracefully if the device skips ACK.
                // ---------------------------------------------------------
                S_ACK: begin
                    if (clk_fall) begin
                        cmd_ready <= 1'b1;
                        state_q   <= S_DONE;
                    end else if (cnt_q == CNT_W'(L_EDGE_TO - 1)) begin
                        cmd_ready <= 1'b1;
                        state_q   <= S_DONE;
                    end else begin
                        cnt_q <= cnt_q + CNT_W'(1);
                    end
                end

                // ---------------------------------------------------------
                // S_DONE: one-cycle cooldown. cmd_ready was set in S_ACK
                // and is now back to 0 (default at the top of the always
                // block). Going through here gives the upstream FSM a
                // cycle to deassert cmd_valid before S_IDLE re-samples
                // it; without this, io_mouse's combinational cmd_valid
                // would still be high and we'd retransmit the same byte.
                // ---------------------------------------------------------
                S_DONE: begin
                    clk_oe  <= 1'b1;
                    data_oe <= 1'b1;
                    state_q <= S_IDLE;
                end

                default: state_q <= S_IDLE;
            endcase
        end
    end

endmodule

`endif  // IO_PS2_TX_SV
