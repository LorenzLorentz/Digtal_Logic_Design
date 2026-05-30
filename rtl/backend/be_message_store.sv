// =====================================================================
// be_message_store.sv  --  Indexed chat-message storage
// ---------------------------------------------------------------------
// Stores up to MAX_MSG_NUM (=64) chat-message records. Each record:
//
//   { valid : 1 bit
//     msg_id : MSG_ID_WIDTH bits          (8)
//     side   : 2 bits                     (MSG_LOCAL/REMOTE/SYSTEM)
//     status : 2 bits                     (MSG_PENDING/SUCCESS/FAIL)
//     len    : LEN_WIDTH bits             (8)
//     payload: MAX_MSG_LEN * 8 bits       (64 bytes packed little-endian:
//                                          byte i at bits [i*8 +: 8])
//   }
//
// Operations (each completes in one cycle):
//
//   wr_en      : atomic record write at wr_idx; sets valid <= 1.
//                Caller picks wr_idx (typically a circular write pointer).
//
//   upd_en     : status-only update at upd_idx; valid bit untouched.
//                Used by HANDLE_TX_STATUS to flip PENDING -> SUCCESS/FAIL.
//
//   clear_en   : single-cycle pulse; clears valid bit on all slots in
//                parallel. Used when the peer username changes (a
//                different person is now on the other end, so prior
//                history is no longer meaningful). Takes priority over
//                wr_en / upd_en in the same cycle.
//
//   rd_idx     : combinational read; outputs reflect the slot at rd_idx.
//                Caller should also gate on rd_valid before trusting data.
//
//   lookup     : combinational find of the LOWEST valid idx whose msg_id
//                matches lookup_msg_id. lookup_hit is 1 if a match exists.
//
// Conflict policy:
//   If wr_en and upd_en target the SAME slot in the same cycle, the
//   write wins -- status is written from wr_status, not upd_status.
//   Different slots are independent.
//   clear_en wins over both wr_en and upd_en when asserted in the same
//   cycle.
//
// Reset:
//   Clears the valid bit of every slot. Other fields keep prior values
//   (don't-care because every consumer should gate on valid).
// =====================================================================

`ifndef BE_MESSAGE_STORE_SV
`define BE_MESSAGE_STORE_SV

module be_message_store
    import chat_pkg::*;
#(
    parameter int IDX_W = $clog2(MAX_MSG_NUM)
) (
    input  logic                          clk,
    input  logic                          rst_n,

    // Atomic record write
    input  logic                          wr_en,
    input  logic [IDX_W-1:0]              wr_idx,
    input  msg_id_t                       wr_msg_id,
    input  logic [1:0]                    wr_side,
    input  logic [1:0]                    wr_status,
    input  msg_len_t                      wr_len,
    input  logic [MAX_MSG_LEN*8-1:0]      wr_payload,

    // Status-only update
    input  logic                          upd_en,
    input  logic [IDX_W-1:0]              upd_idx,
    input  logic [1:0]                    upd_status,

    // Single-cycle clear of all valid bits (used on peer-name change)
    input  logic                          clear_en,

    // Combinational read at rd_idx
    input  logic [IDX_W-1:0]              rd_idx,
    output logic                          rd_valid,
    output msg_id_t                       rd_msg_id,
    output logic [1:0]                    rd_side,
    output logic [1:0]                    rd_status,
    output msg_len_t                      rd_len,
    output logic [MAX_MSG_LEN*8-1:0]      rd_payload,

    // Second combinational read port for backend-owned UI actions.
    input  logic [IDX_W-1:0]              rd2_idx,
    output logic                          rd2_valid,
    output msg_id_t                       rd2_msg_id,
    output logic [1:0]                    rd2_side,
    output logic [1:0]                    rd2_status,
    output msg_len_t                      rd2_len,
    output logic [MAX_MSG_LEN*8-1:0]      rd2_payload,

    // Combinational lookup by msg_id (lowest matching idx)
    input  msg_id_t                       lookup_msg_id,
    output logic                          lookup_hit,
    output logic [IDX_W-1:0]              lookup_idx
);

    typedef struct packed {
        logic                       valid;
        msg_id_t                    msg_id;
        logic [1:0]                 side;
        logic [1:0]                 status;
        msg_len_t                   len;
        logic [MAX_MSG_LEN*8-1:0]   payload;
    } record_t;

    record_t store [MAX_MSG_NUM];

    // -----------------------------------------------------------------
    // Sequential writes / status updates
    // -----------------------------------------------------------------
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            for (int i = 0; i < MAX_MSG_NUM; i++)
                store[i].valid <= 1'b0;
            // Other fields intentionally not reset.
        end else if (clear_en) begin
            // Parallel valid-bit reset; takes priority over wr_en / upd_en.
            for (int i = 0; i < MAX_MSG_NUM; i++)
                store[i].valid <= 1'b0;
        end else begin
            if (wr_en) begin
                store[wr_idx].valid   <= 1'b1;
                store[wr_idx].msg_id  <= wr_msg_id;
                store[wr_idx].side    <= wr_side;
                store[wr_idx].status  <= wr_status;
                store[wr_idx].len     <= wr_len;
                store[wr_idx].payload <= wr_payload;
            end
            // upd_en applies the status update except when wr_en already
            // owns the same slot this cycle (write wins on conflict).
            if (upd_en && !(wr_en && (wr_idx == upd_idx))) begin
                store[upd_idx].status <= upd_status;
            end
        end
    end

    // -----------------------------------------------------------------
    // Combinational read
    // -----------------------------------------------------------------
    assign rd_valid   = store[rd_idx].valid;
    assign rd_msg_id  = store[rd_idx].msg_id;
    assign rd_side    = store[rd_idx].side;
    assign rd_status  = store[rd_idx].status;
    assign rd_len     = store[rd_idx].len;
    assign rd_payload = store[rd_idx].payload;

    assign rd2_valid   = store[rd2_idx].valid;
    assign rd2_msg_id  = store[rd2_idx].msg_id;
    assign rd2_side    = store[rd2_idx].side;
    assign rd2_status  = store[rd2_idx].status;
    assign rd2_len     = store[rd2_idx].len;
    assign rd2_payload = store[rd2_idx].payload;

    // -----------------------------------------------------------------
    // Combinational lookup by msg_id (lowest valid match wins).
    // Forward iteration with a "found" flag so the FIRST valid match
    // sticks and later matches are ignored.
    // -----------------------------------------------------------------
    always_comb begin
        lookup_hit = 1'b0;
        lookup_idx = '0;
        for (int i = 0; i < MAX_MSG_NUM; i++) begin
            if (!lookup_hit && store[i].valid &&
                (store[i].msg_id == lookup_msg_id)) begin
                lookup_hit = 1'b1;
                lookup_idx = i[IDX_W-1:0];
            end
        end
    end

endmodule

`endif  // BE_MESSAGE_STORE_SV
