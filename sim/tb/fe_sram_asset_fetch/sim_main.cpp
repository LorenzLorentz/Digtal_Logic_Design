// =====================================================================
// sim_main.cpp  --  Tests for rtl/frontend/fe_sram_asset_fetch.sv
// =====================================================================

#include "Vfe_sram_asset_fetch.h"
#include "verilated.h"
#include <cstdint>
#include <cstdio>

static int g_failures = 0;

static constexpr uint32_t BG_W_PX             = 800;
static constexpr uint32_t BG_H_PX             = 600;
static constexpr uint32_t AVATAR_W_PX         = 16;
static constexpr uint32_t AVATAR_H_PX         = 16;
static constexpr uint32_t BG_BASE_WORD        = 0;
static constexpr uint32_t LOCAL_BASE_WORD     = (BG_W_PX * BG_H_PX * 2) / 4;
static constexpr uint32_t REMOTE_BASE_WORD    = LOCAL_BASE_WORD
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

static void drive_and_check(
    Vfe_sram_asset_fetch& dut,
    uint16_t h,
    uint16_t v,
    bool remote_req,
    bool local_req,
    uint32_t expect_addr,
    bool expect_hi,
    const char* label
) {
    dut.hdata = h;
    dut.vdata = v;
    dut.avatar_remote_req = remote_req;
    dut.avatar_local_req = local_req;
    dut.eval();

    char addr_label[96];
    char half_label[96];
    snprintf(addr_label, sizeof(addr_label), "%s addr", label);
    snprintf(half_label, sizeof(half_label), "%s half", label);
    CHECK_EQ((uint32_t)dut.sram_addr, expect_addr, addr_label);
    CHECK_EQ((bool)dut.use_hi_half, expect_hi, half_label);
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vfe_sram_asset_fetch dut;

    drive_and_check(dut, 0,   0,   false, false, BG_BASE_WORD,             false, "bg first pixel");
    drive_and_check(dut, 1,   0,   false, false, BG_BASE_WORD,             true,  "bg high half");
    drive_and_check(dut, 2,   0,   false, false, BG_BASE_WORD + 1,         false, "bg next word");
    drive_and_check(dut, 0,   1,   false, false, BG_BASE_WORD + 400,       false, "bg row stride");
    drive_and_check(dut, 799, 599, false, false, BG_BASE_WORD + 239999,    true,  "bg last pixel");

    drive_and_check(dut, 15,  3,   true,  false, REMOTE_BASE_WORD + 31,    true,  "remote avatar");
    drive_and_check(dut, 799, 3,   false, true,  LOCAL_BASE_WORD + 31,     true,  "local avatar");
    drive_and_check(dut, 15,  3,   true,  true,  REMOTE_BASE_WORD + 31,    true,  "remote priority");

    if (g_failures == 0) { printf("\nPASS  (all checks)\n"); return 0; }
    printf("\nFAIL  %d check(s) failed\n", g_failures);
    return 1;
}
