// =====================================================================
// sync_2ff.sv  --  Generic N-stage flop synchronizer
// ---------------------------------------------------------------------
// Standard async-input -> safe synchronous output. Default 2 stages,
// which is the textbook MTBF tradeoff for low-frequency async signals
// (PS/2 CLK at <50 kHz, button presses, etc.).
//
// Use:
//   sync_2ff #(.RST_VAL(1'b1)) u_sync (
//       .clk, .rst_n,
//       .async_in (raw_pin),
//       .sync_out (clean)
//   );
//
// RST_VAL is the value the chain takes on async reset; choose to match
// the line's idle-high or idle-low convention so reset doesn't look
// like a fake edge.
// =====================================================================

`ifndef SYNC_2FF_SV
`define SYNC_2FF_SV

module sync_2ff #(
    parameter int   N_STAGES = 2,
    parameter logic RST_VAL  = 1'b0
) (
    input  logic clk,
    input  logic rst_n,
    input  logic async_in,
    output logic sync_out
);

    // SYNCASYNCNET fires when this primitive is used as a reset
    // synchroniser (async_in tied to 1'b1 with the async reset port
    // driving the actual reset signal). That is the textbook reset-
    // sync pattern -- the warning is informational, not a bug.
    /* verilator lint_off SYNCASYNCNET */
    logic [N_STAGES-1:0] sync_q;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) sync_q <= {N_STAGES{RST_VAL}};
        else        sync_q <= {sync_q[N_STAGES-2:0], async_in};
    end
    /* verilator lint_on SYNCASYNCNET */

    assign sync_out = sync_q[N_STAGES-1];

endmodule

`endif  // SYNC_2FF_SV
