// =====================================================================
// comm_rx_fsm.sv  --  ARQ RX side
// ---------------------------------------------------------------------
// Pulls decoded frames from comm_frame_decoder and routes them:
//
//   ACK / NAK frames:    pulse tx_ack_valid (notifies tx_fsm).
//                        No backend delivery, no ACK enqueue.
//   DATA frames:         apply ARQ alternating-bit duplicate filter
//                        (frame_in_arq from TYPE[7]).
//                        Match  -> deliver to backend, enqueue ACK,
//                                  toggle expected_rx_arq_q.
//                        Dup    -> enqueue ACK only.
//   Control frames:      HELLO / REHELLO / USERNAME / GOODBYE / RECALL always
//   (HELLO etc.)         deliver to backend AND enqueue ACK; the
//                        expected_rx_arq_q counter is NOT consulted.
//                        Rationale: a peer reboot resets its tx arq,
//                        and we don't want a stale expected to
//                        treat the post-boot HELLO as a duplicate.
//                        Idempotent at backend (re-running HELLO/etc.
//                        triggers the same response, no harm).
//
// Per-frame work is sequential:
//   accept frame -> latch -> deliver_be (if not dup) -> queue_ack -> idle
//
// frame_in_ready is high only in IDLE so the decoder back-pressures
// while we're working a frame. (uart_rx supplies bytes about every
// 10*BAUD_DIV cycles so this never accumulates.)
// =====================================================================

`ifndef COMM_RX_FSM_SV
`define COMM_RX_FSM_SV

module comm_rx_fsm
    import chat_pkg::*;
(
    input  logic                          clk,
    input  logic                          rst_n,

    // ---- decoder -> rx_fsm ----
    input  logic                          frame_in_valid,
    output logic                          frame_in_ready,
    input  logic [2:0]                    frame_in_type,
    input  logic                          frame_in_arq,    // ARQ alternating bit from TYPE[7]
    input  seq_t                          frame_in_seq,    // msg_id (full 8 bits)
    input  msg_len_t                      frame_in_len,
    input  logic [MAX_MSG_LEN*8-1:0]      frame_in_payload,

    // ---- rx_fsm -> backend (cm_rx) ----
    output logic                          cm_rx_valid,
    input  logic                          cm_rx_ready,
    output logic [2:0]                    cm_rx_frame_type,
    output seq_t                          cm_rx_seq,       // msg_id to backend
    output msg_len_t                      cm_rx_len,
    output logic [MAX_MSG_LEN*8-1:0]      cm_rx_payload,

    // ---- rx_fsm -> ack_queue ----
    output logic                          ack_q_valid,
    input  logic                          ack_q_ready,
    output seq_t                          ack_q_seq,
    output logic                          ack_q_arq,

    // ---- rx_fsm -> tx_fsm (ACK notification) ----
    output logic                          tx_ack_valid,    // 1-cycle pulse
    output seq_t                          tx_ack_seq,
    output logic                          tx_ack_arq
);

    // -----------------------------------------------------------------
    // FSM
    // -----------------------------------------------------------------
    typedef enum logic [1:0] {
        S_IDLE,
        S_DELIVER_BE,
        S_QUEUE_ACK
    } st_e;
    st_e state_q, state_d;

    // Latched fields
    logic [2:0]                  type_q;
    logic                        arq_q;
    seq_t                        seq_q;
    msg_len_t                    len_q;
    logic [MAX_MSG_LEN*8-1:0]    payload_q;
    logic                        expected_rx_arq_q;   // ARQ alternating bit
    logic                        dup_q;

    // -----------------------------------------------------------------
    // Frame-type aliases (combinational, off frame_in_type)
    // -----------------------------------------------------------------
    logic frame_is_ack, frame_is_data, frame_is_control;
    assign frame_is_ack     = (frame_in_type == 3'(FRAME_ACK))
                           || (frame_in_type == 3'(FRAME_NAK));
    assign frame_is_data    = (frame_in_type == 3'(FRAME_DATA));
    assign frame_is_control = (frame_in_type == 3'(FRAME_HELLO))
                           || (frame_in_type == 3'(FRAME_REHELLO))
                           || (frame_in_type == 3'(FRAME_USERNAME))
                           || (frame_in_type == 3'(FRAME_GOODBYE))
                           || (frame_in_type == 3'(FRAME_RECALL));

    logic accept_frame;
    assign accept_frame = frame_in_valid && frame_in_ready;

    logic incoming_dup;
    assign incoming_dup = frame_is_data
                       && (frame_in_arq != expected_rx_arq_q);

    // -----------------------------------------------------------------
    // Output drivers
    // -----------------------------------------------------------------
    assign frame_in_ready    = (state_q == S_IDLE);

    assign tx_ack_valid      = accept_frame && frame_is_ack;
    assign tx_ack_seq        = frame_in_seq;
    assign tx_ack_arq        = frame_in_arq;

    assign cm_rx_valid       = (state_q == S_DELIVER_BE);
    assign cm_rx_frame_type  = type_q;
    assign cm_rx_seq         = seq_q;
    assign cm_rx_len         = len_q;
    assign cm_rx_payload     = payload_q;

    assign ack_q_valid       = (state_q == S_QUEUE_ACK);
    assign ack_q_seq         = seq_q;
    assign ack_q_arq         = arq_q;

    // -----------------------------------------------------------------
    // Next-state
    // -----------------------------------------------------------------
    always_comb begin
        state_d = state_q;
        unique case (state_q)
            S_IDLE: begin
                if (accept_frame) begin
                    if (frame_is_ack) begin
                        // tx_ack pulses combinationally; no FSM work.
                    end else if (frame_is_data || frame_is_control) begin
                        if (frame_is_data && incoming_dup)
                            state_d = S_QUEUE_ACK;     // skip BE delivery
                        else
                            state_d = S_DELIVER_BE;
                    end
                    // unknown frame type: drop silently (stay in IDLE)
                end
            end
            S_DELIVER_BE: if (cm_rx_ready) state_d = S_QUEUE_ACK;
            S_QUEUE_ACK:  if (ack_q_ready) state_d = S_IDLE;
            default:      state_d = S_IDLE;
        endcase
    end

    // -----------------------------------------------------------------
    // Sequential
    // -----------------------------------------------------------------
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state_q           <= S_IDLE;
            type_q            <= 3'd0;
            arq_q             <= 1'b0;
            seq_q             <= '0;
            len_q             <= '0;
            payload_q         <= '0;
            expected_rx_arq_q <= 1'b0;
            dup_q             <= 1'b0;
        end else begin
            state_q <= state_d;

            // Latch on accepted non-ACK frame.
            if (state_q == S_IDLE && accept_frame
              && (frame_is_data || frame_is_control)) begin
                type_q    <= frame_in_type;
                arq_q     <= frame_in_arq;
                seq_q     <= frame_in_seq;
                len_q     <= frame_in_len;
                payload_q <= frame_in_payload;
                dup_q     <= incoming_dup;
            end

            // Toggle expected ARQ bit only on accepted (non-dup) DATA delivery.
            if (state_q == S_QUEUE_ACK && ack_q_ready
              && !dup_q && (type_q == 3'(FRAME_DATA))) begin
                expected_rx_arq_q <= ~expected_rx_arq_q;
            end
        end
    end

endmodule

`endif  // COMM_RX_FSM_SV
