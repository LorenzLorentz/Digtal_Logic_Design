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
#include "../common/big_emoji_codes.h"
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

static constexpr uint8_t SPRITE_BL     = 0xF3;  // normal left border (rounded, single-line)
static constexpr uint8_t SPRITE_BR     = 0xF4;  // normal right border (rounded, single-line)
static constexpr uint8_t SPRITE_FBL    = 0xF6;  // fail left border (square, single-line)
static constexpr uint8_t SPRITE_FBR    = 0xF7;  // fail right border (square, single-line)
static constexpr uint8_t SPRITE_FAIL_X = 0xF2;  // X mark for failed local msgs
static constexpr uint8_t SPRITE_BL_TOP = 0xF8;  // multi-line top-of-bubble left
static constexpr uint8_t SPRITE_BR_TOP = 0xF9;  // multi-line top-of-bubble right
static constexpr uint8_t SPRITE_BL_BOT = 0xFA;  // multi-line bottom-of-bubble left
static constexpr uint8_t SPRITE_BR_BOT = 0xFB;  // multi-line bottom-of-bubble right
static constexpr uint8_t SPRITE_BL_MID = 0xFC;  // multi-line middle left
static constexpr uint8_t SPRITE_BR_MID = 0xFD;  // multi-line middle right

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
    dut->asset_sram_data = 0;
    dut->mouse_x = 0;
    dut->mouse_y = 0;
    dut->ui_popup_active = 0;
    dut->ui_popup_type = 0;
    dut->ui_popup_x = 0;
    dut->ui_popup_y = 0;
    dut->rd_row = 0;
    dut->rd_col = 0;
    memset(&dut->be_render_payload,   0, sizeof(dut->be_render_payload));
    memset(&dut->be_render_peer_name, 0, sizeof(dut->be_render_peer_name));
    dut->clk = 0; dut->clk_pix = 0;
    for (int i = 0; i < 4; i++) tick();
    dut->rst_n = 1;
    // Give the sync_2ff reset synchroniser (sync_out of u_sync_rst feeds
    // fe_render_decoder's sync reset) a few ticks to walk to 1 after
    // raw rst_n deasserts -- otherwise the decoder is still in
    // synchronous reset when the first command arrives.
    for (int i = 0; i < 4; i++) tick();
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

    uint8_t legend[24];
    read_row(TITLE_ROW + 1, 0, 23, legend);
    const char legend_expect[] = "Me: Alice | Peer: Bob";
    for (int i = 0; i < 21; i++) {
        char lbl[40]; snprintf(lbl, sizeof(lbl), "legend col %d", i);
        CHECK_EQ(legend[i], (uint8_t)legend_expect[i], lbl);
    }
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

static void test_emoji_codes_render_in_bubble() {
    printf("== test_emoji_codes_render_in_bubble\n");
    reset();
    bring_up();

    const uint8_t msg[] = {
        0xE0, ' ', 0xE1, ' ', 0xE2, ' ', 0xE3, ' ',
        0xE4, ' ', 0xE5, ' ', 0xE6, ' ', 0xE7, ' ',
        0xE8, ' ', 0xE9, ' ', 0xEA, ' ', 0xEB, ' ', 0xEC, ' ',
        0xED, ' ', 0xEE
    };
    RenderCmd c;
    c.cmd        = RENDER_APPEND_REMOTE;
    c.msg_id     = 11;
    c.side       = MSG_REMOTE;
    c.status     = MSG_SUCCESS;
    c.len        = 29;
    c.payload    = msg;
    c.payload_n  = 29;
    send_cmd(c);

    CHECK_EQ(read_cell(HIST_ROW_START, 3), 0xE0, "happy emoji code");
    CHECK_EQ(read_cell(HIST_ROW_START, 5), 0xE1, "sad emoji code");
    CHECK_EQ(read_cell(HIST_ROW_START, 7), 0xE2, "heart emoji code");
    CHECK_EQ(read_cell(HIST_ROW_START, 9), 0xE3, "ok emoji code");
    CHECK_EQ(read_cell(HIST_ROW_START, 11), 0xE4, "laugh emoji code");
    CHECK_EQ(read_cell(HIST_ROW_START, 13), 0xE5, "wink emoji code");
    CHECK_EQ(read_cell(HIST_ROW_START, 15), 0xE6, "angry emoji code");
    CHECK_EQ(read_cell(HIST_ROW_START, 17), 0xE7, "star emoji code");
    CHECK_EQ(read_cell(HIST_ROW_START, 19), 0xE8, "fire emoji code");
    CHECK_EQ(read_cell(HIST_ROW_START, 21), 0xE9, "yes emoji code");
    CHECK_EQ(read_cell(HIST_ROW_START, 23), 0xEA, "no emoji code");
    CHECK_EQ(read_cell(HIST_ROW_START, 25), 0xEB, "up emoji code");
    CHECK_EQ(read_cell(HIST_ROW_START, 27), 0xEC, "down emoji code");
    CHECK_EQ(read_cell(HIST_ROW_START, 29), 0xED, "doge emoji code");
    CHECK_EQ(read_cell(HIST_ROW_START, 31), 0xEE, "mairuo emoji code");
}

// Big-emoji bubble: a single-byte payload in the big-emoji anchor range
// expands the bubble to N_ROWS x N_COLS tile cells. Each cell's code is
// anchor + sub_row * N_COLS + sub_col (the scan pipeline then routes that
// tile_id to the colour ROM, but text_ram-side we just verify the codes).
// Remote bubble starts at col BUBBLE_MARGIN_L = 2, so left border lives at
// col 2 and right border at col 2 + 1 + N_COLS = 9.
static void test_big_emoji_bubble_layout_remote() {
    printf("== test_big_emoji_bubble_layout_remote\n");
    reset();
    bring_up();

    const uint8_t payload[] = { (uint8_t)BIG_EMOJI_SHRUG_ANCHOR };
    RenderCmd c;
    c.cmd        = RENDER_APPEND_REMOTE;
    c.msg_id     = 21;
    c.side       = MSG_REMOTE;
    c.status     = MSG_SUCCESS;
    c.len        = 1;
    c.payload    = payload;
    c.payload_n  = 1;
    send_cmd(c);

    const int left  = BUBBLE_MARGIN_L;      // 2
    const int right = left + 1 + BIG_EMOJI_N_COLS;  // 2 + 1 + 6 = 9
    const uint8_t anchor = (uint8_t)BIG_EMOJI_SHRUG_ANCHOR;

    // Row 0: TOP corners + first tile row.
    CHECK_EQ(read_cell(HIST_ROW_START + 0, left),  SPRITE_BL_TOP, "row0 BL_TOP");
    CHECK_EQ(read_cell(HIST_ROW_START + 0, right), SPRITE_BR_TOP, "row0 BR_TOP");
    for (int c0 = 0; c0 < BIG_EMOJI_N_COLS; c0++) {
        char lbl[64]; snprintf(lbl, sizeof(lbl), "row0 tile col %d", c0);
        CHECK_EQ(read_cell(HIST_ROW_START + 0, left + 1 + c0),
                 (uint8_t)(anchor + 0 * BIG_EMOJI_N_COLS + c0), lbl);
    }

    // Row 1: MID corners + second tile row.
    CHECK_EQ(read_cell(HIST_ROW_START + 1, left),  SPRITE_BL_MID, "row1 BL_MID");
    CHECK_EQ(read_cell(HIST_ROW_START + 1, right), SPRITE_BR_MID, "row1 BR_MID");
    for (int c0 = 0; c0 < BIG_EMOJI_N_COLS; c0++) {
        char lbl[64]; snprintf(lbl, sizeof(lbl), "row1 tile col %d", c0);
        CHECK_EQ(read_cell(HIST_ROW_START + 1, left + 1 + c0),
                 (uint8_t)(anchor + 1 * BIG_EMOJI_N_COLS + c0), lbl);
    }

    // Row 2: BOT corners + third tile row.
    CHECK_EQ(read_cell(HIST_ROW_START + 2, left),  SPRITE_BL_BOT, "row2 BL_BOT");
    CHECK_EQ(read_cell(HIST_ROW_START + 2, right), SPRITE_BR_BOT, "row2 BR_BOT");
    for (int c0 = 0; c0 < BIG_EMOJI_N_COLS; c0++) {
        char lbl[64]; snprintf(lbl, sizeof(lbl), "row2 tile col %d", c0);
        CHECK_EQ(read_cell(HIST_ROW_START + 2, left + 1 + c0),
                 (uint8_t)(anchor + 2 * BIG_EMOJI_N_COLS + c0), lbl);
    }

    // Past the right border on every row stays blank (no spill).
    CHECK_EQ(read_cell(HIST_ROW_START + 0, right + 1), ' ', "row0 col past R margin");
    CHECK_EQ(read_cell(HIST_ROW_START + 1, right + 1), ' ', "row1 col past R margin");
    CHECK_EQ(read_cell(HIST_ROW_START + 2, right + 1), ' ', "row2 col past R margin");
}

// Same idea, but for a local (right-aligned) bubble. Right edge sits at
// BUBBLE_RIGHT_EDGE = 97, so left border is at 97 - 6 - 1 = 90 and tiles
// occupy cols 91..96.
static void test_big_emoji_bubble_layout_local() {
    printf("== test_big_emoji_bubble_layout_local\n");
    reset();
    bring_up();

    const uint8_t payload[] = { (uint8_t)BIG_EMOJI_HEARTBROKEN_ANCHOR };
    RenderCmd c;
    c.cmd        = RENDER_APPEND_LOCAL_PENDING;
    c.msg_id     = 22;
    c.side       = MSG_LOCAL;
    c.status     = MSG_PENDING;
    c.len        = 1;
    c.payload    = payload;
    c.payload_n  = 1;
    send_cmd(c);

    const int right = BUBBLE_RIGHT_EDGE;             // 97
    const int left  = right - BIG_EMOJI_N_COLS - 1;  // 90
    const uint8_t anchor = (uint8_t)BIG_EMOJI_HEARTBROKEN_ANCHOR;

    CHECK_EQ(read_cell(HIST_ROW_START + 0, left),  SPRITE_BL_TOP, "L row0 BL_TOP");
    CHECK_EQ(read_cell(HIST_ROW_START + 0, right), SPRITE_BR_TOP, "L row0 BR_TOP");
    CHECK_EQ(read_cell(HIST_ROW_START + 2, left),  SPRITE_BL_BOT, "L row2 BL_BOT");
    CHECK_EQ(read_cell(HIST_ROW_START + 2, right), SPRITE_BR_BOT, "L row2 BR_BOT");

    for (int r = 0; r < BIG_EMOJI_N_ROWS; r++) {
        for (int c0 = 0; c0 < BIG_EMOJI_N_COLS; c0++) {
            char lbl[64]; snprintf(lbl, sizeof(lbl),
                                   "L tile (r=%d,c=%d)", r, c0);
            CHECK_EQ(read_cell(HIST_ROW_START + r, left + 1 + c0),
                     (uint8_t)(anchor + r * BIG_EMOJI_N_COLS + c0), lbl);
        }
    }
}

// A non-anchor single byte must render as a regular 1-line bubble, NOT
// expand into the 3-row layout. Guards against accidentally matching
// codes outside [BIG_EMOJI_BASE, BIG_EMOJI_END_EXCL).
static void test_single_byte_non_anchor_stays_one_line() {
    printf("== test_single_byte_non_anchor_stays_one_line\n");
    reset();
    bring_up();

    const uint8_t payload[] = { 'q' };
    RenderCmd c;
    c.cmd        = RENDER_APPEND_REMOTE;
    c.msg_id     = 23;
    c.side       = MSG_REMOTE;
    c.status     = MSG_SUCCESS;
    c.len        = 1;
    c.payload    = payload;
    c.payload_n  = 1;
    send_cmd(c);

    // Single-line bubble: width 1 -> SPRITE_BL at col 2, 'q' at col 3,
    // SPRITE_BR at col 4. Rows 1 and 2 should stay blank.
    CHECK_EQ(read_cell(HIST_ROW_START + 0, 2), SPRITE_BL, "single-line BL");
    CHECK_EQ(read_cell(HIST_ROW_START + 0, 3), 'q',       "single-line payload");
    CHECK_EQ(read_cell(HIST_ROW_START + 0, 4), SPRITE_BR, "single-line BR");
    CHECK_EQ(read_cell(HIST_ROW_START + 1, 2), ' ',       "no row1 BL_MID");
    CHECK_EQ(read_cell(HIST_ROW_START + 2, 2), ' ',       "no row2 BL_BOT");
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
// Helper: append N short history rows (each a single byte 'X', no \n),
// so used_hist_rows == N (until the ring fills at N_HIST_STORED = 64).
static void append_n_short_msgs(int n) {
    const uint8_t tag[] = {'X'};
    for (int i = 0; i < n; i++) {
        RenderCmd c;
        c.cmd = RENDER_APPEND_REMOTE; c.msg_id = (uint8_t)i;
        c.side = MSG_REMOTE; c.status = MSG_SUCCESS;
        c.payload = tag; c.payload_n = 1; c.len = 1;
        send_cmd(c);
    }
}

static void test_scroll_up_down() {
    printf("== test_scroll_up_down\n");
    reset();
    bring_up();

    CHECK_EQ(dut->scroll_offset_obs, 0, "scroll starts at 0");

    // Need real content -- scroll cap is now derived from used_hist_rows,
    // not the static buffer size. Pre-fill 40 single-row messages so the
    // dynamic cap = 40 - N_HIST_VISIBLE(29) = 11 -- room for 3 ticks.
    append_n_short_msgs(40);

    RenderCmd su; su.cmd = RENDER_SCROLL_UP;
    send_cmd(su); send_cmd(su); send_cmd(su);
    CHECK_EQ(dut->scroll_offset_obs, 3, "scroll up 3 times");

    RenderCmd sd; sd.cmd = RENDER_SCROLL_DOWN;
    send_cmd(sd);
    CHECK_EQ(dut->scroll_offset_obs, 2, "scroll down 1");

    // Scroll down past 0 -> clamps.
    send_cmd(sd); send_cmd(sd); send_cmd(sd);
    CHECK_EQ(dut->scroll_offset_obs, 0, "scroll down clamps at 0");

    // Scroll up past max -> clamps at dynamic max = used_hist_rows -
    // N_HIST_VISIBLE = 40 - 29 = 11.
    for (int i = 0; i < 64; i++) send_cmd(su);
    CHECK_EQ((int)dut->scroll_offset_obs, 11,
             "scroll up clamps at used_hist_rows - N_HIST_VISIBLE");
}

static void test_append_while_scrolled_locks_history_window() {
    printf("== test_append_while_scrolled_locks_history_window\n");
    reset();
    bring_up();

    append_n_short_msgs(40);

    RenderCmd su; su.cmd = RENDER_SCROLL_UP;
    for (int i = 0; i < 5; i++) send_cmd(su);
    CHECK_EQ((int)dut->scroll_offset_obs, 5, "manual scroll to 5");

    const uint8_t one[] = {'R'};
    RenderCmd c1;
    c1.cmd = RENDER_APPEND_REMOTE; c1.msg_id = 100;
    c1.side = MSG_REMOTE; c1.status = MSG_SUCCESS;
    c1.payload = one; c1.payload_n = 1; c1.len = 1;
    send_cmd(c1);
    CHECK_EQ((int)dut->scroll_offset_obs, 6,
             "one-row append keeps history window locked");

    const uint8_t two_lines[] = {'a', 0x0A, 'b'};
    RenderCmd c2;
    c2.cmd = RENDER_APPEND_LOCAL_PENDING; c2.msg_id = 101;
    c2.side = MSG_LOCAL; c2.status = MSG_PENDING;
    c2.payload = two_lines; c2.payload_n = 3; c2.len = 3;
    send_cmd(c2);
    CHECK_EQ((int)dut->scroll_offset_obs, 8,
             "two-row append keeps history window locked");
}

// With no history yet, RENDER_SCROLL_UP is a no-op (dynamic cap = 0).
// Same for RENDER_INPUT_SCROLL_UP with input_n_lines = 1.
static void test_scroll_clamps_when_empty() {
    printf("== test_scroll_clamps_when_empty\n");
    reset();
    bring_up();

    RenderCmd su; su.cmd = RENDER_SCROLL_UP;
    for (int i = 0; i < 10; i++) send_cmd(su);
    CHECK_EQ((int)dut->scroll_offset_obs, 0,
             "scroll up no-op with empty history");

    RenderCmd isu; isu.cmd = RENDER_INPUT_SCROLL_UP;
    for (int i = 0; i < 10; i++) send_cmd(isu);
    CHECK_EQ((int)dut->input_scroll_offset_obs, 0,
             "input scroll up no-op with single input line");
}

// Scroll cap grows with each appended message until the ring fills.
static void test_scroll_cap_tracks_content() {
    printf("== test_scroll_cap_tracks_content\n");
    reset();
    bring_up();
    const int N_HIST_VISIBLE = 29;

    // 29 short messages: cap still 0 (fits entirely in visible window).
    append_n_short_msgs(N_HIST_VISIBLE);
    RenderCmd su; su.cmd = RENDER_SCROLL_UP;
    for (int i = 0; i < 5; i++) send_cmd(su);
    CHECK_EQ((int)dut->scroll_offset_obs, 0,
             "29 msgs => cap 0 (all fit in visible window)");

    // 30 messages: cap = 1, so scroll up can reach 1.
    append_n_short_msgs(1);
    for (int i = 0; i < 5; i++) send_cmd(su);
    CHECK_EQ((int)dut->scroll_offset_obs, 1,
             "30 msgs => cap 1");

    // 64 messages (ring full): cap = 35.
    RenderCmd sd; sd.cmd = RENDER_SCROLL_DOWN;
    for (int i = 0; i < 5; i++) send_cmd(sd);  // reset scroll
    append_n_short_msgs(64 - 30);
    for (int i = 0; i < 64; i++) send_cmd(su);
    CHECK_EQ((int)dut->scroll_offset_obs, 64 - N_HIST_VISIBLE,
             "ring full => cap = N_HIST_STORED - N_HIST_VISIBLE");
}

static void test_peer_change_resets_scroll() {
    printf("== test_peer_change_resets_scroll\n");
    reset();
    bring_up();

    // Pre-fill enough rows that we can actually scroll.
    append_n_short_msgs(35);

    RenderCmd su; su.cmd = RENDER_SCROLL_UP;
    for (int i = 0; i < 5; i++) send_cmd(su);
    CHECK_EQ(dut->scroll_offset_obs, 5, "scrolled up 5");

    // Switch peer -> scroll AND used_hist_rows reset.
    const uint8_t eve[] = {'E','v','e'};
    RenderCmd cn2;
    cn2.cmd = RENDER_CONN_STATE; cn2.conn_state = CONN_CONNECTED;
    cn2.peer_name = eve; cn2.peer_name_n = 3; cn2.peer_name_len = 3;
    send_cmd(cn2);
    CHECK_EQ(dut->scroll_offset_obs, 0, "scroll reset on peer change");

    // And after peer change the cap is back to 0 -- no scroll possible.
    for (int i = 0; i < 5; i++) send_cmd(su);
    CHECK_EQ((int)dut->scroll_offset_obs, 0,
             "peer change resets used_hist_rows => scroll no-op");
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

    // Bubble width = max sub-line length = 3 ("bye"). 2-row multi-line:
    // row 0 uses TOP sprites, row 1 uses BOT sprites (no MID).
    // bubble_left = 97 - 3 - 1 = 93; BR at 97 for every row.
    int row0 = HIST_ROW_START;
    CHECK_EQ(read_cell(row0, 93), (uint8_t)SPRITE_BL_TOP, "row0 TOP-left border");
    CHECK_EQ(read_cell(row0, 94), 'h', "row0 'h'");
    CHECK_EQ(read_cell(row0, 95), 'i', "row0 'i'");
    CHECK_EQ(read_cell(row0, 96), ' ', "row0 padding");
    CHECK_EQ(read_cell(row0, 97), (uint8_t)SPRITE_BR_TOP, "row0 TOP-right border");

    int row1 = HIST_ROW_START + 1;
    CHECK_EQ(read_cell(row1, 93), (uint8_t)SPRITE_BL_BOT, "row1 BOT-left border");
    CHECK_EQ(read_cell(row1, 94), 'b', "row1 'b'");
    CHECK_EQ(read_cell(row1, 95), 'y', "row1 'y'");
    CHECK_EQ(read_cell(row1, 96), 'e', "row1 'e'");
    CHECK_EQ(read_cell(row1, 97), (uint8_t)SPRITE_BR_BOT, "row1 BOT-right border");

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

    // Fresh state, starts at ring slot 0. 2-row multi-line bubble: TOP
    // and BOT variants, no MID.
    int row0 = HIST_ROW_START;
    CHECK_EQ(read_cell(row0, 2), (uint8_t)SPRITE_BL_TOP, "row0 TOP-left");
    CHECK_EQ(read_cell(row0, 3), 'a', "row0 'a'");
    CHECK_EQ(read_cell(row0, 4), 'b', "row0 'b'");
    CHECK_EQ(read_cell(row0, 5), (uint8_t)SPRITE_BR_TOP, "row0 TOP-right");

    int row1 = HIST_ROW_START + 1;
    CHECK_EQ(read_cell(row1, 2), (uint8_t)SPRITE_BL_BOT, "row1 BOT-left");
    CHECK_EQ(read_cell(row1, 3), 'c', "row1 'c'");
    CHECK_EQ(read_cell(row1, 4), 'd', "row1 'd'");
    CHECK_EQ(read_cell(row1, 5), (uint8_t)SPRITE_BR_BOT, "row1 BOT-right");
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

    // Line 0 "xy" right-aligned: BL_TOP@94, x@95, y@96, BR_TOP@97
    int row0 = HIST_ROW_START;
    CHECK_EQ(read_cell(row0, 94), (uint8_t)SPRITE_BL_TOP, "pre-update row0 BL_TOP");
    CHECK_EQ(read_cell(row0, 97), (uint8_t)SPRITE_BR_TOP, "pre-update row0 BR_TOP");

    // Update status to FAIL. Multi-line fail keeps the same TOP/BOT
    // rounded sprites; the X mark (drawn at bubble_left - 1 on row 0)
    // is the fail signal.
    RenderCmd u;
    u.cmd = RENDER_UPDATE_STATUS; u.msg_id = 0;
    u.status = MSG_FAIL;
    send_cmd(u);

    // Bubble width = max sub-line length = 2 ("xy"). All rows use that
    // width: row 0 "xy" fills it, row 1 "z" gets one trailing space.
    // bubble_left = 97 - 2 - 1 = 94; BR at 97 for every row.
    // X mark at col bubble_left - 1 = 93 on row 0 only.
    CHECK_EQ(read_cell(row0, 93), (uint8_t)SPRITE_FAIL_X,
             "row0 X mark left of fail bubble");
    CHECK_EQ(read_cell(row0, 94), (uint8_t)SPRITE_BL_TOP, "row0 BL_TOP after fail");
    CHECK_EQ(read_cell(row0, 95), 'x', "row0 x after fail");
    CHECK_EQ(read_cell(row0, 96), 'y', "row0 y after fail");
    CHECK_EQ(read_cell(row0, 97), (uint8_t)SPRITE_BR_TOP, "row0 BR_TOP after fail");
    int row1 = HIST_ROW_START + 1;
    CHECK_EQ(read_cell(row1, 93), ' ',                    "row1 no X (only row0)");
    CHECK_EQ(read_cell(row1, 94), (uint8_t)SPRITE_BL_BOT, "row1 BL_BOT after fail");
    CHECK_EQ(read_cell(row1, 95), 'z', "row1 z after fail");
    CHECK_EQ(read_cell(row1, 96), ' ', "row1 padding after fail");
    CHECK_EQ(read_cell(row1, 97), (uint8_t)SPRITE_BR_BOT, "row1 BR_BOT after fail");
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

    // Line 0 "a" right-aligned at row 65: BL_TOP@95, 'a'@96, BR_TOP@97.
    CHECK_EQ(read_cell(65, 95), (uint8_t)SPRITE_BL_TOP, "row65 BL_TOP");
    CHECK_EQ(read_cell(65, 96), 'a',                    "row65 'a'");
    CHECK_EQ(read_cell(65, 97), (uint8_t)SPRITE_BR_TOP, "row65 BR_TOP");

    // Line 1 "b" MUST wrap to row 2 (HIST_ROW_START + 0).
    CHECK_EQ(read_cell(2, 95), (uint8_t)SPRITE_BL_BOT, "wrap row2 BL_BOT");
    CHECK_EQ(read_cell(2, 96), 'b',                    "wrap row2 'b'");
    CHECK_EQ(read_cell(2, 97), (uint8_t)SPRITE_BR_BOT, "wrap row2 BR_BOT");

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

    // Bubble width = max sub-line length = 5 (the final merged line
    // "x\ny\nz"). Every row shares that width, so the single-char
    // rows get 4 columns of trailing padding before BR.
    // Multi-line: row 0 uses TOP, middle rows use MID, last row uses BOT.
    // Remote left-aligned: bubble at cols 2..8.
    for (int i = 0; i < MAX_LINES - 1; i++) {
        int row = HIST_ROW_START + i;
        char lbl[40];
        snprintf(lbl, sizeof(lbl), "row %d L-border", i);
        uint8_t expL = (i == 0) ? SPRITE_BL_TOP : SPRITE_BL_MID;
        CHECK_EQ(read_cell(row, 2), expL, lbl);
        snprintf(lbl, sizeof(lbl), "row %d char", i);
        CHECK_EQ(read_cell(row, 3), (uint8_t)('a' + i), lbl);
        snprintf(lbl, sizeof(lbl), "row %d padding", i);
        CHECK_EQ(read_cell(row, 5), ' ', lbl);
        snprintf(lbl, sizeof(lbl), "row %d R-border", i);
        uint8_t expR = (i == 0) ? SPRITE_BR_TOP : SPRITE_BR_MID;
        CHECK_EQ(read_cell(row, 8), expR, lbl);
    }

    // Row MAX_LINES-1 absorbs "<a+M-1>\n<a+M>\n<a+M+1>" -- 5 bytes
    // (full bubble width). This is the BOT row of the bubble.
    int row_last = HIST_ROW_START + MAX_LINES - 1;
    CHECK_EQ(read_cell(row_last, 2), (uint8_t)SPRITE_BL_BOT, "row_last BL_BOT");
    CHECK_EQ(read_cell(row_last, 3), (uint8_t)('a' + MAX_LINES - 1), "row_last [0]");
    CHECK_EQ(read_cell(row_last, 4), 0x0A,                            "row_last [1]");
    CHECK_EQ(read_cell(row_last, 5), (uint8_t)('a' + MAX_LINES),     "row_last [2]");
    CHECK_EQ(read_cell(row_last, 6), 0x0A,                            "row_last [3]");
    CHECK_EQ(read_cell(row_last, 7), (uint8_t)('a' + MAX_LINES + 1), "row_last [4]");
    CHECK_EQ(read_cell(row_last, 8), (uint8_t)SPRITE_BR_BOT, "row_last BR_BOT");

    // Row MAX_LINES is unwritten (no overflow).
    int row_off = HIST_ROW_START + MAX_LINES;
    CHECK_EQ(read_cell(row_off, 2), ' ', "row past cap col2 space");
    CHECK_EQ(read_cell(row_off, 3), ' ', "row past cap col3 space");
    CHECK_EQ(read_cell(row_off, 4), ' ', "row past cap col4 space");

    // Ring head moved exactly MAX_LINES from 0.
    CHECK_EQ(dut->hist_wr_row_obs, MAX_LINES, "hist_wr_row advanced by MAX_LINES");
}

// P4: A long single-line message (no \n) gets soft-wrapped onto
// multiple visual rows of the same bubble. With MAX_BUBBLE_INNER_W=80
// a 100-char message wraps to row0 (80 bytes) + row1 (20 bytes, padded
// to 80). All rows share the same width so borders line up vertically.
static void test_bubble_soft_wrap_long_line() {
    printf("== test_bubble_soft_wrap_long_line\n");
    reset();
    bring_up();
    const int MAX_W   = 80;
    const int L       = 100;
    std::vector<uint8_t> msg(L);
    for (int i = 0; i < L; i++) msg[i] = (uint8_t)('A' + (i % 26));

    RenderCmd c;
    c.cmd = RENDER_APPEND_REMOTE; c.msg_id = 51;
    c.side = MSG_REMOTE; c.status = MSG_SUCCESS;
    c.payload = msg.data(); c.payload_n = (size_t)L; c.len = (uint16_t)L;
    send_cmd(c);

    // Bubble inner width = MAX_W = 80. Remote: borders at col 2 (TOP/BOT)
    // and col 83, content cols 3..82. 2-row multi-line: row 0 uses TOP,
    // row 1 uses BOT.
    int row0 = HIST_ROW_START;
    int row1 = HIST_ROW_START + 1;
    CHECK_EQ(read_cell(row0, 2),  (uint8_t)SPRITE_BL_TOP, "wrap row0 BL_TOP");
    CHECK_EQ(read_cell(row0, 3),  msg[0],                 "wrap row0 first byte");
    CHECK_EQ(read_cell(row0, 82), msg[79],                "wrap row0 last byte");
    CHECK_EQ(read_cell(row0, 83), (uint8_t)SPRITE_BR_TOP, "wrap row0 BR_TOP");

    CHECK_EQ(read_cell(row1, 2),  (uint8_t)SPRITE_BL_BOT, "wrap row1 BL_BOT");
    CHECK_EQ(read_cell(row1, 3),  msg[80],                "wrap row1 first byte");
    CHECK_EQ(read_cell(row1, 22), msg[99],                "wrap row1 last data byte");
    CHECK_EQ(read_cell(row1, 23), ' ',                    "wrap row1 first padding");
    CHECK_EQ(read_cell(row1, 82), ' ',                    "wrap row1 padding before BR");
    CHECK_EQ(read_cell(row1, 83), (uint8_t)SPRITE_BR_BOT, "wrap row1 BR_BOT");

    // hist_wr_row advanced by 2 visual rows.
    CHECK_EQ(dut->hist_wr_row_obs, 2, "wrap advances head by 2");
}

// P4: Multi-line short messages have one continuous bubble (left/right
// borders line up across rows) because every row uses the max sub-line
// length, padded with spaces.
static void test_bubble_multiline_aligned() {
    printf("== test_bubble_multiline_aligned\n");
    reset();
    bring_up();
    // 3 lines: "ab", "wxyz", "c".  max sub-len = 4.
    uint8_t msg[] = {'a','b', 0x0A, 'w','x','y','z', 0x0A, 'c'};
    RenderCmd c;
    c.cmd = RENDER_APPEND_LOCAL_PENDING; c.msg_id = 99;
    c.side = MSG_LOCAL; c.status = MSG_PENDING;
    c.payload = msg; c.payload_n = sizeof(msg); c.len = (uint16_t)sizeof(msg);
    send_cmd(c);

    // Local right-aligned: bubble_right=97, width=4 -> bubble_left=92.
    // 3-row bubble: row 0 = TOP, row 1 = MID, row 2 = BOT.
    int row0 = HIST_ROW_START;
    int row1 = HIST_ROW_START + 1;
    int row2 = HIST_ROW_START + 2;
    CHECK_EQ(read_cell(row0, 92), (uint8_t)SPRITE_BL_TOP, "row0 BL_TOP");
    CHECK_EQ(read_cell(row0, 93), 'a',                    "row0 'a'");
    CHECK_EQ(read_cell(row0, 94), 'b',                    "row0 'b'");
    CHECK_EQ(read_cell(row0, 95), ' ',                    "row0 pad1");
    CHECK_EQ(read_cell(row0, 96), ' ',                    "row0 pad2");
    CHECK_EQ(read_cell(row0, 97), (uint8_t)SPRITE_BR_TOP, "row0 BR_TOP");

    CHECK_EQ(read_cell(row1, 92), (uint8_t)SPRITE_BL_MID, "row1 BL_MID");
    CHECK_EQ(read_cell(row1, 93), 'w',                    "row1 'w'");
    CHECK_EQ(read_cell(row1, 96), 'z',                    "row1 'z'");
    CHECK_EQ(read_cell(row1, 97), (uint8_t)SPRITE_BR_MID, "row1 BR_MID");

    CHECK_EQ(read_cell(row2, 92), (uint8_t)SPRITE_BL_BOT, "row2 BL_BOT");
    CHECK_EQ(read_cell(row2, 93), 'c',                    "row2 'c'");
    CHECK_EQ(read_cell(row2, 94), ' ',                    "row2 pad1");
    CHECK_EQ(read_cell(row2, 96), ' ',                    "row2 pad3");
    CHECK_EQ(read_cell(row2, 97), (uint8_t)SPRITE_BR_BOT, "row2 BR_BOT");
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

    // Row 0 of the input region: "> ab" then blanks. The newline byte
    // is a layout control and is not painted into the input box.
    CHECK_EQ(read_cell(INPUT_ROW_START,    0), '>',  "row0 col0 prompt");
    CHECK_EQ(read_cell(INPUT_ROW_START,    1), ' ',  "row0 col1 prompt space");
    CHECK_EQ(read_cell(INPUT_ROW_START,    2), 'a',  "row0 col2 'a'");
    CHECK_EQ(read_cell(INPUT_ROW_START,    3), 'b',  "row0 col3 'b'");
    CHECK_EQ(read_cell(INPUT_ROW_START,    4), ' ',  "row0 col4 blank past line");
    CHECK_EQ(read_cell(INPUT_ROW_START,    5), ' ',  "row0 col5 blank past NL");

    // Row 1: "cd" starting at col 0 (no prefix). Last line, no ↵.
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

static void test_delete_space_at_cursor() {
    printf("== test_delete_space_at_cursor\n");
    reset();
    bring_up();

    const char buf[] = "ewdhbgw  hidsd";
    type_chars(buf, sizeof(buf) - 1);

    RenderCmd mv;
    mv.cmd = RENDER_MOVE_CURSOR;
    mv.cursor_pos = 9;  // right after the second space
    send_cmd(mv);

    RenderCmd dc;
    dc.cmd = RENDER_DELETE_AT_CURSOR;
    dc.cursor_pos = 8;  // post-edit cursor after deleting one space
    send_cmd(dc);

    const char expect[] = "> ewdhbgw hidsd ";
    for (int i = 0; i < (int)sizeof(expect) - 1; i++) {
        char lbl[48]; snprintf(lbl, sizeof(lbl), "space-delete col %d", i);
        CHECK_EQ(read_cell(INPUT_ROW_START, i), (uint8_t)expect[i], lbl);
    }
    CHECK_EQ((int)dut->input_len_obs, 13, "input_len after deleting one space");
    CHECK_EQ((int)dut->input_cursor_obs, 8, "cursor after deleting one space");
}

static void test_delete_in_multiline_middle_row() {
    printf("== test_delete_in_multiline_middle_row\n");
    reset();
    bring_up();

    // Five visual lines: "aa\nbb\ncc\ndd\nee". Put the cursor after the
    // first 'd' on row 3, then backspace. Only that 'd' should disappear.
    const char buf[] = {'a','a',0x0A,'b','b',0x0A,'c','c',0x0A,
                        'd','d',0x0A,'e','e'};
    type_chars(buf, sizeof(buf));

    RenderCmd mv;
    mv.cmd = RENDER_MOVE_CURSOR;
    mv.cursor_pos = 10;  // row 3, col 1 (after first 'd')
    send_cmd(mv);
    CHECK_EQ((int)dut->input_cursor_row_obs, 3, "cursor on fourth row before delete");
    CHECK_EQ((int)dut->input_cursor_col_obs, 1, "cursor after first d before delete");

    RenderCmd dc;
    dc.cmd = RENDER_DELETE_AT_CURSOR;
    dc.cursor_pos = 9;
    send_cmd(dc);

    CHECK_EQ((int)dut->input_len_obs, 13, "input_len after multiline delete");
    CHECK_EQ((int)dut->input_cursor_row_obs, 3, "cursor stays on fourth row");
    CHECK_EQ((int)dut->input_cursor_col_obs, 0, "cursor at row start after delete");

    CHECK_EQ(read_cell(INPUT_ROW_START,   2), 'a', "row0 a0");
    CHECK_EQ(read_cell(INPUT_ROW_START,   3), 'a', "row0 a1");
    CHECK_EQ(read_cell(INPUT_ROW_START+1, 0), 'b', "row1 b0");
    CHECK_EQ(read_cell(INPUT_ROW_START+1, 1), 'b', "row1 b1");
    CHECK_EQ(read_cell(INPUT_ROW_START+2, 0), 'c', "row2 c0");
    CHECK_EQ(read_cell(INPUT_ROW_START+2, 1), 'c', "row2 c1");
    CHECK_EQ(read_cell(INPUT_ROW_START+3, 0), 'd', "row3 only remaining d");
    CHECK_EQ(read_cell(INPUT_ROW_START+3, 1), ' ', "row3 col1 blank after delete");
    CHECK_EQ(read_cell(INPUT_ROW_START+4, 0), 'e', "row4 e0");
    CHECK_EQ(read_cell(INPUT_ROW_START+4, 1), 'e', "row4 e1");
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

    // Manually scroll down (toward later/bottom lines) via Shift+Down,
    // then move cursor: the cursor move overrides the manual scroll.
    RenderCmd sd; sd.cmd = RENDER_INPUT_SCROLL_DOWN;
    send_cmd(sd); send_cmd(sd);  // offset = 2 explicitly
    CHECK_EQ((int)dut->input_scroll_offset_obs, 2, "manual scroll to 2");
    mv.cursor_pos = (uint16_t)buf.size();  // cursor back to row 6
    send_cmd(mv);
    CHECK_EQ((int)dut->input_scroll_offset_obs, 6 - N_INPUT_VISIBLE + 1,
             "manual scroll overridden by auto-follow");
}

// RENDER_INPUT_SCROLL_UP / DOWN nudge the input window without
// repainting the input region; clamps at [0, input_n_lines -
// N_INPUT_VISIBLE], i.e. the cap follows actual typed line count.
static void test_input_scroll_clamps() {
    printf("== test_input_scroll_clamps\n");
    reset();
    bring_up();

    CHECK_EQ((int)dut->input_scroll_offset_obs, 0, "input scroll starts at 0");

    // Type 9 newline-separated short lines so input_n_lines = 9.
    // Dynamic cap = 9 - N_INPUT_VISIBLE(5) = 4 -- room for 3 ticks.
    for (int i = 0; i < 9; i++) {
        if (i > 0) {
            RenderCmd ic;
            ic.cmd = RENDER_INSERT_AT_CURSOR;
            ic.cursor_pos = (uint16_t)(2 * i);  // logical pos after this byte
            ic.ascii = 0x0A;
            send_cmd(ic);
        }
        RenderCmd ic;
        ic.cmd = RENDER_INSERT_AT_CURSOR;
        ic.cursor_pos = (uint16_t)(2 * i + 1);
        ic.ascii = (uint8_t)('a' + i);
        send_cmd(ic);
    }

    // Cursor is at last typed char on row 8, so auto-follow already
    // pushed input_scroll_offset to 8 - (N_INPUT_VISIBLE-1) = 4.
    CHECK_EQ((int)dut->input_scroll_offset_obs, 4,
             "auto-follow snapped scroll to keep cursor visible");

    // Shift+Up scrolls toward earlier (top) input lines, i.e. decrements
    // offset (smaller offset shows lines closer to the start of buf).
    RenderCmd su; su.cmd = RENDER_INPUT_SCROLL_UP;
    for (int i = 0; i < 6; i++) send_cmd(su);
    CHECK_EQ((int)dut->input_scroll_offset_obs, 0, "scroll up clamps at 0");

    // Shift+Down scrolls back toward later (bottom) input lines.
    // Cap = 9 lines - N_INPUT_VISIBLE(5) = 4.
    RenderCmd sd; sd.cmd = RENDER_INPUT_SCROLL_DOWN;
    send_cmd(sd); send_cmd(sd); send_cmd(sd);
    CHECK_EQ((int)dut->input_scroll_offset_obs, 3, "scroll down 3 ticks");

    for (int i = 0; i < 10; i++) send_cmd(sd);
    CHECK_EQ((int)dut->input_scroll_offset_obs, 4,
             "scroll down clamps at input_n_lines - N_INPUT_VISIBLE");
}

// P5.1 input area soft-wrap: typing a long line with no 0x0A wraps
// to the next visual row at INPUT_SOFT_WRAP_W (= 96 content bytes,
// aligned with BUBBLE_RIGHT_EDGE so the input's right edge matches
// what the bubble will look like on Enter). Row 0 keeps the "> "
// prefix (cols 2..97 hold 96 typed bytes); continuation rows have
// no prefix and start at col 0.
static void test_input_soft_wrap_long_line() {
    printf("== test_input_soft_wrap_long_line\n");
    reset();
    bring_up();

    // Type 100 'a' bytes. INPUT_SOFT_WRAP_W = 96 -> visual row 0
    // holds 96 'a's at cols 2..97, visual row 1 holds 4 'a's.
    const int L = 100;
    const int W = 96;
    for (int i = 0; i < L; i++) {
        RenderCmd ic;
        ic.cmd        = RENDER_INSERT_AT_CURSOR;
        ic.cursor_pos = (uint16_t)(i + 1);
        ic.ascii      = 'a';
        send_cmd(ic);
    }

    CHECK_EQ((int)dut->input_len_obs, L, "input_len after typing");
    // Cursor at end-of-buffer (pos=L) -> visual (row=1, col=L-W=4).
    CHECK_EQ((int)dut->input_cursor_row_obs, 1, "cursor on continuation row");
    CHECK_EQ((int)dut->input_cursor_col_obs, L - W,
             "cursor col = L - INPUT_SOFT_WRAP_W");

    // Row 0 of the input region: "> " prefix at cols 0..1, then 96
    // 'a's at cols 2..97, blanks past col 97.
    CHECK_EQ(read_cell(INPUT_ROW_START,    0), '>',  "row0 col0 prompt");
    CHECK_EQ(read_cell(INPUT_ROW_START,    1), ' ',  "row0 col1 space");
    CHECK_EQ(read_cell(INPUT_ROW_START,    2), 'a',  "row0 col2 first 'a'");
    CHECK_EQ(read_cell(INPUT_ROW_START,   97), 'a',  "row0 col97 last 'a'");
    CHECK_EQ(read_cell(INPUT_ROW_START,   98), ' ',  "row0 col98 blank past wrap");

    // Row 1 of the input region: 4 'a's at cols 0..3, blanks afterwards.
    CHECK_EQ(read_cell(INPUT_ROW_START+1,  0), 'a',  "row1 col0 wrap 'a'");
    CHECK_EQ(read_cell(INPUT_ROW_START+1,  3), 'a',  "row1 col3 last 'a'");
    CHECK_EQ(read_cell(INPUT_ROW_START+1,  4), ' ',  "row1 col4 blank past end");

    // Row 2 is past n_lines = 2: blank.
    CHECK_EQ(read_cell(INPUT_ROW_START+2,  0), ' ',  "row2 col0 blank");
}

// P5.1 input area soft-wrap with mid-line cursor. After typing 100
// chars (wraps at INPUT_SOFT_WRAP_W = 96), move the cursor to
// position 96 (just past byte 95, which was the wrap byte). That
// puts the cursor at row 1 col 0.
static void test_input_soft_wrap_cursor_pre_wrap() {
    printf("== test_input_soft_wrap_cursor_pre_wrap\n");
    reset();
    bring_up();

    const int L = 100;
    const int W = 96;
    for (int i = 0; i < L; i++) {
        RenderCmd ic;
        ic.cmd        = RENDER_INSERT_AT_CURSOR;
        ic.cursor_pos = (uint16_t)(i + 1);
        ic.ascii      = 'a';
        send_cmd(ic);
    }

    // Cursor at pos=W -> first character of continuation row.
    RenderCmd mv;
    mv.cmd        = RENDER_MOVE_CURSOR;
    mv.cursor_pos = (uint16_t)W;
    send_cmd(mv);
    CHECK_EQ((int)dut->input_cursor_row_obs, 1, "cursor_pos=W row=1");
    CHECK_EQ((int)dut->input_cursor_col_obs, 0, "cursor_pos=W col=0");

    // Cursor at pos=W-1 -> last cell of first visual row (logical col
    // 95; rendered with prefix offset = screen col 97).
    mv.cursor_pos = (uint16_t)(W - 1);
    send_cmd(mv);
    CHECK_EQ((int)dut->input_cursor_row_obs, 0, "cursor_pos=W-1 row=0");
    CHECK_EQ((int)dut->input_cursor_col_obs, W - 1, "cursor_pos=W-1 col=W-1");
}

// Newline bytes in the input box should only split visual rows; they
// should not render a visible return-arrow marker.
static void test_input_newline_marker_hidden_at_end_of_line() {
    printf("== test_input_newline_marker_hidden_at_end_of_line\n");
    reset();
    bring_up();
    // "ab\nc\nd"
    const uint8_t typed[] = {'a','b',0x0A,'c',0x0A,'d'};
    for (int i = 0; i < 6; i++) {
        RenderCmd ic;
        ic.cmd = RENDER_INSERT_AT_CURSOR;
        ic.cursor_pos = (uint16_t)(i + 1);
        ic.ascii = typed[i];
        send_cmd(ic);
    }

    // Row 0: "> ab", blank at col 4 where the marker used to be.
    CHECK_EQ(read_cell(INPUT_ROW_START,   2), 'a',  "row0 'a'");
    CHECK_EQ(read_cell(INPUT_ROW_START,   3), 'b',  "row0 'b'");
    CHECK_EQ(read_cell(INPUT_ROW_START,   4), ' ',  "row0 no NL marker at col 4");

    // Row 1: "c", blank at col 1 where the marker used to be.
    CHECK_EQ(read_cell(INPUT_ROW_START+1, 0), 'c',  "row1 'c'");
    CHECK_EQ(read_cell(INPUT_ROW_START+1, 1), ' ',  "row1 no NL marker at col 1");

    // Row 2: "d", no ↵ (last open line).
    CHECK_EQ(read_cell(INPUT_ROW_START+2, 0), 'd',  "row2 'd'");
    CHECK_EQ(read_cell(INPUT_ROW_START+2, 1), ' ',  "row2 col1 no NL glyph");
}

static void test_input_newline_marker_hidden_empty_line() {
    printf("== test_input_newline_marker_hidden_empty_line\n");
    reset();
    bring_up();
    RenderCmd ic;
    ic.cmd = RENDER_INSERT_AT_CURSOR;
    ic.cursor_pos = 1;
    ic.ascii = 0x0A;
    send_cmd(ic);

    // Row 0: "> " followed by blanks; the newline marker is hidden.
    CHECK_EQ(read_cell(INPUT_ROW_START,   2), ' ',  "row0 no NL marker at col 2");
    CHECK_EQ(read_cell(INPUT_ROW_START,   3), ' ',  "row0 col3 blank");

    // Row 1: empty (no ↵).
    CHECK_EQ(read_cell(INPUT_ROW_START+1, 0), ' ',  "row1 col0 blank");
}

// P5.3 -- a row closed by soft-wrap (not \n) gets NO ↵; only newline-
// terminated rows do. Type W+1 'a's so row 0 fills via soft-wrap and
// row 1 has 1 byte.
static void test_input_no_nl_glyph_on_soft_wrap() {
    printf("== test_input_no_nl_glyph_on_soft_wrap\n");
    reset();
    bring_up();
    const int W = 96;
    for (int i = 0; i < W + 1; i++) {
        RenderCmd ic;
        ic.cmd = RENDER_INSERT_AT_CURSOR;
        ic.cursor_pos = (uint16_t)(i + 1);
        ic.ascii = 'a';
        send_cmd(ic);
    }

    // Row 0 ends at col 1+W=97. The cell right after (col 98) is blank,
    // NOT a ↵ -- soft-wrapped rows don't get the newline glyph.
    CHECK_EQ(read_cell(INPUT_ROW_START,   97), 'a', "row0 col97 last wrap byte");
    CHECK_EQ(read_cell(INPUT_ROW_START,   98), ' ', "row0 col98 no NL glyph after wrap");
    CHECK_EQ(read_cell(INPUT_ROW_START+1, 0),  'a', "row1 col0 wrap continuation");
    CHECK_EQ(read_cell(INPUT_ROW_START+1, 1),  ' ', "row1 col1 blank past content");
}

// Regression: a remote bubble whose len == MAX_MSG_LEN (== 128) used
// to truncate to 1 byte stored (msg_total_len_q[MSG_BYTE_IDX_W-1:0]
// was 0 for len=128), so the bubble rendered as one cell instead of
// the full multi-line wrap. Now the full payload is stored and the
// bubble soft-wraps at MAX_BUBBLE_INNER_W (= 80).
static void test_remote_max_len_message() {
    printf("== test_remote_max_len_message\n");
    reset();
    bring_up();
    const int L = 128;  // == MAX_MSG_LEN
    std::vector<uint8_t> msg(L);
    for (int i = 0; i < L; i++) msg[i] = (uint8_t)('A' + (i % 26));

    RenderCmd c;
    c.cmd = RENDER_APPEND_REMOTE; c.msg_id = 77;
    c.side = MSG_REMOTE; c.status = MSG_SUCCESS;
    c.payload = msg.data(); c.payload_n = (size_t)L; c.len = (uint16_t)L;
    send_cmd(c);

    // 128 bytes soft-wrap into 80 + 48. Remote left-aligned: bubble at
    // cols 2 (TOP/BOT) and 83. Row 0 holds bytes 0..79, row 1 bytes 80..127.
    int row0 = HIST_ROW_START;
    int row1 = HIST_ROW_START + 1;
    CHECK_EQ(read_cell(row0, 2),  (uint8_t)SPRITE_BL_TOP, "max-len row0 BL_TOP");
    CHECK_EQ(read_cell(row0, 3),  msg[0],                 "max-len row0 first byte");
    CHECK_EQ(read_cell(row0, 82), msg[79],                "max-len row0 last byte");
    CHECK_EQ(read_cell(row0, 83), (uint8_t)SPRITE_BR_TOP, "max-len row0 BR_TOP");

    CHECK_EQ(read_cell(row1, 2),  (uint8_t)SPRITE_BL_BOT, "max-len row1 BL_BOT");
    CHECK_EQ(read_cell(row1, 3),  msg[80],                "max-len row1 first byte");
    CHECK_EQ(read_cell(row1, 50), msg[127],               "max-len row1 last byte");
    CHECK_EQ(read_cell(row1, 83), (uint8_t)SPRITE_BR_BOT, "max-len row1 BR_BOT");

    CHECK_EQ(dut->hist_wr_row_obs, 2, "max-len advances head by 2");
}

// Regression: same MAX_MSG_LEN bug on the LOCAL append path. Without
// the fix the bubble would collapse to one cell at bubble_right == 97.
static void test_local_max_len_message() {
    printf("== test_local_max_len_message\n");
    reset();
    bring_up();
    const int L = 128;
    std::vector<uint8_t> msg(L);
    for (int i = 0; i < L; i++) msg[i] = (uint8_t)('a' + (i % 26));

    RenderCmd c;
    c.cmd = RENDER_APPEND_LOCAL_PENDING; c.msg_id = 78;
    c.side = MSG_LOCAL; c.status = MSG_PENDING;
    c.payload = msg.data(); c.payload_n = (size_t)L; c.len = (uint16_t)L;
    send_cmd(c);

    // Local right-aligned: bubble_right=97, max sub-line len=80,
    // bubble_left = 97 - 80 - 1 = 16. Row 0 = bytes 0..79, row 1 = 80..127.
    int row0 = HIST_ROW_START;
    int row1 = HIST_ROW_START + 1;
    CHECK_EQ(read_cell(row0, 16), (uint8_t)SPRITE_BL_TOP, "max-len local row0 BL_TOP");
    CHECK_EQ(read_cell(row0, 17), msg[0],                 "max-len local row0 first byte");
    CHECK_EQ(read_cell(row0, 96), msg[79],                "max-len local row0 last byte");
    CHECK_EQ(read_cell(row0, 97), (uint8_t)SPRITE_BR_TOP, "max-len local row0 BR_TOP");

    CHECK_EQ(read_cell(row1, 16), (uint8_t)SPRITE_BL_BOT, "max-len local row1 BL_BOT");
    CHECK_EQ(read_cell(row1, 17), msg[80],                "max-len local row1 first byte");
    CHECK_EQ(read_cell(row1, 64), msg[127],               "max-len local row1 last byte");
    CHECK_EQ(read_cell(row1, 97), (uint8_t)SPRITE_BR_BOT, "max-len local row1 BR_BOT");

    CHECK_EQ(dut->hist_wr_row_obs, 2, "max-len local advances head by 2");
}

// Regression for issue 1.2: typing exactly INPUT_SOFT_WRAP_W (= 96)
// chars used to leave the cursor at logical col 96, which would
// render off the visible screen. Now the line wraps at the boundary
// so the cursor lands on a new empty row 1 at col 0.
static void test_input_soft_wrap_at_boundary() {
    printf("== test_input_soft_wrap_at_boundary\n");
    reset();
    bring_up();
    const int L = 96;  // == INPUT_SOFT_WRAP_W
    for (int i = 0; i < L; i++) {
        RenderCmd ic;
        ic.cmd        = RENDER_INSERT_AT_CURSOR;
        ic.cursor_pos = (uint16_t)(i + 1);
        ic.ascii      = 'a';
        send_cmd(ic);
    }

    CHECK_EQ((int)dut->input_len_obs, L, "input_len after typing");
    CHECK_EQ((int)dut->input_cursor_row_obs, 1, "cursor wraps to row 1");
    CHECK_EQ((int)dut->input_cursor_col_obs, 0, "cursor at row 1 col 0");

    // Row 0 has the full 96 'a's at cols 2..97; row 1 is empty.
    CHECK_EQ(read_cell(INPUT_ROW_START,    2), 'a', "row0 col2 first 'a'");
    CHECK_EQ(read_cell(INPUT_ROW_START,   97), 'a', "row0 col97 last 'a'");
    CHECK_EQ(read_cell(INPUT_ROW_START,   98), ' ', "row0 col98 blank past wrap");
    CHECK_EQ(read_cell(INPUT_ROW_START+1,  0), ' ', "row1 col0 blank");
}

// P5.3 -- a failed local message gets an explicit X mark to the left
// of the bubble's BL on the first visual row (in addition to the
// square FBL/FBR border sprites it already has).
static void test_local_fail_x_mark() {
    printf("== test_local_fail_x_mark\n");
    reset();
    bring_up();
    const uint8_t msg[] = {'h','i'};

    // Append local pending, then mark fail.
    RenderCmd c;
    c.cmd = RENDER_APPEND_LOCAL_PENDING; c.msg_id = 7;
    c.side = MSG_LOCAL; c.status = MSG_PENDING;
    c.payload = msg; c.payload_n = 2; c.len = 2;
    send_cmd(c);

    RenderCmd us;
    us.cmd = RENDER_UPDATE_STATUS; us.msg_id = 7;
    us.status = MSG_FAIL;
    send_cmd(us);

    // Local right-aligned: bubble_right=97, len=2 -> bubble_left=94.
    // FBL at col 94, FBR at col 97. X mark at col 93.
    int row = HIST_ROW_START;
    CHECK_EQ(read_cell(row, 93), (uint8_t)SPRITE_FAIL_X, "X mark left of fail bubble");
    CHECK_EQ(read_cell(row, 94), (uint8_t)SPRITE_FBL,    "FBL at bubble left");
    CHECK_EQ(read_cell(row, 95), 'h',                    "row col95 'h'");
    CHECK_EQ(read_cell(row, 96), 'i',                    "row col96 'i'");
    CHECK_EQ(read_cell(row, 97), (uint8_t)SPRITE_FBR,    "FBR at bubble right");
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

    // Each row N: remote bubble border@2, payload@3..2+LINE_W, border@3+LINE_W.
    // Multi-line: row 0 = TOP, rows 1..N-2 = MID, row N-1 = BOT.
    for (int ln = 0; ln < N_LINES; ln++) {
        int row = HIST_ROW_START + ln;
        char lbl[40];
        uint8_t expL = (ln == 0) ? SPRITE_BL_TOP
                       : (ln == N_LINES - 1) ? SPRITE_BL_BOT
                       : SPRITE_BL_MID;
        uint8_t expR = (ln == 0) ? SPRITE_BR_TOP
                       : (ln == N_LINES - 1) ? SPRITE_BR_BOT
                       : SPRITE_BR_MID;
        snprintf(lbl, sizeof(lbl), "long row %d L-border", ln);
        CHECK_EQ(read_cell(row, 2),  expL, lbl);
        snprintf(lbl, sizeof(lbl), "long row %d first", ln);
        CHECK_EQ(read_cell(row, 3),  (uint8_t)('a' + ln), lbl);
        snprintf(lbl, sizeof(lbl), "long row %d last", ln);
        CHECK_EQ(read_cell(row, 2 + LINE_W), (uint8_t)('a' + ln), lbl);
        snprintf(lbl, sizeof(lbl), "long row %d R-border", ln);
        CHECK_EQ(read_cell(row, 3 + LINE_W), expR, lbl);
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
    test_emoji_codes_render_in_bubble();
    test_big_emoji_bubble_layout_remote();
    test_big_emoji_bubble_layout_local();
    test_single_byte_non_anchor_stays_one_line();
    test_append_local_pending();
    test_update_status_success();
    test_update_status_fail();
    test_insert_at_cursor();
    test_delete_at_cursor();
    test_update_input_line_clear();
    test_move_cursor();
    test_peer_change_clears_hist();
    test_scroll_up_down();
    test_append_while_scrolled_locks_history_window();
    test_scroll_clamps_when_empty();
    test_scroll_cap_tracks_content();
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
    test_delete_space_at_cursor();
    test_delete_in_multiline_middle_row();
    test_cursor_auto_follow_scroll();
    test_bubble_soft_wrap_long_line();
    test_bubble_multiline_aligned();
    test_input_soft_wrap_long_line();
    test_input_soft_wrap_cursor_pre_wrap();
    test_input_newline_marker_hidden_at_end_of_line();
    test_input_newline_marker_hidden_empty_line();
    test_input_no_nl_glyph_on_soft_wrap();
    test_remote_max_len_message();
    test_local_max_len_message();
    test_input_soft_wrap_at_boundary();
    test_local_fail_x_mark();

    tfp->close();
    delete tfp;
    delete dut;

    if (g_failures == 0) { printf("\nPASS  (all checks)\n"); return 0; }
    printf("\nFAIL  %d check(s) failed\n", g_failures);
    return 1;
}
