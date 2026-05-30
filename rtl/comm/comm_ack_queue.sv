// =====================================================================
// comm_ack_queue.sv  --  Pending-ACK queue (thin handshake_fifo wrapper)
// ---------------------------------------------------------------------
// rx_fsm enqueues a {arq, seq} pair to ACK; tx_arbiter dequeues when
// the link is free to send a control frame. Depth 2 is plenty: at the
// link rates we use, an outgoing ACK takes ~5 byte-times and incoming
// frames are spaced >70 byte-times apart, so back-pressure on the
// queue should never trigger.
// =====================================================================

`ifndef COMM_ACK_QUEUE_SV
`define COMM_ACK_QUEUE_SV

module comm_ack_queue
    import chat_pkg::*;
#(
    parameter int DEPTH = 2
) (
    input  logic   clk,
    input  logic   rst_n,

    input  logic   in_valid,
    output logic   in_ready,
    input  seq_t   in_seq,
    input  logic   in_arq,

    output logic   out_valid,
    input  logic   out_ready,
    output seq_t   out_seq,
    output logic   out_arq
);

    localparam int ACK_FIFO_W = SEQ_WIDTH + 1;  // {arq, seq}

    logic [ACK_FIFO_W-1:0] in_data, out_data;
    assign in_data  = {in_arq, in_seq};
    assign out_arq  = out_data[ACK_FIFO_W-1];
    assign out_seq  = out_data[SEQ_WIDTH-1:0];

    handshake_fifo #(
        .WIDTH (ACK_FIFO_W),
        .DEPTH (DEPTH)
    ) u_fifo (
        .clk       (clk),
        .rst_n     (rst_n),
        .in_valid  (in_valid),
        .in_ready  (in_ready),
        .in_data   (in_data),
        .out_valid (out_valid),
        .out_ready (out_ready),
        .out_data  (out_data)
    );

endmodule

`endif  // COMM_ACK_QUEUE_SV
