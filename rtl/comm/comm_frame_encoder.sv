// =====================================================================
// comm_frame_encoder.sv  --  Frame -> byte-stream serialiser
// ---------------------------------------------------------------------
// Accepts a request:
//   { frame_type[2:0], seq[7:0], len[7:0], payload[MAX_MSG_LEN*8-1:0] }
// and emits the byte stream:
//
//   SOF(0x7E) | TYPE | SEQ | LEN | PAYLOAD[0..len-1] | CRC16_HI | CRC16_LO
//
// CRC16 (CCITT, see rtl/common/crc16.sv) covers TYPE..PAYLOAD only --
// not SOF, not the CRC bytes themselves. CRC is transmitted big-endian
// (high byte first).
//
// The frame request is latched on the first cycle in S_IDLE that sees
// frame_in_valid && frame_in_ready (both asserted). The CRC engine is
// reloaded with INIT on that same edge.
//
// Each output byte is held with byte_out_valid=1 until the consumer
// (uart_tx) accepts via byte_out_ready. CRC absorbs the byte on the
// SAME cycle the handshake completes, so the next state's byte_out_data
// (and crc_state, when needed) is correct.
//
// Latency: 1 cycle from request acceptance to first output byte (the
// SOF). After that, throughput is one byte per (handshake-permitting)
// cycle.
// =====================================================================

`ifndef COMM_FRAME_ENCODER_SV
`define COMM_FRAME_ENCODER_SV

module comm_frame_encoder
    import chat_pkg::*;
(
    input  logic                          clk,
    input  logic                          rst_n,

    // Frame-request handshake (from arbiter / tx_fsm)
    input  logic                          frame_in_valid,
    output logic                          frame_in_ready,
    input  logic [2:0]                    frame_in_type,
    input  seq_t                          frame_in_seq,
    input  msg_len_t                      frame_in_len,
    input  logic [MAX_MSG_LEN*8-1:0]      frame_in_payload,

    // Byte-stream handshake (to uart_tx)
    output logic                          byte_out_valid,
    input  logic                          byte_out_ready,
    output byte_t                         byte_out_data
);

    // -----------------------------------------------------------------
    // Latched request
    // -----------------------------------------------------------------
    logic [2:0]                  type_q;
    seq_t                        seq_q;
    msg_len_t                    len_q;
    logic [MAX_MSG_LEN*8-1:0]    payload_q;
    msg_len_t                    pld_idx_q;

    // -----------------------------------------------------------------
    // CRC engine
    // -----------------------------------------------------------------
    logic    crc_init, crc_en;
    byte_t   crc_byte_in;
    crc16_t  crc_state;

    crc16 u_crc (
        .clk     (clk),
        .rst_n   (rst_n),
        .init    (crc_init),
        .en      (crc_en),
        .byte_in (crc_byte_in),
        .crc_out (crc_state)
    );

    // -----------------------------------------------------------------
    // FSM
    // -----------------------------------------------------------------
    typedef enum logic [3:0] {
        S_IDLE,
        S_SOF,
        S_TYPE,
        S_SEQ,
        S_LEN,
        S_PAYLOAD,
        S_CRC_HI,
        S_CRC_LO
    } st_e;
    st_e state_q, state_d;

    logic accept_byte;
    assign accept_byte = byte_out_valid && byte_out_ready;

    assign frame_in_ready = (state_q == S_IDLE);

    // ---- output mux ----
    always_comb begin
        byte_out_valid = 1'b0;
        byte_out_data  = 8'h00;
        unique case (state_q)
            S_SOF:     begin byte_out_valid = 1'b1; byte_out_data = SOF_BYTE; end
            S_TYPE:    begin byte_out_valid = 1'b1; byte_out_data = {5'b0, type_q}; end
            S_SEQ:     begin byte_out_valid = 1'b1; byte_out_data = seq_q; end
            S_LEN:     begin byte_out_valid = 1'b1; byte_out_data = len_q; end
            S_PAYLOAD: begin byte_out_valid = 1'b1;
                              byte_out_data = payload_q[pld_idx_q*8 +: 8]; end
            S_CRC_HI:  begin byte_out_valid = 1'b1; byte_out_data = crc_state[15:8]; end
            S_CRC_LO:  begin byte_out_valid = 1'b1; byte_out_data = crc_state[7:0];  end
            default:   ;
        endcase
    end

    // ---- CRC drive ----
    // INIT pulse on the cycle we accept a new frame request (state==IDLE
    // with frame_in_valid). EN pulses on each handshake-completed byte
    // for TYPE/SEQ/LEN/PAYLOAD (NOT SOF, NOT CRC bytes).
    always_comb begin
        crc_init    = 1'b0;
        crc_en      = 1'b0;
        crc_byte_in = 8'h00;

        if (state_q == S_IDLE && frame_in_valid)
            crc_init = 1'b1;

        if (accept_byte) begin
            unique case (state_q)
                S_TYPE:    begin crc_en = 1'b1; crc_byte_in = {5'b0, type_q}; end
                S_SEQ:     begin crc_en = 1'b1; crc_byte_in = seq_q; end
                S_LEN:     begin crc_en = 1'b1; crc_byte_in = len_q; end
                S_PAYLOAD: begin crc_en = 1'b1;
                                  crc_byte_in = payload_q[pld_idx_q*8 +: 8]; end
                default:   ;
            endcase
        end
    end

    // ---- next-state ----
    always_comb begin
        state_d = state_q;
        unique case (state_q)
            S_IDLE:    if (frame_in_valid) state_d = S_SOF;
            S_SOF:     if (accept_byte)    state_d = S_TYPE;
            S_TYPE:    if (accept_byte)    state_d = S_SEQ;
            S_SEQ:     if (accept_byte)    state_d = S_LEN;
            S_LEN:     if (accept_byte)
                          state_d = (len_q == 0) ? S_CRC_HI : S_PAYLOAD;
            S_PAYLOAD: if (accept_byte
                       && (pld_idx_q == len_q - LEN_WIDTH'(1)))
                          state_d = S_CRC_HI;
            S_CRC_HI:  if (accept_byte)    state_d = S_CRC_LO;
            S_CRC_LO:  if (accept_byte)    state_d = S_IDLE;
            default:   state_d = S_IDLE;
        endcase
    end

    // ---- sequential ----
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state_q   <= S_IDLE;
            type_q    <= 3'd0;
            seq_q     <= '0;
            len_q     <= '0;
            payload_q <= '0;
            pld_idx_q <= '0;
        end else begin
            state_q <= state_d;

            // Latch new request on IDLE acceptance.
            if (state_q == S_IDLE && frame_in_valid) begin
                type_q    <= frame_in_type;
                seq_q     <= frame_in_seq;
                len_q     <= frame_in_len;
                payload_q <= frame_in_payload;
                pld_idx_q <= '0;
            end

            // Advance payload index as bytes are sent.
            if (state_q == S_PAYLOAD && accept_byte) begin
                pld_idx_q <= pld_idx_q + 8'd1;
            end
        end
    end

endmodule

`endif  // COMM_FRAME_ENCODER_SV
