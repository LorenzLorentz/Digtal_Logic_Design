// =====================================================================
// comm_top.sv  --  Communication subsystem top
// ---------------------------------------------------------------------
// Wires the link layer end-to-end:
//
//   uart_rx --bytes--> frame_decoder --frame--> rx_fsm
//                                                 |
//                              ack_queue <--------|---- (ACK request)
//                                  |              |
//                                  v              |
//                             tx_arbiter <---- tx_fsm <-- backend
//                                  |
//                            frame_encoder
//                                  |
//                            uart_tx --line--> peer
//
// Backend interface mirrors the stub. Two parameter knobs:
//   - CLK_FREQ_HZ / BAUD: UART line rate.
//   - TIMEOUT_CYCLES: ARQ timeout.
//
// Tests override these to keep simulations short.
// =====================================================================

`ifndef COMM_TOP_SV
`define COMM_TOP_SV

module comm_top
    import chat_pkg::*;
#(
    parameter int CLK_FREQ_HZ    = CLK_FREQ_HZ_DEFAULT,
    parameter int BAUD           = UART_BAUD_DEFAULT,
    parameter int TIMEOUT_CYCLES = 2_000_000
) (
    input  logic                          clk,
    input  logic                          rst_n,

    // Serial PHY pins
    input  logic                          uart_rxd,
    output logic                          uart_txd,

    // backend -> comm: TX request (DATA / HELLO / REHELLO / USERNAME / GOODBYE)
    input  logic                          be_tx_valid,
    output logic                          be_tx_ready,
    input  logic [2:0]                    be_tx_frame_type,
    input  msg_id_t                       be_tx_msg_id,
    input  msg_len_t                      be_tx_len,
    input  logic [MAX_MSG_LEN*8-1:0]      be_tx_payload,

    // comm -> backend: received remote frame
    output logic                          cm_rx_valid,
    input  logic                          cm_rx_ready,
    output logic [2:0]                    cm_rx_frame_type,
    output seq_t                          cm_rx_seq,
    output msg_len_t                      cm_rx_len,
    output logic [MAX_MSG_LEN*8-1:0]      cm_rx_payload,

    // comm -> backend: TX status feedback (DATA only)
    output logic                          cm_status_valid,
    input  logic                          cm_status_ready,
    output msg_id_t                       cm_status_msg_id,
    output logic [1:0]                    cm_status_code
);

    // -----------------------------------------------------------------
    // RX path: pin -> uart_rx -> decoder -> rx_fsm
    // -----------------------------------------------------------------
    logic         rx_byte_valid;
    byte_t        rx_byte_data;
    /* verilator lint_off UNUSEDSIGNAL */
    logic         rx_frame_error;        // observability only
    /* verilator lint_on UNUSEDSIGNAL */

    uart_rx #(
        .CLK_FREQ_HZ (CLK_FREQ_HZ),
        .BAUD        (BAUD)
    ) u_uart_rx (
        .clk         (clk),
        .rst_n       (rst_n),
        .rx          (uart_rxd),
        .byte_valid  (rx_byte_valid),
        .byte_data   (rx_byte_data),
        .frame_error (rx_frame_error)
    );

    logic                          dec_frame_valid;
    logic                          dec_frame_ready;
    logic [2:0]                    dec_frame_type;
    logic                          dec_frame_arq;
    seq_t                          dec_frame_seq;
    msg_len_t                      dec_frame_len;
    logic [MAX_MSG_LEN*8-1:0]      dec_frame_payload;
    /* verilator lint_off UNUSEDSIGNAL */
    logic                          dec_drop_pulse;     // observability only
    /* verilator lint_on UNUSEDSIGNAL */

    comm_frame_decoder u_dec (
        .clk               (clk),
        .rst_n             (rst_n),
        .byte_in_valid     (rx_byte_valid),
        .byte_in_data      (rx_byte_data),
        .frame_out_valid   (dec_frame_valid),
        .frame_out_ready   (dec_frame_ready),
        .frame_out_type    (dec_frame_type),
        .frame_out_arq     (dec_frame_arq),
        .frame_out_seq     (dec_frame_seq),
        .frame_out_len     (dec_frame_len),
        .frame_out_payload (dec_frame_payload),
        .drop_pulse        (dec_drop_pulse)
    );

    // ---- rx_fsm outputs to ACK queue, tx_fsm, backend ----
    logic    ack_q_in_valid;
    logic    ack_q_in_ready;
    seq_t    ack_q_in_seq;
    logic    ack_q_in_arq;

    logic    tx_ack_valid;
    seq_t    tx_ack_seq;
    logic    tx_ack_arq;

    comm_rx_fsm u_rx_fsm (
        .clk               (clk),
        .rst_n             (rst_n),

        .frame_in_valid    (dec_frame_valid),
        .frame_in_ready    (dec_frame_ready),
        .frame_in_type     (dec_frame_type),
        .frame_in_arq      (dec_frame_arq),
        .frame_in_seq      (dec_frame_seq),
        .frame_in_len      (dec_frame_len),
        .frame_in_payload  (dec_frame_payload),

        .cm_rx_valid       (cm_rx_valid),
        .cm_rx_ready       (cm_rx_ready),
        .cm_rx_frame_type  (cm_rx_frame_type),
        .cm_rx_seq         (cm_rx_seq),
        .cm_rx_len         (cm_rx_len),
        .cm_rx_payload     (cm_rx_payload),

        .ack_q_valid       (ack_q_in_valid),
        .ack_q_ready       (ack_q_in_ready),
        .ack_q_seq         (ack_q_in_seq),
        .ack_q_arq         (ack_q_in_arq),

        .tx_ack_valid      (tx_ack_valid),
        .tx_ack_seq        (tx_ack_seq),
        .tx_ack_arq        (tx_ack_arq)
    );

    // -----------------------------------------------------------------
    // ACK queue
    // -----------------------------------------------------------------
    logic    ack_q_out_valid;
    logic    ack_q_out_ready;
    seq_t    ack_q_out_seq;
    logic    ack_q_out_arq;

    comm_ack_queue u_ack_q (
        .clk       (clk),
        .rst_n     (rst_n),
        .in_valid  (ack_q_in_valid),
        .in_ready  (ack_q_in_ready),
        .in_seq    (ack_q_in_seq),
        .in_arq    (ack_q_in_arq),
        .out_valid (ack_q_out_valid),
        .out_ready (ack_q_out_ready),
        .out_seq   (ack_q_out_seq),
        .out_arq   (ack_q_out_arq)
    );

    // -----------------------------------------------------------------
    // TX path: backend -> tx_fsm -> arbiter -> encoder -> uart_tx
    // -----------------------------------------------------------------
    logic                          tx_req_valid;
    logic                          tx_req_ready;
    logic [2:0]                    tx_req_type;
    logic                          tx_req_arq;
    seq_t                          tx_req_seq;
    msg_len_t                      tx_req_len;
    logic [MAX_MSG_LEN*8-1:0]      tx_req_payload;

    comm_tx_fsm #(
        .TIMEOUT_CYCLES (TIMEOUT_CYCLES)
    ) u_tx_fsm (
        .clk               (clk),
        .rst_n             (rst_n),

        .be_tx_valid       (be_tx_valid),
        .be_tx_ready       (be_tx_ready),
        .be_tx_frame_type  (be_tx_frame_type),
        .be_tx_msg_id      (be_tx_msg_id),
        .be_tx_len         (be_tx_len),
        .be_tx_payload     (be_tx_payload),

        .frame_req_valid   (tx_req_valid),
        .frame_req_ready   (tx_req_ready),
        .frame_req_type    (tx_req_type),
        .frame_req_arq     (tx_req_arq),
        .frame_req_seq     (tx_req_seq),
        .frame_req_len     (tx_req_len),
        .frame_req_payload (tx_req_payload),

        .ack_valid         (tx_ack_valid),
        .ack_seq           (tx_ack_seq),
        .ack_arq           (tx_ack_arq),

        .cm_status_valid   (cm_status_valid),
        .cm_status_ready   (cm_status_ready),
        .cm_status_msg_id  (cm_status_msg_id),
        .cm_status_code    (cm_status_code)
    );

    // ---- arbiter: ACK > tx_fsm ----
    logic                          enc_valid;
    logic                          enc_ready;
    logic [2:0]                    enc_type;
    logic                          enc_arq;
    seq_t                          enc_seq;
    msg_len_t                      enc_len;
    logic [MAX_MSG_LEN*8-1:0]      enc_payload;

    comm_tx_arbiter u_arb (
        .ack_q_valid    (ack_q_out_valid),
        .ack_q_ready    (ack_q_out_ready),
        .ack_q_seq      (ack_q_out_seq),
        .ack_q_arq      (ack_q_out_arq),

        .tx_req_valid   (tx_req_valid),
        .tx_req_ready   (tx_req_ready),
        .tx_req_type    (tx_req_type),
        .tx_req_arq     (tx_req_arq),
        .tx_req_seq     (tx_req_seq),
        .tx_req_len     (tx_req_len),
        .tx_req_payload (tx_req_payload),

        .enc_valid      (enc_valid),
        .enc_ready      (enc_ready),
        .enc_type       (enc_type),
        .enc_arq        (enc_arq),
        .enc_seq        (enc_seq),
        .enc_len        (enc_len),
        .enc_payload    (enc_payload)
    );

    // ---- encoder ----
    logic   tx_byte_valid;
    logic   tx_byte_ready;
    byte_t  tx_byte_data;

    comm_frame_encoder u_enc (
        .clk               (clk),
        .rst_n             (rst_n),
        .frame_in_valid    (enc_valid),
        .frame_in_ready    (enc_ready),
        .frame_in_type     (enc_type),
        .frame_in_arq      (enc_arq),
        .frame_in_seq      (enc_seq),
        .frame_in_len      (enc_len),
        .frame_in_payload  (enc_payload),
        .byte_out_valid    (tx_byte_valid),
        .byte_out_ready    (tx_byte_ready),
        .byte_out_data     (tx_byte_data)
    );

    uart_tx #(
        .CLK_FREQ_HZ (CLK_FREQ_HZ),
        .BAUD        (BAUD)
    ) u_uart_tx (
        .clk      (clk),
        .rst_n    (rst_n),
        .in_valid (tx_byte_valid),
        .in_ready (tx_byte_ready),
        .in_data  (tx_byte_data),
        .tx       (uart_txd)
    );

endmodule

`endif  // COMM_TOP_SV
