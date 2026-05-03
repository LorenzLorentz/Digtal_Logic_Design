// =====================================================================
// sim_main.cpp  --  Tests for rtl/common/crc16.sv
// ---------------------------------------------------------------------
// `crc16` is a streaming CRC16-CCITT (poly 0x1021, init 0xFFFF).
//
// Coverage:
//   1. Reset: crc_out = INIT (0xFFFF).
//   2. `init` pulse mid-stream reloads INIT.
//   3. Canonical vector: bytes "123456789" -> 0x29B1.
//   4. Random vectors cross-checked against the same software model
//      (replicated here in C; matches scripts/crc16_ref.py bit-for-bit).
//   5. Empty after init reads INIT.
// =====================================================================

#include "Vcrc16.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <vector>

static vluint64_t      g_time_ns  = 0;
static int             g_failures = 0;
static Vcrc16*         dut        = nullptr;
static VerilatedVcdC*  tfp        = nullptr;

static void tick_half() {
    dut->eval();
    if (tfp) tfp->dump(g_time_ns);
    g_time_ns += 5;
}
static void tick() {
    dut->clk = 0; tick_half();
    dut->clk = 1; tick_half();
}

static void reset() {
    dut->rst_n   = 0;
    dut->init    = 0;
    dut->en      = 0;
    dut->byte_in = 0;
    dut->clk     = 0;
    for (int i = 0; i < 4; i++) tick();
    dut->rst_n = 1;
    tick();
}

#define CHECK_EQ(actual, expected, label) do {                            \
    auto _a = (actual); auto _e = (expected);                             \
    if (_a != _e) {                                                       \
        ++g_failures;                                                     \
        printf("  [FAIL @ %lluns] %-40s got=0x%llX expected=0x%llX\n",    \
               (unsigned long long)g_time_ns, (label),                    \
               (unsigned long long)_a, (unsigned long long)_e);           \
    }                                                                     \
} while (0)

// ---- Software CRC reference (mirrors scripts/crc16_ref.py) -----------
static uint16_t sw_crc16_step(uint16_t crc, uint8_t b) {
    crc ^= ((uint16_t)b) << 8;
    for (int i = 0; i < 8; i++) {
        if (crc & 0x8000) crc = (uint16_t)((crc << 1) ^ 0x1021);
        else              crc = (uint16_t)(crc << 1);
    }
    return crc;
}
static uint16_t sw_crc16(const std::vector<uint8_t>& data,
                         uint16_t init = 0xFFFF) {
    uint16_t c = init;
    for (uint8_t b : data) c = sw_crc16_step(c, b);
    return c;
}

// Feed `data` into the DUT one byte / cycle.
// Returns crc_out one cycle AFTER the last `en` pulse.
static uint16_t feed_bytes(const std::vector<uint8_t>& data) {
    for (uint8_t b : data) {
        dut->en      = 1;
        dut->byte_in = b;
        tick();
    }
    dut->en      = 0;
    dut->byte_in = 0;
    dut->eval();
    return (uint16_t)dut->crc_out;
}

static void pulse_init() {
    dut->init = 1;
    dut->en   = 0;
    tick();
    dut->init = 0;
    dut->eval();
}

// 1) After reset, crc_out is INIT.
static void test_reset_init() {
    printf("== test_reset_init\n");
    reset();
    CHECK_EQ((uint16_t)dut->crc_out, 0xFFFF, "post-reset crc = INIT");
}

// 2) `init` pulse mid-stream reloads INIT.
static void test_init_pulse_mid_stream() {
    printf("== test_init_pulse_mid_stream\n");
    reset();
    feed_bytes({'a', 'b', 'c'});
    pulse_init();
    CHECK_EQ((uint16_t)dut->crc_out, 0xFFFF, "init reloaded");
}

// 3) Canonical: "123456789" -> 0x29B1.
static void test_canonical_vector() {
    printf("== test_canonical_vector\n");
    reset();
    std::vector<uint8_t> v = {'1','2','3','4','5','6','7','8','9'};
    uint16_t hw = feed_bytes(v);
    CHECK_EQ(hw, 0x29B1, "crc16(\"123456789\")");
    CHECK_EQ(hw, sw_crc16(v), "matches sw model");
}

// 4) Random vectors cross-checked.
static void test_random_vectors() {
    printf("== test_random_vectors\n");
    uint32_t lfsr = 0xACE1u;
    auto next_byte = [&]() {
        uint8_t out = lfsr & 0xFF;
        for (int b = 0; b < 8; b++) {
            uint16_t lsb = lfsr & 1u;
            lfsr >>= 1;
            if (lsb) lfsr ^= 0xB400u;
        }
        return out;
    };

    for (int trial = 0; trial < 8; trial++) {
        reset();
        int len = 1 + (next_byte() & 0x3F);
        std::vector<uint8_t> v(len);
        for (int i = 0; i < len; i++) v[i] = next_byte();
        uint16_t hw = feed_bytes(v);
        char lbl[64];
        std::snprintf(lbl, sizeof(lbl), "random trial %d (len=%d)", trial, len);
        CHECK_EQ(hw, sw_crc16(v), lbl);
    }
}

// 5) Empty stream after init reads INIT.
static void test_empty_after_init() {
    printf("== test_empty_after_init\n");
    reset();
    feed_bytes({0xAA, 0x55});
    pulse_init();
    CHECK_EQ((uint16_t)dut->crc_out, 0xFFFF, "empty after init reads INIT");
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    dut = new Vcrc16;
    tfp = new VerilatedVcdC;
    dut->trace(tfp, /*levels=*/99);
    tfp->open("sim/waves/crc16.vcd");

    test_reset_init();
    test_init_pulse_mid_stream();
    test_canonical_vector();
    test_random_vectors();
    test_empty_after_init();

    tfp->close();
    delete tfp;
    delete dut;

    if (g_failures == 0) { printf("\nPASS  (all checks)\n"); return 0; }
    printf("\nFAIL  %d check(s) failed\n", g_failures);
    return 1;
}
