// =====================================================================
// comm_top_lb.sv  --  comm_top with uart_txd looped back to uart_rxd
// ---------------------------------------------------------------------
// Test-only wrapper. The single comm_top instance receives every frame
// it sends, exercising the entire RX/TX/ARQ chain in one DUT:
//
//   be_tx (DATA) -> tx_fsm -> arbiter -> encoder -> uart_tx
//                                                   |
//                                              loopback
//                                                   |
//   cm_rx <--- rx_fsm <--- decoder <--- uart_rx <---'
//   ack_q -> arbiter -> encoder -> uart_tx -> loopback -> uart_rx ...
//   ... -> decoder -> rx_fsm -> tx_ack -> tx_fsm -> cm_status SUCCESS
// =====================================================================

`ifndef COMM_TOP_LB_SV
`define COMM_TOP_LB_SV

module comm_top_lb
    import chat_pkg::*;
#(
    parameter int CLK_FREQ_HZ    = 160,
    parameter int BAUD           = 10,        // BAUD_DIV = 16
    parameter int TIMEOUT_CYCLES = 8000
) (
    input  logic                          clk,
    input  logic                          rst_n,

    input  logic                          be_tx_valid,
    output logic                          be_tx_ready,
    input  logic [2:0]                    be_tx_frame_type,
    input  msg_id_t                       be_tx_msg_id,
    input  msg_len_t                      be_tx_len,
    input  logic [MAX_MSG_LEN*8-1:0]      be_tx_payload,

    output logic                          cm_rx_valid,
    input  logic                          cm_rx_ready,
    output logic [2:0]                    cm_rx_frame_type,
    output seq_t                          cm_rx_seq,
    output msg_len_t                      cm_rx_len,
    output logic [MAX_MSG_LEN*8-1:0]      cm_rx_payload,

    output logic                          cm_status_valid,
    input  logic                          cm_status_ready,
    output msg_id_t                       cm_status_msg_id,
    output logic [1:0]                    cm_status_code,

    output logic                          line_obs
);

    logic line;

    comm_top #(
        .CLK_FREQ_HZ    (CLK_FREQ_HZ),
        .BAUD           (BAUD),
        .TIMEOUT_CYCLES (TIMEOUT_CYCLES)
    ) u_comm (
        .clk              (clk),
        .rst_n            (rst_n),
        .uart_rxd         (line),
        .uart_txd         (line),

        .be_tx_valid      (be_tx_valid),
        .be_tx_ready      (be_tx_ready),
        .be_tx_frame_type (be_tx_frame_type),
        .be_tx_msg_id     (be_tx_msg_id),
        .be_tx_len        (be_tx_len),
        .be_tx_payload    (be_tx_payload),

        .cm_rx_valid      (cm_rx_valid),
        .cm_rx_ready      (cm_rx_ready),
        .cm_rx_frame_type (cm_rx_frame_type),
        .cm_rx_seq        (cm_rx_seq),
        .cm_rx_len        (cm_rx_len),
        .cm_rx_payload    (cm_rx_payload),

        .cm_status_valid  (cm_status_valid),
        .cm_status_ready  (cm_status_ready),
        .cm_status_msg_id (cm_status_msg_id),
        .cm_status_code   (cm_status_code)
    );

    assign line_obs = line;

endmodule

`endif  // COMM_TOP_LB_SV
