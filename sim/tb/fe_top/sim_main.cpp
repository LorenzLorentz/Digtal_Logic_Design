// =====================================================================
// sim_main.cpp  --  Tests for rtl/frontend/fe_top.sv
// ---------------------------------------------------------------------
// Drives the be_render_* command stream into fe_top and inspects the
// resulting text_ram cells via the scan-side read port. Also checks the
// observability outputs (conn_state, input_len/cursor, peer_name).
//
// Tests:
//   1. test_reset                    text_ram initialised to spaces;
//                                    ready high after reset
//   2. test_redraw_all               REDRAW_ALL consumed; conn_state
//                                    latched
//   3. test_conn_state_connected     CONNECTED transition draws title
//                                    + clears input row
//   4. test_append_remote            remote bubble left-aligned at col 2
//   5. test_append_local_pending     local bubble right-aligned at col 97
//   6. test_update_status_success    pending->success keeps rounded borders
//   7. test_update_status_fail       pending->fail changes to square borders
//   8. test_insert_at_cursor         input row mirrors typed chars
//   9. test_delete_at_cursor         backspace shifts and clears tail
//  10. test_update_input_line_clear  Enter-commit clears input row
//  11. test_move_cursor              cursor obs updates without text write
//  12. test_peer_change_clears_hist  switching peer wipes history rows
//  13. test_scroll_up_down           scroll offset advances / clamps
//  14. test_peer_change_resets_scroll peer switch resets scroll
//  15. test_hist_ring_wrap           ring head wraps at N_HIST_STORED
//  16. test_pixel_boot_splash        BOOT splash colour emitted
//  17. test_remote_long_message      max-length remote bubble fits
//  18. test_local_long_message       max-length local bubble fits
//  19. test_multiline_local          local "hi\nbye" -> 2 rows right-aligned
//  20. test_multiline_remote         remote "ab\ncd" -> 2 rows left-aligned
//  21. test_multiline_status_update  status update rewrites all rows
//  22. test_multiline_wraps_ring     multi-line at end-of-ring wraps rows
//                                    instead of spilling past HIST_ROW_END
//  23. test_multiline_overflow       payload with >MAX_LINES newlines does
//                                    not OOB; tail merges into last row
// =====================================================================

#include "Vfe_top.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <vector>

static vluint64_t   g_time_ns  = 0;
static int          g_failures = 0;
static Vfe_top*     dut        = nullptr;
static VerilatedVcdC* tfp      = nullptr;

// Mirrors of chat_pkg enums.
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
enum : uint8_t { CONN_BOOT = 0, CONN_HANDSHAKE = 1, CONN_CONNECTED = 2,
                 CONN_DISCONNECTED = 3 };
enum : uint8_t { MSG_LOCAL = 0, MSG_REMOTE = 1, MSG_SYSTEM = 2 };
enum : uint8_t { MSG_PENDING = 0, MSG_SUCCESS = 1, MSG_FAIL = 2 };

// Layout constants must match fe_top defaults.
static constexpr int TITLE_ROW        = 0;
static constexpr int HIST_ROW_START   = 2;
static constexpr int INPUT_ROW        = 67;     // = INPUT_ROW_START
static constexpr int INPUT_ROW_START  = 67;
static constexpr int MAX_INPUT_LINES  = 16;

// Bubble layout constants (must match fe_pkg.sv).
static constexpr int BUBBLE_MARGIN_L   = 2;
static constexpr int BUBBLE_RIGHT_EDGE = 97;

static constexpr uint8_t SPRITE_BL  = 0xF3;  // normal left border (rounded)
static constexpr uint8_t SPRITE_BR  = 0xF4;  // normal right border (rounded)
static constexpr uint8_t SPRITE_FBL = 0xF6;  // fail left border (square)
static constexpr uint8_t SPRITE_FBR = 0xF7;  // fail right border (square)

// Mirror of the RTL MAX_LINES localparam in fe_render_decoder.sv.
static constexpr int MAX_LINES = 16;

// ---------------------------------------------------------------------
// clocking / reset
// ---------------------------------------------------------------------
static void tick_half() {
    dut->eval();
    if (tfp) tfp->dump(g_time_ns);
    g_time_ns += 5;
}
static void tick() {
    dut->clk = 0; dut->clk_pix = 0; tick_half();
    dut->clk = 1; dut->clk_pix = 1; tick_half();
}

static void reset() {
    dut->rst_n           = 0;
    dut->be_render_valid = 0;
    dut->be_render_cmd   = 0;
    dut->be_render_msg_id = 0;
    dut->be_render_side  = 0;
    dut->be_render_status = 0;
    dut->be_render_len   = 0;
    dut->be_render_cursor_pos = 0;
    dut->be_render_ascii = 0;
    dut->be_render_conn_state = 0;
    dut->be_render_peer_name_len = 0;
    dut->rd_row = 0;
    dut->rd_col = 0;
    memset(&dut->be_render_payload,   0, sizeof(dut->be_render_payload));
    memset(&dut->be_render_peer_name, 0, sizeof(dut->be_render_peer_name));
    dut->clk = 0; dut->clk_pix = 0;
    for (int i = 0; i < 4; i++) tick();
    dut->rst_n = 1;
    tick();
}

// ---------------------------------------------------------------------
// check macros
// ---------------------------------------------------------------------
#define CHECK_EQ(actual, expected, label) do {                            \
    auto _a = (actual); auto _e = (expected);                             \
    if (_a != _e) {                                                       \
        ++g_failures;                                                     \
        printf("  [FAIL @ %lluns] %-40s got=0x%02llx expected=0x%02llx\n",\
               (unsigned long long)g_time_ns, (label),                    \
               (unsigned long long)_a, (unsigned long long)_e);           \
    }                                                                     \
} while (0)

// ---------------------------------------------------------------------
// Wide-bus helpers: dut->be_render_payload is uint32_t[N], packed
// little-endian (byte i at bit i*8). Same for be_render_peer_name.
// ---------------------------------------------------------------------
template <typename T>
static void pack_bytes(T& dest, const uint8_t* src, size_t n) {
    auto* words = reinterpret_cast<uint32_t*>(&dest);
    size_t total = sizeof(dest) / sizeof(uint32_t);
    for (size_t w = 0; w < total; w++) words[w] = 0;
    for (size_t i = 0; i < n; i++) {
        size_t w = i / 4;
        size_t b = i % 4;
        words[w] |= (uint32_t)src[i] << (b * 8);
    }
}

// Read text_ram[row][col] via the scan-side registered read port.
// Drive rd_row/rd_col, tick, observe rd_code.
static uint8_t read_cell(int row, int col) {
    dut->rd_row = row;
    dut->rd_col = col;
    tick();           // captures address into BRAM read pipe
    tick();           // safety tick
    return dut->rd_code;
}

static void read_row(int row, int col_start, int n, uint8_t* out) {
    for (int i = 0; i < n; i++) out[i] = read_cell(row, col_start + i);
}

// ---------------------------------------------------------------------
// Send one render command (waits for ready=1, then valid one cycle,
// then waits for ready=1 again so multi-cycle writes finish).
// ---------------------------------------------------------------------
struct RenderCmd {
    uint8_t  cmd          = 0;
    uint8_t  msg_id       = 0;
    uint8_t  side         = 0;
    uint8_t  status       = 0;
    uint16_t len          = 0;
    uint16_t cursor_pos   = 0;
    uint8_t  ascii        = 0;
    uint8_t  conn_state   = 0;
    uint8_t  peer_name_len = 0;
    const uint8_t* payload   = nullptr; size_t payload_n   = 0;
    const uint8_t* peer_name = nullptr; size_t peer_name_n = 0;
};

static void wait_ready(int timeout = 100000) {
    int waited = 0;
    while (!dut->be_render_ready && waited < timeout) {
        tick();
        waited++;
    }
    if (!dut->be_render_ready) {
        ++g_failures;
        printf("  [FAIL @ %lluns] timed out waiting for be_render_ready\n",
               (unsigned long long)g_time_ns);
    }
}

static void send_cmd(const RenderCmd& c) {
    wait_ready();

    dut->be_render_cmd            = c.cmd;
    dut->be_render_msg_id         = c.msg_id;
    dut->be_render_side           = c.side;
    dut->be_render_status         = c.status;
    dut->be_render_len            = c.len;
    dut->be_render_cursor_pos     = c.cursor_pos;
    dut->be_render_ascii          = c.ascii;
    dut->be_render_conn_state     = c.conn_state;
    dut->be_render_peer_name_len  = c.peer_name_len;

    if (c.payload && c.payload_n)
        pack_bytes(dut->be_render_payload, c.payload, c.payload_n);
    else
        memset(&dut->be_render_payload, 0, sizeof(dut->be_render_payload));

    if (c.peer_name && c.peer_name_n)
        pack_bytes(dut->be_render_peer_name, c.peer_name, c.peer_name_n);
    else
        memset(&dut->be_render_peer_name, 0, sizeof(dut->be_render_peer_name));

    dut->be_render_valid = 1;
    tick();                          // handshake completes here
    dut->be_render_valid = 0;
    wait_ready();
    memset(&dut->be_render_peer_name, 0, sizeof(dut->be_render_peer_name));
}

// Helper: bring up connection with peer "Bob".
static void bring_up() {
    const uint8_t bob[] = {'B','o','b'};
    RenderCmd cn;
    cn.cmd = RENDER_CONN_STATE; cn.conn_state = CONN_CONNECTED;
    cn.peer_name = bob; cn.peer_name_n = 3; cn.peer_name_len = 3;
    send_cmd(cn);
}

// =====================================================================
// Tests
// =====================================================================

static void test_reset() {
    printf("== test_reset\n");
    reset();
    dut->eval();
    CHECK_EQ(dut->be_render_ready, 1, "ready high in idle");
    CHECK_EQ(dut->conn_state_obs,  CONN_BOOT, "conn_state == BOOT");
    CHECK_EQ(dut->input_len_obs,   0, "input_len == 0");
    CHECK_EQ(dut->input_cursor_obs, 0, "input_cursor == 0");
    CHECK_EQ(read_cell(0, 0),     ' ', "cell (0,0) is space");
    CHECK_EQ(read_cell(36, 50),   ' ', "cell (36,50) is space");
    CHECK_EQ(read_cell(15, 100),  ' ', "cell (15,100) is space");
}

static void test_redraw_all() {
    printf("== test_redraw_all\n");
    reset();
    RenderCmd c;
    c.cmd        = RENDER_REDRAW_ALL;
    c.conn_state = CONN_BOOT;
    send_cmd(c);
    CHECK_EQ(dut->conn_state_obs, CONN_BOOT, "conn_state still BOOT");
}

static void test_conn_state_connected() {
    printf("== test_conn_state_connected\n");
    reset();
    const uint8_t bob[] = {'B','o','b'};
    RenderCmd c;
    c.cmd            = RENDER_CONN_STATE;
    c.conn_state     = CONN_CONNECTED;
    c.peer_name      = bob;
    c.peer_name_n    = 3;
    c.peer_name_len  = 3;
    send_cmd(c);

    CHECK_EQ(dut->conn_state_obs,    CONN_CONNECTED, "conn_state == CONNECTED");
    CHECK_EQ(dut->peer_name_len_obs, 3,              "peer_name_len");

    uint8_t row[16];
    read_row(TITLE_ROW, 0, 14, row);
    const char expect[] = "Chat with: Bob";
    for (int i = 0; i < 14; i++) {
        char lbl[32]; snprintf(lbl, sizeof(lbl), "title col %d", i);
        CHECK_EQ(row[i], (uint8_t)expect[i], lbl);
    }
    CHECK_EQ(read_cell(TITLE_ROW, 14), ' ',  "title col 14 is space");
    CHECK_EQ(read_cell(TITLE_ROW, 99), ' ',  "title tail is space");
}

// Remote message: left-aligned bubble starting at col BUBBLE_MARGIN_L.
//   col 2 = SPRITE_BL, col 3..3+len-1 = payload, col 3+len = SPRITE_BR
static void test_append_remote() {
    printf("== test_append_remote\n");
    reset();
    bring_up();

    const uint8_t hello[] = "hello";
    RenderCmd c;
    c.cmd        = RENDER_APPEND_REMOTE;
    c.msg_id     = 7;
    c.side       = MSG_REMOTE;
    c.status     = MSG_SUCCESS;
    c.payload    = hello;
    c.payload_n  = 5;
    c.len        = 5;
    send_cmd(c);

    // col 0,1 = space (margin); col 2 = left border; col 3..7 = "hello"; col 8 = right border
    CHECK_EQ(read_cell(HIST_ROW_START, 0), ' ',  "remote col 0 margin");
    CHECK_EQ(read_cell(HIST_ROW_START, 1), ' ',  "remote col 1 margin");
    CHECK_EQ(read_cell(HIST_ROW_START, 2), SPRITE_BL, "remote left border");
    CHECK_EQ(read_cell(HIST_ROW_START, 3), 'h',  "remote payload[0]");
    CHECK_EQ(read_cell(HIST_ROW_START, 4), 'e',  "remote payload[1]");
    CHECK_EQ(read_cell(HIST_ROW_START, 5), 'l',  "remote payload[2]");
    CHECK_EQ(read_cell(HIST_ROW_START, 6), 'l',  "remote payload[3]");
    CHECK_EQ(read_cell(HIST_ROW_START, 7), 'o',  "remote payload[4]");
    CHECK_EQ(read_cell(HIST_ROW_START, 8), SPRITE_BR, "remote right border");
    CHECK_EQ(read_cell(HIST_ROW_START, 9), ' ',  "remote col after bubble");
}

// Local message: right-aligned bubble ending at col BUBBLE_RIGHT_EDGE (97).
// For "hi" (len=2): left border at 97-2-1=94, payload at 95..96, right border at 97
static void test_append_local_pending() {
    printf("== test_append_local_pending\n");
    reset();
    bring_up();

    const uint8_t hi[] = "hi";
    RenderCmd c;
    c.cmd        = RENDER_APPEND_LOCAL_PENDING;
    c.msg_id     = 3;
    c.side       = MSG_LOCAL;
    c.status     = MSG_PENDING;
    c.payload    = hi;
    c.payload_n  = 2;
    c.len        = 2;
    send_cmd(c);

    // bubble_left = 97 - 2 - 1 = 94; payload at 95,96; right at 97
    CHECK_EQ(read_cell(HIST_ROW_START, 93), ' ',       "local col before bubble");
    CHECK_EQ(read_cell(HIST_ROW_START, 94), SPRITE_BL, "local left border (rounded, pending)");
    CHECK_EQ(read_cell(HIST_ROW_START, 95), 'h',       "local payload[0]");
    CHECK_EQ(read_cell(HIST_ROW_START, 96), 'i',       "local payload[1]");
    CHECK_EQ(read_cell(HIST_ROW_START, 97), SPRITE_BR, "local right border (rounded, pending)");
    CHECK_EQ(read_cell(HIST_ROW_START, 98), ' ',       "local col after bubble");
}

// Status update PENDING -> SUCCESS: still rounded borders.
static void test_update_status_success() {
    printf("== test_update_status_success\n");
    reset();
    bring_up();

    const uint8_t hi[] = "hi";
    RenderCmd c1;
    c1.cmd = RENDER_APPEND_LOCAL_PENDING;
    c1.msg_id = 7;  c1.side = MSG_LOCAL; c1.status = MSG_PENDING;
    c1.payload = hi; c1.payload_n = 2; c1.len = 2;
    send_cmd(c1);

    // Should have rounded borders initially.
    CHECK_EQ(read_cell(HIST_ROW_START, 94), SPRITE_BL, "initial left border rounded");
    CHECK_EQ(read_cell(HIST_ROW_START, 97), SPRITE_BR, "initial right border rounded");

    // Update to SUCCESS -- still rounded.
    RenderCmd c2;
    c2.cmd = RENDER_UPDATE_STATUS;
    c2.msg_id = 7;  c2.side = MSG_LOCAL; c2.status = MSG_SUCCESS;
    send_cmd(c2);
    CHECK_EQ(read_cell(HIST_ROW_START, 94), SPRITE_BL, "success left border still rounded");
    CHECK_EQ(read_cell(HIST_ROW_START, 95), 'h',       "success payload[0] preserved");
    CHECK_EQ(read_cell(HIST_ROW_START, 96), 'i',       "success payload[1] preserved");
    CHECK_EQ(read_cell(HIST_ROW_START, 97), SPRITE_BR, "success right border still rounded");
}

// Status update PENDING -> FAIL: changes to square borders.
static void test_update_status_fail() {
    printf("== test_update_status_fail\n");
    reset();
    bring_up();

    const uint8_t hi[] = "hi";
    RenderCmd c1;
    c1.cmd = RENDER_APPEND_LOCAL_PENDING;
    c1.msg_id = 7;  c1.side = MSG_LOCAL; c1.status = MSG_PENDING;
    c1.payload = hi; c1.payload_n = 2; c1.len = 2;
    send_cmd(c1);

    // Update to FAIL -- should switch to square borders.
    RenderCmd c2;
    c2.cmd = RENDER_UPDATE_STATUS;
    c2.msg_id = 7;  c2.side = MSG_LOCAL; c2.status = MSG_FAIL;
    send_cmd(c2);

    // Same layout: left at 94, payload at 95,96, right at 97
    CHECK_EQ(read_cell(HIST_ROW_START, 94), SPRITE_FBL, "fail left border square");
    CHECK_EQ(read_cell(HIST_ROW_START, 95), 'h',        "fail payload[0] preserved");
    CHECK_EQ(read_cell(HIST_ROW_START, 96), 'i',        "fail payload[1] preserved");
    CHECK_EQ(read_cell(HIST_ROW_START, 97), SPRITE_FBR, "fail right border square");
}

// Helper: bring the connection up, then type characters via INSERT.
static void bring_up_and_type(const char* s) {
    bring_up();
    for (int i = 0; s[i]; i++) {
        RenderCmd ic;
        ic.cmd        = RENDER_INSERT_AT_CURSOR;
        ic.cursor_pos = i + 1;       // post-edit cursor
        ic.ascii      = (uint8_t)s[i];
        send_cmd(ic);
    }
}

static void test_insert_at_cursor() {
    printf("== test_insert_at_cursor\n");
    reset();
    bring_up_and_type("abc");

    CHECK_EQ(dut->input_len_obs,    3, "input_len after typing abc");
    CHECK_EQ(dut->input_cursor_obs, 3, "input_cursor after typing abc");

    uint8_t row[8];
    read_row(INPUT_ROW, 0, 6, row);
    const char expect[] = "> abc ";
    for (int i = 0; i < 6; i++) {
        char lbl[32]; snprintf(lbl, sizeof(lbl), "input col %d", i);
        CHECK_EQ(row[i], (uint8_t)expect[i], lbl);
    }
}

static void test_delete_at_cursor() {
    printf("== test_delete_at_cursor\n");
    reset();
    bring_up_and_type("abcd");      // input_line = "abcd", cursor = 4

    RenderCmd dc;
    dc.cmd        = RENDER_DELETE_AT_CURSOR;
    dc.cursor_pos = 3;               // post-edit cursor
    send_cmd(dc);

    CHECK_EQ(dut->input_len_obs,    3, "input_len after one BS");
    CHECK_EQ(dut->input_cursor_obs, 3, "input_cursor after one BS");

    uint8_t row[8];
    read_row(INPUT_ROW, 0, 7, row);
    const char expect[] = "> abc  ";
    for (int i = 0; i < 7; i++) {
        char lbl[32]; snprintf(lbl, sizeof(lbl), "input col %d", i);
        CHECK_EQ(row[i], (uint8_t)expect[i], lbl);
    }
}

static void test_update_input_line_clear() {
    printf("== test_update_input_line_clear\n");
    reset();
    bring_up_and_type("hi");

    RenderCmd c;
    c.cmd        = RENDER_UPDATE_INPUT_LINE;
    c.len        = 0;
    c.cursor_pos = 0;
    send_cmd(c);

    CHECK_EQ(dut->input_len_obs,    0, "input_len cleared");
    CHECK_EQ(dut->input_cursor_obs, 0, "input_cursor cleared");

    uint8_t row[8];
    read_row(INPUT_ROW, 0, 6, row);
    const char expect[] = ">     ";
    for (int i = 0; i < 6; i++) {
        char lbl[32]; snprintf(lbl, sizeof(lbl), "input col %d", i);
        CHECK_EQ(row[i], (uint8_t)expect[i], lbl);
    }
}

static void test_move_cursor() {
    printf("== test_move_cursor\n");
    reset();
    bring_up_and_type("xy");
    CHECK_EQ(dut->input_cursor_obs, 2, "cursor at 2");

    RenderCmd c;
    c.cmd        = RENDER_MOVE_CURSOR;
    c.cursor_pos = 1;
    send_cmd(c);

    CHECK_EQ(dut->input_cursor_obs, 1, "cursor moved to 1");
    CHECK_EQ(read_cell(INPUT_ROW, 2), 'x', "x still at col 2");
    CHECK_EQ(read_cell(INPUT_ROW, 3), 'y', "y still at col 3");
}

static void test_peer_change_clears_hist() {
    printf("== test_peer_change_clears_hist\n");
    reset();

    bring_up();

    const uint8_t hi[] = "hi";
    RenderCmd c;
    c.cmd = RENDER_APPEND_REMOTE; c.msg_id = 1; c.side = MSG_REMOTE;
    c.status = MSG_SUCCESS;
    c.payload = hi; c.payload_n = 2; c.len = 2;
    send_cmd(c);
    // Should have bubble content at col 2+
    CHECK_EQ(read_cell(HIST_ROW_START, 2), SPRITE_BL, "bubble left border present");

    const uint8_t eve[] = {'E','v','e'};
    RenderCmd cn2;
    cn2.cmd = RENDER_CONN_STATE; cn2.conn_state = CONN_CONNECTED;
    cn2.peer_name = eve; cn2.peer_name_n = 3; cn2.peer_name_len = 3;
    send_cmd(cn2);

    CHECK_EQ(read_cell(TITLE_ROW, 11), 'E', "title shows E");
    CHECK_EQ(read_cell(TITLE_ROW, 12), 'v', "title shows v");
    CHECK_EQ(read_cell(TITLE_ROW, 13), 'e', "title shows e");

    CHECK_EQ(read_cell(HIST_ROW_START, 0), ' ', "hist row 0 cleared");
    CHECK_EQ(read_cell(HIST_ROW_START, 2), ' ', "hist row 2 cleared");
}

// ---------------------------------------------------------------------
// Scroll tests (RENDER_SCROLL_UP / RENDER_SCROLL_DOWN)
// ---------------------------------------------------------------------
static void test_scroll_up_down() {
    printf("== test_scroll_up_down\n");
    reset();
    bring_up();

    CHECK_EQ(dut->scroll_offset_obs, 0, "scroll starts at 0");

    RenderCmd su; su.cmd = RENDER_SCROLL_UP;
    send_cmd(su); send_cmd(su); send_cmd(su);
    CHECK_EQ(dut->scroll_offset_obs, 3, "scroll up 3 times");

    RenderCmd sd; sd.cmd = RENDER_SCROLL_DOWN;
    send_cmd(sd);
    CHECK_EQ(dut->scroll_offset_obs, 2, "scroll down 1");

    // Scroll down past 0 -> clamps.
    send_cmd(sd); send_cmd(sd); send_cmd(sd);
    CHECK_EQ(dut->scroll_offset_obs, 0, "scroll down clamps at 0");

    // Scroll up past max -> clamps at SCROLL_MAX = N_HIST_STORED - N_HIST_VISIBLE.
    // (P3 layout: N_HIST_STORED=64, N_HIST_VISIBLE=29 -> SCROLL_MAX=35.)
    const int N_HIST_STORED  = 64;
    const int N_HIST_VISIBLE = 29;
    const int SCROLL_MAX     = N_HIST_STORED - N_HIST_VISIBLE;
    for (int i = 0; i < N_HIST_STORED + 4; i++) send_cmd(su);
    CHECK_EQ((int)dut->scroll_offset_obs, SCROLL_MAX, "scroll up clamps at SCROLL_MAX");
}

static void test_peer_change_resets_scroll() {
    printf("== test_peer_change_resets_scroll\n");
    reset();
    bring_up();

    RenderCmd su; su.cmd = RENDER_SCROLL_UP;
    for (int i = 0; i < 5; i++) send_cmd(su);
    CHECK_EQ(dut->scroll_offset_obs, 5, "scrolled up 5");

    // Switch peer -> scroll resets to 0.
    const uint8_t eve[] = {'E','v','e'};
    RenderCmd cn2;
    cn2.cmd = RENDER_CONN_STATE; cn2.conn_state = CONN_CONNECTED;
    cn2.peer_name = eve; cn2.peer_name_n = 3; cn2.peer_name_len = 3;
    send_cmd(cn2);
    CHECK_EQ(dut->scroll_offset_obs, 0, "scroll reset on peer change");
}

static void test_hist_ring_wrap() {
    printf("== test_hist_ring_wrap\n");
    reset();
    bring_up();

    CHECK_EQ(dut->hist_wr_row_obs, 0, "ring head at 0");

    // Write 65 messages so the ring wraps once.
    const uint8_t tag[] = {'X'};
    for (int i = 0; i < 65; i++) {
        RenderCmd c;
        c.cmd = RENDER_APPEND_REMOTE; c.msg_id = (uint8_t)i;
        c.side = MSG_REMOTE; c.status = MSG_SUCCESS;
        c.payload = tag; c.payload_n = 1; c.len = 1;
        send_cmd(c);
    }
    CHECK_EQ(dut->hist_wr_row_obs, 1, "ring head wrapped to 1");
}

// Pixel-side sanity check. After reset the timing counter starts at
// hdata=0/vdata=0 (visible region) and conn_state == BOOT, so the scan
// pipeline should emit the BOOT splash colour after a few cycles.
static void test_pixel_boot_splash() {
    printf("== test_pixel_boot_splash\n");
    reset();
    for (int i = 0; i < 8; i++) tick();
    CHECK_EQ((bool)dut->video_de, true, "video_de high in visible region");
    CHECK_EQ(dut->video_red,   0x08, "BOOT splash red");
    CHECK_EQ(dut->video_green, 0x10, "BOOT splash green");
    CHECK_EQ(dut->video_blue,  0x30, "BOOT splash blue");

    bool saw_hsync_high = false;
    for (int i = 0; i < 1100; i++) {
        tick();
        if (dut->video_hsync) saw_hsync_high = true;
    }
    CHECK_EQ(saw_hsync_high, true, "saw hsync pulse within one line");
}

// Max-length remote message (64 chars): bubble at cols 2..67.
static void test_remote_long_message() {
    printf("== test_remote_long_message\n");
    reset();
    bring_up();

    uint8_t longmsg[64];
    for (int i = 0; i < 64; i++) longmsg[i] = 'A' + (i % 26);

    RenderCmd c;
    c.cmd = RENDER_APPEND_REMOTE; c.msg_id = 10;
    c.side = MSG_REMOTE; c.status = MSG_SUCCESS;
    c.payload = longmsg; c.payload_n = 64; c.len = 64;
    send_cmd(c);

    // bubble_left=2, payload_start=3, bubble_right=3+64=67
    CHECK_EQ(read_cell(HIST_ROW_START, 2),  SPRITE_BL, "long remote left border");
    CHECK_EQ(read_cell(HIST_ROW_START, 3),  'A',       "long remote payload[0]");
    CHECK_EQ(read_cell(HIST_ROW_START, 66), (uint8_t)('A' + (63 % 26)), "long remote payload[63]");
    CHECK_EQ(read_cell(HIST_ROW_START, 67), SPRITE_BR, "long remote right border");
    CHECK_EQ(read_cell(HIST_ROW_START, 68), ' ',       "long remote after bubble");
}

// Max-length local message (64 chars): bubble left at 97-64-1=32, right at 97.
static void test_local_long_message() {
    printf("== test_local_long_message\n");
    reset();
    bring_up();

    uint8_t longmsg[64];
    for (int i = 0; i < 64; i++) longmsg[i] = 'a' + (i % 26);

    RenderCmd c;
    c.cmd = RENDER_APPEND_LOCAL_PENDING; c.msg_id = 20;
    c.side = MSG_LOCAL; c.status = MSG_PENDING;
    c.payload = longmsg; c.payload_n = 64; c.len = 64;
    send_cmd(c);

    // bubble_left=97-64-1=32, payload at 33..96, right at 97
    CHECK_EQ(read_cell(HIST_ROW_START, 31), ' ',       "long local before bubble");
    CHECK_EQ(read_cell(HIST_ROW_START, 32), SPRITE_BL, "long local left border");
    CHECK_EQ(read_cell(HIST_ROW_START, 33), 'a',       "long local payload[0]");
    CHECK_EQ(read_cell(HIST_ROW_START, 96), (uint8_t)('a' + (63 % 26)), "long local payload[63]");
    CHECK_EQ(read_cell(HIST_ROW_START, 97), SPRITE_BR, "long local right border");
    CHECK_EQ(read_cell(HIST_ROW_START, 98), ' ',       "long local after bubble");
}

// =====================================================================
// Multi-line tests
// =====================================================================

// Local multi-line: "hi\nbye" -> two rows in history ring.
// Line 0: "hi" right-aligned, line 1: "bye" right-aligned.
static void test_multiline_local() {
    printf("== test_multiline_local\n");
    reset();
    bring_up();
    uint8_t msg[] = {'h','i',0x0A,'b','y','e'};
    RenderCmd c;
    c.cmd = RENDER_APPEND_LOCAL_PENDING; c.msg_id = 0;
    c.side = MSG_LOCAL; c.status = MSG_PENDING; c.len = 6;
    c.payload = msg; c.payload_n = 6;
    send_cmd(c);

    // Row 0 (HIST_ROW_START): "hi" right-aligned bubble
    int row0 = HIST_ROW_START;
    CHECK_EQ(read_cell(row0, 94), (uint8_t)SPRITE_BL, "row0 left border");
    CHECK_EQ(read_cell(row0, 95), 'h', "row0 'h'");
    CHECK_EQ(read_cell(row0, 96), 'i', "row0 'i'");
    CHECK_EQ(read_cell(row0, 97), (uint8_t)SPRITE_BR, "row0 right border");

    // Row 1 (HIST_ROW_START+1): "bye" right-aligned bubble
    int row1 = HIST_ROW_START + 1;
    CHECK_EQ(read_cell(row1, 93), (uint8_t)SPRITE_BL, "row1 left border");
    CHECK_EQ(read_cell(row1, 94), 'b', "row1 'b'");
    CHECK_EQ(read_cell(row1, 95), 'y', "row1 'y'");
    CHECK_EQ(read_cell(row1, 96), 'e', "row1 'e'");
    CHECK_EQ(read_cell(row1, 97), (uint8_t)SPRITE_BR, "row1 right border");

    // Row 2 should be space (unused)
    CHECK_EQ(read_cell(HIST_ROW_START + 2, 50), ' ', "row2 empty");
}

// Remote multi-line: "ab\ncd" -> two rows, left-aligned.
static void test_multiline_remote() {
    printf("== test_multiline_remote\n");
    reset();
    bring_up();
    uint8_t msg[] = {'a','b',0x0A,'c','d'};
    RenderCmd c;
    c.cmd = RENDER_APPEND_REMOTE; c.msg_id = 1;
    c.side = MSG_REMOTE; c.status = MSG_SUCCESS; c.len = 5;
    c.payload = msg; c.payload_n = 5;
    send_cmd(c);

    // Fresh state, starts at ring slot 0
    int row0 = HIST_ROW_START;
    CHECK_EQ(read_cell(row0, 2), (uint8_t)SPRITE_BL, "row0 left border");
    CHECK_EQ(read_cell(row0, 3), 'a', "row0 'a'");
    CHECK_EQ(read_cell(row0, 4), 'b', "row0 'b'");
    CHECK_EQ(read_cell(row0, 5), (uint8_t)SPRITE_BR, "row0 right border");

    int row1 = HIST_ROW_START + 1;
    CHECK_EQ(read_cell(row1, 2), (uint8_t)SPRITE_BL, "row1 left border");
    CHECK_EQ(read_cell(row1, 3), 'c', "row1 'c'");
    CHECK_EQ(read_cell(row1, 4), 'd', "row1 'd'");
    CHECK_EQ(read_cell(row1, 5), (uint8_t)SPRITE_BR, "row1 right border");
}

// Status update on multi-line message rewrites all rows.
static void test_multiline_status_update() {
    printf("== test_multiline_status_update\n");
    reset();
    bring_up();
    // Send local "xy\nz" -> line0="xy", line1="z"
    uint8_t msg[] = {'x','y',0x0A,'z'};
    RenderCmd c;
    c.cmd = RENDER_APPEND_LOCAL_PENDING; c.msg_id = 0;
    c.side = MSG_LOCAL; c.status = MSG_PENDING; c.len = 4;
    c.payload = msg; c.payload_n = 4;
    send_cmd(c);

    // Line 0 "xy" right-aligned: BL@94, x@95, y@96, BR@97
    int row0 = HIST_ROW_START;
    CHECK_EQ(read_cell(row0, 94), (uint8_t)SPRITE_BL, "pre-update row0 BL rounded");
    CHECK_EQ(read_cell(row0, 97), (uint8_t)SPRITE_BR, "pre-update row0 BR rounded");

    // Update status to FAIL -> square borders
    RenderCmd u;
    u.cmd = RENDER_UPDATE_STATUS; u.msg_id = 0;
    u.status = MSG_FAIL;
    send_cmd(u);

    // Row 0 "xy": FBL@94, x@95, y@96, FBR@97
    CHECK_EQ(read_cell(row0, 94), (uint8_t)SPRITE_FBL, "row0 fail left border");
    CHECK_EQ(read_cell(row0, 95), 'x', "row0 x after fail");
    CHECK_EQ(read_cell(row0, 96), 'y', "row0 y after fail");
    CHECK_EQ(read_cell(row0, 97), (uint8_t)SPRITE_FBR, "row0 fail right border");
    // Row 1 "z": FBL@95, z@96, FBR@97
    int row1 = HIST_ROW_START + 1;
    CHECK_EQ(read_cell(row1, 95), (uint8_t)SPRITE_FBL, "row1 fail left border");
    CHECK_EQ(read_cell(row1, 96), 'z', "row1 z after fail");
    CHECK_EQ(read_cell(row1, 97), (uint8_t)SPRITE_FBR, "row1 fail right border");
}

// Multi-line message landing at the end of the history ring must wrap
// its line writes modulo N_HIST_STORED -- otherwise the second line
// spills into the sep row (HIST_ROW_END+1=66) and beyond, corrupting
// non-history rows.
//
// Setup: push 63 single-line remote messages so hist_wr_row_q == 63;
// then a 2-line local "a\nb". After fix:
//   - line 0 -> text_ram row HIST_ROW_START+63 = 65
//   - line 1 -> wraps to text_ram row HIST_ROW_START+0  = 2
//   - row 66 (sep gap) and row 67 (INPUT_ROW) remain space
//   - hist_wr_row_q advances to (63+2) & 63 = 1
static void test_multiline_wraps_ring() {
    printf("== test_multiline_wraps_ring\n");
    reset();
    bring_up();

    // Push 63 single-byte remote messages to land hist_wr_row at 63.
    const uint8_t tag[] = {'X'};
    for (int i = 0; i < 63; i++) {
        RenderCmd c;
        c.cmd = RENDER_APPEND_REMOTE; c.msg_id = (uint8_t)i;
        c.side = MSG_REMOTE; c.status = MSG_SUCCESS;
        c.payload = tag; c.payload_n = 1; c.len = 1;
        send_cmd(c);
    }
    CHECK_EQ(dut->hist_wr_row_obs, 63, "hist_wr_row at 63 before multi-line");

    // Sanity: row 66 (sep) and row 67 (INPUT_ROW) are still space.
    CHECK_EQ(read_cell(66, 96), ' ', "row66 col96 pre = space");
    CHECK_EQ(read_cell(67, 96), ' ', "row67 col96 pre = space");

    // Now a 2-line local message "a\nb".
    const uint8_t msg[] = {'a', 0x0A, 'b'};
    RenderCmd c;
    c.cmd = RENDER_APPEND_LOCAL_PENDING; c.msg_id = 200;
    c.side = MSG_LOCAL; c.status = MSG_PENDING;
    c.payload = msg; c.payload_n = 3; c.len = 3;
    send_cmd(c);

    // Line 0 "a" right-aligned at row 65: BL@95, 'a'@96, BR@97.
    CHECK_EQ(read_cell(65, 95), (uint8_t)SPRITE_BL, "row65 BL");
    CHECK_EQ(read_cell(65, 96), 'a',                "row65 'a'");
    CHECK_EQ(read_cell(65, 97), (uint8_t)SPRITE_BR, "row65 BR");

    // Line 1 "b" MUST wrap to row 2 (HIST_ROW_START + 0).
    CHECK_EQ(read_cell(2, 95), (uint8_t)SPRITE_BL, "wrap row2 BL");
    CHECK_EQ(read_cell(2, 96), 'b',                "wrap row2 'b'");
    CHECK_EQ(read_cell(2, 97), (uint8_t)SPRITE_BR, "wrap row2 BR");

    // Row 66 and 67 must remain untouched.
    CHECK_EQ(read_cell(66, 95), ' ', "row66 col95 untouched");
    CHECK_EQ(read_cell(66, 96), ' ', "row66 col96 untouched");
    CHECK_EQ(read_cell(66, 97), ' ', "row66 col97 untouched");
    CHECK_EQ(read_cell(67, 96), ' ', "row67 (INPUT_ROW) col96 untouched");

    // Ring head advanced by 2 from 63 -> 1.
    CHECK_EQ(dut->hist_wr_row_obs, 1, "hist_wr_row wraps to 1");
}

// A message with more than MAX_LINES newlines must NOT cause OOB writes
// to ml_offset_q/ml_len_q, and must NOT silently truncate to
// (n_lines mod MAX_LINES) lines. Behavior we want: stop counting
// newlines once MAX_LINES is reached; everything after merges into the
// final line.
//
// Send MAX_LINES+2 single-char lines (each one byte 'a'+i separated by
// 0x0A). After fix:
//   - rows HIST_ROW_START+0..MAX_LINES-2 render lines 0..MAX_LINES-2
//     as single-char bubbles
//   - row HIST_ROW_START+MAX_LINES-1 absorbs the tail (5 bytes: last
//     single char + 0x0A + next char + 0x0A + final char) -- 0x0A
//     bytes render as the return-arrow glyph in the bubble
//   - row HIST_ROW_START+MAX_LINES must remain space
//   - hist_wr_row advances by MAX_LINES (not by the raw line count)
static void test_multiline_overflow() {
    printf("== test_multiline_overflow\n");
    reset();
    bring_up();

    const int N = MAX_LINES + 2;             // lines requested
    const int BYTES = 2 * N - 1;              // 'a','\n','b','\n',...
    std::vector<uint8_t> msg(BYTES);
    int idx = 0;
    for (int i = 0; i < N; i++) {
        msg[idx++] = (uint8_t)('a' + i);
        if (i != N - 1) msg[idx++] = 0x0A;
    }

    RenderCmd c;
    c.cmd = RENDER_APPEND_REMOTE; c.msg_id = 1;
    c.side = MSG_REMOTE; c.status = MSG_SUCCESS;
    c.payload = msg.data(); c.payload_n = (size_t)BYTES;
    c.len = (uint16_t)BYTES;
    send_cmd(c);

    // Rows 0..MAX_LINES-2: single-char remote bubbles 'a'..'a'+M-2.
    for (int i = 0; i < MAX_LINES - 1; i++) {
        int row = HIST_ROW_START + i;
        char lbl[40];
        snprintf(lbl, sizeof(lbl), "row %d BL", i);
        CHECK_EQ(read_cell(row, 2), (uint8_t)SPRITE_BL, lbl);
        snprintf(lbl, sizeof(lbl), "row %d char", i);
        CHECK_EQ(read_cell(row, 3), (uint8_t)('a' + i), lbl);
        snprintf(lbl, sizeof(lbl), "row %d BR", i);
        CHECK_EQ(read_cell(row, 4), (uint8_t)SPRITE_BR, lbl);
    }

    // Row MAX_LINES-1 absorbs "<a+M-1>\n<a+M>\n<a+M+1>" -- 5 bytes.
    int row_last = HIST_ROW_START + MAX_LINES - 1;
    CHECK_EQ(read_cell(row_last, 2), (uint8_t)SPRITE_BL, "row_last BL");
    CHECK_EQ(read_cell(row_last, 3), (uint8_t)('a' + MAX_LINES - 1), "row_last [0]");
    CHECK_EQ(read_cell(row_last, 4), 0x0A,                            "row_last [1]");
    CHECK_EQ(read_cell(row_last, 5), (uint8_t)('a' + MAX_LINES),     "row_last [2]");
    CHECK_EQ(read_cell(row_last, 6), 0x0A,                            "row_last [3]");
    CHECK_EQ(read_cell(row_last, 7), (uint8_t)('a' + MAX_LINES + 1), "row_last [4]");
    CHECK_EQ(read_cell(row_last, 8), (uint8_t)SPRITE_BR, "row_last BR");

    // Row MAX_LINES is unwritten (no overflow).
    int row_off = HIST_ROW_START + MAX_LINES;
    CHECK_EQ(read_cell(row_off, 2), ' ', "row past cap col2 space");
    CHECK_EQ(read_cell(row_off, 3), ' ', "row past cap col3 space");
    CHECK_EQ(read_cell(row_off, 4), ' ', "row past cap col4 space");

    // Ring head moved exactly MAX_LINES from 0.
    CHECK_EQ(dut->hist_wr_row_obs, MAX_LINES, "hist_wr_row advanced by MAX_LINES");
}

// P3.1 input area: Shift+Enter inserts a 0x0A byte; the input region
// renders this as a real newline -- subsequent characters land on the
// next text_ram row (INPUT_ROW_START+1), with no "> " prefix on rows
// past the first. Rows past the last input line stay blank.
static void test_input_newline_renders_multirow() {
    printf("== test_input_newline_renders_multirow\n");
    reset();
    bring_up();

    // Type "ab\ncd" one byte at a time via RENDER_INSERT_AT_CURSOR.
    const uint8_t typed[] = {'a','b', 0x0A, 'c','d'};
    for (int i = 0; i < 5; i++) {
        RenderCmd ic;
        ic.cmd        = RENDER_INSERT_AT_CURSOR;
        ic.cursor_pos = (uint16_t)(i + 1);
        ic.ascii      = typed[i];
        send_cmd(ic);
    }

    CHECK_EQ((int)dut->input_len_obs,    5, "input_len after typing");
    CHECK_EQ((int)dut->input_cursor_obs, 5, "input_cursor after typing");
    CHECK_EQ((int)dut->input_cursor_row_obs, 1, "cursor row = 1 (second line)");
    CHECK_EQ((int)dut->input_cursor_col_obs, 2, "cursor col = 2 (after 'cd')");

    // Row 0 of the input region: "> ab" then blanks.
    CHECK_EQ(read_cell(INPUT_ROW_START,    0), '>',  "row0 col0 prompt");
    CHECK_EQ(read_cell(INPUT_ROW_START,    1), ' ',  "row0 col1 prompt space");
    CHECK_EQ(read_cell(INPUT_ROW_START,    2), 'a',  "row0 col2 'a'");
    CHECK_EQ(read_cell(INPUT_ROW_START,    3), 'b',  "row0 col3 'b'");
    CHECK_EQ(read_cell(INPUT_ROW_START,    4), ' ',  "row0 col4 blank past end");

    // Row 1: "cd" starting at col 0 (no prefix).
    CHECK_EQ(read_cell(INPUT_ROW_START+1,  0), 'c',  "row1 col0 'c'");
    CHECK_EQ(read_cell(INPUT_ROW_START+1,  1), 'd',  "row1 col1 'd'");
    CHECK_EQ(read_cell(INPUT_ROW_START+1,  2), ' ',  "row1 col2 blank");

    // Row 2 is past n_lines = 2: every cell is blank.
    CHECK_EQ(read_cell(INPUT_ROW_START+2,  0), ' ',  "row2 col0 blank");
    CHECK_EQ(read_cell(INPUT_ROW_START+2,  5), ' ',  "row2 col5 blank");
}

// Helper: type a sequence of bytes (including 0x0A for newline) via
// individual RENDER_INSERT_AT_CURSOR commands.
static void type_chars(const char* s, size_t n) {
    for (size_t i = 0; i < n; i++) {
        RenderCmd ic;
        ic.cmd        = RENDER_INSERT_AT_CURSOR;
        ic.cursor_pos = (uint16_t)(i + 1);
        ic.ascii      = (uint8_t)s[i];
        send_cmd(ic);
    }
}

// LEFT/RIGHT (RENDER_MOVE_CURSOR with the new 1-D cursor_pos) cross
// the 0x0A boundary in either direction. The renderer re-parses on
// every MOVE_CURSOR and updates the 2-D (row, col) observers.
static void test_cursor_crosses_newline() {
    printf("== test_cursor_crosses_newline\n");
    reset();
    bring_up();
    const char buf[] = {'a','b', 0x0A, 'c','d'};
    type_chars(buf, 5);
    // After typing: input_cursor=5 (past 'd'), row=1 col=2.
    CHECK_EQ((int)dut->input_cursor_row_obs, 1, "post-type row");
    CHECK_EQ((int)dut->input_cursor_col_obs, 2, "post-type col");

    // RENDER_MOVE_CURSOR cursor_pos=3 -> at start of line 1 (right after
    // the newline). 3 - (newline_idx+1) = 3 - 3 = 0.
    RenderCmd mv;
    mv.cmd = RENDER_MOVE_CURSOR;
    mv.cursor_pos = 3;
    send_cmd(mv);
    CHECK_EQ((int)dut->input_cursor_row_obs, 1, "cursor_pos=3 row=1");
    CHECK_EQ((int)dut->input_cursor_col_obs, 0, "cursor_pos=3 col=0");

    // cursor_pos=2 lands on the line containing the newline (line 0).
    // Cursor sits between 'b' (offset 1) and '\n' (offset 2); col=2.
    mv.cursor_pos = 2;
    send_cmd(mv);
    CHECK_EQ((int)dut->input_cursor_row_obs, 0, "cursor_pos=2 row=0");
    CHECK_EQ((int)dut->input_cursor_col_obs, 2, "cursor_pos=2 col=2");

    // cursor_pos=0 -> very start of input.
    mv.cursor_pos = 0;
    send_cmd(mv);
    CHECK_EQ((int)dut->input_cursor_row_obs, 0, "cursor_pos=0 row=0");
    CHECK_EQ((int)dut->input_cursor_col_obs, 0, "cursor_pos=0 col=0");
}

// Auto-follow: typing past N_INPUT_VISIBLE rows scrolls the input
// window to keep the cursor visible; moving the cursor back up
// scrolls back; explicit INPUT_SCROLL is overridden by the next
// cursor change.
static void test_cursor_auto_follow_scroll() {
    printf("== test_cursor_auto_follow_scroll\n");
    reset();
    bring_up();
    const int N_INPUT_VISIBLE = 5;

    // Fill 7 lines so the cursor lands on row 6, two past the bottom
    // of the visible window.
    std::vector<char> buf;
    for (int i = 0; i < 7; i++) {
        buf.push_back((char)('a' + i));
        if (i != 6) buf.push_back((char)0x0A);
    }
    type_chars(buf.data(), buf.size());

    CHECK_EQ((int)dut->input_cursor_row_obs, 6, "cursor on row 6");
    // Window must have scrolled to keep row 6 visible -> offset = 2.
    CHECK_EQ((int)dut->input_scroll_offset_obs, 6 - N_INPUT_VISIBLE + 1,
             "auto-follow scrolls to row6");

    // Move cursor back to row 0 (cursor_pos=0). Window snaps back to 0.
    RenderCmd mv;
    mv.cmd = RENDER_MOVE_CURSOR;
    mv.cursor_pos = 0;
    send_cmd(mv);
    CHECK_EQ((int)dut->input_cursor_row_obs, 0, "cursor returned to row0");
    CHECK_EQ((int)dut->input_scroll_offset_obs, 0,
             "auto-follow snaps offset back to 0");

    // Manually scroll up via Shift+Up equivalent, then move cursor:
    // the cursor move overrides the manual scroll back to follow.
    RenderCmd su; su.cmd = RENDER_INPUT_SCROLL_UP;
    send_cmd(su); send_cmd(su);  // offset = 2 explicitly
    CHECK_EQ((int)dut->input_scroll_offset_obs, 2, "manual scroll to 2");
    mv.cursor_pos = (uint16_t)buf.size();  // cursor back to row 6
    send_cmd(mv);
    CHECK_EQ((int)dut->input_scroll_offset_obs, 6 - N_INPUT_VISIBLE + 1,
             "manual scroll overridden by auto-follow");
}

// RENDER_INPUT_SCROLL_UP / DOWN nudge the input window without
// repainting the input region; clamps at [0, INPUT_SCROLL_MAX].
static void test_input_scroll_clamps() {
    printf("== test_input_scroll_clamps\n");
    reset();
    bring_up();

    CHECK_EQ((int)dut->input_scroll_offset_obs, 0, "input scroll starts at 0");

    // Scroll up a few ticks, then verify it actually moves.
    RenderCmd su; su.cmd = RENDER_INPUT_SCROLL_UP;
    send_cmd(su); send_cmd(su); send_cmd(su);
    CHECK_EQ((int)dut->input_scroll_offset_obs, 3, "scroll up 3 ticks");

    // Scroll back down once.
    RenderCmd sd; sd.cmd = RENDER_INPUT_SCROLL_DOWN;
    send_cmd(sd);
    CHECK_EQ((int)dut->input_scroll_offset_obs, 2, "scroll down 1");

    // Down past 0 clamps.
    send_cmd(sd); send_cmd(sd); send_cmd(sd);
    CHECK_EQ((int)dut->input_scroll_offset_obs, 0, "scroll down clamps at 0");

    // Up past max clamps at INPUT_SCROLL_MAX = MAX_INPUT_LINES - N_INPUT_VISIBLE.
    const int N_INPUT_VISIBLE = 5;
    const int INPUT_SCROLL_MAX = MAX_INPUT_LINES - N_INPUT_VISIBLE;  // 11
    for (int i = 0; i < MAX_INPUT_LINES + 4; i++) send_cmd(su);
    CHECK_EQ((int)dut->input_scroll_offset_obs, INPUT_SCROLL_MAX,
             "scroll up clamps at INPUT_SCROLL_MAX");
}

// Enter-commit clears every visible input row, not just the first.
static void test_input_commit_clears_all_rows() {
    printf("== test_input_commit_clears_all_rows\n");
    reset();
    bring_up();

    // Pre-fill multiple input rows.
    const uint8_t typed[] = {'x','y', 0x0A, 'z', 0x0A, 'w'};
    for (int i = 0; i < 6; i++) {
        RenderCmd ic;
        ic.cmd        = RENDER_INSERT_AT_CURSOR;
        ic.cursor_pos = (uint16_t)(i + 1);
        ic.ascii      = typed[i];
        send_cmd(ic);
    }
    CHECK_EQ((int)dut->input_len_obs, 6, "pre-commit len");

    // RENDER_UPDATE_INPUT_LINE with len=0 (Enter-commit).
    RenderCmd c;
    c.cmd        = RENDER_UPDATE_INPUT_LINE;
    c.len        = 0;
    c.cursor_pos = 0;
    send_cmd(c);

    CHECK_EQ((int)dut->input_len_obs,    0, "len cleared");
    CHECK_EQ((int)dut->input_cursor_obs, 0, "cursor cleared");
    CHECK_EQ((int)dut->input_cursor_row_obs, 0, "cursor row cleared");
    CHECK_EQ((int)dut->input_cursor_col_obs, 0, "cursor col cleared");

    // Row 0: just the "> " prompt then blanks.
    CHECK_EQ(read_cell(INPUT_ROW_START,    0), '>',  "row0 prompt kept");
    CHECK_EQ(read_cell(INPUT_ROW_START,    1), ' ',  "row0 space kept");
    CHECK_EQ(read_cell(INPUT_ROW_START,    2), ' ',  "row0 content cleared");
    // Rows 1 and 2 previously held 'z' and 'w' -- must be blank now.
    CHECK_EQ(read_cell(INPUT_ROW_START+1,  0), ' ',  "row1 col0 cleared");
    CHECK_EQ(read_cell(INPUT_ROW_START+1,  5), ' ',  "row1 col5 cleared");
    CHECK_EQ(read_cell(INPUT_ROW_START+2,  0), ' ',  "row2 col0 cleared");
}

// Multi-line remote payload split into 5 lines. Validates that the
// 16-bit LEN wire field and multi-line parser flow through to the
// renderer correctly. Sized to fit in the current MAX_MSG_LEN cap.
static void test_long_multiline_payload() {
    printf("== test_long_multiline_payload\n");
    reset();
    bring_up();

    const int LINE_W   = 20;
    const int N_LINES  = 5;
    const int TOTAL    = LINE_W * N_LINES + (N_LINES - 1);  // 104 bytes
    uint8_t msg[TOTAL];
    int idx = 0;
    for (int ln = 0; ln < N_LINES; ln++) {
        for (int i = 0; i < LINE_W; i++) {
            msg[idx++] = (uint8_t)('a' + (ln % 26));  // line ln filled with 'a'+ln
        }
        if (ln != N_LINES - 1) msg[idx++] = 0x0A;
    }

    RenderCmd c;
    c.cmd = RENDER_APPEND_REMOTE; c.msg_id = 42;
    c.side = MSG_REMOTE; c.status = MSG_SUCCESS;
    c.payload = msg; c.payload_n = (size_t)TOTAL; c.len = (uint16_t)TOTAL;
    send_cmd(c);

    // Each row N: remote bubble BL@2, payload[0]@3, ..., payload[49]@52, BR@53.
    for (int ln = 0; ln < N_LINES; ln++) {
        int row = HIST_ROW_START + ln;
        char lbl[40];
        snprintf(lbl, sizeof(lbl), "long row %d BL", ln);
        CHECK_EQ(read_cell(row, 2),  (uint8_t)SPRITE_BL, lbl);
        snprintf(lbl, sizeof(lbl), "long row %d first", ln);
        CHECK_EQ(read_cell(row, 3),  (uint8_t)('a' + ln), lbl);
        snprintf(lbl, sizeof(lbl), "long row %d last", ln);
        CHECK_EQ(read_cell(row, 2 + LINE_W), (uint8_t)('a' + ln), lbl);
        snprintf(lbl, sizeof(lbl), "long row %d BR", ln);
        CHECK_EQ(read_cell(row, 3 + LINE_W), (uint8_t)SPRITE_BR, lbl);
    }

    // ring head advanced by 5
    CHECK_EQ(dut->hist_wr_row_obs, 5, "hist_wr_row advanced by 5");
}

// =====================================================================
int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    dut = new Vfe_top;
    tfp = new VerilatedVcdC;
    dut->trace(tfp, 99);
    tfp->open("sim/waves/fe_top.vcd");

    test_reset();
    test_redraw_all();
    test_conn_state_connected();
    test_append_remote();
    test_append_local_pending();
    test_update_status_success();
    test_update_status_fail();
    test_insert_at_cursor();
    test_delete_at_cursor();
    test_update_input_line_clear();
    test_move_cursor();
    test_peer_change_clears_hist();
    test_scroll_up_down();
    test_peer_change_resets_scroll();
    test_hist_ring_wrap();
    test_pixel_boot_splash();
    test_remote_long_message();
    test_local_long_message();
    test_multiline_local();
    test_multiline_remote();
    test_multiline_status_update();
    test_multiline_wraps_ring();
    test_multiline_overflow();
    test_long_multiline_payload();
    test_input_newline_renders_multirow();
    test_input_commit_clears_all_rows();
    test_input_scroll_clamps();
    test_cursor_crosses_newline();
    test_cursor_auto_follow_scroll();

    tfp->close();
    delete tfp;
    delete dut;

    if (g_failures == 0) { printf("\nPASS  (all checks)\n"); return 0; }
    printf("\nFAIL  %d check(s) failed\n", g_failures);
    return 1;
}
