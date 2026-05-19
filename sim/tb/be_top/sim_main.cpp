// =====================================================================
// sim_main.cpp  --  Testbench for rtl/backend/be_top.sv
// ---------------------------------------------------------------------
// Coverage:
//   (Init)  Boot RENDER_REDRAW_ALL pulse out of reset.
//   (A)     Input handling with cursor (CHAR/BS at cursor, LEFT/RIGHT,
//           ENTER, others).
//   (B)     Local commit pipeline: store_local_pending -> render
//           APPEND_LOCAL_PENDING -> be_tx -> UPDATE_INPUT_LINE (len=0,
//           cursor_pos=0).
//   (C)     RX path with cm_rx_len clamping at MAX_MSG_LEN.
//   (D)     STATUS path.
//   (E)     Render-emission gating and timing sanity.
//
// Conventions:
//   - 10 ns clock, active-low async reset.
//   - be_tx_ready / be_render_ready default high.
//   - reset() drains the boot REDRAW_ALL render so test bodies start in
//     S_IDLE. Use reset_no_drain() if you need to observe the boot
//     render itself.
//   - send_key / inject_rx / inject_status all WAIT for ready.
//   - wait_render / wait_tx capture data, then tick to complete the
//     handshake.
// =====================================================================

#include "Vbe_top.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "../common/big_emoji_codes.h"
#include <cstdint>
#include <cstdio>
#include <string>
#include <vector>

// ---- Globals ---------------------------------------------------------
static vluint64_t       g_time_ns  = 0;
static int              g_failures = 0;
static Vbe_top*         dut        = nullptr;
static VerilatedVcdC*   tfp        = nullptr;

static constexpr int MAX_LINE_LEN = 128;
static constexpr int MAX_MSG_LEN  = 128;
static constexpr int PAYLOAD_W    = MAX_MSG_LEN * 8 / 32;

// key_type_e
enum : uint8_t { KEY_CHAR = 0, KEY_ENTER = 1, KEY_BACKSPACE = 2,
                 KEY_LEFT = 3, KEY_RIGHT = 4, KEY_ESC = 5,
                 KEY_UP   = 6, KEY_DOWN  = 7 };
// msg_side_e / msg_status_e
enum : uint8_t { MSG_LOCAL = 0, MSG_REMOTE = 1, MSG_SYSTEM = 2 };
enum : uint8_t { MSG_PENDING = 0, MSG_SUCCESS = 1, MSG_FAIL = 2 };
// tx_status_e
enum : uint8_t { TX_SUCCESS = 0, TX_FAIL = 1 };
// render_cmd_e (mirrors chat_pkg.sv)
enum : uint8_t {
    RENDER_APPEND_LOCAL_PENDING = 0,
    RENDER_APPEND_REMOTE        = 1,
    RENDER_UPDATE_STATUS        = 2,
    RENDER_UPDATE_INPUT_LINE    = 3,
    RENDER_CLEAR_SCREEN         = 4,
    RENDER_REDRAW_ALL           = 5,
    RENDER_MOVE_CURSOR          = 6,
    RENDER_INSERT_AT_CURSOR     = 7,
    RENDER_DELETE_AT_CURSOR     = 8,
    RENDER_CONN_STATE           = 9,
    RENDER_SCROLL_UP            = 10,
    RENDER_SCROLL_DOWN          = 11,
    RENDER_INPUT_SCROLL_UP      = 12,
    RENDER_INPUT_SCROLL_DOWN    = 13,
};
// frame_type_e
enum : uint8_t {
    FRAME_DATA     = 0,
    FRAME_ACK      = 1,
    FRAME_NAK      = 2,
    FRAME_HELLO    = 3,
    FRAME_REHELLO  = 4,
    FRAME_USERNAME = 5,
    FRAME_GOODBYE  = 6,
};
// conn_state_e
enum : uint8_t {
    CONN_BOOT         = 0,
    CONN_HANDSHAKE    = 1,
    CONN_CONNECTED    = 2,
    CONN_DISCONNECTED = 3,
};

// Default MY_NAME as built into be_top: "Alic" (4 bytes).
static constexpr int      MY_NAME_LEN_DEFAULT = 4;
static const char* const  MY_NAME_DEFAULT     = "Alic";

// Peer name we pretend to receive in bring_up_connection.
static const char* const  PEER_NAME = "Bob";
static constexpr int      PEER_NAME_LEN = 3;

// ---- Clock helpers ---------------------------------------------------
static void tick_half() {
    dut->eval();
    if (tfp) tfp->dump(g_time_ns);
    g_time_ns += 5;
}
static void tick() {
    dut->clk = 0; tick_half();
    dut->clk = 1; tick_half();
}

// ---- Wide-signal byte access ----------------------------------------
static void payload_set_byte(uint32_t* sig, int i, uint8_t b) {
    int w  = i >> 2;
    int sh = (i & 3) * 8;
    sig[w] = (sig[w] & ~(0xFFu << sh)) | (((uint32_t)b) << sh);
}
static uint8_t payload_get_byte(const uint32_t* sig, int i) {
    int w  = i >> 2;
    int sh = (i & 3) * 8;
    return (sig[w] >> sh) & 0xFF;
}
static void payload_clear(uint32_t* sig) {
    for (int w = 0; w < PAYLOAD_W; w++) sig[w] = 0;
}
static void payload_load(uint32_t* sig, const std::vector<uint8_t>& bytes) {
    payload_clear(sig);
    for (size_t i = 0; i < bytes.size() && i < (size_t)MAX_MSG_LEN; i++)
        payload_set_byte(sig, (int)i, bytes[i]);
}

// ---- Capturing render / tx events -----------------------------------
struct RenderEvent {
    uint8_t  cmd, msg_id, side, status, ascii, conn_state;
    uint16_t len, cursor_pos;
    uint8_t  peer_name_len;
    uint32_t payload[PAYLOAD_W];
    uint8_t  peer_name[16];
};
struct TxEvent {
    uint8_t  frame_type, msg_id;
    uint16_t len;
    uint32_t payload[PAYLOAD_W];
};

static bool wait_render(RenderEvent& evt, int timeout = 50) {
    for (int i = 0; i < timeout; i++) {
        dut->eval();
        if (dut->be_render_valid) {
            evt.cmd           = dut->be_render_cmd;
            evt.msg_id        = dut->be_render_msg_id;
            evt.side          = dut->be_render_side;
            evt.status        = dut->be_render_status;
            evt.len           = dut->be_render_len;
            evt.cursor_pos    = dut->be_render_cursor_pos;
            evt.ascii         = dut->be_render_ascii;
            evt.conn_state    = dut->be_render_conn_state;
            evt.peer_name_len = dut->be_render_peer_name_len;
            for (int w = 0; w < PAYLOAD_W; w++)
                evt.payload[w] = dut->be_render_payload[w];
            // peer_name is 16 bytes -> 4 uint32 words on the bus.
            for (int b = 0; b < 16; b++) {
                int w  = b >> 2;
                int sh = (b & 3) * 8;
                evt.peer_name[b] =
                    (((uint32_t)dut->be_render_peer_name[w]) >> sh) & 0xFF;
            }
            tick();
            return true;
        }
        tick();
    }
    return false;
}

static bool wait_tx(TxEvent& evt, int timeout = 50) {
    for (int i = 0; i < timeout; i++) {
        dut->eval();
        if (dut->be_tx_valid) {
            evt.frame_type = dut->be_tx_frame_type;
            evt.msg_id     = dut->be_tx_msg_id;
            evt.len        = dut->be_tx_len;
            for (int w = 0; w < PAYLOAD_W; w++)
                evt.payload[w] = dut->be_tx_payload[w];
            tick();
            return true;
        }
        tick();
    }
    return false;
}

static bool no_render_for(int cycles) {
    for (int i = 0; i < cycles; i++) {
        dut->eval();
        if (dut->be_render_valid) return false;
        tick();
    }
    return true;
}

// ---- Reset ----------------------------------------------------------
static void clear_inputs() {
    dut->io_key_valid      = 0;
    dut->io_key_type       = 0;
    dut->io_key_ascii      = 0;
    dut->cm_rx_valid       = 0;
    dut->cm_rx_frame_type  = 0;
    dut->cm_rx_seq         = 0;
    dut->cm_rx_len         = 0;
    payload_clear(&dut->cm_rx_payload[0]);
    dut->cm_status_valid   = 0;
    dut->cm_status_msg_id  = 0;
    dut->cm_status_code    = 0;
    dut->be_tx_ready       = 1;
    dut->be_render_ready   = 1;
    dut->line_rd_idx       = 0;
    dut->store_rd_idx      = 0;
}

// Low-level reset that does NOT drain the boot REDRAW_ALL render. Used
// only by `test_boot_redraw_all` so it can observe the very first render.
//
// Notably we do NOT tick after raising rst_n: while reset is asserted the
// FSM is parked in S_BOOT_REDRAW, with be_render_valid combinational-high.
// One extra post-reset tick would complete the handshake (since
// be_render_ready defaults high) and consume the boot render before any
// observer could see it.
static void reset_no_drain(int cycles = 4) {
    dut->rst_n = 0;
    clear_inputs();
    dut->clk = 0;
    for (int i = 0; i < cycles; i++) tick();
    dut->rst_n = 1;
}

// Forward declaration: bring_up_connection drives a peer USERNAME.
static void inject_rx_frame(uint8_t frame_type, uint8_t seq, uint16_t len,
                            const std::vector<uint8_t>& bytes,
                            int timeout = 200);

// Drain the full boot/handshake sequence and inject a peer USERNAME so
// that the FSM parks in S_IDLE under CONN_CONNECTED with peer_name=PEER_NAME.
//
// Sequence:
//   1. RENDER_REDRAW_ALL (boot screen)
//   2. be_tx FRAME_HELLO + MY_NAME
//   3. cm_rx FRAME_USERNAME + PEER_NAME (TB plays the peer)
//   4. RENDER_CONN_STATE (connected, peer_name)
static void bring_up_connection() {
    RenderEvent r;
    if (!wait_render(r, 10) || r.cmd != RENDER_REDRAW_ALL) {
        ++g_failures;
        printf("  [FAIL @ %lluns] bring_up: REDRAW_ALL didn't fire (got cmd=%u)\n",
               (unsigned long long)g_time_ns, r.cmd);
        return;
    }
    TxEvent tx;
    if (!wait_tx(tx, 10) || tx.frame_type != FRAME_HELLO) {
        ++g_failures;
        printf("  [FAIL @ %lluns] bring_up: HELLO didn't fire (got ft=%u)\n",
               (unsigned long long)g_time_ns, tx.frame_type);
        return;
    }
    // Pretend peer responds with USERNAME(PEER_NAME).
    std::vector<uint8_t> bytes(PEER_NAME, PEER_NAME + PEER_NAME_LEN);
    inject_rx_frame(FRAME_USERNAME, /*seq=*/0, PEER_NAME_LEN, bytes);
    if (!wait_render(r, 10) || r.cmd != RENDER_CONN_STATE) {
        ++g_failures;
        printf("  [FAIL @ %lluns] bring_up: CONN_STATE didn't fire (got cmd=%u)\n",
               (unsigned long long)g_time_ns, r.cmd);
        return;
    }
    if (r.conn_state != CONN_CONNECTED) {
        ++g_failures;
        printf("  [FAIL @ %lluns] bring_up: conn_state=%u, expected CONNECTED\n",
               (unsigned long long)g_time_ns, r.conn_state);
    }
}

// Standard reset: drives reset, completes boot+handshake so the FSM is
// parked in S_IDLE under CONN_CONNECTED before the test body runs.
static void reset(int cycles = 4) {
    reset_no_drain(cycles);
    bring_up_connection();
}

// ---- Stimulus -------------------------------------------------------
static void send_key(uint8_t kt, uint8_t a, int timeout = 200) {
    dut->io_key_valid = 1;
    dut->io_key_type  = kt;
    dut->io_key_ascii = a;
    for (int i = 0; i < timeout; i++) {
        dut->eval();
        if (dut->io_key_ready) {
            tick();
            dut->io_key_valid = 0;
            dut->io_key_type  = 0;
            dut->io_key_ascii = 0;
            return;
        }
        tick();
    }
    ++g_failures;
    printf("  [FAIL @ %lluns] send_key: io_key_ready never asserted\n",
           (unsigned long long)g_time_ns);
    dut->io_key_valid = 0;
}

static void inject_rx_frame(uint8_t frame_type, uint8_t seq, uint16_t len,
                            const std::vector<uint8_t>& bytes,
                            int timeout) {
    dut->cm_rx_valid      = 1;
    dut->cm_rx_frame_type = frame_type;
    dut->cm_rx_seq        = seq;
    dut->cm_rx_len        = len;
    payload_load(&dut->cm_rx_payload[0], bytes);
    for (int i = 0; i < timeout; i++) {
        dut->eval();
        if (dut->cm_rx_ready) {
            tick();
            dut->cm_rx_valid      = 0;
            dut->cm_rx_frame_type = 0;
            dut->cm_rx_seq        = 0;
            dut->cm_rx_len        = 0;
            payload_clear(&dut->cm_rx_payload[0]);
            return;
        }
        tick();
    }
    ++g_failures;
    printf("  [FAIL @ %lluns] inject_rx_frame(ft=%u): cm_rx_ready never asserted\n",
           (unsigned long long)g_time_ns, frame_type);
    dut->cm_rx_valid = 0;
}

// Backward-compat wrapper: existing tests just inject DATA frames.
static void inject_rx(uint8_t seq, uint16_t len,
                      const std::vector<uint8_t>& bytes, int timeout = 200) {
    inject_rx_frame(FRAME_DATA, seq, len, bytes, timeout);
}

static void inject_status(uint8_t msg_id, uint8_t code, int timeout = 200) {
    dut->cm_status_valid  = 1;
    dut->cm_status_msg_id = msg_id;
    dut->cm_status_code   = code;
    for (int i = 0; i < timeout; i++) {
        dut->eval();
        if (dut->cm_status_ready) {
            tick();
            dut->cm_status_valid  = 0;
            dut->cm_status_msg_id = 0;
            dut->cm_status_code   = 0;
            return;
        }
        tick();
    }
    ++g_failures;
    printf("  [FAIL @ %lluns] inject_status: cm_status_ready never asserted\n",
           (unsigned long long)g_time_ns);
    dut->cm_status_valid = 0;
}

// Drain one render of any kind, ignoring its content. Useful to advance
// the FSM past a side-effect render that the current test doesn't care
// about (e.g. the INSERT_AT_CURSOR fired by every CHAR, or the trailing
// UPDATE_INPUT_LINE after a commit). Timeout is generous so the
// multi-cycle line_buf shift (S_LINE_INSERT/_DELETE walks up to
// MAX_LINE_LEN cycles) has room to finish before emitting the render.
static void drain_render(int timeout = MAX_LINE_LEN + 10) {
    RenderEvent e;
    if (!wait_render(e, timeout)) {
        ++g_failures;
        printf("  [FAIL @ %lluns] drain_render: no render within %d cycles\n",
               (unsigned long long)g_time_ns, timeout);
    }
}

// Drain the full commit pipeline: APPEND_LOCAL_PENDING -> be_tx ->
// UPDATE_INPUT_LINE. Use after send_key(KEY_ENTER) when the test only
// cares about the post-commit state (not the pipeline contents).
static void drain_commit_pipeline() {
    // First render comes after the multi-cycle encoder finishes, so
    // its timeout has to cover the full encoder walk (worst case
    // ~MAX_LINE_LEN cycles for a buffer of pure literal bytes).
    RenderEvent r1; wait_render(r1, MAX_LINE_LEN + 20);
    TxEvent t;      wait_tx(t, 10);
    RenderEvent r2; wait_render(r2, 10);
}

// ---- Read helpers ---------------------------------------------------
static uint8_t read_buf(int i) {
    dut->line_rd_idx = i;
    dut->eval();
    return dut->line_rd_data;
}
struct StoreRead { uint8_t valid, msg_id, side, status; uint16_t len; };
static StoreRead read_store(int idx) {
    dut->store_rd_idx = idx;
    dut->eval();
    return {(uint8_t)dut->store_rd_valid, (uint8_t)dut->store_rd_msg_id,
            (uint8_t)dut->store_rd_side,  (uint8_t)dut->store_rd_status,
            (uint16_t)dut->store_rd_len};
}
static uint8_t store_payload_byte(int i) {
    return payload_get_byte(&dut->store_rd_payload[0], i);
}

// ---- Assertion macro -------------------------------------------------
#define CHECK_EQ(actual, expected, label) do {                            \
    auto _a = (actual); auto _e = (expected);                             \
    if (_a != _e) {                                                       \
        ++g_failures;                                                     \
        printf("  [FAIL @ %lluns] %-40s got=0x%02llx expected=0x%02llx\n",\
               (unsigned long long)g_time_ns, (label),                    \
               (unsigned long long)_a, (unsigned long long)_e);           \
    }                                                                     \
} while (0)

// =====================================================================
// (Init) Boot render
// =====================================================================

// First render after reset is RENDER_REDRAW_ALL with conn_state=BOOT. The
// FSM then immediately drives FRAME_HELLO on be_tx -- it does NOT land in
// IDLE until the handshake completes.
static void test_boot_redraw_all() {
    printf("== test_boot_redraw_all\n");
    reset_no_drain();
    RenderEvent e;
    CHECK_EQ(wait_render(e, 10), true, "boot render fires");
    CHECK_EQ(e.cmd,        RENDER_REDRAW_ALL, "first render is REDRAW_ALL");
    CHECK_EQ(e.conn_state, CONN_BOOT,         "conn_state = BOOT");
    // FSM is now in S_TX_HELLO, asserting be_tx with FRAME_HELLO.
    dut->eval();
    CHECK_EQ(dut->io_key_ready,      0,           "io_key_ready withheld in S_TX_HELLO");
    CHECK_EQ(dut->be_tx_valid,       1,           "HELLO tx pending");
    CHECK_EQ(dut->be_tx_frame_type,  FRAME_HELLO, "HELLO frame_type");
    CHECK_EQ(dut->be_tx_len,         MY_NAME_LEN_DEFAULT, "HELLO carries MY_NAME_LEN");
    CHECK_EQ(payload_get_byte(&dut->be_tx_payload[0], 0), (uint8_t)'A',
             "HELLO payload byte 0");
    CHECK_EQ(payload_get_byte(&dut->be_tx_payload[0], 3), (uint8_t)'c',
             "HELLO payload byte 3");
}

// =====================================================================
// (A) Input handling
// =====================================================================

static void test_reset_clears_state() {
    printf("== test_reset_clears_state\n");
    reset();  // bring up to CONN_CONNECTED
    CHECK_EQ(dut->line_len,        0, "line_len");
    CHECK_EQ(dut->cursor_pos,      0, "cursor_pos");
    CHECK_EQ(dut->enter_committed, 0, "enter_committed");
    CHECK_EQ(dut->be_render_valid, 0, "be_render_valid (handshake drained)");
    CHECK_EQ(dut->be_tx_valid,     0, "be_tx_valid");
    CHECK_EQ(dut->conn_state_obs,  CONN_CONNECTED, "conn_state CONNECTED");
    CHECK_EQ(dut->be_render_peer_name_len, PEER_NAME_LEN, "peer_name_len latched");
}

static void test_single_char_append() {
    printf("== test_single_char_append\n");
    reset();
    send_key(KEY_CHAR, 'a'); drain_render();
    CHECK_EQ(dut->line_len,   1, "line_len");
    CHECK_EQ(dut->cursor_pos, 1, "cursor_pos advanced");
    CHECK_EQ(read_buf(0),     'a', "buf[0]");
}

static void test_multi_char_builds_string() {
    printf("== test_multi_char_builds_string\n");
    reset();
    for (char c : std::string("hello")) { send_key(KEY_CHAR, (uint8_t)c); drain_render(); }
    CHECK_EQ(dut->line_len,   5, "line_len");
    CHECK_EQ(dut->cursor_pos, 5, "cursor at end");
    for (int i = 0; i < 5; i++) {
        char lbl[40]; snprintf(lbl, sizeof(lbl), "buf[%d]", i);
        CHECK_EQ(read_buf(i), (uint8_t)"hello"[i], lbl);
    }
}

static void test_backspace_removes_last() {
    printf("== test_backspace_removes_last\n");
    reset();
    for (char c : std::string("abc")) { send_key(KEY_CHAR, (uint8_t)c); drain_render(); }
    send_key(KEY_BACKSPACE, 0); drain_render();
    CHECK_EQ(dut->line_len,   2, "line_len after BS");
    CHECK_EQ(dut->cursor_pos, 2, "cursor follows BS");
}

static void test_backspace_at_zero_no_op() {
    printf("== test_backspace_at_zero_no_op\n");
    reset();
    send_key(KEY_BACKSPACE, 0);  // no render expected
    CHECK_EQ(dut->line_len,        0, "line_len stays 0");
    CHECK_EQ(dut->cursor_pos,      0, "cursor_pos stays 0");
    CHECK_EQ(no_render_for(5), true, "no render on empty BS");
}

static void test_backspace_then_char() {
    printf("== test_backspace_then_char\n");
    reset();
    for (char c : std::string("abc")) { send_key(KEY_CHAR, (uint8_t)c); drain_render(); }
    send_key(KEY_BACKSPACE, 0); drain_render();
    send_key(KEY_BACKSPACE, 0); drain_render();
    send_key(KEY_CHAR, 'X');    drain_render();
    CHECK_EQ(dut->line_len,   2,   "line_len");
    CHECK_EQ(dut->cursor_pos, 2,   "cursor_pos");
    CHECK_EQ(read_buf(0),     'a', "buf[0]");
    CHECK_EQ(read_buf(1),     'X', "buf[1] overwritten via insert at end");
}

static void test_enter_empty_no_commit() {
    printf("== test_enter_empty_no_commit\n");
    reset();
    send_key(KEY_ENTER, 0);
    CHECK_EQ(dut->enter_committed, 0, "no commit pulse");
    CHECK_EQ(dut->line_len,        0, "line still empty");
    CHECK_EQ(dut->cursor_pos,      0, "cursor still 0");
    CHECK_EQ(no_render_for(5), true, "no render on empty ENTER");
}

static void test_enter_nonempty_commits() {
    printf("== test_enter_nonempty_commits\n");
    reset();
    send_key(KEY_CHAR, 'h'); drain_render();
    send_key(KEY_CHAR, 'i'); drain_render();
    send_key(KEY_ENTER, 0);
    // Capture the commit pulse before the pipeline consumes time.
    CHECK_EQ(dut->enter_committed, 1, "commit pulse high right after ENTER");
    drain_commit_pipeline();
    CHECK_EQ(dut->line_len,   0, "line cleared");
    CHECK_EQ(dut->cursor_pos, 0, "cursor cleared");
}

// ESC in S_IDLE now triggers a GOODBYE tx and disconnects. The input
// line is also cleared so reconnect doesn't show stale typing. Full
// disconnect/reconnect coverage lives in the (F) section below; this
// test just confirms ESC is no longer inert.
static void test_esc_triggers_goodbye() {
    printf("== test_esc_triggers_goodbye\n");
    reset();
    send_key(KEY_CHAR, 'a'); drain_render();
    send_key(KEY_ESC, 0);
    TxEvent tx;
    CHECK_EQ(wait_tx(tx, 10),     true,          "GOODBYE fires after ESC");
    CHECK_EQ(tx.frame_type,       FRAME_GOODBYE, "frame_type GOODBYE");
    CHECK_EQ(tx.len,              0,             "GOODBYE has no payload");
    RenderEvent r;
    CHECK_EQ(wait_render(r, 10),  true,             "CONN_STATE render fires");
    CHECK_EQ(r.cmd,               RENDER_CONN_STATE,"cmd = CONN_STATE");
    CHECK_EQ(r.conn_state,        CONN_DISCONNECTED,"conn_state DISCONNECTED");
    CHECK_EQ(dut->line_len,       0,                "input line cleared");
    CHECK_EQ(dut->cursor_pos,     0,                "cursor cleared");
}

static void test_buffer_full_drops_extra() {
    printf("== test_buffer_full_drops_extra\n");
    reset();
    for (int i = 0; i < MAX_LINE_LEN; i++) {
        send_key(KEY_CHAR, (uint8_t)('A' + (i % 26)));
        drain_render();
    }
    CHECK_EQ(dut->line_len,   MAX_LINE_LEN, "line_len at MAX");
    CHECK_EQ(dut->cursor_pos, MAX_LINE_LEN, "cursor at MAX");
    uint8_t last = read_buf(MAX_LINE_LEN - 1);

    send_key(KEY_CHAR, '!');    // dropped
    CHECK_EQ(dut->line_len,   MAX_LINE_LEN, "line_len did not grow");
    CHECK_EQ(dut->cursor_pos, MAX_LINE_LEN, "cursor not advanced");
    CHECK_EQ(read_buf(MAX_LINE_LEN - 1), last, "last slot unchanged");
    CHECK_EQ(no_render_for(5), true, "no render on dropped CHAR");
}

// =====================================================================
// (E) Render-emission gating + cursor render commands
// =====================================================================

// CHAR emits RENDER_INSERT_AT_CURSOR carrying the inserted ascii and
// the post-edit cursor.
static void test_char_emits_insert_render() {
    printf("== test_char_emits_insert_render\n");
    reset();
    send_key(KEY_CHAR, 'a');
    RenderEvent e;
    CHECK_EQ(wait_render(e, 5), true, "render fires");
    CHECK_EQ(e.cmd,        RENDER_INSERT_AT_CURSOR, "cmd INSERT_AT_CURSOR");
    CHECK_EQ(e.cursor_pos, 1,   "post-edit cursor_pos");
    CHECK_EQ(e.ascii,      'a', "render carries ascii");
}

// BACKSPACE on non-empty emits RENDER_DELETE_AT_CURSOR with post-edit
// cursor.
static void test_bs_emits_delete_render() {
    printf("== test_bs_emits_delete_render\n");
    reset();
    send_key(KEY_CHAR, 'a'); drain_render();
    send_key(KEY_CHAR, 'b'); drain_render();
    send_key(KEY_BACKSPACE, 0);
    RenderEvent e;
    CHECK_EQ(wait_render(e, 5), true, "render fires");
    CHECK_EQ(e.cmd,        RENDER_DELETE_AT_CURSOR, "cmd DELETE_AT_CURSOR");
    CHECK_EQ(e.cursor_pos, 1, "post-edit cursor_pos");
}

static void test_left_at_zero_no_render() {
    printf("== test_left_at_zero_no_render\n");
    reset();
    send_key(KEY_LEFT, 0);
    CHECK_EQ(dut->cursor_pos, 0, "cursor stays 0");
    CHECK_EQ(no_render_for(5), true, "no render at LEFT boundary");
}

static void test_right_at_end_no_render() {
    printf("== test_right_at_end_no_render\n");
    reset();
    send_key(KEY_CHAR, 'a'); drain_render();
    // cursor_pos is now 1, line_len 1 -> RIGHT is a no-op.
    send_key(KEY_RIGHT, 0);
    CHECK_EQ(dut->cursor_pos, 1, "cursor stays at end");
    CHECK_EQ(no_render_for(5), true, "no render at RIGHT boundary");
}

static void test_left_right_emit_move_cursor() {
    printf("== test_left_right_emit_move_cursor\n");
    reset();
    send_key(KEY_CHAR, 'a'); drain_render();
    send_key(KEY_CHAR, 'b'); drain_render();
    // cursor_pos=2, line_len=2.
    send_key(KEY_LEFT, 0);
    RenderEvent l;
    CHECK_EQ(wait_render(l, 5), true, "LEFT render fires");
    CHECK_EQ(l.cmd,        RENDER_MOVE_CURSOR, "cmd MOVE_CURSOR");
    CHECK_EQ(l.cursor_pos, 1,                  "cursor_pos post-LEFT");

    send_key(KEY_RIGHT, 0);
    RenderEvent r;
    CHECK_EQ(wait_render(r, 5), true, "RIGHT render fires");
    CHECK_EQ(r.cmd,        RENDER_MOVE_CURSOR, "cmd MOVE_CURSOR");
    CHECK_EQ(r.cursor_pos, 2,                  "cursor_pos post-RIGHT");
}

// KEY_UP / KEY_DOWN in S_IDLE emit RENDER_SCROLL_UP / RENDER_SCROLL_DOWN
// frames. They don't touch the input line buffer or send anything via
// comm. Shift-arrow (ascii bit 0 set) routes to RENDER_INPUT_SCROLL_*.
static void test_scroll_keys_emit_render() {
    printf("== test_scroll_keys_emit_render\n");
    reset();
    send_key(KEY_UP, 0);
    RenderEvent u;
    CHECK_EQ(wait_render(u, 5), true,         "UP render fires");
    CHECK_EQ(u.cmd, RENDER_SCROLL_UP,         "cmd SCROLL_UP");

    send_key(KEY_DOWN, 0);
    RenderEvent d;
    CHECK_EQ(wait_render(d, 5), true,         "DOWN render fires");
    CHECK_EQ(d.cmd, RENDER_SCROLL_DOWN,       "cmd SCROLL_DOWN");

    // Shift+Up / Shift+Down (ascii=KEY_SHIFT_MASK=0x01) route to
    // RENDER_INPUT_SCROLL_* instead.
    send_key(KEY_UP, 0x01);
    RenderEvent su;
    CHECK_EQ(wait_render(su, 5), true,             "Shift+UP render fires");
    CHECK_EQ(su.cmd, RENDER_INPUT_SCROLL_UP,       "cmd INPUT_SCROLL_UP");

    send_key(KEY_DOWN, 0x01);
    RenderEvent sd;
    CHECK_EQ(wait_render(sd, 5), true,             "Shift+DOWN render fires");
    CHECK_EQ(sd.cmd, RENDER_INPUT_SCROLL_DOWN,     "cmd INPUT_SCROLL_DOWN");

    // Scroll keys must not alter the input line.
    CHECK_EQ(dut->line_len,   0, "line_len untouched");
    CHECK_EQ(dut->cursor_pos, 0, "cursor_pos untouched");
}

// Type "ab", LEFT, type "X" -> buffer "aXb", cursor=2, len=3.
// Render of the X carries cursor_pos=2 and ascii='X'.
static void test_insert_in_middle() {
    printf("== test_insert_in_middle\n");
    reset();
    send_key(KEY_CHAR, 'a'); drain_render();
    send_key(KEY_CHAR, 'b'); drain_render();
    send_key(KEY_LEFT, 0);   drain_render();   // MOVE_CURSOR
    send_key(KEY_CHAR, 'X');
    RenderEvent e;
    CHECK_EQ(wait_render(e, 5), true, "render fires");
    CHECK_EQ(e.cmd,        RENDER_INSERT_AT_CURSOR, "cmd INSERT");
    CHECK_EQ(e.cursor_pos, 2,   "post-edit cursor");
    CHECK_EQ(e.ascii,      'X', "ascii");

    CHECK_EQ(dut->line_len,   3, "line_len");
    CHECK_EQ(dut->cursor_pos, 2, "cursor_pos");
    CHECK_EQ(read_buf(0),     'a', "buf[0]");
    CHECK_EQ(read_buf(1),     'X', "buf[1] (inserted)");
    CHECK_EQ(read_buf(2),     'b', "buf[2] (shifted right)");
}

// Type "abc", LEFT, BS -> buffer "ac", cursor=0, len=2.
// Render carries cursor_pos=0.
static void test_delete_in_middle() {
    printf("== test_delete_in_middle\n");
    reset();
    send_key(KEY_CHAR, 'a'); drain_render();
    send_key(KEY_CHAR, 'b'); drain_render();
    send_key(KEY_CHAR, 'c'); drain_render();
    send_key(KEY_LEFT, 0);   drain_render();   // cursor 3 -> 2
    send_key(KEY_BACKSPACE, 0);
    RenderEvent e;
    CHECK_EQ(wait_render(e, 5), true, "render fires");
    CHECK_EQ(e.cmd,        RENDER_DELETE_AT_CURSOR, "cmd DELETE");
    CHECK_EQ(e.cursor_pos, 1, "post-edit cursor (was 2 -> 1)");

    CHECK_EQ(dut->line_len,   2, "line_len");
    CHECK_EQ(dut->cursor_pos, 1, "cursor_pos");
    CHECK_EQ(read_buf(0),     'a', "buf[0]");
    CHECK_EQ(read_buf(1),     'c', "buf[1] shifted left");
}

// Fill the buffer to MAX, move the cursor mid-line, type a char ->
// dropped, no render.
static void test_full_buffer_insert_dropped() {
    printf("== test_full_buffer_insert_dropped\n");
    reset();
    for (int i = 0; i < MAX_LINE_LEN; i++) {
        send_key(KEY_CHAR, (uint8_t)('A' + (i % 26)));
        drain_render();
    }
    // Move cursor a few positions back to mid-line.
    for (int i = 0; i < 3; i++) { send_key(KEY_LEFT, 0); drain_render(); }
    CHECK_EQ(dut->cursor_pos, MAX_LINE_LEN - 3, "cursor mid-line");

    send_key(KEY_CHAR, '!');
    CHECK_EQ(dut->line_len,   MAX_LINE_LEN,     "line_len unchanged");
    CHECK_EQ(dut->cursor_pos, MAX_LINE_LEN - 3, "cursor unchanged");
    CHECK_EQ(no_render_for(5), true, "no render on dropped insert");
}

// =====================================================================
// (B) Store + commit pipeline
// =====================================================================

static void test_no_commit_no_store_write() {
    printf("== test_no_commit_no_store_write\n");
    reset();
    send_key(KEY_CHAR, 'a'); drain_render();
    send_key(KEY_BACKSPACE, 0); drain_render();
    auto r = read_store(0);
    CHECK_EQ(r.valid, 0, "slot 0 invalid");
}

static void test_empty_enter_does_not_write() {
    printf("== test_empty_enter_does_not_write\n");
    reset();
    send_key(KEY_ENTER, 0);
    auto r = read_store(0);
    CHECK_EQ(r.valid, 0, "slot 0 invalid (empty ENTER)");
}

static void test_commit_writes_record() {
    printf("== test_commit_writes_record\n");
    reset();
    send_key(KEY_CHAR, 'h'); drain_render();
    send_key(KEY_CHAR, 'i'); drain_render();
    send_key(KEY_ENTER, 0);
    drain_commit_pipeline();
    auto r = read_store(0);
    CHECK_EQ(r.valid,  1,           "slot 0 valid");
    CHECK_EQ(r.msg_id, 0,           "msg_id 0");
    CHECK_EQ(r.side,   MSG_LOCAL,   "side LOCAL");
    CHECK_EQ(r.status, MSG_PENDING, "status PENDING");
    CHECK_EQ(r.len,    2,           "len 2");
    CHECK_EQ(store_payload_byte(0), 'h', "payload[0]");
    CHECK_EQ(store_payload_byte(1), 'i', "payload[1]");
}

static void test_two_commits_distinct_slots() {
    printf("== test_two_commits_distinct_slots\n");
    reset();
    send_key(KEY_CHAR, 'a'); drain_render();
    send_key(KEY_CHAR, 'b'); drain_render();
    send_key(KEY_ENTER, 0);  drain_commit_pipeline();
    send_key(KEY_CHAR, 'c'); drain_render();
    send_key(KEY_CHAR, 'd'); drain_render();
    send_key(KEY_ENTER, 0);  drain_commit_pipeline();
    auto r0 = read_store(0);
    CHECK_EQ(r0.msg_id, 0, "slot 0 msg_id");
    CHECK_EQ(r0.len,    2, "slot 0 len");
    CHECK_EQ(store_payload_byte(0), 'a', "slot 0 byte 0");
    CHECK_EQ(store_payload_byte(1), 'b', "slot 0 byte 1");

    auto r1 = read_store(1);
    CHECK_EQ(r1.msg_id, 1, "slot 1 msg_id");
    CHECK_EQ(r1.len,    2, "slot 1 len");
    CHECK_EQ(store_payload_byte(0), 'c', "slot 1 byte 0");
    CHECK_EQ(store_payload_byte(1), 'd', "slot 1 byte 1");
}

static void test_payload_packed_correctly() {
    printf("== test_payload_packed_correctly\n");
    reset();
    for (int i = 0; i < 10; i++) {
        send_key(KEY_CHAR, (uint8_t)('A' + i));
        drain_render();
    }
    send_key(KEY_ENTER, 0);
    drain_commit_pipeline();
    read_store(0);
    for (int i = 0; i < 10; i++) {
        char lbl[40]; snprintf(lbl, sizeof(lbl), "payload[%d]", i);
        CHECK_EQ(store_payload_byte(i), (uint8_t)('A' + i), lbl);
    }
    CHECK_EQ(store_payload_byte(10), 0, "payload[10] zero past len");
}

static void test_emoji_tokens_encoded_on_commit() {
    printf("== test_emoji_tokens_encoded_on_commit\n");
    reset();
    for (char c : std::string("\\happy \\sad \\heart \\ok \\laugh \\wink \\angry \\star \\fire \\yes \\no \\up \\down \\doge \\mairuo")) {
        send_key(KEY_CHAR, (uint8_t)c);
        drain_render();
    }

    send_key(KEY_ENTER, 0);

    RenderEvent r1;
    CHECK_EQ(wait_render(r1), true, "got local append render");
    CHECK_EQ(r1.cmd, RENDER_APPEND_LOCAL_PENDING, "render append local");
    CHECK_EQ(r1.len, 29, "encoded render len");
    const uint8_t expected[] = {
        0xE0, ' ', 0xE1, ' ', 0xE2, ' ', 0xE3, ' ',
        0xE4, ' ', 0xE5, ' ', 0xE6, ' ', 0xE7, ' ',
        0xE8, ' ', 0xE9, ' ', 0xEA, ' ', 0xEB, ' ', 0xEC, ' ',
        0xED, ' ', 0xEE
    };
    for (int i = 0; i < 29; i++) {
        char lbl[48]; snprintf(lbl, sizeof(lbl), "render emoji payload[%d]", i);
        CHECK_EQ(payload_get_byte(r1.payload, i), expected[i], lbl);
    }

    TxEvent tx;
    CHECK_EQ(wait_tx(tx), true, "got DATA tx");
    CHECK_EQ(tx.len, 29, "encoded tx len");
    for (int i = 0; i < 29; i++) {
        char lbl[48]; snprintf(lbl, sizeof(lbl), "tx emoji payload[%d]", i);
        CHECK_EQ(payload_get_byte(tx.payload, i), expected[i], lbl);
    }

    RenderEvent clear;
    CHECK_EQ(wait_render(clear), true, "got input clear render");
    CHECK_EQ(clear.cmd, RENDER_UPDATE_INPUT_LINE, "clear render");

    StoreRead s = read_store(0);
    CHECK_EQ(s.valid, 1, "store valid");
    CHECK_EQ(s.len, 29, "encoded store len");
    for (int i = 0; i < 29; i++) {
        char lbl[48]; snprintf(lbl, sizeof(lbl), "store emoji payload[%d]", i);
        CHECK_EQ(store_payload_byte(i), expected[i], lbl);
    }
}

// Big-emoji tokens (capital first letter) encode to a single anchor
// byte each; render/tx/store all carry that single byte. The frontend
// is what expands it into a multi-tile bubble on display.
static void test_big_emoji_tokens_encoded_on_commit() {
    printf("== test_big_emoji_tokens_encoded_on_commit\n");
    reset();
    for (char c : std::string("\\Shrug \\Hissing \\Heartbroken \\Sweat \\Xiucai")) {
        send_key(KEY_CHAR, (uint8_t)c);
        drain_render();
    }
    send_key(KEY_ENTER, 0);

    RenderEvent r1;
    CHECK_EQ(wait_render(r1), true, "got local append render");
    CHECK_EQ(r1.cmd, RENDER_APPEND_LOCAL_PENDING, "render append local");
    CHECK_EQ(r1.len, 9, "encoded render len (5 anchors + 4 spaces)");
    const uint8_t expected[] = {
        (uint8_t)BIG_EMOJI_SHRUG_ANCHOR,       ' ',
        (uint8_t)BIG_EMOJI_HISSING_ANCHOR,     ' ',
        (uint8_t)BIG_EMOJI_HEARTBROKEN_ANCHOR, ' ',
        (uint8_t)BIG_EMOJI_SWEAT_ANCHOR,       ' ',
        (uint8_t)BIG_EMOJI_XIUCAI_ANCHOR
    };
    for (int i = 0; i < 9; i++) {
        char lbl[48]; snprintf(lbl, sizeof(lbl), "render big-emoji payload[%d]", i);
        CHECK_EQ(payload_get_byte(r1.payload, i), expected[i], lbl);
    }

    TxEvent tx;
    CHECK_EQ(wait_tx(tx), true, "got DATA tx");
    CHECK_EQ(tx.len, 9, "encoded tx len");
    for (int i = 0; i < 9; i++) {
        char lbl[48]; snprintf(lbl, sizeof(lbl), "tx big-emoji payload[%d]", i);
        CHECK_EQ(payload_get_byte(tx.payload, i), expected[i], lbl);
    }

    RenderEvent clear;
    CHECK_EQ(wait_render(clear), true, "got input clear render");
    CHECK_EQ(clear.cmd, RENDER_UPDATE_INPUT_LINE, "clear render");

    StoreRead s = read_store(0);
    CHECK_EQ(s.valid, 1, "store valid");
    CHECK_EQ(s.len, 9, "encoded store len");
    for (int i = 0; i < 9; i++) {
        char lbl[48]; snprintf(lbl, sizeof(lbl), "store big-emoji payload[%d]", i);
        CHECK_EQ(store_payload_byte(i), expected[i], lbl);
    }
}

// An unmatched capitalized token (no such big emoji) must fall through
// to the literal byte path, just like an unknown lowercase token does.
static void test_big_emoji_unknown_token_passthrough() {
    printf("== test_big_emoji_unknown_token_passthrough\n");
    reset();
    for (char c : std::string("\\Bogus")) {
        send_key(KEY_CHAR, (uint8_t)c);
        drain_render();
    }
    send_key(KEY_ENTER, 0);

    RenderEvent r1;
    CHECK_EQ(wait_render(r1), true, "got local append render");
    CHECK_EQ(r1.len, 6, "literal len = original 6 bytes");
    const char* expect = "\\Bogus";
    for (int i = 0; i < 6; i++) {
        char lbl[40]; snprintf(lbl, sizeof(lbl), "literal byte[%d]", i);
        CHECK_EQ(payload_get_byte(r1.payload, i), (uint8_t)expect[i], lbl);
    }
}

// Full pipeline: APPEND_LOCAL_PENDING -> be_tx -> UPDATE_INPUT_LINE
// (with cursor_pos=0 to match the cleared input).
static void test_commit_full_pipeline_order() {
    printf("== test_commit_full_pipeline_order\n");
    reset();
    send_key(KEY_CHAR, 'h'); drain_render();
    send_key(KEY_CHAR, 'i'); drain_render();
    send_key(KEY_ENTER, 0);

    RenderEvent r1;
    CHECK_EQ(wait_render(r1, 5), true, "pipeline render 1 fired");
    CHECK_EQ(r1.cmd,    RENDER_APPEND_LOCAL_PENDING, "first render APPEND_LOCAL_PENDING");
    CHECK_EQ(r1.msg_id, 0,           "render msg_id");
    CHECK_EQ(r1.side,   MSG_LOCAL,   "side");
    CHECK_EQ(r1.status, MSG_PENDING, "status");
    CHECK_EQ(r1.len,    2,           "len");
    CHECK_EQ(payload_get_byte(r1.payload, 0), 'h', "byte 0");
    CHECK_EQ(payload_get_byte(r1.payload, 1), 'i', "byte 1");

    TxEvent tx;
    CHECK_EQ(wait_tx(tx, 5), true, "be_tx fired");
    CHECK_EQ(tx.msg_id, 0, "tx msg_id");
    CHECK_EQ(tx.len,    2, "tx len");
    CHECK_EQ(payload_get_byte(tx.payload, 0), 'h', "tx byte 0");
    CHECK_EQ(payload_get_byte(tx.payload, 1), 'i', "tx byte 1");

    RenderEvent r2;
    CHECK_EQ(wait_render(r2, 5), true, "pipeline render 2 fired");
    CHECK_EQ(r2.cmd,        RENDER_UPDATE_INPUT_LINE, "trailing UPDATE_INPUT_LINE");
    CHECK_EQ(r2.len,        0, "input cleared");
    CHECK_EQ(r2.cursor_pos, 0, "cursor cleared");
}

static void test_commit_blocked_by_render_backpressure() {
    printf("== test_commit_blocked_by_render_backpressure\n");
    reset();
    send_key(KEY_CHAR, 'x'); drain_render();

    dut->be_render_ready = 0;
    send_key(KEY_ENTER, 0);

    for (int i = 0; i < 20; i++) tick();
    dut->eval();
    CHECK_EQ(dut->be_render_valid, 1, "render still asserted");
    CHECK_EQ(dut->be_tx_valid,     0, "tx withheld");

    dut->be_render_ready = 1;
    RenderEvent r1; CHECK_EQ(wait_render(r1, 10), true, "pending render drains");
    CHECK_EQ(r1.cmd, RENDER_APPEND_LOCAL_PENDING, "drained APPEND_LOCAL_PENDING");
    TxEvent tx; CHECK_EQ(wait_tx(tx, 10), true, "tx fires");
    RenderEvent r2; CHECK_EQ(wait_render(r2, 10), true, "trailing render fires");
    CHECK_EQ(r2.cmd,        RENDER_UPDATE_INPUT_LINE, "trailing");
    CHECK_EQ(r2.cursor_pos, 0, "trailing cursor cleared");
}

static void test_commit_blocked_by_tx_backpressure() {
    printf("== test_commit_blocked_by_tx_backpressure\n");
    reset();
    send_key(KEY_CHAR, 'q'); drain_render();

    dut->be_tx_ready = 0;
    send_key(KEY_ENTER, 0);

    RenderEvent r1; CHECK_EQ(wait_render(r1, 5), true, "first render");
    CHECK_EQ(r1.cmd, RENDER_APPEND_LOCAL_PENDING, "APPEND_LOCAL_PENDING");

    for (int i = 0; i < 20; i++) tick();
    dut->eval();
    CHECK_EQ(dut->be_tx_valid,     1, "tx asserted while blocked");
    CHECK_EQ(dut->be_render_valid, 0, "trailing render withheld");

    dut->be_tx_ready = 1;
    TxEvent tx; CHECK_EQ(wait_tx(tx, 5), true, "tx drains");
    RenderEvent r2; CHECK_EQ(wait_render(r2, 5), true, "trailing render");
    CHECK_EQ(r2.cmd,        RENDER_UPDATE_INPUT_LINE, "trailing");
    CHECK_EQ(r2.cursor_pos, 0, "trailing cursor cleared");
}

// After the commit pipeline drains, the FSM is in IDLE again. A new CHAR
// should produce a fresh INSERT_AT_CURSOR render with cursor_pos=1.
static void test_commit_back_to_idle() {
    printf("== test_commit_back_to_idle\n");
    reset();
    send_key(KEY_CHAR, 'p'); drain_render();
    send_key(KEY_ENTER, 0);  drain_commit_pipeline();
    send_key(KEY_CHAR, 'Z');
    RenderEvent r;
    CHECK_EQ(wait_render(r, 5), true, "post-pipeline render fires");
    CHECK_EQ(r.cmd,        RENDER_INSERT_AT_CURSOR, "cmd");
    CHECK_EQ(r.cursor_pos, 1,   "fresh cursor");
    CHECK_EQ(r.ascii,      'Z', "fresh byte");
}

// =====================================================================
// (C) RX path
// =====================================================================

static void test_rx_writes_remote_record() {
    printf("== test_rx_writes_remote_record\n");
    reset();
    inject_rx(/*seq=*/7, /*len=*/3, {'p','e','e'});
    drain_render();
    auto r = read_store(0);
    CHECK_EQ(r.valid,  1,          "remote slot valid");
    CHECK_EQ(r.msg_id, 7,          "remote msg_id from seq");
    CHECK_EQ(r.side,   MSG_REMOTE, "side REMOTE");
    CHECK_EQ(r.status, MSG_SUCCESS,"status SUCCESS");
    CHECK_EQ(r.len,    3,          "len");
    CHECK_EQ(store_payload_byte(0), 'p', "byte 0");
    CHECK_EQ(store_payload_byte(2), 'e', "byte 2");
}

static void test_rx_emits_render_remote() {
    printf("== test_rx_emits_render_remote\n");
    reset();
    inject_rx(11, 4, {'b','o','o','m'});
    RenderEvent e;
    CHECK_EQ(wait_render(e, 5), true, "render fires");
    CHECK_EQ(e.cmd,    RENDER_APPEND_REMOTE, "cmd APPEND_REMOTE");
    CHECK_EQ(e.msg_id, 11,                   "render carries seq");
    CHECK_EQ(e.side,   MSG_REMOTE,           "side");
    CHECK_EQ(e.status, MSG_SUCCESS,          "status");
    CHECK_EQ(e.len,    4,                    "len");
    CHECK_EQ(payload_get_byte(e.payload, 3), 'm', "byte 3");
}

static void test_rx_does_not_consume_local_msg_id() {
    printf("== test_rx_does_not_consume_local_msg_id\n");
    reset();
    inject_rx(50, 1, {'r'});           drain_render();
    send_key(KEY_CHAR, 'a');           drain_render();
    send_key(KEY_ENTER, 0);            drain_commit_pipeline();
    auto local = read_store(1);
    CHECK_EQ(local.msg_id, 0,         "local msg_id starts at 0");
    CHECK_EQ(local.side,   MSG_LOCAL, "local slot side");
}

// cm_rx_len > MAX_MSG_LEN must be clamped at MAX_MSG_LEN both in the
// store and in the render len.
static void test_cm_rx_len_clamped() {
    printf("== test_cm_rx_len_clamped\n");
    reset();
    std::vector<uint8_t> bytes(MAX_MSG_LEN, 'Z');  // wide bus is exactly MAX_MSG_LEN bytes
    inject_rx(/*seq=*/3, /*len=*/(uint16_t)(MAX_MSG_LEN + 100), bytes);
    RenderEvent e;
    CHECK_EQ(wait_render(e, 5), true, "render fires");
    CHECK_EQ((int)e.len, MAX_MSG_LEN, "render len clamped");
    auto r = read_store(0);
    CHECK_EQ((int)r.len, MAX_MSG_LEN, "store len clamped");
}

static void test_cm_rx_len_passthrough_when_small() {
    printf("== test_cm_rx_len_passthrough_when_small\n");
    reset();
    inject_rx(9, 5, {'h','e','l','l','o'});
    RenderEvent e;
    CHECK_EQ(wait_render(e, 5), true, "render fires");
    CHECK_EQ(e.len, 5, "render len pass-through");
    auto r = read_store(0);
    CHECK_EQ(r.len, 5, "store len pass-through");
}

// =====================================================================
// (D) STATUS path
// =====================================================================

static void test_status_updates_store() {
    printf("== test_status_updates_store\n");
    reset();
    send_key(KEY_CHAR, 'q'); drain_render();
    send_key(KEY_ENTER, 0);  drain_commit_pipeline();
    auto pre = read_store(0);
    CHECK_EQ(pre.status, MSG_PENDING, "starts PENDING");

    inject_status(0, TX_SUCCESS); drain_render();
    auto post = read_store(0);
    CHECK_EQ(post.status, MSG_SUCCESS, "becomes SUCCESS");

    inject_status(0, TX_FAIL); drain_render();
    post = read_store(0);
    CHECK_EQ(post.status, MSG_FAIL, "becomes FAIL");
}

static void test_status_emits_render() {
    printf("== test_status_emits_render\n");
    reset();
    send_key(KEY_CHAR, 'a'); drain_render();
    send_key(KEY_ENTER, 0);  drain_commit_pipeline();
    inject_status(0, TX_SUCCESS);
    RenderEvent e;
    CHECK_EQ(wait_render(e, 5), true, "render fires");
    CHECK_EQ(e.cmd,    RENDER_UPDATE_STATUS, "cmd");
    CHECK_EQ(e.msg_id, 0,                    "msg_id");
    CHECK_EQ(e.status, MSG_SUCCESS,          "status");
}

static void test_status_unknown_msg_id() {
    printf("== test_status_unknown_msg_id\n");
    reset();
    inject_status(99, TX_SUCCESS);
    RenderEvent e;
    CHECK_EQ(wait_render(e, 5), true, "render fires");
    CHECK_EQ(e.cmd,    RENDER_UPDATE_STATUS, "cmd");
    CHECK_EQ(e.msg_id, 99,                   "render carries the offered msg_id");
    auto r = read_store(0);
    CHECK_EQ(r.valid, 0, "no slot magically appeared");
}

// =====================================================================
// (G) Arbitration
// =====================================================================

static void test_arbitration_priority() {
    printf("== test_arbitration_priority\n");
    reset();
    // Pre-load a local commit so slot 0 has a PENDING message.
    send_key(KEY_CHAR, 'a'); drain_render();
    send_key(KEY_ENTER, 0);  drain_commit_pipeline();

    dut->cm_status_valid  = 1;
    dut->cm_status_msg_id = 0;
    dut->cm_status_code   = TX_SUCCESS;

    dut->cm_rx_valid      = 1;
    dut->cm_rx_frame_type = FRAME_DATA;
    dut->cm_rx_seq        = 5;
    dut->cm_rx_len        = 1;
    payload_load(&dut->cm_rx_payload[0], {'r'});

    dut->io_key_valid = 1;
    dut->io_key_type  = KEY_CHAR;
    dut->io_key_ascii = 'X';

    dut->eval();
    CHECK_EQ(dut->cm_status_ready, 1, "status ready (highest priority)");
    CHECK_EQ(dut->cm_rx_ready,     0, "rx ready withheld");
    CHECK_EQ(dut->io_key_ready,    0, "io ready withheld");

    tick();
    drain_render();   // status render
    dut->cm_status_valid = 0;

    dut->eval();
    CHECK_EQ(dut->cm_rx_ready,  1, "rx ready next");
    CHECK_EQ(dut->io_key_ready, 0, "io still withheld");

    tick();
    drain_render();   // rx render
    dut->cm_rx_valid = 0;
    payload_clear(&dut->cm_rx_payload[0]);

    dut->eval();
    CHECK_EQ(dut->io_key_ready, 1, "io ready last");

    tick();
    dut->io_key_valid = 0;
    drain_render();   // insert render
}

// =====================================================================
// (H) Sanity / timing
// =====================================================================

static void test_enter_pulse_one_cycle() {
    printf("== test_enter_pulse_one_cycle\n");
    reset();
    send_key(KEY_CHAR, 'x'); drain_render();
    send_key(KEY_ENTER, 0);
    CHECK_EQ(dut->enter_committed, 1, "pulse high right after ENTER");
    tick();
    dut->eval();
    CHECK_EQ(dut->enter_committed, 0, "pulse low next cycle");
    drain_commit_pipeline();
}

static void test_three_commits() {
    printf("== test_three_commits\n");
    reset();
    auto commit_msg = [](const std::string& s) {
        for (char c : s) { send_key(KEY_CHAR, (uint8_t)c); drain_render(); }
        send_key(KEY_ENTER, 0); drain_commit_pipeline();
    };
    commit_msg("a");
    commit_msg("bb");
    commit_msg("ccc");
    CHECK_EQ(read_store(0).msg_id, 0, "first msg_id");
    CHECK_EQ(read_store(1).msg_id, 1, "second msg_id");
    CHECK_EQ(read_store(2).msg_id, 2, "third msg_id");
    CHECK_EQ(read_store(0).len,    1, "first len");
    CHECK_EQ(read_store(1).len,    2, "second len");
    CHECK_EQ(read_store(2).len,    3, "third len");
}

static void test_rx_local_interleaved() {
    printf("== test_rx_local_interleaved\n");
    reset();
    inject_rx(20, 1, {'P'});  drain_render();
    send_key(KEY_CHAR, 'L');  drain_render();
    send_key(KEY_ENTER, 0);   drain_commit_pipeline();
    inject_rx(21, 1, {'Q'});  drain_render();

    auto s0 = read_store(0);
    CHECK_EQ(s0.side,   MSG_REMOTE, "slot 0 REMOTE");
    CHECK_EQ(s0.msg_id, 20,         "slot 0 seq");

    auto s1 = read_store(1);
    CHECK_EQ(s1.side,   MSG_LOCAL,  "slot 1 LOCAL");
    CHECK_EQ(s1.msg_id, 0,          "slot 1 local msg_id");

    auto s2 = read_store(2);
    CHECK_EQ(s2.side,   MSG_REMOTE, "slot 2 REMOTE");
    CHECK_EQ(s2.msg_id, 21,         "slot 2 seq");
}

// =====================================================================
// (F) Connection management
// =====================================================================

// Bring us to S_HANDSHAKE_IDLE: REDRAW drained, HELLO drained, no peer
// reply yet. FSM idles waiting for cm_rx.
static void reset_to_handshake_idle() {
    reset_no_drain();
    RenderEvent r;  wait_render(r, 10);  // REDRAW_ALL
    TxEvent tx;     wait_tx(tx, 10);     // HELLO
}

// Disconnect via ESC. Assumes the FSM is in S_IDLE (CONN_CONNECTED).
// Drains the GOODBYE tx and the trailing RENDER_CONN_STATE.
static void disconnect_via_esc() {
    send_key(KEY_ESC, 0);
    TxEvent tx;     wait_tx(tx, 10);     // GOODBYE
    RenderEvent r;  wait_render(r, 10);  // CONN_STATE = DISCONNECTED
}

// Peer USERNAME during handshake -> directly into S_CONNECTED, single
// RENDER_CONN_STATE.
static void test_handshake_via_peer_username() {
    printf("== test_handshake_via_peer_username\n");
    reset_to_handshake_idle();
    inject_rx_frame(FRAME_USERNAME, /*seq=*/0, 4, {'C','a','r','l'});
    RenderEvent r;
    CHECK_EQ(wait_render(r, 10), true,             "CONN_STATE render fires");
    CHECK_EQ(r.cmd,              RENDER_CONN_STATE,"cmd CONN_STATE");
    CHECK_EQ(r.conn_state,       CONN_CONNECTED,   "conn_state CONNECTED");
    CHECK_EQ(r.peer_name_len,    4,                "peer_name_len latched");
    CHECK_EQ(r.peer_name[0],     (uint8_t)'C',     "peer byte 0");
    CHECK_EQ(r.peer_name[3],     (uint8_t)'l',     "peer byte 3");
    CHECK_EQ(dut->conn_state_obs,CONN_CONNECTED,   "obs CONNECTED");
}

// Peer HELLO during handshake -> we tx USERNAME, then enter CONNECTED.
static void test_handshake_via_peer_hello() {
    printf("== test_handshake_via_peer_hello\n");
    reset_to_handshake_idle();
    inject_rx_frame(FRAME_HELLO, /*seq=*/0, 3, {'B','o','b'});
    TxEvent tx;
    CHECK_EQ(wait_tx(tx, 10),    true,             "USERNAME tx fires");
    CHECK_EQ(tx.frame_type,      FRAME_USERNAME,   "frame_type USERNAME");
    CHECK_EQ(tx.len,             MY_NAME_LEN_DEFAULT, "len = MY_NAME_LEN");
    RenderEvent r;
    CHECK_EQ(wait_render(r, 10), true,             "CONN_STATE fires");
    CHECK_EQ(r.cmd,              RENDER_CONN_STATE,"cmd");
    CHECK_EQ(r.conn_state,       CONN_CONNECTED,   "conn_state CONNECTED");
    CHECK_EQ(r.peer_name_len,    3,                "peer_name_len");
    CHECK_EQ(r.peer_name[0],     (uint8_t)'B',     "peer byte 0");
}

// Peer REHELLO during handshake (atypical but defensive): same effect
// as HELLO -- we respond with USERNAME and proceed.
static void test_handshake_via_peer_rehello() {
    printf("== test_handshake_via_peer_rehello\n");
    reset_to_handshake_idle();
    inject_rx_frame(FRAME_REHELLO, /*seq=*/0, 3, {'B','o','b'});
    TxEvent tx;
    CHECK_EQ(wait_tx(tx, 10),    true,           "USERNAME tx fires");
    CHECK_EQ(tx.frame_type,      FRAME_USERNAME, "frame_type USERNAME");
    RenderEvent r;
    CHECK_EQ(wait_render(r, 10), true,             "CONN_STATE fires");
    CHECK_EQ(r.conn_state,       CONN_CONNECTED,   "CONNECTED");
}

// DATA during handshake is silently dropped (consumed but no render/tx).
static void test_handshake_drops_data_frame() {
    printf("== test_handshake_drops_data_frame\n");
    reset_to_handshake_idle();
    inject_rx_frame(FRAME_DATA, /*seq=*/9, 1, {'X'});
    CHECK_EQ(no_render_for(5), true, "no render on dropped DATA");
    dut->eval();
    CHECK_EQ(dut->be_tx_valid, 0, "no tx triggered");
    CHECK_EQ(dut->conn_state_obs, CONN_HANDSHAKE, "still HANDSHAKE");
}

// io_key events in S_HANDSHAKE_IDLE are accepted (ready=1) and dropped.
// Verify by sending CHAR while in handshake -- buffer doesn't grow,
// no render fires.
static void test_handshake_drops_keys() {
    printf("== test_handshake_drops_keys\n");
    reset_to_handshake_idle();
    send_key(KEY_CHAR, 'q');
    CHECK_EQ(dut->line_len,    0, "line_len stays 0");
    CHECK_EQ(no_render_for(5), true, "no render");
    CHECK_EQ(dut->conn_state_obs, CONN_HANDSHAKE, "still HANDSHAKE");
}

// After ESC->disconnect, pressing SPACE re-handshakes (sends HELLO).
static void test_disconnected_space_reconnects() {
    printf("== test_disconnected_space_reconnects\n");
    reset();
    disconnect_via_esc();
    CHECK_EQ(dut->conn_state_obs, CONN_DISCONNECTED, "in DISCONNECTED");
    send_key(KEY_CHAR, ' ');
    TxEvent tx;
    CHECK_EQ(wait_tx(tx, 10),  true,         "HELLO fires");
    CHECK_EQ(tx.frame_type,    FRAME_HELLO,  "frame_type HELLO");
    CHECK_EQ(dut->conn_state_obs, CONN_HANDSHAKE, "now HANDSHAKE");
}

// Disconnected + peer HELLO (peer reconnecting via their SPACE) ->
// we tx USERNAME -> back to CONNECTED.
static void test_disconnected_peer_hello_reconnects() {
    printf("== test_disconnected_peer_hello_reconnects\n");
    reset();
    disconnect_via_esc();
    inject_rx_frame(FRAME_HELLO, 0, 3, {'B','o','b'});
    TxEvent tx;
    CHECK_EQ(wait_tx(tx, 10), true,           "USERNAME tx fires");
    CHECK_EQ(tx.frame_type,   FRAME_USERNAME, "frame_type USERNAME");
    RenderEvent r;
    CHECK_EQ(wait_render(r, 10), true,            "CONN_STATE fires");
    CHECK_EQ(r.conn_state,    CONN_CONNECTED,    "back to CONNECTED");
}

// In disconnected, non-SPACE keys are dropped (no tx, no render).
static void test_disconnected_drops_other_keys() {
    printf("== test_disconnected_drops_other_keys\n");
    reset();
    disconnect_via_esc();
    send_key(KEY_CHAR, 'a');
    CHECK_EQ(no_render_for(5), true, "no render");
    dut->eval();
    CHECK_EQ(dut->be_tx_valid,    0,                  "no tx");
    CHECK_EQ(dut->conn_state_obs, CONN_DISCONNECTED,  "still DISCONNECTED");
    send_key(KEY_ENTER, 0);
    CHECK_EQ(no_render_for(5), true, "ENTER also dropped");
    send_key(KEY_LEFT, 0);
    CHECK_EQ(no_render_for(5), true, "LEFT also dropped");
}

// In disconnected, peer DATA is silently dropped.
static void test_disconnected_drops_data() {
    printf("== test_disconnected_drops_data\n");
    reset();
    disconnect_via_esc();
    inject_rx_frame(FRAME_DATA, 7, 1, {'X'});
    CHECK_EQ(no_render_for(5), true, "no render on dropped DATA");
    auto r0 = read_store(0);
    CHECK_EQ(r0.valid, 0, "store unchanged");
}

// Mid-chat HELLO from peer (peer rebooted): we emit REHELLO + refresh
// CONN_STATE; our state stays CONNECTED.
static void test_peer_hello_in_chat_emits_rehello() {
    printf("== test_peer_hello_in_chat_emits_rehello\n");
    reset();  // peer = "Bob"
    inject_rx_frame(FRAME_HELLO, /*seq=*/0, 3, {'B','o','b'});
    TxEvent tx;
    CHECK_EQ(wait_tx(tx, 10),  true,           "REHELLO tx fires");
    CHECK_EQ(tx.frame_type,    FRAME_REHELLO,  "frame_type REHELLO");
    CHECK_EQ(tx.len,           MY_NAME_LEN_DEFAULT, "REHELLO carries our name len");
    RenderEvent r;
    CHECK_EQ(wait_render(r, 10), true,             "CONN_STATE fires");
    CHECK_EQ(r.conn_state,     CONN_CONNECTED,     "still CONNECTED");
    CHECK_EQ(dut->conn_state_obs, CONN_CONNECTED,  "obs CONNECTED");
}

// Mid-chat REHELLO from peer (peer responded to OUR HELLO): we emit
// USERNAME and refresh CONN_STATE. We do NOT emit REHELLO (would loop).
static void test_peer_rehello_in_chat_emits_username() {
    printf("== test_peer_rehello_in_chat_emits_username\n");
    reset();
    inject_rx_frame(FRAME_REHELLO, /*seq=*/0, 3, {'B','o','b'});
    TxEvent tx;
    CHECK_EQ(wait_tx(tx, 10),  true,           "USERNAME tx fires");
    CHECK_EQ(tx.frame_type,    FRAME_USERNAME, "frame_type USERNAME (NOT REHELLO)");
    RenderEvent r;
    CHECK_EQ(wait_render(r, 10), true,             "CONN_STATE fires");
    CHECK_EQ(r.conn_state,     CONN_CONNECTED,     "still CONNECTED");
}

// Mid-chat USERNAME from peer (just an info refresh): no tx, only the
// CONN_STATE refresh render.
static void test_peer_username_in_chat_refreshes() {
    printf("== test_peer_username_in_chat_refreshes\n");
    reset();
    inject_rx_frame(FRAME_USERNAME, /*seq=*/0, 3, {'B','o','b'});
    RenderEvent r;
    CHECK_EQ(wait_render(r, 10), true,             "CONN_STATE refresh");
    CHECK_EQ(r.conn_state,     CONN_CONNECTED,     "still CONNECTED");
    dut->eval();
    CHECK_EQ(dut->be_tx_valid, 0, "no tx triggered");
}

// Peer reboots with a different username -> store is cleared.
// Mid-chat HELLO triggers REHELLO tx + CONN_STATE render.
static void test_peer_name_change_clears_store() {
    printf("== test_peer_name_change_clears_store\n");
    reset();  // peer = "Bob"
    // Populate the store with one remote message and one local commit.
    inject_rx_frame(FRAME_DATA, 100, 3, {'h','e','y'});
    drain_render();
    send_key(KEY_CHAR, 'a'); drain_render();
    send_key(KEY_ENTER, 0);  drain_commit_pipeline();
    CHECK_EQ(read_store(0).valid, 1, "slot 0 has Bob's message (pre)");
    CHECK_EQ(read_store(1).valid, 1, "slot 1 has local commit (pre)");

    // Peer "rebooted" as Carl: HELLO with new name.
    inject_rx_frame(FRAME_HELLO, 0, 4, {'C','a','r','l'});
    TxEvent tx;     wait_tx(tx, 10);          // REHELLO
    RenderEvent r;  wait_render(r, 10);       // CONN_STATE refresh

    CHECK_EQ(read_store(0).valid, 0, "slot 0 cleared");
    CHECK_EQ(read_store(1).valid, 0, "slot 1 cleared");
    CHECK_EQ(r.peer_name_len,     4,            "peer_name updated");
    CHECK_EQ(r.peer_name[0],      (uint8_t)'C', "peer byte 0");
    CHECK_EQ(r.peer_name[3],      (uint8_t)'l', "peer byte 3");
}

// Peer reboots with the SAME username -> store preserved.
static void test_peer_name_same_preserves_store() {
    printf("== test_peer_name_same_preserves_store\n");
    reset();  // peer = "Bob"
    inject_rx_frame(FRAME_DATA, 100, 3, {'h','e','y'});
    drain_render();
    auto pre = read_store(0);
    CHECK_EQ(pre.valid, 1, "slot 0 has Bob's msg");

    inject_rx_frame(FRAME_HELLO, 0, 3, {'B','o','b'});
    TxEvent tx;     wait_tx(tx, 10);          // REHELLO
    RenderEvent r;  wait_render(r, 10);       // CONN_STATE

    auto post = read_store(0);
    CHECK_EQ(post.valid,  1,                "slot 0 still valid");
    CHECK_EQ(post.msg_id, 100,              "msg_id preserved");
    CHECK_EQ(post.side,   MSG_REMOTE,       "side preserved");
}

// Peer GOODBYE -> we go to DISCONNECTED, emit CONN_STATE render. No tx.
static void test_peer_goodbye_disconnects() {
    printf("== test_peer_goodbye_disconnects\n");
    reset();
    inject_rx_frame(FRAME_GOODBYE, /*seq=*/0, 0, {});
    RenderEvent r;
    CHECK_EQ(wait_render(r, 10), true,             "CONN_STATE fires");
    CHECK_EQ(r.cmd,              RENDER_CONN_STATE,"cmd");
    CHECK_EQ(r.conn_state,       CONN_DISCONNECTED,"DISCONNECTED");
    dut->eval();
    CHECK_EQ(dut->be_tx_valid,   0,                "no tx (peer initiated)");
}

// =====================================================================
// (I) Cursor editing with spaces
// =====================================================================

// Type "abc   xyz" (abc, 3 spaces, xyz), move cursor to position 3 (first
// space), insert 'X'. Expected: "abcX   xyz", len=10, cursor=4.
static void test_insert_at_space_position() {
    printf("== test_insert_at_space_position\n");
    reset();
    // Type "abc"
    for (char c : std::string("abc")) { send_key(KEY_CHAR, (uint8_t)c); drain_render(); }
    // Type 3 spaces
    for (int i = 0; i < 3; i++) { send_key(KEY_CHAR, ' '); drain_render(); }
    // Type "xyz"
    for (char c : std::string("xyz")) { send_key(KEY_CHAR, (uint8_t)c); drain_render(); }

    CHECK_EQ(dut->line_len,   9, "initial len");
    // Move left 6 times: cursor 9 -> 3 (first space)
    for (int i = 0; i < 6; i++) { send_key(KEY_LEFT, 0); drain_render(); }
    CHECK_EQ(dut->cursor_pos, 3, "cursor at first space");

    send_key(KEY_CHAR, 'X'); drain_render();
    CHECK_EQ(dut->line_len,   10, "len after insert");
    CHECK_EQ(dut->cursor_pos, 4,  "cursor after insert");
    // Verify buffer: "abcX   xyz"
    const char* expected = "abcX   xyz";
    for (int i = 0; i < 10; i++) {
        char lbl[40]; snprintf(lbl, sizeof(lbl), "buf[%d] after insert", i);
        CHECK_EQ(read_buf(i), (uint8_t)expected[i], lbl);
    }
}

// Type "abc   xyz", move cursor to position 4 (second space), press BS.
// Expected: "abc  xyz" (delete the first space), len=8, cursor=3.
static void test_delete_at_space_position() {
    printf("== test_delete_at_space_position\n");
    reset();
    for (char c : std::string("abc   xyz")) { send_key(KEY_CHAR, (uint8_t)c); drain_render(); }
    CHECK_EQ(dut->line_len,   9, "initial len");
    // Move cursor to position 4 (second space)
    for (int i = 0; i < 5; i++) { send_key(KEY_LEFT, 0); drain_render(); }
    CHECK_EQ(dut->cursor_pos, 4, "cursor at second space");

    send_key(KEY_BACKSPACE, 0); drain_render();
    CHECK_EQ(dut->line_len,   8, "len after BS");
    CHECK_EQ(dut->cursor_pos, 3, "cursor after BS");
    // Verify: "abc  xyz" (first space deleted, remaining shifted left)
    const char* expected = "abc  xyz";
    for (int i = 0; i < 8; i++) {
        char lbl[40]; snprintf(lbl, sizeof(lbl), "buf[%d] after BS", i);
        CHECK_EQ(read_buf(i), (uint8_t)expected[i], lbl);
    }
}

// Type "ab  cd", move to position 2 (first space), insert 'X' then 'Y'.
// Expected: "abXY  cd", len=8, cursor=4.
static void test_insert_multiple_at_space() {
    printf("== test_insert_multiple_at_space\n");
    reset();
    for (char c : std::string("ab  cd")) { send_key(KEY_CHAR, (uint8_t)c); drain_render(); }
    // Move to position 2
    for (int i = 0; i < 4; i++) { send_key(KEY_LEFT, 0); drain_render(); }
    CHECK_EQ(dut->cursor_pos, 2, "cursor at first space");

    send_key(KEY_CHAR, 'X'); drain_render();
    send_key(KEY_CHAR, 'Y'); drain_render();
    CHECK_EQ(dut->line_len,   8, "len after 2 inserts");
    CHECK_EQ(dut->cursor_pos, 4, "cursor after 2 inserts");
    const char* expected = "abXY  cd";
    for (int i = 0; i < 8; i++) {
        char lbl[40]; snprintf(lbl, sizeof(lbl), "buf[%d]", i);
        CHECK_EQ(read_buf(i), (uint8_t)expected[i], lbl);
    }
}

// Type "ab  cd", move to position 3 (second space), press BS twice.
// Expected: "a  cd" after first BS (cursor=2, delete 'b'), then "a cd" after
// second BS (cursor=1, delete 'a'... no wait, delete at position 2).
// Actually: cursor=3, BS -> delete at pos 2 (char 'b'), result "a  cd", cursor=2.
// Then BS again -> delete at pos 1 (char 'a'), result " cd", cursor=1.
// Hmm that doesn't make sense for what user wants. Let me re-think.
//
// Actually: "ab  cd" buffer = ['a','b',' ',' ','c','d'], len=6, cursor=3.
// BS: delete at cursor-1=2, which is ' ' (first space). Shift left:
//   buf[2] <= buf[3] = ' '
//   buf[3] <= buf[4] = 'c'
//   buf[4] <= buf[5] = 'd'
// Result: ['a','b',' ','c','d',?], len=5, cursor=2.
// That's "ab cd".
// BS again: delete at cursor-1=1, which is 'b'. Shift left:
//   buf[1] <= buf[2] = ' '
//   buf[2] <= buf[3] = 'c'
//   buf[3] <= buf[4] = 'd'
// Result: ['a',' ','c','d',?,?], len=4, cursor=1.
// That's "a cd".
static void test_delete_multiple_at_space() {
    printf("== test_delete_multiple_at_space\n");
    reset();
    for (char c : std::string("ab  cd")) { send_key(KEY_CHAR, (uint8_t)c); drain_render(); }
    // Move to position 3
    for (int i = 0; i < 3; i++) { send_key(KEY_LEFT, 0); drain_render(); }
    CHECK_EQ(dut->cursor_pos, 3, "cursor at pos 3");

    send_key(KEY_BACKSPACE, 0); drain_render();
    CHECK_EQ(dut->line_len,   5, "len after 1st BS");
    CHECK_EQ(dut->cursor_pos, 2, "cursor after 1st BS");
    const char* exp1 = "ab cd";
    for (int i = 0; i < 5; i++) {
        char lbl[40]; snprintf(lbl, sizeof(lbl), "buf[%d] after 1st BS", i);
        CHECK_EQ(read_buf(i), (uint8_t)exp1[i], lbl);
    }

    send_key(KEY_BACKSPACE, 0); drain_render();
    CHECK_EQ(dut->line_len,   4, "len after 2nd BS");
    CHECK_EQ(dut->cursor_pos, 1, "cursor after 2nd BS");
    const char* exp2 = "a cd";
    for (int i = 0; i < 4; i++) {
        char lbl[40]; snprintf(lbl, sizeof(lbl), "buf[%d] after 2nd BS", i);
        CHECK_EQ(read_buf(i), (uint8_t)exp2[i], lbl);
    }
}

// Simulate user's reported scenario: type text with spaces, move cursor to
// space region, insert and delete multiple times.
// Type "hello   world", move to first space, insert 'X', delete twice.
static void test_insert_delete_mixed_with_spaces() {
    printf("== test_insert_delete_mixed_with_spaces\n");
    reset();
    for (char c : std::string("hello   world")) { send_key(KEY_CHAR, (uint8_t)c); drain_render(); }
    CHECK_EQ(dut->line_len,   13, "initial len");
    // Move left 8 times: cursor 13 -> 5 (first space)
    for (int i = 0; i < 8; i++) { send_key(KEY_LEFT, 0); drain_render(); }
    CHECK_EQ(dut->cursor_pos, 5, "cursor at first space");

    // Insert 'X' at position 5
    send_key(KEY_CHAR, 'X'); drain_render();
    CHECK_EQ(dut->line_len,   14, "len after insert");
    CHECK_EQ(dut->cursor_pos, 6,  "cursor after insert");
    // Expected: "helloX   world"
    CHECK_EQ(read_buf(5), 'X', "inserted X");
    CHECK_EQ(read_buf(6), ' ', "shifted space at 6");
    CHECK_EQ(read_buf(7), ' ', "shifted space at 7");
    CHECK_EQ(read_buf(8), ' ', "shifted space at 8");
    CHECK_EQ(read_buf(9), 'w', "shifted w at 9");

    // Now delete (BS) twice: removes the 'X' we just inserted, then 'o'
    send_key(KEY_BACKSPACE, 0); drain_render();
    CHECK_EQ(dut->line_len,   13, "len after 1st BS");
    CHECK_EQ(dut->cursor_pos, 5,  "cursor after 1st BS");
    // Back to "hello   world"
    CHECK_EQ(read_buf(4), 'o', "buf[4] = o");
    CHECK_EQ(read_buf(5), ' ', "buf[5] = space");
    CHECK_EQ(read_buf(6), ' ', "buf[6] = space");

    send_key(KEY_BACKSPACE, 0); drain_render();
    CHECK_EQ(dut->line_len,   12, "len after 2nd BS");
    CHECK_EQ(dut->cursor_pos, 4,  "cursor after 2nd BS");
    // Deleted 'o' at position 4: "hell   world"
    CHECK_EQ(read_buf(3), 'l', "buf[3] = l");
    CHECK_EQ(read_buf(4), ' ', "buf[4] = space (shifted)");
    CHECK_EQ(read_buf(5), ' ', "buf[5] = space (shifted)");
    CHECK_EQ(read_buf(6), ' ', "buf[6] = space (shifted)");
    CHECK_EQ(read_buf(7), 'w', "buf[7] = w");
}

// Type all spaces, then insert/delete in the middle.
static void test_spaces_only_edit() {
    printf("== test_spaces_only_edit\n");
    reset();
    // Type 5 spaces
    for (int i = 0; i < 5; i++) { send_key(KEY_CHAR, ' '); drain_render(); }
    CHECK_EQ(dut->line_len,   5, "5 spaces");
    // Move left 2 times: cursor 5 -> 3
    for (int i = 0; i < 2; i++) { send_key(KEY_LEFT, 0); drain_render(); }
    CHECK_EQ(dut->cursor_pos, 3, "cursor at pos 3");

    // Insert 'X' at position 3
    send_key(KEY_CHAR, 'X'); drain_render();
    CHECK_EQ(dut->line_len,   6, "len after insert");
    CHECK_EQ(dut->cursor_pos, 4, "cursor after insert");
    // Expected: "   X " (3 spaces, X, 2 spaces)
    CHECK_EQ(read_buf(0), ' ', "buf[0] = space");
    CHECK_EQ(read_buf(1), ' ', "buf[1] = space");
    CHECK_EQ(read_buf(2), ' ', "buf[2] = space");
    CHECK_EQ(read_buf(3), 'X', "buf[3] = X");
    CHECK_EQ(read_buf(4), ' ', "buf[4] = space");
    CHECK_EQ(read_buf(5), ' ', "buf[5] = space");

    // Delete (BS): remove the X
    send_key(KEY_BACKSPACE, 0); drain_render();
    CHECK_EQ(dut->line_len,   5, "len after BS");
    CHECK_EQ(dut->cursor_pos, 3, "cursor after BS");
    CHECK_EQ(read_buf(3), ' ', "buf[3] = space (X removed)");
}

// Stress test: longer text with multiple space groups, cursor movement and
// editing at various positions.
static void test_long_text_with_spaces() {
    printf("== test_long_text_with_spaces\n");
    reset();
    // "abc   def   ghi"
    for (char c : std::string("abc   def   ghi")) { send_key(KEY_CHAR, (uint8_t)c); drain_render(); }
    CHECK_EQ(dut->line_len,   15, "initial len");

    // Move to position 6 (between the two space groups, at 'd')
    for (int i = 0; i < 9; i++) { send_key(KEY_LEFT, 0); drain_render(); }
    CHECK_EQ(dut->cursor_pos, 6, "cursor at 'd'");

    // Insert 'X' before 'd'
    send_key(KEY_CHAR, 'X'); drain_render();
    CHECK_EQ(dut->line_len,   16, "len after insert");
    CHECK_EQ(dut->cursor_pos, 7, "cursor after insert");
    CHECK_EQ(read_buf(6), 'X', "buf[6] = X");
    CHECK_EQ(read_buf(7), 'd', "buf[7] = d");

    // Move right to position 12 (at third space of second group)
    for (int i = 0; i < 5; i++) { send_key(KEY_RIGHT, 0); drain_render(); }
    CHECK_EQ(dut->cursor_pos, 12, "cursor at pos 12");

    // Delete (BS): remove the space at position 11
    send_key(KEY_BACKSPACE, 0); drain_render();
    CHECK_EQ(dut->line_len,   15, "len after BS");
    CHECK_EQ(dut->cursor_pos, 11, "cursor after BS");
    CHECK_EQ(read_buf(10), ' ', "buf[10] = space");
    CHECK_EQ(read_buf(11), ' ', "buf[11] = space (shifted)");
    CHECK_EQ(read_buf(12), 'g', "buf[12] = g (shifted)");
    CHECK_EQ(read_buf(13), 'h', "buf[13] = h");
    CHECK_EQ(read_buf(14), 'i', "buf[14] = i");
}

// =====================================================================
// (J) Multi-line input (newline via KEY_CHAR ascii=0x0A)
// =====================================================================

// Type "hello\nworld", verify the buffer holds the full 11-byte content
// including the embedded newline, then commit and verify the store slot.
static void test_multiline_input_commit() {
    printf("== test_multiline_input_commit\n");
    reset();
    // Type "hello"
    for (char c : std::string("hello")) { send_key(KEY_CHAR, (uint8_t)c); drain_render(); }
    // Shift+Enter: newline character
    send_key(KEY_CHAR, 0x0A); drain_render();
    // Type "world"
    for (char c : std::string("world")) { send_key(KEY_CHAR, (uint8_t)c); drain_render(); }

    // "hello\nworld" = 11 bytes
    CHECK_EQ(dut->line_len,   11, "line_len = 11");
    CHECK_EQ(dut->cursor_pos, 11, "cursor_pos = 11");

    // Verify buffer content: h,e,l,l,o,0x0A,w,o,r,l,d
    uint8_t expected[] = {'h','e','l','l','o',0x0A,'w','o','r','l','d'};
    for (int i = 0; i < 11; i++) {
        char lbl[40]; snprintf(lbl, sizeof(lbl), "buf[%d] multiline", i);
        CHECK_EQ(read_buf(i), expected[i], lbl);
    }

    // Commit
    send_key(KEY_ENTER, 0);
    drain_commit_pipeline();
    CHECK_EQ(dut->line_len,   0, "line cleared after commit");
    CHECK_EQ(dut->cursor_pos, 0, "cursor cleared after commit");

    // Verify store slot 0 contains "hello\nworld" with len=11
    auto s = read_store(0);
    CHECK_EQ(s.valid,  1,           "slot 0 valid");
    CHECK_EQ(s.msg_id, 0,           "msg_id 0");
    CHECK_EQ(s.side,   MSG_LOCAL,   "side LOCAL");
    CHECK_EQ(s.len,    11,          "len 11");
    for (int i = 0; i < 11; i++) {
        char lbl[40]; snprintf(lbl, sizeof(lbl), "store_payload[%d]", i);
        CHECK_EQ(store_payload_byte(i), expected[i], lbl);
    }
}

// Type "ab\ncd", move cursor left to position 2 (at '\n'), press backspace
// to delete 'b'. Buffer becomes "a\ncd", len=4, cursor=1.
static void test_multiline_backspace() {
    printf("== test_multiline_backspace\n");
    reset();
    // Type "ab\ncd"
    for (char c : std::string("ab")) { send_key(KEY_CHAR, (uint8_t)c); drain_render(); }
    send_key(KEY_CHAR, 0x0A); drain_render();
    for (char c : std::string("cd")) { send_key(KEY_CHAR, (uint8_t)c); drain_render(); }

    CHECK_EQ(dut->line_len,   5, "line_len before moves");
    CHECK_EQ(dut->cursor_pos, 5, "cursor at end");

    // Move cursor left 2 times to position 3 (at 'c')
    send_key(KEY_LEFT, 0); drain_render();  // cursor 5 -> 4 (at 'd')
    send_key(KEY_LEFT, 0); drain_render();  // cursor 4 -> 3 (at 'c')
    // Move left 1 more to position 2 (at '\n')
    send_key(KEY_LEFT, 0); drain_render();  // cursor 3 -> 2 (at '\n')

    CHECK_EQ(dut->cursor_pos, 2, "cursor at newline position");

    // Backspace: deletes char at cursor-1 = position 1, which is 'b'
    // Buffer shifts left: "a\ncd", len=4, cursor=1
    send_key(KEY_BACKSPACE, 0); drain_render();
    CHECK_EQ(dut->line_len,   4, "len after BS");
    CHECK_EQ(dut->cursor_pos, 1, "cursor after BS");

    CHECK_EQ(read_buf(0), (uint8_t)'a',    "buf[0] = 'a'");
    CHECK_EQ(read_buf(1), (uint8_t)0x0A,   "buf[1] = newline");
    CHECK_EQ(read_buf(2), (uint8_t)'c',    "buf[2] = 'c'");
    CHECK_EQ(read_buf(3), (uint8_t)'d',    "buf[3] = 'd'");
}

// =====================================================================
int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    dut = new Vbe_top;
    tfp = new VerilatedVcdC;
    dut->trace(tfp, /*levels=*/99);
    tfp->open("sim/waves/be_top.vcd");

    // (Init)
    test_boot_redraw_all();
    // (A) Input
    test_reset_clears_state();
    test_single_char_append();
    test_multi_char_builds_string();
    test_backspace_removes_last();
    test_backspace_at_zero_no_op();
    test_backspace_then_char();
    test_enter_empty_no_commit();
    test_enter_nonempty_commits();
    test_esc_triggers_goodbye();
    test_buffer_full_drops_extra();
    // (E) Render gating + cursor
    test_char_emits_insert_render();
    test_bs_emits_delete_render();
    test_left_at_zero_no_render();
    test_right_at_end_no_render();
    test_left_right_emit_move_cursor();
    test_scroll_keys_emit_render();
    test_insert_in_middle();
    test_delete_in_middle();
    test_full_buffer_insert_dropped();
    // (B) Store + commit pipeline
    test_no_commit_no_store_write();
    test_empty_enter_does_not_write();
    test_commit_writes_record();
    test_two_commits_distinct_slots();
    test_payload_packed_correctly();
    test_emoji_tokens_encoded_on_commit();
    test_big_emoji_tokens_encoded_on_commit();
    test_big_emoji_unknown_token_passthrough();
    test_commit_full_pipeline_order();
    test_commit_blocked_by_render_backpressure();
    test_commit_blocked_by_tx_backpressure();
    test_commit_back_to_idle();
    // (C) RX
    test_rx_writes_remote_record();
    test_rx_emits_render_remote();
    test_rx_does_not_consume_local_msg_id();
    test_cm_rx_len_clamped();
    test_cm_rx_len_passthrough_when_small();
    // (D) STATUS
    test_status_updates_store();
    test_status_emits_render();
    test_status_unknown_msg_id();
    // (G) Arbitration
    test_arbitration_priority();
    // (H) Sanity
    test_enter_pulse_one_cycle();
    test_three_commits();
    test_rx_local_interleaved();
    // (F) Connection management
    test_handshake_via_peer_username();
    test_handshake_via_peer_hello();
    test_handshake_via_peer_rehello();
    test_handshake_drops_data_frame();
    test_handshake_drops_keys();
    test_disconnected_space_reconnects();
    test_disconnected_peer_hello_reconnects();
    test_disconnected_drops_other_keys();
    test_disconnected_drops_data();
    test_peer_hello_in_chat_emits_rehello();
    test_peer_rehello_in_chat_emits_username();
    test_peer_username_in_chat_refreshes();
    test_peer_name_change_clears_store();
    test_peer_name_same_preserves_store();
    test_peer_goodbye_disconnects();
    // (I) Cursor editing with spaces
    test_insert_at_space_position();
    test_delete_at_space_position();
    test_insert_multiple_at_space();
    test_delete_multiple_at_space();
    test_insert_delete_mixed_with_spaces();
    test_spaces_only_edit();
    test_long_text_with_spaces();
    // (J) Multi-line input
    test_multiline_input_commit();
    test_multiline_backspace();

    tfp->close();
    delete tfp;
    delete dut;

    if (g_failures == 0) { printf("\nPASS  (all checks)\n"); return 0; }
    printf("\nFAIL  %d check(s) failed\n", g_failures);
    return 1;
}
