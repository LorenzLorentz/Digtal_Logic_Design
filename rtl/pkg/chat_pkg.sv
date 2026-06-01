// =====================================================================
// chat_pkg.sv
// ---------------------------------------------------------------------
// Shared types, enums and parameters for the chat system.
//
// Naming convention:
//   - Identifiers that cross module boundaries live here, prefixed by
//     subsystem (KEY_*, TX_*, MSG_*, RENDER_*, FRAME_*).
//   - FSM-internal state encodings are declared LOCALLY inside each
//     module and must NOT appear in this package.
// =====================================================================

`ifndef CHAT_PKG_SV
`define CHAT_PKG_SV

package chat_pkg;

    // -----------------------------------------------------------------
    // Sizing parameters
    // -----------------------------------------------------------------
    // Variable-length payload support. 128 is the current compile-and-
    // board-test setting; the wire format still uses the 16-bit LEN
    // (LEN_HI / LEN_LO) introduced in P2, so raising this back to
    // 256/640 is a one-line change here -- see docs/synthesis_perf.md
    // for the elab-time/BRAM trade-offs at higher MAX_MSG_LEN.
    localparam int MAX_MSG_LEN  = 128;   // bytes per chat message payload
    localparam int MAX_MSG_NUM  = 64;    // chat history depth
    localparam int MAX_LINE_LEN = 128;   // current input line buffer
    localparam int MAX_NAME_LEN = 16;    // peer username (ASCII bytes)

    localparam int MSG_ID_WIDTH = 8;
    localparam int SEQ_WIDTH    = 8;
    localparam int LEN_WIDTH    = 16;
    localparam int RETRY_WIDTH  = 4;

    localparam int MAX_RETRY    = 4;    // max retransmissions before TX_FAIL

    // -----------------------------------------------------------------
    // Frame layer constants
    // -----------------------------------------------------------------
    localparam logic [7:0]  SOF_BYTE   = 8'h7E;
    localparam int          CRC_WIDTH  = 16;
    localparam logic [15:0] CRC16_POLY = 16'h1021;  // CCITT
    localparam logic [15:0] CRC16_INIT = 16'hFFFF;

    // -----------------------------------------------------------------
    // UART defaults (override per-instance via parameters)
    // -----------------------------------------------------------------
    localparam int CLK_FREQ_HZ_DEFAULT = 100_000_000;
    localparam int UART_BAUD_DEFAULT   = 115_200;

    // -----------------------------------------------------------------
    // Common typedefs
    // -----------------------------------------------------------------
    typedef logic [7:0]              byte_t;
    typedef logic [MSG_ID_WIDTH-1:0] msg_id_t;
    typedef logic [SEQ_WIDTH-1:0]    seq_t;
    typedef logic [LEN_WIDTH-1:0]    msg_len_t;
    typedef logic [RETRY_WIDTH-1:0]  retry_count_t;
    typedef logic [CRC_WIDTH-1:0]    crc16_t;

    // -----------------------------------------------------------------
    // io <-> backend : key event types
    //   Width matches README: io_key_type[2:0]
    //
    // Shift sideband: for arrow keys (KEY_LEFT/RIGHT/UP/DOWN) the PS/2
    // decoder sets io_key_ascii bit 0 when Shift was held at the moment
    // of the keystroke. ASCII is otherwise 0x00 for arrow keys, so this
    // does not collide with anything. Backend uses bit 0 to distinguish
    // history-scroll (Shift cleared) from input-scroll (Shift set).
    // -----------------------------------------------------------------
    typedef enum logic [2:0] {
        KEY_CHAR      = 3'd0,
        KEY_ENTER     = 3'd1,
        KEY_BACKSPACE = 3'd2,
        KEY_LEFT      = 3'd3,
        KEY_RIGHT     = 3'd4,
        KEY_ESC       = 3'd5,
        KEY_UP        = 3'd6,    // history scroll up   (oldwards)
        KEY_DOWN      = 3'd7     // history scroll down (newwards)
    } key_type_e;

    // Mask for the Shift-held bit in io_key_ascii on arrow-key events.
    localparam byte_t KEY_SHIFT_MASK = 8'h01;

    // -----------------------------------------------------------------
    // comm -> backend : final transmission status of a message
    //   Width matches README: cm_status_code[1:0]
    // -----------------------------------------------------------------
    typedef enum logic [1:0] {
        TX_SUCCESS = 2'd0,
        TX_FAIL    = 2'd1
    } tx_status_e;

    // -----------------------------------------------------------------
    // backend internal / backend -> frontend : message metadata
    //   Width matches README: be_render_side[1:0], be_render_status[1:0]
    // -----------------------------------------------------------------
    typedef enum logic [1:0] {
        MSG_LOCAL  = 2'd0,
        MSG_REMOTE = 2'd1,
        MSG_SYSTEM = 2'd2
    } msg_side_e;

    typedef enum logic [1:0] {
        MSG_PENDING = 2'd0,
        MSG_SUCCESS = 2'd1,
        MSG_FAIL    = 2'd2,
        MSG_RECALLED = 2'd3
    } msg_status_e;

    // -----------------------------------------------------------------
    // backend -> frontend : render commands
    //   Width matches README: be_render_cmd[3:0]
    // -----------------------------------------------------------------
    typedef enum logic [3:0] {
        RENDER_APPEND_LOCAL_PENDING = 4'd0,
        RENDER_APPEND_REMOTE        = 4'd1,
        RENDER_UPDATE_STATUS        = 4'd2,
        RENDER_UPDATE_INPUT_LINE    = 4'd3,  // full input-line state push
        RENDER_CLEAR_SCREEN         = 4'd4,
        RENDER_REDRAW_ALL           = 4'd5,
        // Incremental input-line edits. Carry be_render_cursor_pos
        // (post-edit) and, for INSERT, be_render_ascii.
        RENDER_MOVE_CURSOR          = 4'd6,
        RENDER_INSERT_AT_CURSOR     = 4'd7,
        RENDER_DELETE_AT_CURSOR     = 4'd8,
        // Connection-state change. Carries conn_state and (when
        // CONN_CONNECTED) be_render_peer_name / be_render_peer_name_len.
        RENDER_CONN_STATE           = 4'd9,
        // History scroll: shift the visible window in the history
        // ring buffer. No payload; clamped at fe.
        RENDER_SCROLL_UP            = 4'd10,
        RENDER_SCROLL_DOWN          = 4'd11,
        // Input scroll: shift the visible window in the multi-row
        // input buffer. Emitted on Shift+Up / Shift+Down. Clamped at fe.
        RENDER_INPUT_SCROLL_UP      = 4'd12,
        RENDER_INPUT_SCROLL_DOWN    = 4'd13
    } render_cmd_e;

    // -----------------------------------------------------------------
    // backend -> frontend : connection-state field on RENDER_CONN_STATE
    //   Width: be_render_conn_state[1:0]
    // -----------------------------------------------------------------
    typedef enum logic [1:0] {
        CONN_BOOT         = 2'd0,
        CONN_HANDSHAKE    = 2'd1,
        CONN_CONNECTED    = 2'd2,
        CONN_DISCONNECTED = 2'd3
    } conn_state_e;

    // -----------------------------------------------------------------
    // UI popup overlay state
    // -----------------------------------------------------------------
    typedef enum logic [1:0] {
        POPUP_NONE           = 2'd0,
        POPUP_MSG_MENU       = 2'd1,
        POPUP_STICKER_PICKER = 2'd2
    } popup_type_e;

    // Ctrl+E is carried through the existing KEY_CHAR path as the
    // conventional ASCII control code for E (0x05).
    localparam byte_t KEY_CTRL_E = 8'h05;

    // Sticker picker hit-test geometry. The frontend can style/draw the
    // picker however it wants, but backend selection uses this stable
    // 5-cell row layout.
    localparam int POPUP_STICKER_COUNT       = 5;
    localparam int POPUP_STICKER_CELL_W_PX   = 64;
    localparam int POPUP_STICKER_PICKER_W_PX = POPUP_STICKER_COUNT
                                                * POPUP_STICKER_CELL_W_PX;
    localparam int POPUP_STICKER_PICKER_H_PX = 80;

    // -----------------------------------------------------------------
    // Emoji backslash token metadata
    // -----------------------------------------------------------------
    localparam int EMOJI_TOKEN_COUNT   = 15;
    localparam int EMOJI_TOKEN_ID_W    = $clog2(EMOJI_TOKEN_COUNT);
    localparam int EMOJI_TOKEN_MAX_LEN = 7;   // longest token: "\mairuo"

    localparam int EMOJI_SUGGEST_MAX     = EMOJI_TOKEN_COUNT;
    localparam int EMOJI_SUGGEST_COUNT_W = $clog2(EMOJI_SUGGEST_MAX + 1);

    // At most this many candidate rows are drawn. When more tokens match
    // an extra "......" row is appended below them, so the overlay never
    // grows past EMOJI_SUGGEST_VISIBLE_MAX + 1 rows (no scrolling).
    localparam int EMOJI_SUGGEST_VISIBLE_MAX = 10;
    localparam int EMOJI_SUGGEST_ROWS_MAX    = EMOJI_SUGGEST_VISIBLE_MAX + 1;

    localparam int EMOJI_SUGGEST_X_PX      = 16;
    localparam int EMOJI_SUGGEST_Y_PX      = 260;
    localparam int EMOJI_SUGGEST_W_PX      = 112;
    localparam int EMOJI_SUGGEST_BORDER_PX = 2;
    localparam int EMOJI_SUGGEST_ITEM_H_PX = 16;
    // Layout inside a row: the token text "\happy" sits on the left and
    // the monochrome emoji glyph is column-aligned on the right.
    localparam int EMOJI_SUGGEST_TEXT_X_PX = EMOJI_SUGGEST_BORDER_PX;
    localparam int EMOJI_SUGGEST_ICON_X_PX = EMOJI_SUGGEST_BORDER_PX + 8 * 8;
    // Number of dots drawn on the overflow "......" row.
    localparam int EMOJI_SUGGEST_ELLIPSIS_N = 6;

    // Small-emoji glyph codes occupy 0xE0..0xEE, one per token.
    localparam byte_t EMOJI_GLYPH_BASE = 8'hE0;

    typedef logic [EMOJI_TOKEN_ID_W-1:0] emoji_token_id_t;

    localparam emoji_token_id_t EMOJI_TOKEN_HAPPY       = emoji_token_id_t'(0);
    localparam emoji_token_id_t EMOJI_TOKEN_SAD         = emoji_token_id_t'(1);
    localparam emoji_token_id_t EMOJI_TOKEN_HEART       = emoji_token_id_t'(2);
    localparam emoji_token_id_t EMOJI_TOKEN_OK          = emoji_token_id_t'(3);
    localparam emoji_token_id_t EMOJI_TOKEN_LAUGH       = emoji_token_id_t'(4);
    localparam emoji_token_id_t EMOJI_TOKEN_WINK        = emoji_token_id_t'(5);
    localparam emoji_token_id_t EMOJI_TOKEN_ANGRY       = emoji_token_id_t'(6);
    localparam emoji_token_id_t EMOJI_TOKEN_STAR        = emoji_token_id_t'(7);
    localparam emoji_token_id_t EMOJI_TOKEN_FIRE        = emoji_token_id_t'(8);
    localparam emoji_token_id_t EMOJI_TOKEN_YES         = emoji_token_id_t'(9);
    localparam emoji_token_id_t EMOJI_TOKEN_NO          = emoji_token_id_t'(10);
    localparam emoji_token_id_t EMOJI_TOKEN_UP          = emoji_token_id_t'(11);
    localparam emoji_token_id_t EMOJI_TOKEN_DOWN        = emoji_token_id_t'(12);
    localparam emoji_token_id_t EMOJI_TOKEN_DOGE        = emoji_token_id_t'(13);
    localparam emoji_token_id_t EMOJI_TOKEN_MAIRUO      = emoji_token_id_t'(14);

    function automatic logic emoji_token_valid(input emoji_token_id_t token_id);
        begin
            emoji_token_valid = (int'(token_id) < EMOJI_TOKEN_COUNT);
        end
    endfunction

    function automatic msg_len_t emoji_token_len(input emoji_token_id_t token_id);
        begin
            unique case (token_id)
                EMOJI_TOKEN_HAPPY:       emoji_token_len = msg_len_t'(6);
                EMOJI_TOKEN_SAD:         emoji_token_len = msg_len_t'(4);
                EMOJI_TOKEN_HEART:       emoji_token_len = msg_len_t'(6);
                EMOJI_TOKEN_OK:          emoji_token_len = msg_len_t'(3);
                EMOJI_TOKEN_LAUGH:       emoji_token_len = msg_len_t'(6);
                EMOJI_TOKEN_WINK:        emoji_token_len = msg_len_t'(5);
                EMOJI_TOKEN_ANGRY:       emoji_token_len = msg_len_t'(6);
                EMOJI_TOKEN_STAR:        emoji_token_len = msg_len_t'(5);
                EMOJI_TOKEN_FIRE:        emoji_token_len = msg_len_t'(5);
                EMOJI_TOKEN_YES:         emoji_token_len = msg_len_t'(4);
                EMOJI_TOKEN_NO:          emoji_token_len = msg_len_t'(3);
                EMOJI_TOKEN_UP:          emoji_token_len = msg_len_t'(3);
                EMOJI_TOKEN_DOWN:        emoji_token_len = msg_len_t'(5);
                EMOJI_TOKEN_DOGE:        emoji_token_len = msg_len_t'(5);
                EMOJI_TOKEN_MAIRUO:      emoji_token_len = msg_len_t'(7);
                default:                 emoji_token_len = '0;
            endcase
        end
    endfunction

    function automatic byte_t emoji_token_char(
        input emoji_token_id_t token_id,
        input logic [3:0]      char_idx
    );
        begin
            emoji_token_char = 8'h20;
            unique case (token_id)
                EMOJI_TOKEN_HAPPY: begin
                    unique case (char_idx)
                        4'd0: emoji_token_char = 8'h5C;
                        4'd1: emoji_token_char = "h";
                        4'd2: emoji_token_char = "a";
                        4'd3: emoji_token_char = "p";
                        4'd4: emoji_token_char = "p";
                        4'd5: emoji_token_char = "y";
                        default: ;
                    endcase
                end
                EMOJI_TOKEN_SAD: begin
                    unique case (char_idx)
                        4'd0: emoji_token_char = 8'h5C;
                        4'd1: emoji_token_char = "s";
                        4'd2: emoji_token_char = "a";
                        4'd3: emoji_token_char = "d";
                        default: ;
                    endcase
                end
                EMOJI_TOKEN_HEART: begin
                    unique case (char_idx)
                        4'd0: emoji_token_char = 8'h5C;
                        4'd1: emoji_token_char = "h";
                        4'd2: emoji_token_char = "e";
                        4'd3: emoji_token_char = "a";
                        4'd4: emoji_token_char = "r";
                        4'd5: emoji_token_char = "t";
                        default: ;
                    endcase
                end
                EMOJI_TOKEN_OK: begin
                    unique case (char_idx)
                        4'd0: emoji_token_char = 8'h5C;
                        4'd1: emoji_token_char = "o";
                        4'd2: emoji_token_char = "k";
                        default: ;
                    endcase
                end
                EMOJI_TOKEN_LAUGH: begin
                    unique case (char_idx)
                        4'd0: emoji_token_char = 8'h5C;
                        4'd1: emoji_token_char = "l";
                        4'd2: emoji_token_char = "a";
                        4'd3: emoji_token_char = "u";
                        4'd4: emoji_token_char = "g";
                        4'd5: emoji_token_char = "h";
                        default: ;
                    endcase
                end
                EMOJI_TOKEN_WINK: begin
                    unique case (char_idx)
                        4'd0: emoji_token_char = 8'h5C;
                        4'd1: emoji_token_char = "w";
                        4'd2: emoji_token_char = "i";
                        4'd3: emoji_token_char = "n";
                        4'd4: emoji_token_char = "k";
                        default: ;
                    endcase
                end
                EMOJI_TOKEN_ANGRY: begin
                    unique case (char_idx)
                        4'd0: emoji_token_char = 8'h5C;
                        4'd1: emoji_token_char = "a";
                        4'd2: emoji_token_char = "n";
                        4'd3: emoji_token_char = "g";
                        4'd4: emoji_token_char = "r";
                        4'd5: emoji_token_char = "y";
                        default: ;
                    endcase
                end
                EMOJI_TOKEN_STAR: begin
                    unique case (char_idx)
                        4'd0: emoji_token_char = 8'h5C;
                        4'd1: emoji_token_char = "s";
                        4'd2: emoji_token_char = "t";
                        4'd3: emoji_token_char = "a";
                        4'd4: emoji_token_char = "r";
                        default: ;
                    endcase
                end
                EMOJI_TOKEN_FIRE: begin
                    unique case (char_idx)
                        4'd0: emoji_token_char = 8'h5C;
                        4'd1: emoji_token_char = "f";
                        4'd2: emoji_token_char = "i";
                        4'd3: emoji_token_char = "r";
                        4'd4: emoji_token_char = "e";
                        default: ;
                    endcase
                end
                EMOJI_TOKEN_YES: begin
                    unique case (char_idx)
                        4'd0: emoji_token_char = 8'h5C;
                        4'd1: emoji_token_char = "y";
                        4'd2: emoji_token_char = "e";
                        4'd3: emoji_token_char = "s";
                        default: ;
                    endcase
                end
                EMOJI_TOKEN_NO: begin
                    unique case (char_idx)
                        4'd0: emoji_token_char = 8'h5C;
                        4'd1: emoji_token_char = "n";
                        4'd2: emoji_token_char = "o";
                        default: ;
                    endcase
                end
                EMOJI_TOKEN_UP: begin
                    unique case (char_idx)
                        4'd0: emoji_token_char = 8'h5C;
                        4'd1: emoji_token_char = "u";
                        4'd2: emoji_token_char = "p";
                        default: ;
                    endcase
                end
                EMOJI_TOKEN_DOWN: begin
                    unique case (char_idx)
                        4'd0: emoji_token_char = 8'h5C;
                        4'd1: emoji_token_char = "d";
                        4'd2: emoji_token_char = "o";
                        4'd3: emoji_token_char = "w";
                        4'd4: emoji_token_char = "n";
                        default: ;
                    endcase
                end
                EMOJI_TOKEN_DOGE: begin
                    unique case (char_idx)
                        4'd0: emoji_token_char = 8'h5C;
                        4'd1: emoji_token_char = "d";
                        4'd2: emoji_token_char = "o";
                        4'd3: emoji_token_char = "g";
                        4'd4: emoji_token_char = "e";
                        default: ;
                    endcase
                end
                EMOJI_TOKEN_MAIRUO: begin
                    unique case (char_idx)
                        4'd0: emoji_token_char = 8'h5C;
                        4'd1: emoji_token_char = "m";
                        4'd2: emoji_token_char = "a";
                        4'd3: emoji_token_char = "i";
                        4'd4: emoji_token_char = "r";
                        4'd5: emoji_token_char = "u";
                        4'd6: emoji_token_char = "o";
                        default: ;
                    endcase
                end
                default: ;
            endcase
        end
    endfunction

    function automatic byte_t emoji_token_glyph(input emoji_token_id_t token_id);
        begin
            emoji_token_glyph = EMOJI_GLYPH_BASE + byte_t'(token_id);
        end
    endfunction

    // -----------------------------------------------------------------
    // comm internal : link-layer frame types
    //   Width matches README: TYPE field is 3 bits
    // -----------------------------------------------------------------
    typedef enum logic [2:0] {
        FRAME_DATA     = 3'd0,
        FRAME_ACK      = 3'd1,
        FRAME_NAK      = 3'd2,
        FRAME_HELLO    = 3'd3,  // boot / SPACE-reconnect; payload = sender's name
        FRAME_REHELLO  = 3'd4,  // mid-chat re-confirm; payload = sender's name
        FRAME_USERNAME = 3'd5,  // response; payload = sender's name
        FRAME_GOODBYE  = 3'd6,  // ESC; no payload
        FRAME_RECALL   = 3'd7   // recall msg_id in SEQ; no payload
    } frame_type_e;

    // -----------------------------------------------------------------
    // Quote wire-format marker. Payload for a quoted message is:
    //   [0] = QUOTE_MARKER (0x01)
    //   [1] = quoted_side   (the quoted message's side FROM THE
    //         RECEIVER's perspective: the sender stores the side it sees
    //         and inverts it so the receiver can resolve the right
    //         message — LOCAL<->REMOTE — since msg_id alone is ambiguous
    //         across the two independent side namespaces.)
    //   [2] = quoted_msg_id
    //   [3..N-1] = user text
    // The marker cannot appear in user-typed text because the PS/2
    // input path only admits printable ASCII (0x20..0x7E) and LF (0x0A).
    // -----------------------------------------------------------------
    localparam byte_t QUOTE_MARKER     = 8'h01;
    localparam int    QUOTE_MARKER_LEN = 3;          // marker + side + msg_id
    localparam int    QUOTE_DISP_MAX   = 60;         // max quoted chars to show

endpackage : chat_pkg

`endif  // CHAT_PKG_SV
