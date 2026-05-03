// =====================================================================
// handshake_fifo.sv  --  Generic synchronous valid/ready FIFO
// ---------------------------------------------------------------------
// Simple circular-buffer FIFO with standard valid/ready handshakes on
// both ends.
//
// Producer side (in_*):
//   - Writes complete on cycles where (in_valid && in_ready) is high
//     at the rising edge.
//   - in_ready is high iff the FIFO is not full.
//
// Consumer side (out_*):
//   - Reads complete on cycles where (out_valid && out_ready) is high.
//   - out_valid is high iff the FIFO is not empty.
//   - out_data is the head entry (combinational read of mem[rd_ptr]).
//
// Sizing:
//   - DEPTH must be a power of 2 (we use a (clog2(DEPTH)+1)-bit pointer
//     pair to distinguish full from empty).
//
// Concurrent in+out at the same cycle is supported. Reset clears both
// pointers; mem contents are don't-care.
// =====================================================================

`ifndef HANDSHAKE_FIFO_SV
`define HANDSHAKE_FIFO_SV

module handshake_fifo #(
    parameter int WIDTH = 8,
    parameter int DEPTH = 16   // must be a power of 2
) (
    input  logic              clk,
    input  logic              rst_n,

    // Producer
    input  logic              in_valid,
    output logic              in_ready,
    input  logic [WIDTH-1:0]  in_data,

    // Consumer
    output logic              out_valid,
    input  logic              out_ready,
    output logic [WIDTH-1:0]  out_data
);

    localparam int IDX_W = $clog2(DEPTH);

    logic [WIDTH-1:0] mem [DEPTH];

    // (IDX_W+1)-bit pointers: the lower IDX_W bits are the memory
    // address, the top bit is a wrap-parity tag so that
    //   wr == rd                  -> empty
    //   wr[low]==rd[low] and wr[top]!=rd[top] -> full
    logic [IDX_W:0] wr_ptr_q;
    logic [IDX_W:0] rd_ptr_q;

    logic empty, full;
    assign empty = (wr_ptr_q == rd_ptr_q);
    assign full  = (wr_ptr_q[IDX_W-1:0] == rd_ptr_q[IDX_W-1:0])
                && (wr_ptr_q[IDX_W]     != rd_ptr_q[IDX_W]);

    // Concurrent read forwards capacity to the producer in the same
    // cycle: when full but the consumer is also reading, in_ready
    // still goes high so the next entry can land.
    logic do_rd;
    assign do_rd = !empty && out_ready;

    assign in_ready  = !full || do_rd;
    assign out_valid = !empty;
    assign out_data  = mem[rd_ptr_q[IDX_W-1:0]];

    logic do_wr;
    assign do_wr = in_valid && in_ready;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            wr_ptr_q <= '0;
            rd_ptr_q <= '0;
        end else begin
            if (do_wr) begin
                mem[wr_ptr_q[IDX_W-1:0]] <= in_data;
                wr_ptr_q <= wr_ptr_q + 1'b1;
            end
            if (do_rd) begin
                rd_ptr_q <= rd_ptr_q + 1'b1;
            end
        end
    end

endmodule

`endif  // HANDSHAKE_FIFO_SV
