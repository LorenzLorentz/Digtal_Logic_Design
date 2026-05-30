// =====================================================================
// sim_main.cpp  --  io_top + be_top end-to-end integration tests
// ---------------------------------------------------------------------
// Two integration concerns make this TB a bit different from the
// per-module ones:
//
//   * `ps2_send_byte` ticks the clock for ~300 cycles per byte. During
//     that window the backend's render and tx handshakes complete with
//     be_render_ready / be_tx_ready = 1 (the natural default), so
//     events come and go BEFORE any wait_render() could observe them.
//     Solution: capture transactions PASSIVELY -- the tick() helper
//     itself records every (valid && ready) firing into a global log.
//     Tests then just drive PS/2 and check the log in order.
//
//   * Backpressure tests (be_render_ready=0) keep the FSM stalled,
//     produce no log entries during the stall, and then drain after
//     re-enabling ready. The same log mechanism handles this naturally.
//
// Test surface:
//   1.  test_boot_redraw_all              first render after reset
//                                         is RENDER_REDRAW_ALL
//   2.  test_type_lowercase_hi_then_enter end-to-end "hi" + ENTER:
//                                         line, render stream, be_tx,
//                                         and stored record all match
//   3.  test_uppercase_via_shift_to_store Shift+'h' -> 'H' in store
//   4.  test_punctuation_via_shift        '!' arrives via PS/2
//   5.  test_cursor_left_insert_middle    LEFT then insert mid-line
//   6.  test_backspace_via_ps2            BS removes last typed
//   7.  test_arrow_keys_emit_move_cursor  LEFT/RIGHT -> MOVE_CURSOR
//   8.  test_render_backpressure          be_render_ready=0 stalls,
//                                         then drains intact
// =====================================================================

#include "Vio_be_integration.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <cstdint>
#include <cstdio>
#include <vector>

static vluint64_t           g_time_ns  = 0;
static int                  g_failures = 0;
static Vio_be_integration*  dut        = nullptr;
static VerilatedVcdC*       tfp        = nullptr;

static constexpr int MAX_MSG_LEN     = 64;
static constexpr int PAYLOAD_W       = MAX_MSG_LEN * 8 / 32;
static constexpr int BIT_HALF_CYCLES = 10;

// key_type_e
enum : uint8_t { KEY_CHAR = 0, KEY_ENTER = 1, KEY_BACKSPACE = 2,
                 KEY_LEFT = 3, KEY_RIGHT = 4, KEY_ESC = 5 };
// msg_side_e / msg_status_e
enum : uint8_t { MSG_LOCAL = 0, MSG_REMOTE = 1, MSG_SYSTEM = 2 };
enum : uint8_t { MSG_PENDING = 0, MSG_SUCCESS = 1, MSG_FAIL = 2 };
// render_cmd_e
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

// Peer name we inject in reset() to complete the boot handshake.
static const char* const  PEER_NAME = "Bob";
static constexpr int      PEER_NAME_LEN = 3;

// PS/2 letter scancodes (a..z), used by ps2_type_letter().
static const uint8_t LETTER_SCANCODES[26] = {
    0x1C, 0x32, 0x21, 0x23, 0x24, 0x2B, 0x34, 0x33,  // a-h
    0x43, 0x3B, 0x42, 0x4B, 0x3A, 0x31, 0x44, 0x4D,  // i-p
    0x15, 0x2D, 0x1B, 0x2C, 0x3C, 0x2A, 0x1D, 0x22,  // q-x
    0x35, 0x1A,                                      // y-z
};

// ---- Captured transaction logs --------------------------------------
struct RenderEvent {
    uint8_t  cmd, msg_id, side, status, len, cursor_pos, ascii, conn_state;
    uint8_t  peer_name_len;
    uint32_t payload[PAYLOAD_W];
    uint8_t  peer_name[16];
};
struct TxEvent {
    uint8_t  frame_type, msg_id, len;
    uint32_t payload[PAYLOAD_W];
};
static std::vector<RenderEvent> g_render_log;
static std::vector<TxEvent>     g_tx_log;
static size_t                   g_render_cur = 0;
static size_t                   g_tx_cur     = 0;

static void reset_logs() {
    g_render_log.clear();
    g_tx_log.clear();
    g_render_cur = 0;
    g_tx_cur     = 0;
}

// ---- Clock helpers (with passive capture) --------------------------
//
// The capture happens at clk=0 phase (i.e. after the previous rising
// edge has already updated state, and before the upcoming rising edge
// would consume the current valid). This way each "transaction"
// (valid && ready high during a rising edge) is logged exactly once,
// in the cycle where it commits.
static void capture_at_clk_low() {
    if (dut->be_render_valid && dut->be_render_ready) {
        RenderEvent e;
        e.cmd           = dut->be_render_cmd;
        e.msg_id        = dut->be_render_msg_id;
        e.side          = dut->be_render_side;
        e.status        = dut->be_render_status;
        e.len           = dut->be_render_len;
        e.cursor_pos    = dut->be_render_cursor_pos;
        e.ascii         = dut->be_render_ascii;
        e.conn_state    = dut->be_render_conn_state;
        e.peer_name_len = dut->be_render_peer_name_len;
        for (int w = 0; w < PAYLOAD_W; w++)
            e.payload[w] = dut->be_render_payload[w];
        for (int b = 0; b < 16; b++) {
            int w  = b >> 2;
            int sh = (b & 3) * 8;
            e.peer_name[b] =
                (((uint32_t)dut->be_render_peer_name[w]) >> sh) & 0xFF;
        }
        g_render_log.push_back(e);
    }
    if (dut->be_tx_valid && dut->be_tx_ready) {
        TxEvent t;
        t.frame_type = dut->be_tx_frame_type;
        t.msg_id     = dut->be_tx_msg_id;
        t.len        = dut->be_tx_len;
        for (int w = 0; w < PAYLOAD_W; w++)
            t.payload[w] = dut->be_tx_payload[w];
        g_tx_log.push_back(t);
    }
}

static void tick() {
    dut->clk = 0;
    dut->eval();
    if (tfp) tfp->dump(g_time_ns);
    g_time_ns += 5;
    capture_at_clk_low();         // log transactions about to commit
    dut->clk = 1;
    dut->eval();
    if (tfp) tfp->dump(g_time_ns);
    g_time_ns += 5;
}

// ---- Wide-signal byte access ---------------------------------------
static uint8_t payload_get_byte(const uint32_t* sig, int i) {
    int w  = i >> 2;
    int sh = (i & 3) * 8;
    return (sig[w] >> sh) & 0xFF;
}

static void payload_set_byte(uint32_t* sig, int i, uint8_t b) {
    int w  = i >> 2;
    int sh = (i & 3) * 8;
    sig[w] = (sig[w] & ~(0xFFu << sh)) | (((uint32_t)b) << sh);
}

static void payload_clear(uint32_t* sig) {
    for (int w = 0; w < PAYLOAD_W; w++) sig[w] = 0;
}

static void payload_load(uint32_t* sig, const std::vector<uint8_t>& bytes) {
    payload_clear(sig);
    for (size_t i = 0; i < bytes.size() && i < (size_t)MAX_MSG_LEN; i++)
        payload_set_byte(sig, (int)i, bytes[i]);
}

// ---- Reset ----------------------------------------------------------
static void clear_inputs() {
    dut->ps2_clk          = 1;          // PS/2 idle high
    dut->ps2_data         = 1;
    dut->be_tx_ready      = 1;
    dut->be_render_ready  = 1;
    dut->cm_rx_valid      = 0;
    dut->cm_rx_frame_type = 0;
    dut->cm_rx_seq        = 0;
    dut->cm_rx_len        = 0;
    payload_clear(&dut->cm_rx_payload[0]);
    dut->cm_status_valid  = 0;
    dut->line_rd_idx      = 0;
    dut->store_rd_idx      = 0;
    dut->store_rd_byte_idx = 0;
}

// reset_no_drain leaves the FSM parked in S_BOOT_REDRAW. Crucially, no
// post-rst_n tick: with be_render_ready=1 (default), one trailing tick
// would already commit the boot REDRAW_ALL into the log before any
// "first observation" test could see it.
static void reset_no_drain(int cycles = 4) {
    dut->rst_n = 0;
    clear_inputs();
    dut->clk = 0;
    for (int i = 0; i < cycles; i++) tick();
    dut->rst_n = 1;
}

// Drive a cm_rx frame and wait for cm_rx_ready handshake.
static void inject_rx_frame(uint8_t frame_type, uint8_t seq, uint8_t len,
                            const std::vector<uint8_t>& bytes,
                            int timeout = 500) {
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

// Run the clock long enough for the backend pipeline to drain anything
// that PS/2 just kicked off. Forward-declared above settle's first user.
static void settle(int cycles);

// Standard reset: bring backend through boot+handshake so it's parked
// in S_IDLE under CONN_CONNECTED with peer_name=PEER_NAME. The handshake
// chatter is wiped from the log at the end so test bodies start clean.
static void reset(int cycles = 4) {
    reset_no_drain(cycles);
    // Tick enough for REDRAW_ALL to fire and FSM to land in S_TX_HELLO.
    tick();
    // Tick enough for HELLO tx to fire and FSM to land in S_HANDSHAKE_IDLE.
    settle(20);
    // Inject peer USERNAME -> FSM goes to S_RENDER_CONN_CONNECTED -> S_IDLE.
    std::vector<uint8_t> name_bytes(PEER_NAME, PEER_NAME + PEER_NAME_LEN);
    inject_rx_frame(FRAME_USERNAME, /*seq=*/0, PEER_NAME_LEN, name_bytes);
    settle(20);
    // Wipe the boot/handshake log so tests start fresh.
    g_render_log.clear();
    g_tx_log.clear();
    g_render_cur = 0;
    g_tx_cur     = 0;
}

// ---- PS/2 driver ----------------------------------------------------
static void ps2_send_bit(uint8_t b) {
    dut->ps2_data = b;
    for (int i = 0; i < 4; i++) tick();
    dut->ps2_clk = 0;
    for (int i = 0; i < BIT_HALF_CYCLES; i++) tick();
    dut->ps2_clk = 1;
    for (int i = 0; i < BIT_HALF_CYCLES; i++) tick();
}
static uint8_t odd_parity(uint8_t b) {
    uint8_t p = 1;
    for (int i = 0; i < 8; i++) p ^= (b >> i) & 1;
    return p;
}
static void ps2_send_byte(uint8_t b) {
    ps2_send_bit(0);
    for (int i = 0; i < 8; i++) ps2_send_bit((b >> i) & 1);
    ps2_send_bit(odd_parity(b));
    ps2_send_bit(1);
    for (int i = 0; i < 30; i++) tick();
}

// One letter in or out of upper case.
static void ps2_type_letter(char c) {
    bool upper = (c >= 'A' && c <= 'Z');
    char low   = upper ? (char)(c - 'A' + 'a') : c;
    uint8_t scancode = LETTER_SCANCODES[low - 'a'];
    if (upper) ps2_send_byte(0x12);
    ps2_send_byte(scancode);
    if (upper) { ps2_send_byte(0xF0); ps2_send_byte(0x12); }
}
static void ps2_press_bang() {
    ps2_send_byte(0x12);
    ps2_send_byte(0x16);
    ps2_send_byte(0xF0);
    ps2_send_byte(0x12);
}
static void ps2_press_enter()     { ps2_send_byte(0x5A); }
static void ps2_press_backspace() { ps2_send_byte(0x66); }
static void ps2_press_left()      { ps2_send_byte(0xE0); ps2_send_byte(0x6B); }
static void ps2_press_right()     { ps2_send_byte(0xE0); ps2_send_byte(0x74); }

// Run the clock long enough for the backend pipeline to drain anything
// that PS/2 just kicked off. The longest pipeline (commit) is render +
// be_tx + render = ~3 transactions; each takes 1 cycle when ready=1,
// so 100 cycles is generous.
static void settle(int cycles = 100) {
    for (int i = 0; i < cycles; i++) tick();
}

// ---- Log access -----------------------------------------------------
//
// Tests pull events in order via next_render() / next_tx(). If the log
// already has more entries than the cursor, the next one is returned
// immediately; otherwise we tick a bit more and try again.
static bool next_render(RenderEvent* out, int wait_cycles = 500) {
    int spent = 0;
    while (g_render_cur >= g_render_log.size()) {
        if (spent >= wait_cycles) return false;
        tick();
        spent++;
    }
    *out = g_render_log[g_render_cur++];
    return true;
}
static bool next_tx(TxEvent* out, int wait_cycles = 500) {
    int spent = 0;
    while (g_tx_cur >= g_tx_log.size()) {
        if (spent >= wait_cycles) return false;
        tick();
        spent++;
    }
    *out = g_tx_log[g_tx_cur++];
    return true;
}

// ---- Read helpers ---------------------------------------------------
static uint8_t read_buf(int i) {
    dut->line_rd_idx = i;
    dut->eval();
    return dut->line_rd_data;
}
struct StoreRead { uint8_t valid, msg_id, side, status, len; };
static StoreRead read_store(int idx) {
    dut->store_rd_idx = idx;
    dut->eval();
    return {(uint8_t)dut->store_rd_valid, (uint8_t)dut->store_rd_msg_id,
            (uint8_t)dut->store_rd_side,  (uint8_t)dut->store_rd_status,
            (uint8_t)dut->store_rd_len};
}
static uint8_t store_payload_byte(int i) {
    // BRAM-backed payload (1-cycle read latency).
    dut->store_rd_byte_idx = i;
    tick();
    return (uint8_t)dut->store_rd_byte;
}

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
// Tests
// =====================================================================

// 1) After reset, the backend emits RENDER_REDRAW_ALL (conn_state=BOOT)
//    and then asserts FRAME_HELLO on be_tx with our username payload.
static void test_boot_redraw_then_hello() {
    printf("== test_boot_redraw_then_hello\n");
    reset_no_drain();
    reset_logs();
    settle(50);
    // Find REDRAW_ALL render and HELLO tx in the captured log.
    bool saw_redraw = false, saw_hello = false;
    for (auto& e : g_render_log) {
        if (e.cmd == RENDER_REDRAW_ALL) {
            saw_redraw = true;
            CHECK_EQ(e.conn_state, CONN_BOOT, "REDRAW_ALL conn_state=BOOT");
        }
    }
    for (auto& t : g_tx_log) {
        if (t.frame_type == FRAME_HELLO) {
            saw_hello = true;
            CHECK_EQ(t.len, (uint8_t)4, "HELLO len = MY_NAME_LEN (Alic)");
            CHECK_EQ(payload_get_byte(t.payload, 0), (uint8_t)'A', "HELLO byte 0");
            CHECK_EQ(payload_get_byte(t.payload, 3), (uint8_t)'c', "HELLO byte 3");
        }
    }
    CHECK_EQ(saw_redraw, true, "REDRAW_ALL fired");
    CHECK_EQ(saw_hello,  true, "HELLO fired");
}

// 2) After peer USERNAME, backend emits RENDER_CONN_STATE=CONNECTED with
//    peer_name. Then we're in S_IDLE; this is what reset() does.
static void test_handshake_completes_via_username() {
    printf("== test_handshake_completes_via_username\n");
    // Manually walk the handshake (don't use the wrapping reset()).
    reset_no_drain();
    reset_logs();
    settle(50);  // REDRAW + HELLO fire
    std::vector<uint8_t> name(PEER_NAME, PEER_NAME + PEER_NAME_LEN);
    inject_rx_frame(FRAME_USERNAME, 0, PEER_NAME_LEN, name);
    settle(20);
    // Find the CONN_STATE render in the post-handshake log.
    bool saw_conn = false;
    for (auto& e : g_render_log) {
        if (e.cmd == RENDER_CONN_STATE && e.conn_state == CONN_CONNECTED) {
            saw_conn = true;
            CHECK_EQ(e.peer_name_len, PEER_NAME_LEN, "peer_name_len");
            CHECK_EQ(e.peer_name[0],  (uint8_t)'B',  "peer byte 0");
            CHECK_EQ(e.peer_name[2],  (uint8_t)'b',  "peer byte 2");
        }
    }
    CHECK_EQ(saw_conn, true, "CONN_STATE = CONNECTED fired");
    CHECK_EQ(dut->conn_state_obs, CONN_CONNECTED, "conn_state CONNECTED");
}

// 2) Type "hi" + ENTER end-to-end.
static void test_type_lowercase_hi_then_enter() {
    printf("== test_type_lowercase_hi_then_enter\n");
    reset();
    reset_logs();

    ps2_type_letter('h');
    ps2_type_letter('i');

    // Sanity: line buffer matches.
    CHECK_EQ(dut->line_len, 2, "line_len=2");
    CHECK_EQ(read_buf(0),   (uint8_t)'h', "buf[0]");
    CHECK_EQ(read_buf(1),   (uint8_t)'i', "buf[1]");

    ps2_press_enter();
    settle();

    RenderEvent r1, r2, r3, r4;
    CHECK_EQ(next_render(&r1), true, "render 1");
    CHECK_EQ(r1.cmd,        RENDER_INSERT_AT_CURSOR, "[1] cmd INSERT");
    CHECK_EQ(r1.cursor_pos, 1,                       "[1] cursor=1");
    CHECK_EQ(r1.ascii,      (uint8_t)'h',            "[1] ascii 'h'");

    CHECK_EQ(next_render(&r2), true, "render 2");
    CHECK_EQ(r2.cmd,        RENDER_INSERT_AT_CURSOR, "[2] cmd INSERT");
    CHECK_EQ(r2.cursor_pos, 2,                       "[2] cursor=2");
    CHECK_EQ(r2.ascii,      (uint8_t)'i',            "[2] ascii 'i'");

    CHECK_EQ(next_render(&r3), true, "render 3");
    CHECK_EQ(r3.cmd,    RENDER_APPEND_LOCAL_PENDING, "[3] APPEND_LOCAL_PENDING");
    CHECK_EQ(r3.msg_id, 0,                           "[3] msg_id 0");
    CHECK_EQ(r3.side,   MSG_LOCAL,                   "[3] side LOCAL");
    CHECK_EQ(r3.status, MSG_PENDING,                 "[3] status PENDING");
    CHECK_EQ(r3.len,    2,                           "[3] len");
    CHECK_EQ(payload_get_byte(r3.payload, 0), (uint8_t)'h', "[3] byte 0");
    CHECK_EQ(payload_get_byte(r3.payload, 1), (uint8_t)'i', "[3] byte 1");

    CHECK_EQ(next_render(&r4), true, "render 4");
    CHECK_EQ(r4.cmd,        RENDER_UPDATE_INPUT_LINE, "[4] UPDATE_INPUT_LINE");
    CHECK_EQ(r4.len,        0, "[4] len 0");
    CHECK_EQ(r4.cursor_pos, 0, "[4] cursor 0");

    TxEvent tx;
    CHECK_EQ(next_tx(&tx), true, "be_tx fires");
    CHECK_EQ(tx.msg_id, 0, "tx msg_id");
    CHECK_EQ(tx.len,    2, "tx len");
    CHECK_EQ(payload_get_byte(tx.payload, 0), (uint8_t)'h', "tx[0]");
    CHECK_EQ(payload_get_byte(tx.payload, 1), (uint8_t)'i', "tx[1]");

    auto rec = read_store(0);
    CHECK_EQ(rec.valid,  1,           "store slot 0 valid");
    CHECK_EQ(rec.msg_id, 0,           "store msg_id");
    CHECK_EQ(rec.side,   MSG_LOCAL,   "store side");
    CHECK_EQ(rec.status, MSG_PENDING, "store status");
    CHECK_EQ(rec.len,    2,           "store len");
    CHECK_EQ(store_payload_byte(0), (uint8_t)'h', "store byte 0");
    CHECK_EQ(store_payload_byte(1), (uint8_t)'i', "store byte 1");

    CHECK_EQ(dut->line_len,   0, "line cleared");
    CHECK_EQ(dut->cursor_pos, 0, "cursor cleared");
}

// 3) Shift+letter via PS/2 lands the uppercase byte in the store.
static void test_uppercase_via_shift_to_store() {
    printf("== test_uppercase_via_shift_to_store\n");
    reset();
    reset_logs();

    ps2_type_letter('H');   // Shift make + 0x33 + Shift release
    ps2_press_enter();
    settle();

    auto rec = read_store(0);
    CHECK_EQ(rec.len, 1, "store len=1");
    CHECK_EQ(store_payload_byte(0), (uint8_t)'H', "stored 'H' uppercase");
}

// 4) Shift+1 -> '!'.
static void test_punctuation_via_shift() {
    printf("== test_punctuation_via_shift\n");
    reset();
    reset_logs();
    ps2_press_bang();
    settle();
    RenderEvent r;
    CHECK_EQ(next_render(&r), true, "render fires");
    CHECK_EQ(r.cmd,   RENDER_INSERT_AT_CURSOR, "INSERT");
    CHECK_EQ(r.ascii, (uint8_t)'!',           "ascii '!'");
}

// 5) Type "ab", LEFT, then 'X' -> "aXb".
static void test_cursor_left_insert_middle() {
    printf("== test_cursor_left_insert_middle\n");
    reset();
    reset_logs();
    ps2_type_letter('a');
    ps2_type_letter('b');
    ps2_press_left();
    ps2_type_letter('X');
    settle();

    // Skip the two leading INSERTs and the MOVE_CURSOR; the next event
    // is the mid-line INSERT we care about.
    RenderEvent r;
    for (int i = 0; i < 3; i++) CHECK_EQ(next_render(&r), true, "drain prelude");

    CHECK_EQ(next_render(&r), true,                 "mid-line insert render");
    CHECK_EQ(r.cmd,        RENDER_INSERT_AT_CURSOR, "INSERT");
    CHECK_EQ(r.cursor_pos, 2,                       "post-edit cursor=2");
    CHECK_EQ(r.ascii,      (uint8_t)'X',            "ascii X");

    CHECK_EQ(dut->line_len,   3,            "line_len=3");
    CHECK_EQ(dut->cursor_pos, 2,            "cursor=2");
    CHECK_EQ(read_buf(0),     (uint8_t)'a', "buf[0]");
    CHECK_EQ(read_buf(1),     (uint8_t)'X', "buf[1] inserted");
    CHECK_EQ(read_buf(2),     (uint8_t)'b', "buf[2] shifted right");
}

// 6) Type "abc", BS -> buffer "ab", cursor=2.
static void test_backspace_via_ps2() {
    printf("== test_backspace_via_ps2\n");
    reset();
    reset_logs();
    ps2_type_letter('a');
    ps2_type_letter('b');
    ps2_type_letter('c');
    ps2_press_backspace();
    settle();

    RenderEvent r;
    for (int i = 0; i < 3; i++) CHECK_EQ(next_render(&r), true, "drain INSERTs");

    CHECK_EQ(next_render(&r), true,                 "delete render");
    CHECK_EQ(r.cmd,        RENDER_DELETE_AT_CURSOR, "DELETE");
    CHECK_EQ(r.cursor_pos, 2,                       "post-edit cursor 3->2");

    CHECK_EQ(dut->line_len,   2,            "line_len=2");
    CHECK_EQ(dut->cursor_pos, 2,            "cursor=2");
    CHECK_EQ(read_buf(0),     (uint8_t)'a', "buf[0]");
    CHECK_EQ(read_buf(1),     (uint8_t)'b', "buf[1]");
}

// 7) Arrow keys produce MOVE_CURSOR with new cursor.
static void test_arrow_keys_emit_move_cursor() {
    printf("== test_arrow_keys_emit_move_cursor\n");
    reset();
    reset_logs();
    ps2_type_letter('a');
    ps2_type_letter('b');                  // cursor=2
    ps2_press_left();
    ps2_press_right();
    settle();

    RenderEvent r;
    for (int i = 0; i < 2; i++) CHECK_EQ(next_render(&r), true, "drain INSERTs");

    CHECK_EQ(next_render(&r), true,             "LEFT render");
    CHECK_EQ(r.cmd,        RENDER_MOVE_CURSOR,  "MOVE_CURSOR");
    CHECK_EQ(r.cursor_pos, 1,                   "cursor=1");

    CHECK_EQ(next_render(&r), true,             "RIGHT render");
    CHECK_EQ(r.cmd,        RENDER_MOVE_CURSOR,  "MOVE_CURSOR");
    CHECK_EQ(r.cursor_pos, 2,                   "cursor=2");
}

// 8) ESC via PS/2 (0x76 scancode) -> backend emits FRAME_GOODBYE on tx
//    and RENDER_CONN_STATE = DISCONNECTED.
static void test_ps2_esc_disconnects() {
    printf("== test_ps2_esc_disconnects\n");
    reset();
    reset_logs();
    ps2_send_byte(0x76);   // ESC
    settle(50);

    bool saw_goodbye = false, saw_disc = false;
    for (auto& t : g_tx_log) {
        if (t.frame_type == FRAME_GOODBYE) {
            saw_goodbye = true;
            CHECK_EQ(t.len, (uint8_t)0, "GOODBYE has no payload");
        }
    }
    for (auto& e : g_render_log) {
        if (e.cmd == RENDER_CONN_STATE && e.conn_state == CONN_DISCONNECTED)
            saw_disc = true;
    }
    CHECK_EQ(saw_goodbye, true, "GOODBYE tx fired");
    CHECK_EQ(saw_disc,    true, "CONN_STATE = DISCONNECTED fired");
    CHECK_EQ(dut->conn_state_obs, CONN_DISCONNECTED, "conn DISCONNECTED");
}

// 9) From DISCONNECTED, pressing SPACE via PS/2 (scancode 0x29)
//    re-handshakes -- backend emits FRAME_HELLO again.
static void test_ps2_space_reconnects() {
    printf("== test_ps2_space_reconnects\n");
    reset();
    ps2_send_byte(0x76);  // ESC
    settle(50);
    reset_logs();         // clear post-disconnect log
    ps2_send_byte(0x29);  // SPACE
    settle(50);

    bool saw_hello = false;
    for (auto& t : g_tx_log) {
        if (t.frame_type == FRAME_HELLO) saw_hello = true;
    }
    CHECK_EQ(saw_hello, true, "second HELLO fired after SPACE");
    CHECK_EQ(dut->conn_state_obs, CONN_HANDSHAKE, "now HANDSHAKE");
}

// 10) Holding be_render_ready=0 stalls the pipeline; nothing logged
//    while ready is low, then on release the captured render appears.
static void test_render_backpressure() {
    printf("== test_render_backpressure\n");
    reset();
    reset_logs();
    dut->be_render_ready = 0;
    ps2_type_letter('a');
    settle(50);
    CHECK_EQ(g_render_log.size(), (size_t)0, "no captures while blocked");

    dut->be_render_ready = 1;
    settle(50);

    RenderEvent r;
    CHECK_EQ(next_render(&r), true,                 "render captured after release");
    CHECK_EQ(r.cmd,        RENDER_INSERT_AT_CURSOR, "INSERT");
    CHECK_EQ(r.ascii,      (uint8_t)'a',            "ascii 'a'");
    CHECK_EQ(r.cursor_pos, 1,                       "cursor=1");
}

// =====================================================================
int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    dut = new Vio_be_integration;
    tfp = new VerilatedVcdC;
    dut->trace(tfp, /*levels=*/99);
    tfp->open("sim/waves/io_be_integration.vcd");

    test_boot_redraw_then_hello();
    test_handshake_completes_via_username();
    test_type_lowercase_hi_then_enter();
    test_uppercase_via_shift_to_store();
    test_punctuation_via_shift();
    test_cursor_left_insert_middle();
    test_backspace_via_ps2();
    test_arrow_keys_emit_move_cursor();
    test_ps2_esc_disconnects();
    test_ps2_space_reconnects();
    test_render_backpressure();

    tfp->close();
    delete tfp;
    delete dut;

    if (g_failures == 0) { printf("\nPASS  (all checks)\n"); return 0; }
    printf("\nFAIL  %d check(s) failed\n", g_failures);
    return 1;
}
