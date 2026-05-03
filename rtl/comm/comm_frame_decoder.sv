// =====================================================================
// comm_frame_decoder.sv  --  byte-stream -> frame parser
// ---------------------------------------------------------------------
// Consumes a byte stream from uart_rx (1-cycle byte_in_valid pulses,
// no back-pressure) and emits decoded frames on a valid/ready output
// to comm_rx_fsm.
//
// Frame layout (matches comm_frame_encoder.sv):
//
//   SOF(0x7E) | TYPE | SEQ | LEN | PAYLOAD[0..len-1] | CRC16_HI | CRC16_LO
//
// Recovery rules:
//   - In WAIT_SOF, we wait for byte == SOF_BYTE. CRC engine reloads
//     INIT on the SOF cycle.
//   - LEN > MAX_MSG_LEN is treated as malformed: drop and resync.
//   - If CRC mismatches at the LO byte, drop and resync.
//   - On success, hold frame_out_valid until rx_fsm asserts ready.
//     During DELIVER, additional bytes from uart_rx are dropped (in
//     practice rx_fsm consumes in 1-2 cycles and bytes arrive every
//     ~10*BAUD_DIV, so this is theoretical).
//
// Note: there is no byte stuffing. SOF inside a payload is just data
// (we know the frame length up front from LEN). When recovering after
// a corrupt frame we may briefly mis-sync on a payload-internal SOF;
// that frame's CRC will fail and ARQ retransmits. Acceptable.
// =====================================================================

`ifndef COMM_FRAME_DECODER_SV
`define COMM_FRAME_DECODER_SV

module comm_frame_decoder
    import chat_pkg::*;
(
    input  logic                          clk,
    input  logic                          rst_n,

    // Byte stream from uart_rx. byte_in_valid is a 1-cycle pulse; no
    // back-pressure (we always accept).
    input  logic                          byte_in_valid,
    input  byte_t                         byte_in_data,

    // Decoded frame to rx_fsm. Held until rx_fsm asserts ready.
    output logic                          frame_out_valid,
    input  logic                          frame_out_ready,
    output logic [2:0]                    frame_out_type,
    output seq_t                          frame_out_seq,
    output msg_len_t                      frame_out_len,
    output logic [MAX_MSG_LEN*8-1:0]      frame_out_payload,

    // Observability: pulses for one cycle when a frame is dropped due
    // to CRC mismatch or malformed LEN.
    output logic                          drop_pulse
);

    // -----------------------------------------------------------------
    // FSM
    // -----------------------------------------------------------------
    typedef enum logic [3:0] {
        S_WAIT_SOF,
        S_TYPE,
        S_SEQ,
        S_LEN,
        S_PAYLOAD,
        S_CRC_HI,
        S_CRC_LO,
        S_DELIVER
    } st_e;
    st_e state_q, state_d;

    // -----------------------------------------------------------------
    // Latched fields
    // -----------------------------------------------------------------
    logic [2:0]                  type_q;
    seq_t                        seq_q;
    msg_len_t                    len_q;
    msg_len_t                    pld_idx_q;
    logic [MAX_MSG_LEN*8-1:0]    payload_q;
    logic [7:0]                  rx_crc_hi_q;

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

    // CRC drive
    always_comb begin
        crc_init    = 1'b0;
        crc_en      = 1'b0;
        crc_byte_in = byte_in_data;
        if (state_q == S_WAIT_SOF
         && byte_in_valid
         && (byte_in_data == SOF_BYTE)) begin
            crc_init = 1'b1;
        end
        if (byte_in_valid) begin
            unique case (state_q)
                S_TYPE, S_SEQ, S_LEN, S_PAYLOAD: crc_en = 1'b1;
                default: ;
            endcase
        end
    end

    // -----------------------------------------------------------------
    // Next-state logic
    //
    // CRC compare at S_CRC_LO uses {rx_crc_hi_q, byte_in_data} since
    // rx_crc_lo is only being captured on this very edge.
    // -----------------------------------------------------------------
    logic crc_match_now;
    assign crc_match_now =
        (crc_state == {rx_crc_hi_q, byte_in_data});

    always_comb begin
        state_d = state_q;

        unique case (state_q)
            S_WAIT_SOF:
                if (byte_in_valid && (byte_in_data == SOF_BYTE))
                    state_d = S_TYPE;

            S_TYPE: if (byte_in_valid) state_d = S_SEQ;
            S_SEQ:  if (byte_in_valid) state_d = S_LEN;

            S_LEN: if (byte_in_valid) begin
                if (byte_in_data > LEN_WIDTH'(MAX_MSG_LEN))
                    state_d = S_WAIT_SOF;          // malformed -- drop
                else if (byte_in_data == 0)
                    state_d = S_CRC_HI;
                else
                    state_d = S_PAYLOAD;
            end

            S_PAYLOAD: if (byte_in_valid
                       && (pld_idx_q == len_q - LEN_WIDTH'(1)))
                state_d = S_CRC_HI;

            S_CRC_HI: if (byte_in_valid) state_d = S_CRC_LO;

            S_CRC_LO: if (byte_in_valid)
                state_d = crc_match_now ? S_DELIVER : S_WAIT_SOF;

            S_DELIVER: if (frame_out_ready) state_d = S_WAIT_SOF;

            default: state_d = S_WAIT_SOF;
        endcase
    end

    // drop_pulse is REGISTERED so it captures the pre-edge state of the
    // drop condition. A pure combinational version would re-evaluate
    // post-edge with the new state_q (and an input pulse that's still
    // formally high), producing spurious activations.
    logic drop_d;
    always_comb begin
        drop_d = 1'b0;
        if (byte_in_valid) begin
            if (state_q == S_LEN
              && byte_in_data > LEN_WIDTH'(MAX_MSG_LEN))
                drop_d = 1'b1;
            else if (state_q == S_CRC_LO && !crc_match_now)
                drop_d = 1'b1;
        end
    end

    // -----------------------------------------------------------------
    // Sequential
    // -----------------------------------------------------------------
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state_q     <= S_WAIT_SOF;
            type_q      <= 3'd0;
            seq_q       <= '0;
            len_q       <= '0;
            pld_idx_q   <= '0;
            payload_q   <= '0;
            rx_crc_hi_q <= 8'd0;
            drop_pulse  <= 1'b0;
        end else begin
            state_q    <= state_d;
            drop_pulse <= drop_d;

            if (byte_in_valid) begin
                unique case (state_q)
                    S_TYPE: type_q <= byte_in_data[2:0];
                    S_SEQ:  seq_q  <= byte_in_data;
                    S_LEN:  begin
                        len_q     <= byte_in_data;
                        pld_idx_q <= '0;
                        // (Wipe payload_q so a short frame leaves zeros
                        // in the unused upper bytes -- makes downstream
                        // observation deterministic.)
                        payload_q <= '0;
                    end
                    S_PAYLOAD: begin
                        payload_q[pld_idx_q*8 +: 8] <= byte_in_data;
                        pld_idx_q <= pld_idx_q + 8'd1;
                    end
                    S_CRC_HI: rx_crc_hi_q <= byte_in_data;
                    default: ;
                endcase
            end
        end
    end

    // -----------------------------------------------------------------
    // Outputs
    // -----------------------------------------------------------------
    assign frame_out_valid   = (state_q == S_DELIVER);
    assign frame_out_type    = type_q;
    assign frame_out_seq     = seq_q;
    assign frame_out_len     = len_q;
    assign frame_out_payload = payload_q;

endmodule

`endif  // COMM_FRAME_DECODER_SV
