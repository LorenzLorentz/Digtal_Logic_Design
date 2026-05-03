// =====================================================================
// comm_tx_arbiter.sv  --  ACK > frame_req TX-side arbiter
// ---------------------------------------------------------------------
// Combinational mux that drives the encoder's frame request from
// either the ACK queue (priority) or the tx_fsm. Pure pass-through:
//
//   - When ack_q has a pending ACK, the encoder sees a synthesised
//     ACK frame (type=FRAME_ACK, len=0, payload=0, seq=ack_q_seq).
//     The handshake fires when the encoder is ready, and the same
//     cycle dequeues the ACK from the queue.
//   - Otherwise tx_fsm's request is forwarded verbatim.
//   - When neither has work, the encoder sees frame_req_valid=0.
//
// Encoder accepts only at frame boundaries (frame_req_ready high in
// its IDLE), so swapping the source mid-frame can't happen.
// =====================================================================

`ifndef COMM_TX_ARBITER_SV
`define COMM_TX_ARBITER_SV

module comm_tx_arbiter
    import chat_pkg::*;
(
    // ---- ACK queue (priority source) ----
    input  logic                          ack_q_valid,
    output logic                          ack_q_ready,
    input  seq_t                          ack_q_seq,

    // ---- tx_fsm (regular source) ----
    input  logic                          tx_req_valid,
    output logic                          tx_req_ready,
    input  logic [2:0]                    tx_req_type,
    input  seq_t                          tx_req_seq,
    input  msg_len_t                      tx_req_len,
    input  logic [MAX_MSG_LEN*8-1:0]      tx_req_payload,

    // ---- to encoder ----
    output logic                          enc_valid,
    input  logic                          enc_ready,
    output logic [2:0]                    enc_type,
    output seq_t                          enc_seq,
    output msg_len_t                      enc_len,
    output logic [MAX_MSG_LEN*8-1:0]      enc_payload
);

    logic ack_wins;
    assign ack_wins = ack_q_valid;

    // Drive encoder request.
    assign enc_valid    = ack_wins ? 1'b1 : tx_req_valid;
    assign enc_type     = ack_wins ? 3'(FRAME_ACK)        : tx_req_type;
    assign enc_seq      = ack_wins ? ack_q_seq            : tx_req_seq;
    assign enc_len      = ack_wins ? '0                   : tx_req_len;
    assign enc_payload  = ack_wins ? '0                   : tx_req_payload;

    // Drain the chosen source on a successful encoder handshake.
    assign ack_q_ready  = ack_wins  && enc_ready;
    assign tx_req_ready = !ack_wins && enc_ready;

endmodule

`endif  // COMM_TX_ARBITER_SV
