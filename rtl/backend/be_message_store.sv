// =====================================================================
// be_message_store.sv  --  Indexed chat-message storage
// ---------------------------------------------------------------------
// Stores up to MAX_MSG_NUM (=64) chat-message records.
//
// Split into two storage tiers to keep Vivado elaboration fast:
//
//   Metadata (registers, combinational read):
//     { valid : 1 bit, msg_id : 8 bits, side : 2 bits,
//       status : 2 bits, len : 16 bits }   — 29 bits × 64 = 1,856 bits
//     Small enough for distributed RAM; 2 combinational read ports +
//     a combinational lookup are cheap at this width.
//
//   Payload (BRAM, byte-addressable, 1-cycle read latency):
//     MAX_MSG_NUM × MAX_MSG_LEN = 64 × 128 = 8,192 bytes
//     Single simple-dual-port BRAM array.  Vivado infers this as a
//     handful of BRAM18 blocks instead of burning LUTs on a 64 ×
//     1,024-bit distributed-RAM register file.
//
//     Writes stream one byte per cycle (up to 128 cycles).  A local
//     FSM walks the byte index; wr_busy is asserted until the stream
//     finishes.  The caller must not assert wr_en while wr_busy is
//     high — in practice the BE→FE render pipeline and UART tx
//     handshake always provide > 128 cycles of back-pressure between
//     consecutive writes, so this is a non-issue.
//
//     Reads are also byte-at-a-time through a single registered port.
//     The payload appears one cycle after {slot, byte_idx} is driven.
//
// Operations (metadata — all combinational, 1 cycle):
//
//   wr_en      : metadata written immediately (same cycle).
//                Payload streaming starts; wr_busy asserts.
//
//   upd_en     : status-only update at upd_idx; valid bit untouched.
//
//   clear_en   : single-cycle pulse; clears all metadata valid bits
//                and aborts any in-flight payload stream.
//
//   rd_idx     : combinational metadata read.
//
//   rd2_idx    : second combinational metadata read (for UI popups).
//
//   lookup     : combinational find of the LOWEST valid idx whose
//                side and msg_id match. Scans metadata only.
//
// Conflict policy (metadata):
//   If wr_en and upd_en target the SAME slot, write wins.
//   clear_en wins over both.
// =====================================================================

`ifndef BE_MESSAGE_STORE_SV
`define BE_MESSAGE_STORE_SV

module be_message_store
    import chat_pkg::*;
#(
    parameter int IDX_W       = $clog2(MAX_MSG_NUM),
    parameter int BYTE_IDX_W  = $clog2(MAX_MSG_LEN),
    parameter int PAYLOAD_AW  = IDX_W + BYTE_IDX_W   // 6 + 7 = 13
) (
    input  logic                          clk,
    input  logic                          rst_n,

    // ---- Atomic record write ----
    // Metadata is committed in the same cycle wr_en fires.
    // Payload streams to BRAM over the next MAX_MSG_LEN cycles;
    // wr_busy stays high until the last byte is written.
    input  logic                          wr_en,
    input  logic [IDX_W-1:0]              wr_idx,
    input  msg_id_t                       wr_msg_id,
    input  logic [1:0]                    wr_side,
    input  logic [1:0]                    wr_status,
    input  msg_len_t                      wr_len,
    input  logic [MAX_MSG_LEN*8-1:0]      wr_payload,
    output logic                          wr_busy,

    // ---- Status-only update (metadata only) ----
    input  logic                          upd_en,
    input  logic [IDX_W-1:0]              upd_idx,
    input  logic [1:0]                    upd_status,

    // ---- Single-cycle clear of all valid bits ----
    input  logic                          clear_en,

    // ---- Combinational metadata read at rd_idx ----
    input  logic [IDX_W-1:0]              rd_idx,
    output logic                          rd_valid,
    output msg_id_t                       rd_msg_id,
    output logic [1:0]                    rd_side,
    output logic [1:0]                    rd_status,
    output msg_len_t                      rd_len,

    // ---- Byte-level payload read (1-cycle latency) ----
    // Drive {rd_byte_slot, rd_byte_idx}; rd_byte_data appears next cycle.
    input  logic [IDX_W-1:0]              rd_byte_slot,
    input  logic [BYTE_IDX_W-1:0]         rd_byte_idx,
    output byte_t                         rd_byte_data,

    // ---- Combinational metadata read at rd2_idx ----
    input  logic [IDX_W-1:0]              rd2_idx,
    output logic                          rd2_valid,
    output msg_id_t                       rd2_msg_id,
    output logic [1:0]                    rd2_side,
    output logic [1:0]                    rd2_status,
    output msg_len_t                      rd2_len,

    // ---- Combinational lookup by side + msg_id (lowest match wins) ----
    input  logic [1:0]                    lookup_side,
    input  msg_id_t                       lookup_msg_id,
    output logic                          lookup_hit,
    output logic [IDX_W-1:0]              lookup_idx
);

    // -----------------------------------------------------------------
    // Metadata — register arrays (small: 29 bits × 64 = 1,856 bits)
    // -----------------------------------------------------------------
    logic                       meta_valid [MAX_MSG_NUM];
    msg_id_t                    meta_msg_id [MAX_MSG_NUM];
    logic [1:0]                 meta_side   [MAX_MSG_NUM];
    logic [1:0]                 meta_status [MAX_MSG_NUM];
    msg_len_t                   meta_len    [MAX_MSG_NUM];

    // -----------------------------------------------------------------
    // Payload — byte-addressable BRAM
    //   Depth = MAX_MSG_NUM × MAX_MSG_LEN = 64 × 128 = 8,192
    //   Address = {slot[5:0], byte_idx[6:0]}
    //   Vivado infers this as BRAM (4–8 BRAM18 blocks at current
    //   MAX_MSG_LEN=128).
    // -----------------------------------------------------------------
    byte_t payload_bram [1 << PAYLOAD_AW];

    // -----------------------------------------------------------------
    // Write-streaming FSM
    // -----------------------------------------------------------------
    typedef enum logic [1:0] {
        WS_IDLE,
        WS_STREAM
    } ws_state_e;

    ws_state_e ws_state_q, ws_state_d;

    logic [IDX_W-1:0]              ws_slot_q;
    logic [BYTE_IDX_W-1:0]         ws_byte_q;
    logic [MAX_MSG_LEN*8-1:0]      ws_buf_q;     // latched full payload

    // BRAM read pipeline (1-cycle latency)
    logic [PAYLOAD_AW-1:0]         bram_rd_addr;

    // BRAM read address — always driven by the byte-level read port.
    assign bram_rd_addr = {rd_byte_slot, rd_byte_idx};

    // BRAM write address — driven by the streaming FSM.
    logic [PAYLOAD_AW-1:0]         bram_wr_addr;
    logic                          bram_wr_en;
    assign bram_wr_addr = {ws_slot_q, ws_byte_q};
    assign bram_wr_en   = (ws_state_q == WS_STREAM);

    // -----------------------------------------------------------------
    // Payload BRAM array (simple dual-port: 1 write + 1 read)
    // Standard BRAM inference: combinational address, registered data.
    // 1-cycle read latency.
    // -----------------------------------------------------------------
    always_ff @(posedge clk) begin
        if (bram_wr_en)
            payload_bram[bram_wr_addr] <= ws_buf_q[ws_byte_q*8 +: 8];
    end

    always_ff @(posedge clk) begin
        rd_byte_data <= payload_bram[bram_rd_addr];
    end

    // -----------------------------------------------------------------
    // Write-streaming FSM
    // -----------------------------------------------------------------
    always_comb begin
        ws_state_d = ws_state_q;
        if (ws_state_q == WS_STREAM) begin
            // Advance byte index; last byte returns to idle.
            if (ws_byte_q == BYTE_IDX_W'(MAX_MSG_LEN - 1))
                ws_state_d = WS_IDLE;
        end else begin
            // WS_IDLE: kick off on wr_en
            if (wr_en && !clear_en)
                ws_state_d = WS_STREAM;
        end
        if (clear_en)
            ws_state_d = WS_IDLE;
    end

    assign wr_busy = (ws_state_q != WS_IDLE);

    // -----------------------------------------------------------------
    // Metadata sequential write / update / clear
    // -----------------------------------------------------------------
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            ws_state_q <= WS_IDLE;
            ws_slot_q  <= '0;
            ws_byte_q  <= '0;
            ws_buf_q   <= '0;

            for (int i = 0; i < MAX_MSG_NUM; i++) begin
                meta_valid[i]  <= 1'b0;
                meta_msg_id[i] <= '0;
                meta_side[i]   <= 2'(MSG_LOCAL);
                meta_status[i] <= 2'(MSG_PENDING);
                meta_len[i]    <= '0;
            end
        end else begin
            ws_state_q <= ws_state_d;

            // Write-streaming FSM
            if (ws_state_q == WS_IDLE && ws_state_d == WS_STREAM) begin
                // Latch the full payload and start streaming from byte 0.
                ws_slot_q <= wr_idx;
                ws_byte_q <= '0;
                ws_buf_q  <= wr_payload;
            end else if (ws_state_q == WS_STREAM) begin
                ws_byte_q <= ws_byte_q + 1'b1;
            end

            // Metadata
            if (clear_en) begin
                for (int i = 0; i < MAX_MSG_NUM; i++)
                    meta_valid[i] <= 1'b0;
            end else begin
                if (wr_en) begin
                    meta_valid[wr_idx]  <= 1'b1;
                    meta_msg_id[wr_idx] <= wr_msg_id;
                    meta_side[wr_idx]   <= wr_side;
                    meta_status[wr_idx] <= wr_status;
                    meta_len[wr_idx]    <= wr_len;
                end
                if (upd_en && !(wr_en && (wr_idx == upd_idx))) begin
                    meta_status[upd_idx] <= upd_status;
                end
            end
        end
    end

    // -----------------------------------------------------------------
    // Combinational metadata reads
    // -----------------------------------------------------------------
    assign rd_valid   = meta_valid[rd_idx];
    assign rd_msg_id  = meta_msg_id[rd_idx];
    assign rd_side    = meta_side[rd_idx];
    assign rd_status  = meta_status[rd_idx];
    assign rd_len     = meta_len[rd_idx];

    assign rd2_valid   = meta_valid[rd2_idx];
    assign rd2_msg_id  = meta_msg_id[rd2_idx];
    assign rd2_side    = meta_side[rd2_idx];
    assign rd2_status  = meta_status[rd2_idx];
    assign rd2_len     = meta_len[rd2_idx];

    // -----------------------------------------------------------------
    // Combinational lookup (metadata only)
    // -----------------------------------------------------------------
    always_comb begin
        lookup_hit = 1'b0;
        lookup_idx = '0;
        for (int i = 0; i < MAX_MSG_NUM; i++) begin
            if (!lookup_hit && meta_valid[i] &&
                (meta_side[i] == lookup_side) &&
                (meta_msg_id[i] == lookup_msg_id)) begin
                lookup_hit = 1'b1;
                lookup_idx = i[IDX_W-1:0];
            end
        end
    end

endmodule

`endif  // BE_MESSAGE_STORE_SV
