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
// =====================================================================

#include "Vfe_top.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <cstdint>
#include <cstdio>
#include <cstring>

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
};
enum : uint8_t { CONN_BOOT = 0, CONN_HANDSHAKE = 1, CONN_CONNECTED = 2,
                 CONN_DISCONNECTED = 3 };
enum : uint8_t { MSG_LOCAL = 0, MSG_REMOTE = 1, MSG_SYSTEM = 2 };
enum : uint8_t { MSG_PENDING = 0, MSG_SUCCESS = 1, MSG_FAIL = 2 };

// Layout constants must match fe_top defaults.
static constexpr int TITLE_ROW        = 0;
static constexpr int HIST_ROW_START   = 2;
static constexpr int INPUT_ROW        = 67;

// Bubble layout constants (must match fe_pkg.sv).
static constexpr int BUBBLE_MARGIN_L   = 2;
static constexpr int BUBBLE_RIGHT_EDGE = 97;

static constexpr uint8_t SPRITE_BL  = 0xF3;  // normal left border (rounded)
static constexpr uint8_t SPRITE_BR  = 0xF4;  // normal right border (rounded)
static constexpr uint8_t SPRITE_FBL = 0xF6;  // fail left border (square)
static constexpr uint8_t SPRITE_FBR = 0xF7;  // fail right border (square)

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
    uint8_t  len          = 0;
    uint8_t  cursor_pos   = 0;
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

    // Scroll up past max -> clamps at SCROLL_MAX = 64-33 = 31.
    for (int i = 0; i < 40; i++) send_cmd(su);
    CHECK_EQ(dut->scroll_offset_obs, 31, "scroll up clamps at 31");
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

    tfp->close();
    delete tfp;
    delete dut;

    if (g_failures == 0) { printf("\nPASS  (all checks)\n"); return 0; }
    printf("\nFAIL  %d check(s) failed\n", g_failures);
    return 1;
}
