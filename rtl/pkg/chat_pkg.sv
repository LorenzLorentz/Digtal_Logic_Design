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
    // MAX_MSG_LEN/MAX_LINE_LEN bumped to 640 to support variable-length
    // payloads up to ~10 visible rows of bubble text. LEN_WIDTH widens
    // to 16 so msg_len_t (and the on-wire LEN field) can carry the full
    // 0..MAX_MSG_LEN range. The frame layer transmits LEN as two bytes
    // (LEN_HI then LEN_LO).
    localparam int MAX_MSG_LEN  = 640;   // bytes per chat message payload
    localparam int MAX_MSG_NUM  = 64;    // chat history depth
    localparam int MAX_LINE_LEN = 640;   // current input line buffer
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
        MSG_FAIL    = 2'd2
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
        FRAME_GOODBYE  = 3'd6   // ESC; no payload
    } frame_type_e;

endpackage : chat_pkg

`endif  // CHAT_PKG_SV
