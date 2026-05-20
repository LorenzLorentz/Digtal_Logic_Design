// =====================================================================
// io_ps2_tx.sv  --  PS/2 host-to-device transmitter (one byte)
// ---------------------------------------------------------------------
// Sends a single command byte over the PS/2 bus using the standard
// host-to-device protocol:
//   1. Inhibit: hold CLK low for INHIBIT_US (~150 us).
//   2. Request-to-send: pull DATA low, release CLK.
//   3. Device starts clocking; on each falling CLK edge we present the
//      next data bit (LSB first).  Total 10 host bits:
//        start(0), d0..d7, parity(odd).
//   4. Stop: release DATA (goes high via pull-up).
//   5. Device acknowledges by pulling DATA low for one clock cycle.
//
// Tri-state convention (open-drain w/ external pull-up):
//   _oe = 1  =>  high-Z (not driving, pulled high)
//   _oe = 0  =>  driving low
//
// After sending, cmd_ready pulses for one clk cycle and the module
// returns to IDLE.  The caller waits for cmd_ready before queueing
// the next byte.
// =====================================================================

`ifndef IO_PS2_TX_SV
`define IO_PS2_TX_SV

module io_ps2_tx
    import chat_pkg::*;
#(
    parameter int CLK_FREQ_HZ   = 100_000_000,
    parameter int INHIBIT_US    = 150,
    parameter int INHIBIT_TICKS = CLK_FREQ_HZ / 1_000_000 * INHIBIT_US,
    parameter int RTS_TIMEOUT_US = 15_000,
    parameter int RTS_TICKS     = CLK_FREQ_HZ / 1_000_000 * RTS_TIMEOUT_US
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

    // Ensure ticks >= 1 so cnt comparisons are not constant-zero
    // when CLK_FREQ_HZ is overridden to a tiny value in simulation.
    localparam int L_INHIBIT = (INHIBIT_TICKS > 0) ? INHIBIT_TICKS : 1;
    localparam int L_RTS     = (RTS_TICKS > 0)     ? RTS_TICKS     : 1;

    // -----------------------------------------------------------------
    // FSM
    // -----------------------------------------------------------------
    typedef enum logic [2:0] {
        S_IDLE     = 3'd0,
        S_INHIBIT  = 3'd1,
        S_RTS      = 3'd2,
        S_SHIFT    = 3'd3,
        S_STOP     = 3'd4,
        S_ACK      = 3'd5
    } state_e;

    state_e state_q;

    // Fixed-width counter (16 bits, handles all clock freq overrides).
    logic [15:0] cnt_q;

    // Shift register: holds {parity, d7..d0, start_bit}
    /* verilator lint_off UNUSEDSIGNAL */
    logic [9:0]  shift_q;
    /* verilator lint_on UNUSEDSIGNAL */
    logic [3:0]  bit_cnt_q;

    // Tri-state controls: 1 = high-Z (released), 0 = drive low
    logic clk_oe, data_oe;
    assign ps2_clk  = clk_oe  ? 1'bz : 1'b0;
    assign ps2_data = data_oe ? 1'bz : 1'b0;

    // Synchronised read of CLK (for edge detect)
    logic clk_s;
    sync_2ff #(.RST_VAL(1'b1)) u_sync_clk (
        .clk(clk), .rst_n(rst_n), .async_in(ps2_clk), .sync_out(clk_s)
    );

    // Falling-edge detector on synchronised CLK
    logic clk_prev;
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) clk_prev <= 1'b1;
        else        clk_prev <= clk_s;
    end
    logic clk_fall;
    assign clk_fall = clk_prev && !clk_s;

    // Shift: LSB first
    logic [9:0] shift_next;
    assign shift_next = {1'b0, shift_q[9:1]};

    // -----------------------------------------------------------------
    // Sequential logic
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
                S_IDLE: begin
                    clk_oe  <= 1'b1;
                    data_oe <= 1'b1;
                    if (cmd_valid) begin
                        shift_q   <= {~(^cmd_data), cmd_data, 1'b0};
                        bit_cnt_q <= '0;
                        cnt_q     <= '0;
                        clk_oe    <= 1'b0;
                        data_oe   <= 1'b1;
                        state_q   <= S_INHIBIT;
                    end
                end

                S_INHIBIT: begin
                    if (cnt_q >= 16'(L_INHIBIT)) begin
                        data_oe <= 1'b0;
                        clk_oe  <= 1'b1;
                        cnt_q   <= '0;
                        state_q <= S_RTS;
                    end else begin
                        cnt_q <= cnt_q + 16'd1;
                    end
                end

                S_RTS: begin
                    if (clk_fall) begin
                        shift_q   <= shift_next;
                        bit_cnt_q <= bit_cnt_q + 4'd1;
                        state_q   <= S_SHIFT;
                    end else if (cnt_q >= 16'(L_RTS)) begin
                        clk_oe    <= 1'b1;
                        data_oe   <= 1'b1;
                        cmd_ready <= 1'b1;
                        state_q   <= S_IDLE;
                    end else begin
                        cnt_q <= cnt_q + 16'd1;
                    end
                end

                S_SHIFT: begin
                    if (clk_fall) begin
                        if (bit_cnt_q == 4'd9) begin
                            data_oe <= 1'b1;
                            state_q <= S_STOP;
                        end else begin
                            data_oe   <= shift_q[1];
                            shift_q   <= shift_next;
                            bit_cnt_q <= bit_cnt_q + 4'd1;
                        end
                    end
                end

                S_STOP: begin
                    if (clk_fall)
                        state_q <= S_ACK;
                end

                S_ACK: begin
                    clk_oe    <= 1'b1;
                    data_oe   <= 1'b1;
                    cmd_ready <= 1'b1;
                    state_q   <= S_IDLE;
                end

                default: state_q <= S_IDLE;
            endcase
        end
    end

endmodule

`endif  // IO_PS2_TX_SV
