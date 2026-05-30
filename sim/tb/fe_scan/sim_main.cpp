// =====================================================================
// sim_main.cpp  --  Tests for rtl/frontend/fe_scan.sv
// =====================================================================

#include "Vfe_scan.h"
#include "verilated.h"
#include <cstdint>
#include <cstdio>
#include <cstring>

static int g_failures = 0;
static Vfe_scan* dut = nullptr;

static constexpr uint8_t CONN_CONNECTED = 2;
static constexpr uint8_t BUBBLE_ATTR_NONE   = 0;
static constexpr uint8_t BUBBLE_ATTR_REMOTE = 1;
static constexpr uint8_t BUBBLE_ATTR_LOCAL  = 2;

static constexpr uint8_t REMOTE_R = 0x07;
static constexpr uint8_t REMOTE_G = 0x5E;
static constexpr uint8_t REMOTE_B = 0x54;
static constexpr uint8_t LOCAL_R  = 0x02;
static constexpr uint8_t LOCAL_G  = 0x28;
static constexpr uint8_t LOCAL_B  = 0x23;
static constexpr uint8_t FG_R = 0xFF;
static constexpr uint8_t FG_G = 0xFF;
static constexpr uint8_t FG_B = 0xFF;
static constexpr uint8_t POPUP_BG_R     = 0x18;
static constexpr uint8_t POPUP_BG_G     = 0x1C;
static constexpr uint8_t POPUP_BG_B     = 0x24;
static constexpr uint8_t POPUP_BORDER_R = 0xC8;
static constexpr uint8_t POPUP_BORDER_G = 0xD0;
static constexpr uint8_t POPUP_BORDER_B = 0xD8;
static constexpr uint8_t POPUP_HOVER_R  = 0x2B;
static constexpr uint8_t POPUP_HOVER_G  = 0x51;
static constexpr uint8_t POPUP_HOVER_B  = 0x7A;
static constexpr uint8_t POPUP_TEXT_R   = 0xF4;
static constexpr uint8_t POPUP_TEXT_G   = 0xF7;
static constexpr uint8_t POPUP_TEXT_B   = 0xFB;

static constexpr uint8_t POPUP_NONE = 0;
static constexpr uint8_t POPUP_MSG_MENU = 1;
static constexpr uint8_t POPUP_STICKER_PICKER = 2;

static constexpr int EMOJI_SUGGEST_X_PX = 16;
static constexpr int EMOJI_SUGGEST_Y_PX = 260;
static constexpr int EMOJI_SUGGEST_BORDER_PX = 2;
static constexpr int EMOJI_SUGGEST_TEXT_X_PX = 10;

static constexpr uint8_t SPRITE_BL = 0xF3;
static constexpr uint8_t SPRITE_BR = 0xF4;

static constexpr uint32_t BG_W_PX          = 800;
static constexpr uint32_t BG_H_PX          = 600;
static constexpr uint32_t AVATAR_W_PX      = 16;
static constexpr uint32_t AVATAR_H_PX      = 16;
static constexpr uint32_t LOCAL_BASE_WORD  = (BG_W_PX * BG_H_PX * 2) / 4;
static constexpr uint32_t REMOTE_BASE_WORD = LOCAL_BASE_WORD
                                           + (AVATAR_W_PX * AVATAR_H_PX * 2) / 4;

#define CHECK_EQ(actual, expected, label) do {                         \
    auto _a = (actual); auto _e = (expected);                          \
    if (_a != _e) {                                                    \
        ++g_failures;                                                  \
        printf("  [FAIL] %-34s got=0x%llx expected=0x%llx\n",          \
               (label),                                                \
               (unsigned long long)_a, (unsigned long long)_e);        \
    }                                                                  \
} while (0)

#define CHECK_NEQ(actual, unexpected, label) do {                      \
    auto _a = (actual); auto _u = (unexpected);                        \
    if (_a == _u) {                                                    \
        ++g_failures;                                                  \
        printf("  [FAIL] %-34s got=0x%llx (unexpected)\n",             \
               (label),                                                \
               (unsigned long long)_a);                                \
    }                                                                  \
} while (0)

static void tick() {
    dut->clk_pix = 0;
    dut->eval();
    dut->clk_pix = 1;
    dut->eval();
}

static void clear_avatar_attrs() {
    std::memset(&dut->hist_avatar_attr, 0, sizeof(dut->hist_avatar_attr));
}

static void set_avatar_attr(int slot, uint8_t attr) {
    auto* words = reinterpret_cast<uint32_t*>(&dut->hist_avatar_attr);
    int bit = slot * 2;
    words[bit / 32] |= (uint32_t)(attr & 0x3) << (bit % 32);
}

static void reset() {
    dut->rst_n = 0;
    dut->clk_pix = 0;
    dut->hdata = 0;
    dut->vdata = 0;
    dut->hsync = 0;
    dut->vsync = 0;
    dut->data_enable = 1;
    dut->rd_code = ' ';
    dut->rd_attr = BUBBLE_ATTR_NONE;
    dut->glyph_row = 0;
    dut->asset_sram_data = 0;
    dut->conn_state = CONN_CONNECTED;
    // Pick a ring head such that screen history row 2 maps to slot 0:
    // hist_slot = hist_wr_row + (64 - 29) + screen_offset.
    dut->hist_wr_row = 29;
    dut->scroll_offset = 0;
    dut->input_cursor_row = 0;
    dut->input_cursor_col = 0;
    dut->input_scroll_offset = 0;
    dut->mouse_x = 1023;
    dut->mouse_y = 1023;
    dut->popup_active = 0;
    dut->popup_type = POPUP_NONE;
    dut->popup_x = 0;
    dut->popup_y = 0;
    dut->emoji_suggest_active = 0;
    dut->emoji_suggest_count = 0;
    dut->emoji_suggest_ids = 0;
    clear_avatar_attrs();

    tick();
    dut->rst_n = 1;
    tick();
}

static void drive_visible_pixel(uint16_t h, uint16_t v, uint8_t attr) {
    dut->hdata = h;
    dut->vdata = v;
    dut->data_enable = 1;
    dut->rd_code = ' ';
    dut->rd_attr = attr;
    dut->glyph_row = 0;          // force a background pixel
    dut->asset_sram_data = 0;
    tick();
}

static void drive_visible_pixel(
    uint16_t h,
    uint16_t v,
    uint8_t attr,
    uint8_t code,
    uint8_t glyph_row
) {
    dut->hdata = h;
    dut->vdata = v;
    dut->data_enable = 1;
    dut->rd_code = code;
    dut->rd_attr = attr;
    dut->glyph_row = glyph_row;
    dut->asset_sram_data = 0;
    tick();
}

static void test_bubble_background_attr() {
    printf("== test_bubble_background_attr\n");
    reset();

    drive_visible_pixel(24, 32, BUBBLE_ATTR_REMOTE);
    CHECK_EQ(dut->video_red,   REMOTE_R, "remote bubble red");
    CHECK_EQ(dut->video_green, REMOTE_G, "remote bubble green");
    CHECK_EQ(dut->video_blue,  REMOTE_B, "remote bubble blue");

    drive_visible_pixel(760, 32, BUBBLE_ATTR_LOCAL);
    CHECK_EQ(dut->video_red,   LOCAL_R, "local bubble red");
    CHECK_EQ(dut->video_green, LOCAL_G, "local bubble green");
    CHECK_EQ(dut->video_blue,  LOCAL_B, "local bubble blue");
}

static void test_bubble_fill_clips_to_edge_outline() {
    printf("== test_bubble_fill_clips_to_edge_outline\n");
    reset();

    // Left edge row "..#.....": x<2 is outside, x=2 is border,
    // x>2 is inside the rounded bubble.
    drive_visible_pixel(1, 33, BUBBLE_ATTR_REMOTE, SPRITE_BL, 0x20);
    CHECK_EQ(dut->video_red,   0x00, "left outside red");
    CHECK_EQ(dut->video_green, 0x00, "left outside green");
    CHECK_EQ(dut->video_blue,  0x00, "left outside blue");

    drive_visible_pixel(2, 33, BUBBLE_ATTR_REMOTE, SPRITE_BL, 0x20);
    CHECK_EQ(dut->video_red,   FG_R, "left border red");
    CHECK_EQ(dut->video_green, FG_G, "left border green");
    CHECK_EQ(dut->video_blue,  FG_B, "left border blue");

    drive_visible_pixel(3, 33, BUBBLE_ATTR_REMOTE, SPRITE_BL, 0x20);
    CHECK_EQ(dut->video_red,   REMOTE_R, "left inside red");
    CHECK_EQ(dut->video_green, REMOTE_G, "left inside green");
    CHECK_EQ(dut->video_blue,  REMOTE_B, "left inside blue");

    // Right edge row ".....#..": x<5 is inside, x=5 is border,
    // x>5 is outside.
    drive_visible_pixel(4, 33, BUBBLE_ATTR_REMOTE, SPRITE_BR, 0x04);
    CHECK_EQ(dut->video_red,   REMOTE_R, "right inside red");
    CHECK_EQ(dut->video_green, REMOTE_G, "right inside green");
    CHECK_EQ(dut->video_blue,  REMOTE_B, "right inside blue");

    drive_visible_pixel(5, 33, BUBBLE_ATTR_REMOTE, SPRITE_BR, 0x04);
    CHECK_EQ(dut->video_red,   FG_R, "right border red");
    CHECK_EQ(dut->video_green, FG_G, "right border green");
    CHECK_EQ(dut->video_blue,  FG_B, "right border blue");

    drive_visible_pixel(6, 33, BUBBLE_ATTR_REMOTE, SPRITE_BR, 0x04);
    CHECK_EQ(dut->video_red,   0x00, "right outside red");
    CHECK_EQ(dut->video_green, 0x00, "right outside green");
    CHECK_EQ(dut->video_blue,  0x00, "right outside blue");
}

static void test_avatar_request_only_first_row() {
    printf("== test_avatar_request_only_first_row\n");
    reset();

    clear_avatar_attrs();
    set_avatar_attr(0, BUBBLE_ATTR_REMOTE);
    dut->hdata = 0;
    dut->vdata = 32;     // screen history row 2 -> slot 0
    dut->eval();
    CHECK_EQ((uint32_t)dut->asset_sram_addr, REMOTE_BASE_WORD,
             "remote avatar first row addr");

    dut->vdata = 48;     // next visual row -> slot 1, no avatar attr
    dut->eval();
    CHECK_EQ((uint32_t)dut->asset_sram_addr, 48u * 400u,
             "remote next row bg addr");

    clear_avatar_attrs();
    set_avatar_attr(0, BUBBLE_ATTR_LOCAL);
    dut->hdata = 799;
    dut->vdata = 32;
    dut->eval();
    CHECK_EQ((uint32_t)dut->asset_sram_addr, LOCAL_BASE_WORD + 7u,
             "local avatar first row addr");

    dut->vdata = 48;
    dut->eval();
    CHECK_EQ((uint32_t)dut->asset_sram_addr, 48u * 400u + 399u,
             "local next row bg addr");
}

static void test_popup_menu_overlay() {
    printf("== test_popup_menu_overlay\n");
    reset();

    dut->popup_active = 1;
    dut->popup_type = POPUP_MSG_MENU;
    dut->popup_x = 100;
    dut->popup_y = 120;
    dut->mouse_x = 1023;
    dut->mouse_y = 1023;

    drive_visible_pixel(100, 120, BUBBLE_ATTR_NONE);
    CHECK_EQ(dut->video_red,   POPUP_BORDER_R, "popup border red");
    CHECK_EQ(dut->video_green, POPUP_BORDER_G, "popup border green");
    CHECK_EQ(dut->video_blue,  POPUP_BORDER_B, "popup border blue");

    drive_visible_pixel(108, 132, BUBBLE_ATTR_NONE);
    CHECK_EQ(dut->video_red,   POPUP_BG_R, "popup bg red");
    CHECK_EQ(dut->video_green, POPUP_BG_G, "popup bg green");
    CHECK_EQ(dut->video_blue,  POPUP_BG_B, "popup bg blue");

    dut->mouse_x = 108;
    dut->mouse_y = 150;  // inside item 1, away from the checked pixel
    drive_visible_pixel(180, 150, BUBBLE_ATTR_NONE);
    CHECK_EQ(dut->video_red,   POPUP_HOVER_R, "popup hover red");
    CHECK_EQ(dut->video_green, POPUP_HOVER_G, "popup hover green");
    CHECK_EQ(dut->video_blue,  POPUP_HOVER_B, "popup hover blue");
}

static void test_popup_menu_text_uses_glyph_rom_bus() {
    printf("== test_popup_menu_text_uses_glyph_rom_bus\n");
    reset();

    dut->popup_active = 1;
    dut->popup_type = POPUP_MSG_MENU;
    dut->popup_x = 100;
    dut->popup_y = 120;
    dut->mouse_x = 1023;
    dut->mouse_y = 1023;

    // First item text starts at x+12, y+2+4. With gx=0 and glyph_row[7]
    // set, the popup text colour should be selected and glyph_code should
    // request "Q".
    drive_visible_pixel(112, 126, BUBBLE_ATTR_NONE, ' ', 0x80);
    CHECK_EQ(dut->glyph_code, (uint8_t)'Q', "popup first label glyph");
    CHECK_EQ(dut->video_red,   POPUP_TEXT_R, "popup text red");
    CHECK_EQ(dut->video_green, POPUP_TEXT_G, "popup text green");
    CHECK_EQ(dut->video_blue,  POPUP_TEXT_B, "popup text blue");
}

static constexpr int EMOJI_SUGGEST_MAX = 15;
static constexpr int EMOJI_SUGGEST_ITEM_H_PX = 16;

static void test_emoji_suggest_overlay() {
    printf("== test_emoji_suggest_overlay\n");
    reset();

    // count=1 -> dynamic Y = 260 + (15-1)*16 = 484
    static constexpr int SUGGEST_Y =
        EMOJI_SUGGEST_Y_PX
        + (EMOJI_SUGGEST_MAX - 1) * EMOJI_SUGGEST_ITEM_H_PX;

    dut->emoji_suggest_active = 1;
    dut->emoji_suggest_count = 1;
    dut->emoji_suggest_ids = 0;  // slot 0 = EMOJI_TOKEN_HAPPY
    dut->mouse_x = 1023;
    dut->mouse_y = 1023;

    // Top-left pixel of the overlay (border).
    drive_visible_pixel(EMOJI_SUGGEST_X_PX, SUGGEST_Y,
                        BUBBLE_ATTR_NONE);
    CHECK_EQ(dut->video_red,   POPUP_BORDER_R, "suggest border red");
    CHECK_EQ(dut->video_green, POPUP_BORDER_G, "suggest border green");
    CHECK_EQ(dut->video_blue,  POPUP_BORDER_B, "suggest border blue");

    // Interior (background).
    drive_visible_pixel(EMOJI_SUGGEST_X_PX + 40,
                        SUGGEST_Y + EMOJI_SUGGEST_BORDER_PX + 8,
                        BUBBLE_ATTR_NONE);
    CHECK_EQ(dut->video_red,   POPUP_BG_R, "suggest bg red");
    CHECK_EQ(dut->video_green, POPUP_BG_G, "suggest bg green");
    CHECK_EQ(dut->video_blue,  POPUP_BG_B, "suggest bg blue");

    // Icon area: glyph should be the emoji code (0xE0 = HAPPY).
    drive_visible_pixel(EMOJI_SUGGEST_X_PX + EMOJI_SUGGEST_BORDER_PX + 4,
                        SUGGEST_Y + EMOJI_SUGGEST_BORDER_PX,
                        BUBBLE_ATTR_NONE, ' ', 0x80);
    CHECK_EQ(dut->glyph_code, (uint8_t)0xE0, "suggest icon glyph");

    // Text label: pixel at text start renders '\\' (first char).
    drive_visible_pixel(EMOJI_SUGGEST_X_PX + EMOJI_SUGGEST_TEXT_X_PX,
                        SUGGEST_Y + EMOJI_SUGGEST_BORDER_PX,
                        BUBBLE_ATTR_NONE, ' ', 0x80);
    CHECK_EQ(dut->glyph_code, (uint8_t)'\\', "suggest label glyph");
    CHECK_EQ(dut->video_red,   POPUP_TEXT_R, "suggest text red");
    CHECK_EQ(dut->video_green, POPUP_TEXT_G, "suggest text green");
    CHECK_EQ(dut->video_blue,  POPUP_TEXT_B, "suggest text blue");
}

static constexpr int STICKER_CELL_W = 64;
static constexpr int STICKER_CELL_H = 80;
static constexpr int STICKER_EMOJI_X_OFF = 8;
static constexpr int STICKER_EMOJI_Y_OFF = 16;

static void test_sticker_picker_display() {
    printf("== test_sticker_picker_display\n");
    reset();

    static constexpr int PX = 200;
    static constexpr int PY = 100;

    dut->popup_active = 1;
    dut->popup_type = POPUP_STICKER_PICKER;
    dut->popup_x = PX;
    dut->popup_y = PY;
    dut->mouse_x = 1023;
    dut->mouse_y = 1023;

    // 1. Border: top-left corner of the popup.
    drive_visible_pixel(PX, PY, BUBBLE_ATTR_NONE);
    CHECK_EQ(dut->video_red,   POPUP_BORDER_R, "sticker border R");
    CHECK_EQ(dut->video_green, POPUP_BORDER_G, "sticker border G");
    CHECK_EQ(dut->video_blue,  POPUP_BORDER_B, "sticker border B");

    // 2. Grid line: cell boundary at dx=64, i.e. left edge of cell 1.
    //    popup_dx[5:0] == 0 < BORDER_PX triggers grid_line.
    drive_visible_pixel(PX + STICKER_CELL_W, PY + 40, BUBBLE_ATTR_NONE);
    CHECK_EQ(dut->video_red,   POPUP_BORDER_R, "sticker grid R");
    CHECK_EQ(dut->video_green, POPUP_BORDER_G, "sticker grid G");
    CHECK_EQ(dut->video_blue,  POPUP_BORDER_B, "sticker grid B");

    // 3. Background: inside popup but outside the 48x48 sticker content area.
    //    Cell 0, dx=4 (past the 2 px border, before content at dx=8).
    drive_visible_pixel(PX + 4, PY + 40, BUBBLE_ATTR_NONE);
    CHECK_EQ(dut->video_red,   POPUP_BG_R, "sticker bg R");
    CHECK_EQ(dut->video_green, POPUP_BG_G, "sticker bg G");
    CHECK_EQ(dut->video_blue,  POPUP_BG_B, "sticker bg B");

    // 4. Sticker content transparency: tile 0 is all zero → pix_idx==0.
    //    The pipeline must fall back to the popup background colour.
    //    Cell 0, sub_col=0, sub_row=0, gx=0, gy=0.
    drive_visible_pixel(PX + STICKER_EMOJI_X_OFF,
                        PY + STICKER_EMOJI_Y_OFF,
                        BUBBLE_ATTR_NONE);
    CHECK_EQ(dut->video_red,   POPUP_BG_R, "sticker transparent R");
    CHECK_EQ(dut->video_green, POPUP_BG_G, "sticker transparent G");
    CHECK_EQ(dut->video_blue,  POPUP_BG_B, "sticker transparent B");

    // 5. Sticker content opaque pixel.
    //    Cell 0, tile 1 (sub_col=1, sub_row=0), gy=9, gx=6.
    //    pixel ROM addr 25 → 0x000000ae → gx=6 nibble = 0xa.
    //    Palette emoji 0, entry 10 → 0xBBB294.
    //    hdata = PX + X_OFF + 14 (sub_col=1,gx=6 → dx_from_off=14)
    //    vdata = PY + Y_OFF + 9  (gy=9)
    drive_visible_pixel(PX + STICKER_EMOJI_X_OFF + 14,
                        PY + STICKER_EMOJI_Y_OFF + 9,
                        BUBBLE_ATTR_NONE);
    CHECK_EQ(dut->video_red,   0xBB, "sticker content R");
    CHECK_EQ(dut->video_green, 0xB2, "sticker content G");
    CHECK_EQ(dut->video_blue,  0x94, "sticker content B");

    // 6. Pixel immediately left of content area: sticker_content_active
    //    should be false (dx_from_off < 0), so it falls through to bg.
    drive_visible_pixel(PX + STICKER_EMOJI_X_OFF - 1,
                        PY + STICKER_EMOJI_Y_OFF + 9,
                        BUBBLE_ATTR_NONE);
    CHECK_EQ(dut->video_red,   POPUP_BG_R, "sticker content left edge R");
    CHECK_EQ(dut->video_green, POPUP_BG_G, "sticker content left edge G");
    CHECK_EQ(dut->video_blue,  POPUP_BG_B, "sticker content left edge B");

    // 7. Cell 1 content area: verify cell-index (emoji_id) extraction.
    //    Same tile/gx/gy offsets, but popup_dx shifted by one cell.
    //    emoji_id = popup_dx[8:6] = 1, tile_off = 1*18 + 0*6 + 1 = 19.
    //    pixel ROM addr 19*16+9 = 313 → line 314.
    drive_visible_pixel(PX + STICKER_CELL_W + STICKER_EMOJI_X_OFF + 14,
                        PY + STICKER_EMOJI_Y_OFF + 9,
                        BUBBLE_ATTR_NONE);
    // With correct emoji_id extraction the palette lookup should succeed
    // (pix_idx != 0), so the pixel should NOT be the popup background.
    CHECK_NEQ(dut->video_red,   POPUP_BG_R, "sticker cell1 not bg R");
    CHECK_NEQ(dut->video_green, POPUP_BG_G, "sticker cell1 not bg G");
    CHECK_NEQ(dut->video_blue,  POPUP_BG_B, "sticker cell1 not bg B");
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vfe_scan d;
    dut = &d;

    test_bubble_background_attr();
    test_bubble_fill_clips_to_edge_outline();
    test_avatar_request_only_first_row();
    test_popup_menu_overlay();
    test_popup_menu_text_uses_glyph_rom_bus();
    test_emoji_suggest_overlay();
    test_sticker_picker_display();

    if (g_failures == 0) { printf("\nPASS  (all checks)\n"); return 0; }
    printf("\nFAIL  %d check(s) failed\n", g_failures);
    return 1;
}
