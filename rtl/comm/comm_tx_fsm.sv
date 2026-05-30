// =====================================================================
// comm_tx_fsm.sv  --  ARQ TX side (stop-and-wait, alternating bit)
// ---------------------------------------------------------------------
// Accepts frame requests from backend, drives them to the encoder
// (via the arbiter), waits for an ACK with matching seq, and either
// reports SUCCESS / FAIL back to backend (DATA only) or returns
// silently to IDLE (control frames are fire-and-forget per the
// agreed protocol).
//
// SEQ / ARQ usage:
//   - frame_req_seq carries the full 8-bit msg_id on the wire.
//   - The ARQ alternating bit (tx_seq_q[0]) is sent via TYPE[7] on the
//     wire and echoed back in ACK frames. On a successful DATA ACK, the
//     alternating bit toggles; control frames are ACKed/retried but do not
//     advance the DATA duplicate-filter sequence.
//
// Timeout / retry:
//   - On entering WAIT_ACK, the timeout counter is reset.
//   - It increments each cycle in WAIT_ACK while !ack_match.
//   - When the counter equals TIMEOUT_CYCLES-1 (one cycle before it
//     would saturate), we either RETRY (retry_q < MAX_RETRY) or FAIL.
//   - Each RETRY restarts SEND with the same payload+seq and increments
//     retry_q. After MAX_RETRY+1 attempts total, we FAIL.
//
// State machine:
//   S_IDLE             -> backend can post a new request
//   S_SEND             -> drive frame request to arbiter; advance when accepted
//   S_WAIT_ACK         -> count timeout, watch for ack
//   S_REPORT_SUCCESS   -> drive cm_status_valid (DATA only); ready -> IDLE
//   S_REPORT_FAIL      -> same but TX_FAIL code
// =====================================================================

`ifndef COMM_TX_FSM_SV
`define COMM_TX_FSM_SV

module comm_tx_fsm
    import chat_pkg::*;
#(
    // 100 MHz / 20 ms = 2_000_000 cycles. Tests override.
    parameter int TIMEOUT_CYCLES = 2_000_000
) (
    input  logic                          clk,
    input  logic                          rst_n,

    // ---- backend -> tx ----
    input  logic                          be_tx_valid,
    output logic                          be_tx_ready,
    input  logic [2:0]                    be_tx_frame_type,
    input  msg_id_t                       be_tx_msg_id,
    input  msg_len_t                      be_tx_len,
    input  logic [MAX_MSG_LEN*8-1:0]      be_tx_payload,

    // ---- tx -> arbiter ----
    output logic                          frame_req_valid,
    input  logic                          frame_req_ready,
    output logic [2:0]                    frame_req_type,
    output logic                          frame_req_arq,    // ARQ alternating bit
    output seq_t                          frame_req_seq,    // msg_id (full 8 bits)
    output msg_len_t                      frame_req_len,
    output logic [MAX_MSG_LEN*8-1:0]      frame_req_payload,

    // ---- rx_fsm -> tx (ACK notification) ----
    input  logic                          ack_valid,        // 1-cycle pulse
    input  seq_t                          ack_seq,           // msg_id echoed by ACK
    input  logic                          ack_arq,           // ARQ alternating bit from ACK

    // ---- tx -> backend (status feedback, DATA only) ----
    output logic                          cm_status_valid,
    input  logic                          cm_status_ready,
    output msg_id_t                       cm_status_msg_id,
    output logic [1:0]                    cm_status_code
);

    localparam int TIMEOUT_W = (TIMEOUT_CYCLES <= 1)
                                 ? 1 : $clog2(TIMEOUT_CYCLES + 1);

    typedef enum logic [2:0] {
        S_IDLE,
        S_SEND,
        S_WAIT_ACK,
        S_REPORT_SUCCESS,
        S_REPORT_FAIL
    } st_e;

    st_e                          state_q, state_d;

    logic [2:0]                   type_q;
    msg_id_t                      msg_id_q;
    msg_len_t                     len_q;
    logic [MAX_MSG_LEN*8-1:0]     payload_q;
    /* verilator lint_off UNUSEDSIGNAL */
    seq_t                         tx_seq_q;          // only bit[0] is meaningful
    /* verilator lint_on UNUSEDSIGNAL */
    retry_count_t                 retry_q;
    logic [TIMEOUT_W-1:0]         timeout_q;

    // -----------------------------------------------------------------
    // Output drivers
    // -----------------------------------------------------------------
    assign be_tx_ready       = (state_q == S_IDLE);

    assign frame_req_valid   = (state_q == S_SEND);
    assign frame_req_type    = type_q;
    assign frame_req_arq     = tx_seq_q[0];
    assign frame_req_seq     = msg_id_q;
    assign frame_req_len     = len_q;
    assign frame_req_payload = payload_q;

    assign cm_status_valid   = (state_q == S_REPORT_SUCCESS)
                            || (state_q == S_REPORT_FAIL);
    assign cm_status_msg_id  = msg_id_q;
    assign cm_status_code    = (state_q == S_REPORT_SUCCESS)
                                ? 2'(TX_SUCCESS) : 2'(TX_FAIL);

    // -----------------------------------------------------------------
    // Helpers
    // -----------------------------------------------------------------
    logic timeout_hit;
    assign timeout_hit = (timeout_q == TIMEOUT_W'(TIMEOUT_CYCLES - 1));

    logic ack_match;
    assign ack_match = ack_valid
                    && (ack_arq == tx_seq_q[0])
                    && (ack_seq == seq_t'(msg_id_q));

    logic is_data;
    assign is_data = (type_q == 3'(FRAME_DATA));

    logic max_retries_used;
    assign max_retries_used = (retry_q == retry_count_t'(MAX_RETRY));

    // -----------------------------------------------------------------
    // Next-state
    // -----------------------------------------------------------------
    always_comb begin
        state_d = state_q;
        unique case (state_q)
            S_IDLE: begin
                if (be_tx_valid) state_d = S_SEND;
            end
            S_SEND: begin
                if (frame_req_ready) state_d = S_WAIT_ACK;
            end
            S_WAIT_ACK: begin
                if (ack_match) begin
                    state_d = is_data ? S_REPORT_SUCCESS : S_IDLE;
                end else if (timeout_hit) begin
                    if (max_retries_used)
                        state_d = is_data ? S_REPORT_FAIL : S_IDLE;
                    else
                        state_d = S_SEND;
                end
            end
            S_REPORT_SUCCESS: if (cm_status_ready) state_d = S_IDLE;
            S_REPORT_FAIL:    if (cm_status_ready) state_d = S_IDLE;
            default:          state_d = S_IDLE;
        endcase
    end

    // -----------------------------------------------------------------
    // Sequential
    // -----------------------------------------------------------------
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state_q   <= S_IDLE;
            type_q    <= 3'd0;
            msg_id_q  <= '0;
            len_q     <= '0;
            payload_q <= '0;
            tx_seq_q  <= '0;
            retry_q   <= '0;
            timeout_q <= '0;
        end else begin
            state_q <= state_d;

            // Latch new request on IDLE acceptance.
            if (state_q == S_IDLE && be_tx_valid) begin
                type_q    <= be_tx_frame_type;
                msg_id_q  <= be_tx_msg_id;
                len_q     <= be_tx_len;
                payload_q <= be_tx_payload;
                retry_q   <= '0;
            end

            // Reset timeout on transition into WAIT_ACK (first send or retry).
            if (state_q == S_SEND && frame_req_ready) begin
                timeout_q <= '0;
            end

            // Increment timeout while waiting (and not about to leave).
            if (state_q == S_WAIT_ACK && !ack_match && !timeout_hit) begin
                timeout_q <= timeout_q + 1'b1;
            end

            // Increment retry on a retry-driven SEND.
            if (state_q == S_WAIT_ACK && timeout_hit && !ack_match
              && !max_retries_used) begin
                retry_q <= retry_q + 1'b1;
            end

            // Toggle alternating bit only on DATA success. Control frames are
            // deliberately outside the RX DATA duplicate-filter sequence.
            if (state_q == S_WAIT_ACK && ack_match && is_data) begin
                tx_seq_q <= {7'b0, ~tx_seq_q[0]};
            end
        end
    end

endmodule

`endif  // COMM_TX_FSM_SV
