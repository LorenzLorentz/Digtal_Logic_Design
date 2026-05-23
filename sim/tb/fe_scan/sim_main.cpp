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

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vfe_scan d;
    dut = &d;

    test_bubble_background_attr();
    test_bubble_fill_clips_to_edge_outline();
    test_avatar_request_only_first_row();

    if (g_failures == 0) { printf("\nPASS  (all checks)\n"); return 0; }
    printf("\nFAIL  %d check(s) failed\n", g_failures);
    return 1;
}
