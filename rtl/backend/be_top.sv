// =====================================================================
// be_top.sv  --  Backend top
// ---------------------------------------------------------------------
// Two-layer FSM:
//
// Outer layer (connection management):
//   S_BOOT_REDRAW -> S_TX_HELLO -> S_HANDSHAKE_IDLE
//                                    -> (peer HELLO/REHELLO) S_TX_USERNAME
//                                    -> (peer USERNAME)      [skip tx]
//                                  -> S_RENDER_CONN_CONNECTED -> S_IDLE
//   S_IDLE (=== "connected.idle") -> ESC -> S_TX_GOODBYE
//                                  -> peer GOODBYE          -> S_RENDER_CONN_DISCONNECTED
//                                  -> peer HELLO   (mid-chat) -> S_TX_REHELLO
//                                  -> peer REHELLO (mid-chat) -> S_TX_USERNAME
//                                  -> peer USERNAME(mid-chat) -> S_RENDER_CONN_CONNECTED
//   S_DISCONNECTED_IDLE -> SPACE     -> S_TX_HELLO  (re-handshake)
//                       -> peer HELLO/REHELLO -> S_TX_USERNAME
//
// Inner layer (chat, only enabled while in S_IDLE = connected):
//   - input-line cursor editing (LEFT/RIGHT/INSERT-at-cursor/DELETE-at-cursor)
//   - local commit pipeline: STORE -> RENDER_APPEND_LOCAL_PENDING ->
//                            be_tx(DATA) -> RENDER_UPDATE_INPUT_LINE (cleared)
//   - remote DATA receive (with cm_rx_len clamped to MAX_MSG_LEN)
//   - tx-status update
//
// Username protocol:
//   HELLO / REHELLO / USERNAME frames carry the sender's username as
//   payload; GOODBYE has no payload. On every received username we
//   compare with peer_name_q; if it differs, message_store is cleared
//   in one cycle (different person on the other end -> prior history
//   no longer meaningful), wr_ptr_q and next_msg_id_q are reset.
//
//   REHELLO breaks the "ask for username" loop: HELLO triggers REHELLO
//   only when received in S_IDLE (mid-chat); REHELLO never triggers a
//   fresh REHELLO/HELLO -- it only triggers a USERNAME response.
//
// Event sources, in IDLE arbitration order (highest first):
//   1. cm_status_valid : peer/local TX result (DATA only)
//   2. cm_rx_valid     : a remote frame arrived (DATA / HELLO / ...)
//   3. io_key_valid    : a keyboard event from io
//
// FSM states (18 total, 5-bit enum):
//   S_BOOT_REDRAW              start state after reset; emits REDRAW_ALL
//   S_TX_HELLO                 emits FRAME_HELLO + MY_NAME
//   S_HANDSHAKE_IDLE           waits for peer's HELLO/REHELLO/USERNAME
//   S_TX_USERNAME              emits FRAME_USERNAME + MY_NAME
//   S_RENDER_CONN_CONNECTED    emits RENDER_CONN_STATE = CONNECTED
//   S_IDLE                     chat idle (under CONN_CONNECTED)
//   S_RENDER_MOVE_CURSOR       after LEFT/RIGHT
//   S_RENDER_INSERT            after CHAR insert
//   S_RENDER_DELETE            after BS at cursor
//   S_ENTER_RENDER_LOCAL       commit step 1: APPEND_LOCAL_PENDING
//   S_ENTER_SEND_COMM          commit step 2: be_tx (FRAME_DATA)
//   S_ENTER_RENDER_INPUT_CLEAR commit step 3: UPDATE_INPUT_LINE len=0
//   S_RX_RENDER                after cm_rx DATA accept: APPEND_REMOTE
//   S_STATUS_RENDER            after cm_status accept: UPDATE_STATUS
//   S_TX_REHELLO               emits FRAME_REHELLO + MY_NAME
//   S_TX_GOODBYE               emits FRAME_GOODBYE
//   S_RENDER_CONN_DISCONNECTED emits RENDER_CONN_STATE = DISCONNECTED
//   S_DISCONNECTED_IDLE        waits for SPACE / peer HELLO
//
// Cursor-edit conventions:
//   - cursor_pos_q in [0, line_len]; line_buf[i] for i<line_len is live
//   - INSERT (CHAR): line_buf[cursor..len-1] shifts right by 1, byte goes to
//     cursor, len++, cursor_pos++. The render carries the POST-edit cursor
//     (so the inserted byte is at buf[cursor_pos - 1]).
//   - DELETE (BS): only when cursor_pos > 0; line_buf[cursor..len-1] shifts
//     LEFT by 1 to cursor-1, len--, cursor_pos--. Render carries the
//     post-edit cursor.
//   - LEFT/RIGHT only fire a render if cursor actually moved.
//   - ENTER on a non-empty line clears len_q AND cursor_pos_q to 0.
//
// cm_rx_len is clamped to MAX_MSG_LEN before reaching the store (DATA path)
// and to MAX_NAME_LEN before reaching peer_name_q (HELLO/REHELLO/USERNAME
// path). The payload bus is exactly MAX_MSG_LEN bytes wide.
// =====================================================================

`ifndef BE_TOP_SV
`define BE_TOP_SV

module be_top
    import chat_pkg::*;
#(
    parameter int LINE_IDX_W  = $clog2(MAX_LINE_LEN),
    parameter int STORE_IDX_W = $clog2(MAX_MSG_NUM),
    // ---- Identity (override at chat_top instantiation) ----
    parameter int MY_NAME_LEN = 4,
    // Packed little-endian: byte 0 (= ASCII char 0) at bits [7:0].
    // Default: "Alic" (0x41 0x6c 0x69 0x63), zero-padded.
    parameter logic [MAX_NAME_LEN*8-1:0] MY_NAME_PACKED =
        128'h00000000_00000000_00000000_63696c41
) (
    input  logic                       clk,
    input  logic                       rst_n,

    // ---- io -> backend ----
    input  logic                       io_key_valid,
    output logic                       io_key_ready,
    input  logic [2:0]                 io_key_type,
    input  byte_t                      io_key_ascii,

    // ---- mouse click -> backend ----
    /* verilator lint_off UNUSEDSIGNAL */
    input  logic                       io_mouse_click_valid,
    output logic                       io_mouse_click_ready,
    input  logic [9:0]                 io_mouse_click_x,
    input  logic [9:0]                 io_mouse_click_y,

    // ---- frontend -> backend : input scroll offset (for click) ----
    /* verilator lint_on UNUSEDSIGNAL */
    input  logic [3:0]                 fe_input_scroll_offset,

    // ---- comm -> backend : remote frame ----
    input  logic                       cm_rx_valid,
    output logic                       cm_rx_ready,
    input  logic [2:0]                 cm_rx_frame_type,
    input  seq_t                       cm_rx_seq,
    input  msg_len_t                   cm_rx_len,
    input  logic [MAX_MSG_LEN*8-1:0]   cm_rx_payload,

    // ---- comm -> backend : DATA tx status ----
    input  logic                       cm_status_valid,
    output logic                       cm_status_ready,
    input  msg_id_t                    cm_status_msg_id,
    input  logic [1:0]                 cm_status_code,

    // ---- backend -> comm : send a frame ----
    output logic                       be_tx_valid,
    input  logic                       be_tx_ready,
    output logic [2:0]                 be_tx_frame_type,
    output msg_id_t                    be_tx_msg_id,
    output msg_len_t                   be_tx_len,
    output logic [MAX_MSG_LEN*8-1:0]   be_tx_payload,

    // ---- backend -> frontend : render command ----
    output logic                       be_render_valid,
    input  logic                       be_render_ready,
    output logic [3:0]                 be_render_cmd,
    output msg_id_t                    be_render_msg_id,
    output logic [1:0]                 be_render_side,
    output logic [1:0]                 be_render_status,
    output msg_len_t                   be_render_len,
    output logic [MAX_MSG_LEN*8-1:0]   be_render_payload,
    output msg_len_t                   be_render_cursor_pos,
    output byte_t                      be_render_ascii,
    output logic [1:0]                 be_render_conn_state,
    output msg_len_t                   be_render_peer_name_len,
    output logic [MAX_NAME_LEN*8-1:0]  be_render_peer_name,

    // ---- Observability for tests ----
    input  logic [LINE_IDX_W-1:0]      line_rd_idx,
    output byte_t                      line_rd_data,
    output logic [LEN_WIDTH-1:0]       line_len,
    output logic [LEN_WIDTH-1:0]       cursor_pos,

    output logic                       enter_committed,

    input  logic [STORE_IDX_W-1:0]     store_rd_idx,
    output logic                       store_rd_valid,
    output msg_id_t                    store_rd_msg_id,
    output logic [1:0]                 store_rd_side,
    output logic [1:0]                 store_rd_status,
    output msg_len_t                   store_rd_len,
    output logic [MAX_MSG_LEN*8-1:0]   store_rd_payload,

    output logic [1:0]                 conn_state_obs
);

    // -----------------------------------------------------------------
    // FSM
    // -----------------------------------------------------------------
    typedef enum logic [4:0] {
        S_BOOT_REDRAW              = 5'd0,
        S_TX_HELLO                 = 5'd1,
        S_HANDSHAKE_IDLE           = 5'd2,
        S_TX_USERNAME              = 5'd3,
        S_RENDER_CONN_CONNECTED    = 5'd4,
        S_IDLE                     = 5'd5,
        S_RENDER_MOVE_CURSOR       = 5'd6,
        S_RENDER_INSERT            = 5'd7,
        S_RENDER_DELETE            = 5'd8,
        S_ENTER_RENDER_LOCAL       = 5'd9,
        S_ENTER_SEND_COMM          = 5'd10,
        S_ENTER_RENDER_INPUT_CLEAR = 5'd11,
        S_RX_RENDER                = 5'd12,
        S_STATUS_RENDER            = 5'd13,
        S_TX_REHELLO               = 5'd14,
        S_TX_GOODBYE               = 5'd15,
        S_RENDER_CONN_DISCONNECTED = 5'd16,
        S_DISCONNECTED_IDLE        = 5'd17,
        S_RENDER_SCROLL_UP         = 5'd18,
        S_RENDER_SCROLL_DOWN       = 5'd19,
        S_RENDER_INPUT_SCROLL_UP   = 5'd20,
        S_RENDER_INPUT_SCROLL_DOWN = 5'd21,
        // Multi-cycle byte-by-byte shift for KEY_CHAR insert /
        // KEY_BACKSPACE delete. Replaces the old in-S_IDLE parallel
        // shift over MAX_LINE_LEN, which Vivado was unrolling into a
        // 128-input mux per byte.
        S_LINE_INSERT              = 5'd22,
        S_LINE_DELETE              = 5'd23,
        // Multi-cycle token-expansion encoder for KEY_ENTER commit.
        // Replaces a 128-iter unrolled for-loop whose per-iteration
        // 19-token priority chain + 1024-bit dynamic bit-slice write
        // was blowing up Vivado RTL Opt Phase 2.
        S_LINE_ENCODE              = 5'd24,
        // Mouse click in input area: multi-cycle 2D→linear cursor
        // position conversion. Walks line_buf tracking visual rows.
        S_MOUSE_CLICK              = 5'd25
    } state_e;

    state_e state_q, state_d;

    // -----------------------------------------------------------------
    // State / scratch registers
    // -----------------------------------------------------------------
    byte_t                              line_buf [MAX_LINE_LEN];
    logic [LEN_WIDTH-1:0]               len_q;
    logic [LEN_WIDTH-1:0]               cursor_pos_q;
    logic                               enter_pulse_q;

    // last ASCII byte just inserted -- drives be_render_ascii during INSERT
    byte_t                              last_event_ascii_q;

    // S_LINE_INSERT/_DELETE byte-walk counter. Counts down (insert)
    // from len_q toward cursor_pos_q, or up (delete) from
    // cursor_pos_q - 1 toward len_q - 1.
    logic [LEN_WIDTH-1:0]               shift_idx_q;
    // Narrow index used to address line_buf (LINE_IDX_W bits suffice).
    logic [LINE_IDX_W-1:0]              shift_addr;
    assign shift_addr = shift_idx_q[LINE_IDX_W-1:0];

    // S_LINE_ENCODE source / destination pointers. enc_src_q walks
    // line_buf forward consuming token bytes; enc_dst_q walks
    // pending_payload_q forward emitting one anchor byte per token
    // (or one literal byte per non-token char).
    logic [LEN_WIDTH-1:0]               enc_src_q;
    logic [LEN_WIDTH-1:0]               enc_dst_q;

    // Allocation pointers (advance on every commit / on every rx accept).
    // Both reset to 0 on store_clear (peer changed).
    logic [STORE_IDX_W-1:0]             wr_ptr_q;
    msg_id_t                            next_msg_id_q;

    // Latched fields needed AFTER S_IDLE leaves them stale.
    msg_id_t                            pending_msg_id_q;
    msg_len_t                           pending_len_q;
    logic [MAX_MSG_LEN*8-1:0]           pending_payload_q;

    seq_t                               rx_seq_q;
    msg_len_t                           rx_len_q;
    logic [MAX_MSG_LEN*8-1:0]           rx_payload_q;

    msg_id_t                            status_msg_id_q;
    logic [1:0]                         status_status_q;

    // Peer username state (packed: byte i at bits [i*8 +: 8]).
    logic [MAX_NAME_LEN*8-1:0]          peer_name_q;
    msg_len_t                           peer_name_len_q;

    // Mouse click sticky latch (latest-wins). io_mouse_click_valid is
    // a 1-cycle pulse and the X/Y position regs in io_mouse keep moving
    // after the click. We need to (a) not lose the click if the FSM is
    // busy when it arrives and (b) keep the X/Y at the moment of the
    // click, not the moment the FSM gets around to processing it. If a
    // second click arrives while pending, the newest wins -- the older
    // un-consumed click is overwritten (FIFO would queue them up and
    // make the cursor teleport through every click in order, which is
    // not what anybody wants).
    logic                               click_pending_q;
    logic [6:0]                         click_raw_col_q;     // io_mouse_click_x[9:3]
    logic [5:0]                         click_screen_row_q;  // io_mouse_click_y[9:4]

    // Mouse click: walk registers for the multi-cycle 2D→linear
    // conversion in S_MOUSE_CLICK. click_walk_done_q gates the render
    // output -- without it, S_MOUSE_CLICK asserts be_render_valid on
    // cycle 1 with the stale cursor_pos_q, FE accepts, BE exits before
    // the walk has even started.
    logic [3:0]                         click_target_row_q;
    logic [6:0]                         click_target_col_q;
    logic [3:0]                         click_vis_row_q;
    logic [6:0]                         click_vis_col_q;
    logic                               click_walk_done_q;

    // -----------------------------------------------------------------
    // Combinational helpers
    // -----------------------------------------------------------------

    // Token encoder: one byte per cycle, single-step.
    //
    // Earlier this block was an unrolled `for (step ...; step <
    // MAX_LINE_LEN; ...)` loop with a 19-token priority chain and a
    // 1024-bit dynamic bit-slice write per iteration. Each iteration
    // carried src/dst across the next, so Vivado had to elaborate a
    // 128-stage serial combinational menu -- RTL Opt Phase 2 alone
    // was ~3 min and peak memory ~12 GB.
    //
    // The new shape evaluates the SAME priority chain once per cycle
    // against the current enc_src_q position, emits one byte into
    // pending_payload_q[enc_dst_q*8 +: 8], and advances. Total commit
    // latency grows by ~MAX_LINE_LEN cycles (~1.3 us @100 MHz), which
    // is invisible next to UART throughput and PS/2 key cadence.
    byte_t                enc_emit_byte;
    logic [3:0]           enc_src_delta;

    always_comb begin
        int src;

        enc_emit_byte = 8'h00;
        enc_src_delta = 4'd0;
        src = int'(enc_src_q);

        if ((src + 5 < int'(len_q))
         && (line_buf[src + 0] == 8'h5C)
         && (line_buf[src + 1] == "h")
         && (line_buf[src + 2] == "a")
         && (line_buf[src + 3] == "p")
         && (line_buf[src + 4] == "p")
         && (line_buf[src + 5] == "y")) begin
            enc_emit_byte = 8'hE0;
            enc_src_delta = 4'd6;
        end else if ((src + 5 < int'(len_q))
         && (line_buf[src + 0] == 8'h5C)
         && (line_buf[src + 1] == "l")
         && (line_buf[src + 2] == "a")
         && (line_buf[src + 3] == "u")
         && (line_buf[src + 4] == "g")
         && (line_buf[src + 5] == "h")) begin
            enc_emit_byte = 8'hE4;
            enc_src_delta = 4'd6;
        end else if ((src + 4 < int'(len_q))
         && (line_buf[src + 0] == 8'h5C)
         && (line_buf[src + 1] == "w")
         && (line_buf[src + 2] == "i")
         && (line_buf[src + 3] == "n")
         && (line_buf[src + 4] == "k")) begin
            enc_emit_byte = 8'hE5;
            enc_src_delta = 4'd5;
        end else if ((src + 5 < int'(len_q))
         && (line_buf[src + 0] == 8'h5C)
         && (line_buf[src + 1] == "a")
         && (line_buf[src + 2] == "n")
         && (line_buf[src + 3] == "g")
         && (line_buf[src + 4] == "r")
         && (line_buf[src + 5] == "y")) begin
            enc_emit_byte = 8'hE6;
            enc_src_delta = 4'd6;
        end else if ((src + 4 < int'(len_q))
         && (line_buf[src + 0] == 8'h5C)
         && (line_buf[src + 1] == "s")
         && (line_buf[src + 2] == "t")
         && (line_buf[src + 3] == "a")
         && (line_buf[src + 4] == "r")) begin
            enc_emit_byte = 8'hE7;
            enc_src_delta = 4'd5;
        end else if ((src + 4 < int'(len_q))
         && (line_buf[src + 0] == 8'h5C)
         && (line_buf[src + 1] == "f")
         && (line_buf[src + 2] == "i")
         && (line_buf[src + 3] == "r")
         && (line_buf[src + 4] == "e")) begin
            enc_emit_byte = 8'hE8;
            enc_src_delta = 4'd5;
        end else if ((src + 3 < int'(len_q))
         && (line_buf[src + 0] == 8'h5C)
         && (line_buf[src + 1] == "y")
         && (line_buf[src + 2] == "e")
         && (line_buf[src + 3] == "s")) begin
            enc_emit_byte = 8'hE9;
            enc_src_delta = 4'd4;
        end else if ((src + 2 < int'(len_q))
         && (line_buf[src + 0] == 8'h5C)
         && (line_buf[src + 1] == "n")
         && (line_buf[src + 2] == "o")) begin
            enc_emit_byte = 8'hEA;
            enc_src_delta = 4'd3;
        end else if ((src + 2 < int'(len_q))
         && (line_buf[src + 0] == 8'h5C)
         && (line_buf[src + 1] == "u")
         && (line_buf[src + 2] == "p")) begin
            enc_emit_byte = 8'hEB;
            enc_src_delta = 4'd3;
        end else if ((src + 4 < int'(len_q))
         && (line_buf[src + 0] == 8'h5C)
         && (line_buf[src + 1] == "d")
         && (line_buf[src + 2] == "o")
         && (line_buf[src + 3] == "w")
         && (line_buf[src + 4] == "n")) begin
            enc_emit_byte = 8'hEC;
            enc_src_delta = 4'd5;
        end else if ((src + 4 < int'(len_q))
         && (line_buf[src + 0] == 8'h5C)
         && (line_buf[src + 1] == "d")
         && (line_buf[src + 2] == "o")
         && (line_buf[src + 3] == "g")
         && (line_buf[src + 4] == "e")) begin
            enc_emit_byte = 8'hED;
            enc_src_delta = 4'd5;
        end else if ((src + 6 < int'(len_q))
         && (line_buf[src + 0] == 8'h5C)
         && (line_buf[src + 1] == "m")
         && (line_buf[src + 2] == "a")
         && (line_buf[src + 3] == "i")
         && (line_buf[src + 4] == "r")
         && (line_buf[src + 5] == "u")
         && (line_buf[src + 6] == "o")) begin
            enc_emit_byte = 8'hEE;
            enc_src_delta = 4'd7;
        end else if ((src + 5 < int'(len_q))
         && (line_buf[src + 0] == 8'h5C)
         && (line_buf[src + 1] == "h")
         && (line_buf[src + 2] == "e")
         && (line_buf[src + 3] == "a")
         && (line_buf[src + 4] == "r")
         && (line_buf[src + 5] == "t")) begin
            enc_emit_byte = 8'hE2;
            enc_src_delta = 4'd6;
        end else if ((src + 3 < int'(len_q))
         && (line_buf[src + 0] == 8'h5C)
         && (line_buf[src + 1] == "s")
         && (line_buf[src + 2] == "a")
         && (line_buf[src + 3] == "d")) begin
            enc_emit_byte = 8'hE1;
            enc_src_delta = 4'd4;
        end else if ((src + 2 < int'(len_q))
         && (line_buf[src + 0] == 8'h5C)
         && (line_buf[src + 1] == "o")
         && (line_buf[src + 2] == "k")) begin
            enc_emit_byte = 8'hE3;
            enc_src_delta = 4'd3;
        end
        // Big-emoji tokens (capital first letter) are appended via the
        // generated include. Each branch emits a single anchor byte;
        // the frontend expands the anchor into a 3 x 6 tile bubble on
        // render. Path mirrors fe_glyph_rom: Vivado searches the
        // source dir, Verilator searches cwd=repo-root.
`ifdef SYNTHESIS
        `include "be_big_emoji_tokens.svh"
`else
        `include "rtl/backend/be_big_emoji_tokens.svh"
`endif
        else begin
            enc_emit_byte = line_buf[src];
            enc_src_delta = 4'd1;
        end
    end

    // High in the LAST cycle of S_LINE_ENCODE: enc_src_q has caught up
    // to len_q so nothing more to emit. Used to fire store_wr, advance
    // wr_ptr_q / next_msg_id_q, and transition to S_ENTER_RENDER_LOCAL.
    logic enc_done;
    assign enc_done = (state_q == S_LINE_ENCODE) && (enc_src_q >= len_q);

    // MY_NAME zero-extended to MAX_MSG_LEN bytes for tx payload.
    logic [MAX_MSG_LEN*8-1:0] my_name_payload;
    assign my_name_payload =
        {{(MAX_MSG_LEN-MAX_NAME_LEN)*8{1'b0}}, MY_NAME_PACKED};

    // cm_rx_len clamp to MAX_MSG_LEN for DATA path.
    msg_len_t rx_len_clamped;
    assign rx_len_clamped =
        (cm_rx_len > LEN_WIDTH'(MAX_MSG_LEN)) ? LEN_WIDTH'(MAX_MSG_LEN)
                                              : cm_rx_len;

    // cm_rx_len clamp to MAX_NAME_LEN for username path.
    msg_len_t rx_name_len_clamped;
    assign rx_name_len_clamped =
        (cm_rx_len > LEN_WIDTH'(MAX_NAME_LEN)) ? LEN_WIDTH'(MAX_NAME_LEN)
                                               : cm_rx_len;

    // True when rx username (HELLO/REHELLO/USERNAME) differs from
    // currently-stored peer_name_q -- triggers store_clear.
    logic peer_name_changed;
    always_comb begin
        peer_name_changed = (rx_name_len_clamped != peer_name_len_q);
        for (int i = 0; i < MAX_NAME_LEN; i++) begin
            if (i < int'(rx_name_len_clamped) &&
                cm_rx_payload[i*8 +: 8] != peer_name_q[i*8 +: 8])
                peer_name_changed = 1'b1;
        end
    end

    // Frame-type aliases (prevent stray casts).
    logic rx_is_data, rx_is_hello, rx_is_rehello, rx_is_username, rx_is_goodbye;
    assign rx_is_data     = (cm_rx_frame_type == 3'(FRAME_DATA));
    assign rx_is_hello    = (cm_rx_frame_type == 3'(FRAME_HELLO));
    assign rx_is_rehello  = (cm_rx_frame_type == 3'(FRAME_REHELLO));
    assign rx_is_username = (cm_rx_frame_type == 3'(FRAME_USERNAME));
    assign rx_is_goodbye  = (cm_rx_frame_type == 3'(FRAME_GOODBYE));

    // -----------------------------------------------------------------
    // Backpressure (ready) signals
    //
    // S_IDLE              : full arbitration cm_status > cm_rx > io_key.
    // S_HANDSHAKE_IDLE    : accepts cm_rx and io_key (drops most types).
    // S_DISCONNECTED_IDLE : accepts cm_rx and io_key.
    // Other states        : do not accept (transient emitters wait on
    //                       be_tx_ready / be_render_ready).
    // -----------------------------------------------------------------
    logic in_chat_idle, in_handshake_idle, in_disc_idle;
    assign in_chat_idle      = (state_q == S_IDLE);
    assign in_handshake_idle = (state_q == S_HANDSHAKE_IDLE);
    assign in_disc_idle      = (state_q == S_DISCONNECTED_IDLE);

    assign cm_status_ready = in_chat_idle;
    assign cm_rx_ready     = (in_chat_idle && !cm_status_valid)
                          || in_handshake_idle
                          || in_disc_idle;
    assign io_key_ready    = (in_chat_idle && !cm_status_valid && !cm_rx_valid)
                          || (in_handshake_idle && !cm_rx_valid)
                          || (in_disc_idle      && !cm_rx_valid);
    // click_ready stays a level signal driven from BE state for symmetry
    // with the other accept ports, but io_mouse never reads it: clicks
    // are 1-cycle pulses, captured unconditionally by the sticky latch
    // below.
    assign io_mouse_click_ready = in_chat_idle && !cm_status_valid
                               && !cm_rx_valid && !io_key_valid;

    logic accept_io;
    logic accept_rx;
    logic accept_status;
    logic accept_mouse_click;
    assign accept_status      = cm_status_valid      && cm_status_ready;
    assign accept_rx          = cm_rx_valid           && cm_rx_ready;
    assign accept_io          = io_key_valid          && io_key_ready;
    // Consume the latched click, not the live pulse: the pulse can fire
    // while BE is in any state, and we want to act on it as soon as the
    // gating conditions allow.
    assign accept_mouse_click = click_pending_q       && io_mouse_click_ready;

    // -----------------------------------------------------------------
    // Next-state logic
    // -----------------------------------------------------------------
    always_comb begin
        state_d = state_q;
        unique case (state_q)
            S_BOOT_REDRAW: begin
                if (be_render_ready) state_d = S_TX_HELLO;
            end

            S_TX_HELLO: begin
                if (be_tx_ready) state_d = S_HANDSHAKE_IDLE;
            end

            S_HANDSHAKE_IDLE: begin
                if (accept_rx) begin
                    if (rx_is_hello || rx_is_rehello)
                        state_d = S_TX_USERNAME;
                    else if (rx_is_username)
                        state_d = S_RENDER_CONN_CONNECTED;
                    // DATA / GOODBYE / unknown: drop, stay
                end
                // io key events accepted but ignored (drop).
            end

            S_TX_USERNAME: begin
                if (be_tx_ready) state_d = S_RENDER_CONN_CONNECTED;
            end

            S_RENDER_CONN_CONNECTED: begin
                if (be_render_ready) state_d = S_IDLE;
            end

            S_IDLE: begin
                if (accept_status) begin
                    state_d = S_STATUS_RENDER;
                end else if (accept_rx) begin
                    if (rx_is_data) begin
                        state_d = S_RX_RENDER;
                    end else if (rx_is_hello) begin
                        state_d = S_TX_REHELLO;
                    end else if (rx_is_rehello) begin
                        state_d = S_TX_USERNAME;
                    end else if (rx_is_username) begin
                        state_d = S_RENDER_CONN_CONNECTED;
                    end else if (rx_is_goodbye) begin
                        state_d = S_RENDER_CONN_DISCONNECTED;
                    end
                end else if (accept_io) begin
                    unique case (key_type_e'(io_key_type))
                        // KEY_CHAR / KEY_BACKSPACE no longer shift
                        // line_buf in-place during this cycle -- they
                        // hand off to S_LINE_INSERT / S_LINE_DELETE,
                        // which walk the buffer one byte per cycle.
                        // The subsequent S_RENDER_INSERT / _DELETE
                        // emit the BE->FE render command unchanged.
                        KEY_CHAR: begin
                            state_d = (len_q < LEN_WIDTH'(MAX_LINE_LEN))
                                      ? S_LINE_INSERT : S_IDLE;
                        end
                        KEY_BACKSPACE: begin
                            state_d = (cursor_pos_q != 0)
                                      ? S_LINE_DELETE : S_IDLE;
                        end
                        KEY_LEFT: begin
                            state_d = (cursor_pos_q != 0)
                                      ? S_RENDER_MOVE_CURSOR : S_IDLE;
                        end
                        KEY_RIGHT: begin
                            state_d = (cursor_pos_q < len_q)
                                      ? S_RENDER_MOVE_CURSOR : S_IDLE;
                        end
                        KEY_ENTER: begin
                            // S_LINE_ENCODE is the multi-cycle token
                            // expander; it transitions on to
                            // S_ENTER_RENDER_LOCAL when done.
                            state_d = (len_q != 0)
                                      ? S_LINE_ENCODE : S_IDLE;
                        end
                        KEY_ESC: begin
                            state_d = S_TX_GOODBYE;
                        end
                        // Shift+Up/Down scroll the input area (multi-row
                        // input buffer); plain Up/Down scroll history.
                        KEY_UP: state_d = (io_key_ascii[0])
                                          ? S_RENDER_INPUT_SCROLL_UP
                                          : S_RENDER_SCROLL_UP;
                        KEY_DOWN: state_d = (io_key_ascii[0])
                                            ? S_RENDER_INPUT_SCROLL_DOWN
                                            : S_RENDER_SCROLL_DOWN;
                        default: state_d = S_IDLE;
                    endcase
                end else if (accept_mouse_click) begin
                    // Only transition if click falls within the input area
                    // (screen rows 32..36, i.e. pixel Y 512..591). Clicks
                    // outside the input area still consume the pending
                    // latch (BE returns to S_IDLE next cycle) so they
                    // don't stick around.
                    if (click_screen_row_q >= 6'd32 &&
                        click_screen_row_q <= 6'd36)
                        state_d = S_MOUSE_CLICK;
                end
            end

            S_LINE_INSERT: begin
                // Stay until shift_idx_q reaches cursor_pos_q (the
                // cycle that writes the new ascii); on that cycle the
                // sequential block flips state_d to S_RENDER_INSERT.
                if (shift_idx_q == cursor_pos_q) state_d = S_RENDER_INSERT;
            end
            S_LINE_DELETE: begin
                // Symmetric: walks shift_idx_q UP from cursor_pos_q-1
                // to len_q-1 (or stops immediately when there's nothing
                // to shift, i.e. cursor at the end of the buffer).
                if (shift_idx_q >= len_q - LEN_WIDTH'(1))
                    state_d = S_RENDER_DELETE;
            end
            S_LINE_ENCODE: begin
                // Stay here while bytes remain to encode; exit on the
                // cycle that finds enc_src_q already caught up to len_q
                // (that's the cycle store_wr fires, see below).
                if (enc_src_q >= len_q) state_d = S_ENTER_RENDER_LOCAL;
            end
            S_RENDER_MOVE_CURSOR:       if (be_render_ready) state_d = S_IDLE;
            S_RENDER_INSERT:            if (be_render_ready) state_d = S_IDLE;
            S_RENDER_DELETE:            if (be_render_ready) state_d = S_IDLE;
            S_RENDER_SCROLL_UP:         if (be_render_ready) state_d = S_IDLE;
            S_RENDER_SCROLL_DOWN:       if (be_render_ready) state_d = S_IDLE;
            S_RENDER_INPUT_SCROLL_UP:   if (be_render_ready) state_d = S_IDLE;
            S_RENDER_INPUT_SCROLL_DOWN: if (be_render_ready) state_d = S_IDLE;
            // Stay in S_MOUSE_CLICK while the walk progresses; only emit
            // the render command once cursor_pos_q has been resolved.
            S_MOUSE_CLICK: if (click_walk_done_q && be_render_ready) state_d = S_IDLE;
            S_ENTER_RENDER_LOCAL:       if (be_render_ready) state_d = S_ENTER_SEND_COMM;
            S_ENTER_SEND_COMM:          if (be_tx_ready)     state_d = S_ENTER_RENDER_INPUT_CLEAR;
            S_ENTER_RENDER_INPUT_CLEAR: if (be_render_ready) state_d = S_IDLE;
            S_RX_RENDER:                if (be_render_ready) state_d = S_IDLE;
            S_STATUS_RENDER:            if (be_render_ready) state_d = S_IDLE;

            S_TX_REHELLO: begin
                if (be_tx_ready) state_d = S_RENDER_CONN_CONNECTED;
            end

            S_TX_GOODBYE: begin
                if (be_tx_ready) state_d = S_RENDER_CONN_DISCONNECTED;
            end

            S_RENDER_CONN_DISCONNECTED: begin
                if (be_render_ready) state_d = S_DISCONNECTED_IDLE;
            end

            S_DISCONNECTED_IDLE: begin
                if (accept_rx) begin
                    if (rx_is_hello || rx_is_rehello)
                        state_d = S_TX_USERNAME;
                    // USERNAME / DATA / GOODBYE: drop, stay
                end else if (accept_io) begin
                    if ((key_type_e'(io_key_type) == KEY_CHAR) &&
                        (io_key_ascii == 8'h20))  // SPACE
                        state_d = S_TX_HELLO;
                end
            end

            default: state_d = S_BOOT_REDRAW;
        endcase
    end

    // -----------------------------------------------------------------
    // be_tx output drivers
    // -----------------------------------------------------------------
    always_comb begin
        be_tx_valid      = 1'b0;
        be_tx_frame_type = 3'(FRAME_DATA);
        be_tx_msg_id     = '0;
        be_tx_len        = '0;
        be_tx_payload    = '0;

        unique case (state_q)
            S_TX_HELLO: begin
                be_tx_valid      = 1'b1;
                be_tx_frame_type = 3'(FRAME_HELLO);
                be_tx_len        = LEN_WIDTH'(MY_NAME_LEN);
                be_tx_payload    = my_name_payload;
            end
            S_TX_USERNAME: begin
                be_tx_valid      = 1'b1;
                be_tx_frame_type = 3'(FRAME_USERNAME);
                be_tx_len        = LEN_WIDTH'(MY_NAME_LEN);
                be_tx_payload    = my_name_payload;
            end
            S_TX_REHELLO: begin
                be_tx_valid      = 1'b1;
                be_tx_frame_type = 3'(FRAME_REHELLO);
                be_tx_len        = LEN_WIDTH'(MY_NAME_LEN);
                be_tx_payload    = my_name_payload;
            end
            S_TX_GOODBYE: begin
                be_tx_valid      = 1'b1;
                be_tx_frame_type = 3'(FRAME_GOODBYE);
            end
            S_ENTER_SEND_COMM: begin
                be_tx_valid      = 1'b1;
                be_tx_frame_type = 3'(FRAME_DATA);
                be_tx_msg_id     = pending_msg_id_q;
                be_tx_len        = pending_len_q;
                be_tx_payload    = pending_payload_q;
            end
            default: ;
        endcase
    end

    // -----------------------------------------------------------------
    // be_render output drivers
    // -----------------------------------------------------------------
    always_comb begin
        be_render_valid       = 1'b0;
        be_render_cmd         = 4'd0;
        be_render_msg_id      = '0;
        be_render_side        = 2'd0;
        be_render_status      = 2'd0;
        be_render_len         = '0;
        be_render_payload     = '0;
        be_render_cursor_pos  = '0;
        be_render_ascii       = 8'd0;

        unique case (state_q)
            S_BOOT_REDRAW: begin
                be_render_valid = 1'b1;
                be_render_cmd   = 4'(RENDER_REDRAW_ALL);
            end
            S_RENDER_MOVE_CURSOR: begin
                be_render_valid      = 1'b1;
                be_render_cmd        = 4'(RENDER_MOVE_CURSOR);
                be_render_cursor_pos = cursor_pos_q;
            end
            S_RENDER_INSERT: begin
                be_render_valid      = 1'b1;
                be_render_cmd        = 4'(RENDER_INSERT_AT_CURSOR);
                be_render_cursor_pos = cursor_pos_q;
                be_render_ascii      = last_event_ascii_q;
            end
            S_RENDER_DELETE: begin
                be_render_valid      = 1'b1;
                be_render_cmd        = 4'(RENDER_DELETE_AT_CURSOR);
                be_render_cursor_pos = cursor_pos_q;
            end
            S_ENTER_RENDER_LOCAL: begin
                be_render_valid   = 1'b1;
                be_render_cmd     = 4'(RENDER_APPEND_LOCAL_PENDING);
                be_render_msg_id  = pending_msg_id_q;
                be_render_side    = 2'(MSG_LOCAL);
                be_render_status  = 2'(MSG_PENDING);
                be_render_len     = pending_len_q;
                be_render_payload = pending_payload_q;
            end
            S_ENTER_RENDER_INPUT_CLEAR: begin
                be_render_valid      = 1'b1;
                be_render_cmd        = 4'(RENDER_UPDATE_INPUT_LINE);
                be_render_side       = 2'(MSG_LOCAL);
                be_render_status     = 2'(MSG_PENDING);
                be_render_len        = '0;
                be_render_cursor_pos = '0;
            end
            S_RX_RENDER: begin
                be_render_valid   = 1'b1;
                be_render_cmd     = 4'(RENDER_APPEND_REMOTE);
                be_render_msg_id  = msg_id_t'(rx_seq_q);
                be_render_side    = 2'(MSG_REMOTE);
                be_render_status  = 2'(MSG_SUCCESS);
                be_render_len     = rx_len_q;
                be_render_payload = rx_payload_q;
            end
            S_STATUS_RENDER: begin
                be_render_valid   = 1'b1;
                be_render_cmd     = 4'(RENDER_UPDATE_STATUS);
                be_render_msg_id  = status_msg_id_q;
                be_render_side    = 2'(MSG_LOCAL);
                be_render_status  = status_status_q;
                be_render_len     = '0;
            end
            S_RENDER_CONN_CONNECTED: begin
                be_render_valid   = 1'b1;
                be_render_cmd     = 4'(RENDER_CONN_STATE);
            end
            S_RENDER_CONN_DISCONNECTED: begin
                be_render_valid   = 1'b1;
                be_render_cmd     = 4'(RENDER_CONN_STATE);
            end
            S_RENDER_SCROLL_UP: begin
                be_render_valid = 1'b1;
                be_render_cmd   = 4'(RENDER_SCROLL_UP);
            end
            S_RENDER_SCROLL_DOWN: begin
                be_render_valid = 1'b1;
                be_render_cmd   = 4'(RENDER_SCROLL_DOWN);
            end
            S_RENDER_INPUT_SCROLL_UP: begin
                be_render_valid = 1'b1;
                be_render_cmd   = 4'(RENDER_INPUT_SCROLL_UP);
            end
            S_RENDER_INPUT_SCROLL_DOWN: begin
                be_render_valid = 1'b1;
                be_render_cmd   = 4'(RENDER_INPUT_SCROLL_DOWN);
            end
            S_MOUSE_CLICK: begin
                // Gated on walk_done so the FE doesn't latch a stale
                // cursor_pos_q on cycle 1 of the walk.
                be_render_valid      = click_walk_done_q;
                be_render_cmd        = 4'(RENDER_MOVE_CURSOR);
                be_render_cursor_pos = cursor_pos_q;
            end
            default: ;
        endcase
    end

    // be_render_conn_state always tracks the current logical conn state
    // -- frontend uses it on RENDER_CONN_STATE / RENDER_REDRAW_ALL.
    always_comb begin
        unique case (state_q)
            S_BOOT_REDRAW, S_TX_HELLO:
                be_render_conn_state = 2'(CONN_BOOT);
            S_HANDSHAKE_IDLE, S_TX_USERNAME:
                be_render_conn_state = 2'(CONN_HANDSHAKE);
            S_TX_GOODBYE, S_RENDER_CONN_DISCONNECTED, S_DISCONNECTED_IDLE:
                be_render_conn_state = 2'(CONN_DISCONNECTED);
            default:  // includes S_RENDER_CONN_CONNECTED, S_IDLE, edit/commit/rx/status, S_TX_REHELLO
                be_render_conn_state = 2'(CONN_CONNECTED);
        endcase
    end

    assign be_render_peer_name     = peer_name_q;
    assign be_render_peer_name_len = peer_name_len_q;
    assign conn_state_obs          = be_render_conn_state;

    // -----------------------------------------------------------------
    // Observability
    // -----------------------------------------------------------------
    assign line_rd_data    = line_buf[line_rd_idx];
    assign line_len        = len_q;
    assign cursor_pos      = cursor_pos_q;
    assign enter_committed = enter_pulse_q;

    // -----------------------------------------------------------------
    // Username latch + store_clear pulse
    //
    // Whenever an idle state accepts a HELLO / REHELLO / USERNAME, we
    // latch the new peer_name and (if it differs) clear the store and
    // reset wr_ptr / next_msg_id.
    // -----------------------------------------------------------------
    logic accept_username_frame;
    assign accept_username_frame = accept_rx
                                && (rx_is_hello || rx_is_rehello || rx_is_username);

    logic do_store_clear;
    assign do_store_clear = accept_username_frame && peer_name_changed;

    // -----------------------------------------------------------------
    // Sequential logic
    // -----------------------------------------------------------------
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state_q            <= S_BOOT_REDRAW;
            len_q              <= '0;
            cursor_pos_q       <= '0;
            enter_pulse_q      <= 1'b0;
            wr_ptr_q           <= '0;
            next_msg_id_q      <= '0;
            pending_msg_id_q   <= '0;
            pending_len_q      <= '0;
            pending_payload_q  <= '0;
            rx_seq_q           <= '0;
            rx_len_q           <= '0;
            rx_payload_q       <= '0;
            status_msg_id_q    <= '0;
            status_status_q    <= '0;
            last_event_ascii_q <= 8'd0;
            shift_idx_q        <= '0;
            enc_src_q          <= '0;
            enc_dst_q          <= '0;
            peer_name_len_q    <= '0;
            peer_name_q        <= '0;
            click_pending_q    <= 1'b0;
            click_raw_col_q    <= '0;
            click_screen_row_q <= '0;
            click_target_row_q <= '0;
            click_target_col_q <= '0;
            click_vis_row_q    <= '0;
            click_vis_col_q    <= '0;
            click_walk_done_q  <= 1'b0;
            for (int i = 0; i < MAX_LINE_LEN; i++) line_buf[i]    <= 8'd0;
        end else begin
            state_q       <= state_d;
            enter_pulse_q <= 1'b0;

            // -------------------------------------------------------------
            // Pre-load shift_idx_q on entry to the multi-cycle shift
            // states. KEY_CHAR/_BACKSPACE in S_IDLE just latches
            // last_event_ascii_q; the actual line_buf walk starts here.
            // -------------------------------------------------------------
            if (state_q == S_IDLE && state_d == S_LINE_INSERT) begin
                shift_idx_q <= len_q;
            end
            if (state_q == S_IDLE && state_d == S_LINE_DELETE) begin
                shift_idx_q <= cursor_pos_q - LEN_WIDTH'(1);
            end

            // -------------------------------------------------------------
            // S_LINE_INSERT: shift line_buf[cursor_pos_q..len_q] right by
            // one and drop last_event_ascii_q into line_buf[cursor_pos_q].
            // Walks shift_idx_q from len_q down to cursor_pos_q, doing one
            // byte per cycle.
            // -------------------------------------------------------------
            if (state_q == S_LINE_INSERT) begin
                if (shift_idx_q == cursor_pos_q) begin
                    line_buf[shift_addr] <= last_event_ascii_q;
                    len_q        <= len_q        + LEN_WIDTH'(1);
                    cursor_pos_q <= cursor_pos_q + LEN_WIDTH'(1);
                end else begin
                    line_buf[shift_addr] <= line_buf[
                        LINE_IDX_W'(shift_idx_q - LEN_WIDTH'(1))];
                    shift_idx_q <= shift_idx_q - LEN_WIDTH'(1);
                end
            end

            // -------------------------------------------------------------
            // S_LINE_DELETE: shift line_buf[cursor_pos_q..len_q-1] left by
            // one. Walks shift_idx_q UP from cursor_pos_q-1 to len_q-1.
            // The "no shift needed" case (cursor at end of buffer)
            // collapses to a single cycle that just decrements counters.
            // -------------------------------------------------------------
            if (state_q == S_LINE_DELETE) begin
                if (shift_idx_q >= len_q - LEN_WIDTH'(1)) begin
                    len_q        <= len_q        - LEN_WIDTH'(1);
                    cursor_pos_q <= cursor_pos_q - LEN_WIDTH'(1);
                end else begin
                    line_buf[shift_addr] <= line_buf[
                        LINE_IDX_W'(shift_idx_q + LEN_WIDTH'(1))];
                    shift_idx_q <= shift_idx_q + LEN_WIDTH'(1);
                end
            end

            // -------------------------------------------------------------
            // S_LINE_ENCODE: one byte per cycle. While bytes remain
            // (enc_src_q < len_q), drop the encoder's emitted byte into
            // pending_payload_q[enc_dst_q] and advance both pointers.
            // The final "done" cycle (enc_src_q >= len_q) latches the
            // total length, clears the input line, and advances the
            // store write-pointer + msg_id allocator. store_wr_en fires
            // combinationally on the same cycle (see store_wr block).
            // -------------------------------------------------------------
            if (state_q == S_LINE_ENCODE) begin
                if (enc_src_q < len_q) begin
                    pending_payload_q[enc_dst_q*8 +: 8] <= enc_emit_byte;
                    enc_src_q <= enc_src_q + LEN_WIDTH'(enc_src_delta);
                    enc_dst_q <= enc_dst_q + LEN_WIDTH'(1);
                end else begin
                    pending_len_q <= enc_dst_q;
                    len_q         <= '0;
                    cursor_pos_q  <= '0;
                    wr_ptr_q      <= wr_ptr_q + 1'b1;
                    next_msg_id_q <= next_msg_id_q + 8'd1;
                end
            end

            // -------------------------------------------------------------
            // S_MOUSE_CLICK: multi-cycle 2D→linear cursor conversion.
            // Walks line_buf[shift_idx_q] tracking visual row/col.
            // Newline (0x0A) or soft wrap (96 chars) advances the
            // visual row.  When click_vis_row matches the target,
            // cursor_pos_q is set and we transition to S_RENDER_MOVE_CURSOR.
            // INPUT_SOFT_WRAP_W = 96 (matches fe_render_decoder).
            // -------------------------------------------------------------
            if (state_q == S_IDLE && state_d == S_MOUSE_CLICK) begin
                // Latch click target from the *latched* click coords so
                // intermediate mouse movement between click and FSM
                // pickup doesn't change where the cursor lands.
                automatic logic [6:0] raw_col;
                automatic logic [5:0] buf_row;
                raw_col = click_raw_col_q;
                // Buffer row = (screen_row - 32) + scroll offset.
                buf_row = click_screen_row_q - 6'd32
                          + {1'b0, fe_input_scroll_offset};
                click_target_row_q <= buf_row[3:0];
                // Adjust col for the "> " prefix on buffer row 0.
                if (buf_row == '0)
                    click_target_col_q <= (raw_col > 7'd2)
                                          ? raw_col - 7'd2 : 7'd0;
                else
                    click_target_col_q <= raw_col;
                // Init walk registers
                shift_idx_q       <= '0;
                click_vis_row_q   <= '0;
                click_vis_col_q   <= '0;
                click_walk_done_q <= 1'b0;
            end

            // The walk only runs while !done. Once we've resolved
            // cursor_pos_q the FSM sits in S_MOUSE_CLICK with
            // be_render_valid asserted waiting for FE ready.
            if (state_q == S_MOUSE_CLICK && !click_walk_done_q) begin
                if (shift_idx_q >= len_q) begin
                    // Walked past end without matching row: clamp
                    cursor_pos_q      <= len_q;
                    click_walk_done_q <= 1'b1;
                end else begin
                    automatic byte_t cur_byte;
                    cur_byte = line_buf[shift_idx_q[LINE_IDX_W-1:0]];
                    if (click_vis_row_q == click_target_row_q
                        && click_vis_col_q >= click_target_col_q) begin
                        // Found the target position
                        cursor_pos_q      <= shift_idx_q;
                        click_walk_done_q <= 1'b1;
                    end else begin
                        // Advance position trackers
                        if (cur_byte == 8'h0A) begin
                            // Newline: advance to next visual row
                            click_vis_row_q <= click_vis_row_q + 4'd1;
                            click_vis_col_q <= '0;
                        end else begin
                            click_vis_col_q <= click_vis_col_q + 7'd1;
                            if (click_vis_col_q == 7'd95) begin
                                // Soft wrap at 96 chars
                                click_vis_row_q <= click_vis_row_q + 4'd1;
                                click_vis_col_q <= '0;
                            end
                        end
                        shift_idx_q <= shift_idx_q + LEN_WIDTH'(1);
                    end
                end
            end

            // -------------------------------------------------------------
            // Mouse-click sticky latch (latest-wins). io_mouse_click_valid
            // is a 1-cycle pulse from io_mouse; clicks must not be lost
            // when BE isn't in S_IDLE, but rapid clicks should NOT queue --
            // only the most recent un-consumed click matters. The pulse
            // also takes priority over accept_mouse_click in the same
            // cycle so a click landing exactly as BE picks one up isn't
            // dropped on the floor.
            // -------------------------------------------------------------
            if (io_mouse_click_valid) begin
                click_raw_col_q    <= io_mouse_click_x[9:3];
                click_screen_row_q <= io_mouse_click_y[9:4];
                click_pending_q    <= 1'b1;
            end else if (accept_mouse_click) begin
                click_pending_q    <= 1'b0;
            end

            // -------------------------------------------------------------
            // Username latch + ptr resets (idle states that accept username)
            // -------------------------------------------------------------
            if (accept_username_frame) begin
                peer_name_len_q <= rx_name_len_clamped;
                for (int i = 0; i < MAX_NAME_LEN; i++) begin
                    peer_name_q[i*8 +: 8] <= (i < int'(rx_name_len_clamped))
                                              ? cm_rx_payload[i*8 +: 8] : 8'd0;
                end
                if (peer_name_changed) begin
                    wr_ptr_q      <= '0;
                    next_msg_id_q <= '0;
                end
            end

            // -------------------------------------------------------------
            // Chat IDLE: arbitration latches (cm_status / cm_rx / io)
            // -------------------------------------------------------------
            if (state_q == S_IDLE) begin
                if (accept_status) begin
                    status_msg_id_q <= cm_status_msg_id;
                    status_status_q <= (cm_status_code == 2'(TX_SUCCESS))
                                       ? 2'(MSG_SUCCESS) : 2'(MSG_FAIL);
                end
                else if (accept_rx && rx_is_data) begin
                    rx_seq_q     <= cm_rx_seq;
                    rx_len_q     <= rx_len_clamped;
                    rx_payload_q <= cm_rx_payload;
                    wr_ptr_q     <= wr_ptr_q + 1'b1;
                end
                else if (accept_io) begin
                    unique case (key_type_e'(io_key_type))

                        KEY_CHAR: begin
                            // Just latch the ASCII byte for the
                            // sequential walk in S_LINE_INSERT. shift
                            // counter init happens via entering_new_state
                            // below; len_q / cursor_pos_q update on
                            // the LAST cycle of S_LINE_INSERT.
                            if (len_q < LEN_WIDTH'(MAX_LINE_LEN)) begin
                                last_event_ascii_q <= io_key_ascii;
                            end
                        end

                        KEY_BACKSPACE: begin
                            // Same idea -- the actual shift is the
                            // job of S_LINE_DELETE.
                        end

                        KEY_LEFT: begin
                            if (cursor_pos_q != 0)
                                cursor_pos_q <= cursor_pos_q - LEN_WIDTH'(1);
                        end

                        KEY_RIGHT: begin
                            if (cursor_pos_q < len_q)
                                cursor_pos_q <= cursor_pos_q + LEN_WIDTH'(1);
                        end

                        KEY_ENTER: begin
                            if (len_q != 0) begin
                                // Kick off the encoder. pending_payload_q
                                // is cleared so bytes past the encoded
                                // length stay 0 (test_payload_packed_
                                // correctly relies on this). The actual
                                // line clear, wr_ptr / msg_id advance,
                                // and store_wr all happen in the
                                // encoder's done cycle (state_q ==
                                // S_LINE_ENCODE && enc_src_q >= len_q).
                                pending_msg_id_q  <= next_msg_id_q;
                                pending_payload_q <= '0;
                                enc_src_q         <= '0;
                                enc_dst_q         <= '0;
                                enter_pulse_q     <= 1'b1;
                            end
                        end

                        // ESC and other keys: no buffer update; FSM
                        // transition handled by next-state logic.
                        default: ;
                    endcase
                end
            end

            // -------------------------------------------------------------
            // ESC -> S_TX_GOODBYE: also clear the in-flight input line
            // (so reconnect doesn't show stale typing).
            // -------------------------------------------------------------
            if ((state_q == S_IDLE) && accept_io
              && (key_type_e'(io_key_type) == KEY_ESC)) begin
                len_q        <= '0;
                cursor_pos_q <= '0;
            end

        end
    end

    // -----------------------------------------------------------------
    // Store write / status-update / clear drivers (combinational)
    // -----------------------------------------------------------------
    logic                          store_wr_en;
    logic [STORE_IDX_W-1:0]        store_wr_idx;
    msg_id_t                       store_wr_msg_id;
    logic [1:0]                    store_wr_side;
    logic [1:0]                    store_wr_status;
    msg_len_t                      store_wr_len;
    logic [MAX_MSG_LEN*8-1:0]      store_wr_payload;

    always_comb begin
        store_wr_en      = 1'b0;
        store_wr_idx     = wr_ptr_q;
        store_wr_msg_id  = '0;
        store_wr_side    = 2'd0;
        store_wr_status  = 2'd0;
        store_wr_len     = '0;
        store_wr_payload = '0;

        if (state_q == S_IDLE) begin
            if (accept_rx && rx_is_data) begin
                store_wr_en      = 1'b1;
                store_wr_msg_id  = msg_id_t'(cm_rx_seq);
                store_wr_side    = 2'(MSG_REMOTE);
                store_wr_status  = 2'(MSG_SUCCESS);
                store_wr_len     = rx_len_clamped;
                store_wr_payload = cm_rx_payload;
            end
        end else if (enc_done) begin
            // Encoder finished: pending_payload_q holds the encoded
            // bytes, enc_dst_q is the total length, pending_msg_id_q
            // was latched on KEY_ENTER. wr_ptr_q is still the
            // pre-increment value this cycle (NBA bumps it on the
            // posedge), so store_wr_idx lands in the right slot.
            store_wr_en      = 1'b1;
            store_wr_msg_id  = pending_msg_id_q;
            store_wr_side    = 2'(MSG_LOCAL);
            store_wr_status  = 2'(MSG_PENDING);
            store_wr_len     = enc_dst_q;
            store_wr_payload = pending_payload_q;
        end
    end

    logic                       store_lookup_hit;
    logic [STORE_IDX_W-1:0]     store_lookup_idx;

    logic                       store_upd_en;
    logic [STORE_IDX_W-1:0]     store_upd_idx;
    logic [1:0]                 store_upd_status;

    assign store_upd_en     = (state_q == S_IDLE) && accept_status && store_lookup_hit;
    assign store_upd_idx    = store_lookup_idx;
    assign store_upd_status = (cm_status_code == 2'(TX_SUCCESS))
                              ? 2'(MSG_SUCCESS) : 2'(MSG_FAIL);

    // -----------------------------------------------------------------
    // Message store instance
    // -----------------------------------------------------------------
    be_message_store u_store (
        .clk            (clk),
        .rst_n          (rst_n),

        .wr_en          (store_wr_en),
        .wr_idx         (store_wr_idx),
        .wr_msg_id      (store_wr_msg_id),
        .wr_side        (store_wr_side),
        .wr_status      (store_wr_status),
        .wr_len         (store_wr_len),
        .wr_payload     (store_wr_payload),

        .upd_en         (store_upd_en),
        .upd_idx        (store_upd_idx),
        .upd_status     (store_upd_status),

        .clear_en       (do_store_clear),

        .rd_idx         (store_rd_idx),
        .rd_valid       (store_rd_valid),
        .rd_msg_id      (store_rd_msg_id),
        .rd_side        (store_rd_side),
        .rd_status      (store_rd_status),
        .rd_len         (store_rd_len),
        .rd_payload     (store_rd_payload),

        .lookup_msg_id  (cm_status_msg_id),
        .lookup_hit     (store_lookup_hit),
        .lookup_idx     (store_lookup_idx)
    );

endmodule

`endif  // BE_TOP_SV
