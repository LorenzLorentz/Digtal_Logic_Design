// =====================================================================
// sim_main.cpp  --  Tests for rtl/io/io_ps2_phy.sv
// ---------------------------------------------------------------------
// `io_ps2_phy` deserialises PS/2 device-to-host frames into bytes.
// We drive ps2_clk and ps2_data manually from the C++ TB to mimic the
// behaviour of a real keyboard:
//
//   - Idle: both lines high.
//   - For each bit: hold ps2_data steady; drop ps2_clk low (host
//     samples on the CLK falling edge); raise ps2_clk back high.
//   - 11 bits per frame: start(0) + d0..d7 LSB-first + odd_parity + stop(1).
//
// Conventions:
//   - 100 MHz local clock (10 ns).
//   - PS/2 clock period in this TB is intentionally fast (~50 cycles =
//     500 ns per half-period). Real PS/2 is far slower; we just need
//     each PS/2 bit to last enough cycles for the 2-FF synchroniser to
//     see clean transitions, which only needs a handful of cycles.
//
// Tests:
//   1. Reset: no spurious byte_valid / frame_error.
//   2. Single byte 0x55 (alternating bits) round-trips.
//   3. Byte 0x00 (all zeros, parity = 1).
//   4. Byte 0xFF (all ones, parity = 1: 8 ones + 1 parity = 9, odd).
//   5. Bad parity flips frame_error, no byte_valid.
//   6. Bad start (first bit == 1) -> frame_error.
//   7. Bad stop (last bit == 0) -> frame_error.
//   8. Three back-to-back valid frames are all received.
//   9. Specific PS/2 scan codes used downstream: 0x1C ('A' make),
//      0xF0 (release prefix), 0xE0 (extended prefix), 0x5A (ENTER),
//      0x66 (BACKSPACE), 0xAA (BAT). All bytes round-trip; the decoder
//      will care about meanings later.
//  10. After a frame_error the PHY can still receive the next valid
//      frame (state machine recovers).
// =====================================================================

#include "Vio_ps2_phy.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <cstdint>
#include <cstdio>

static vluint64_t       g_time_ns  = 0;
static int              g_failures = 0;
static Vio_ps2_phy*     dut        = nullptr;
static VerilatedVcdC*   tfp        = nullptr;

// PS/2 bit timing. Each half-period is BIT_HALF_CYCLES local cycles.
static constexpr int BIT_HALF_CYCLES = 50;

static void tick_half() {
    dut->eval();
    if (tfp) tfp->dump(g_time_ns);
    g_time_ns += 5;
}
static void tick() {
    dut->clk = 0; tick_half();
    dut->clk = 1; tick_half();
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

static void reset(int cycles = 4) {
    dut->rst_n    = 0;
    dut->ps2_clk  = 1;     // PS/2 idle high
    dut->ps2_data = 1;
    dut->clk      = 0;
    for (int i = 0; i < cycles; i++) tick();
    dut->rst_n = 1;
    tick();
}

// --- PS/2 bit driver -------------------------------------------------
//
// Drive one PS/2 bit. Convention: caller has held ps2_clk=1 for some
// time. We:
//   - Set ps2_data first while ps2_clk is high (data setup).
//   - Drop ps2_clk low; spend BIT_HALF_CYCLES.
//   - Raise ps2_clk back high; spend BIT_HALF_CYCLES.
// The host PHY samples ps2_data on the clk falling edge, so this is
// the natural shape.
static void ps2_send_bit(uint8_t b) {
    dut->ps2_data = b;
    // Tiny setup before clk falls -- 4 cycles is well above the
    // 2-FF synchroniser depth.
    for (int i = 0; i < 4; i++) tick();
    dut->ps2_clk = 0;
    for (int i = 0; i < BIT_HALF_CYCLES; i++) tick();
    dut->ps2_clk = 1;
    for (int i = 0; i < BIT_HALF_CYCLES; i++) tick();
}

// While the device drives the frame, watch for byte_valid / frame_error
// in parallel. They are 1-cycle pulses; we have to catch them on the
// cycle they fire.
static bool g_saw_valid;
static bool g_saw_error;
static uint8_t g_captured_byte;

static void poll_outputs_during_drive() {
    dut->eval();
    if (dut->byte_valid)  { g_saw_valid = true; g_captured_byte = dut->byte_data; }
    if (dut->frame_error) { g_saw_error = true; }
}

// Override tick() callsite inside the driver so we poll on every cycle.
// (Implemented by wrapping tick(); ps2_send_bit etc. all call this.)
static void tick_polling() {
    dut->clk = 0; dut->eval(); if (tfp) tfp->dump(g_time_ns); g_time_ns += 5;
    dut->clk = 1; dut->eval(); if (tfp) tfp->dump(g_time_ns); g_time_ns += 5;
    poll_outputs_during_drive();
}
// Replace the ps2_send_bit body to use tick_polling.
static void ps2_send_bit_polling(uint8_t b) {
    dut->ps2_data = b;
    for (int i = 0; i < 4; i++)  tick_polling();
    dut->ps2_clk = 0;
    for (int i = 0; i < BIT_HALF_CYCLES; i++) tick_polling();
    dut->ps2_clk = 1;
    for (int i = 0; i < BIT_HALF_CYCLES; i++) tick_polling();
}

// Reset the polling latches before each frame.
static void clear_outputs() {
    g_saw_valid = false;
    g_saw_error = false;
    g_captured_byte = 0;
}

// Send a generic 11-bit frame: bits[0]=start, bits[1..8]=data LSB-first,
// bits[9]=parity, bits[10]=stop. Lets us inject malformed frames too.
static void ps2_send_raw(const uint8_t bits[11]) {
    for (int i = 0; i < 11; i++) ps2_send_bit_polling(bits[i]);
    // Trailing idle so byte_valid / frame_error pulses propagate before
    // the next test starts.
    for (int i = 0; i < 20; i++) tick_polling();
}

// Compute odd parity over the 8 data bits.
static uint8_t odd_parity(uint8_t b) {
    uint8_t p = 1;
    for (int i = 0; i < 8; i++) p ^= (b >> i) & 1;
    return p;
}

// Helper: send a well-formed PS/2 frame for byte b.
static void ps2_send_byte(uint8_t b) {
    uint8_t bits[11];
    bits[0] = 0;                       // start
    for (int i = 0; i < 8; i++)
        bits[1 + i] = (b >> i) & 1;    // data LSB-first
    bits[9]  = odd_parity(b);          // parity
    bits[10] = 1;                      // stop
    ps2_send_raw(bits);
}

// =====================================================================
// Tests
// =====================================================================

static void test_reset_no_spurious() {
    printf("== test_reset_no_spurious\n");
    reset();
    // Hold idle for a while.
    clear_outputs();
    for (int i = 0; i < 200; i++) tick_polling();
    CHECK_EQ(g_saw_valid, false, "no spurious byte_valid in idle");
    CHECK_EQ(g_saw_error, false, "no spurious frame_error in idle");
}

static void test_single_byte_0x55() {
    printf("== test_single_byte_0x55\n");
    reset();
    clear_outputs();
    ps2_send_byte(0x55);
    CHECK_EQ(g_saw_valid,     true, "byte_valid pulsed");
    CHECK_EQ(g_saw_error,     false,"no frame_error");
    CHECK_EQ(g_captured_byte, 0x55, "byte_data == 0x55");
}

static void test_byte_zero() {
    printf("== test_byte_zero\n");
    reset();
    clear_outputs();
    ps2_send_byte(0x00);
    CHECK_EQ(g_saw_valid,     true, "valid");
    CHECK_EQ(g_captured_byte, 0x00, "byte_data == 0x00");
}

static void test_byte_ff() {
    printf("== test_byte_ff\n");
    reset();
    clear_outputs();
    ps2_send_byte(0xFF);
    CHECK_EQ(g_saw_valid,     true, "valid");
    CHECK_EQ(g_captured_byte, 0xFF, "byte_data == 0xFF");
}

static void test_bad_parity() {
    printf("== test_bad_parity\n");
    reset();
    clear_outputs();
    uint8_t b = 0x5A;
    uint8_t bits[11];
    bits[0] = 0;
    for (int i = 0; i < 8; i++) bits[1+i] = (b >> i) & 1;
    bits[9]  = odd_parity(b) ^ 1;       // flipped: now even parity
    bits[10] = 1;
    ps2_send_raw(bits);
    CHECK_EQ(g_saw_valid, false, "no byte_valid");
    CHECK_EQ(g_saw_error, true,  "frame_error on bad parity");
}

static void test_bad_start() {
    printf("== test_bad_start\n");
    reset();
    clear_outputs();
    uint8_t b = 0x33;
    uint8_t bits[11];
    bits[0] = 1;                        // BAD start (should be 0)
    for (int i = 0; i < 8; i++) bits[1+i] = (b >> i) & 1;
    bits[9]  = odd_parity(b);
    bits[10] = 1;
    ps2_send_raw(bits);
    CHECK_EQ(g_saw_valid, false, "no byte_valid");
    CHECK_EQ(g_saw_error, true,  "frame_error on bad start");
}

static void test_bad_stop() {
    printf("== test_bad_stop\n");
    reset();
    clear_outputs();
    uint8_t b = 0x33;
    uint8_t bits[11];
    bits[0] = 0;
    for (int i = 0; i < 8; i++) bits[1+i] = (b >> i) & 1;
    bits[9]  = odd_parity(b);
    bits[10] = 0;                       // BAD stop (should be 1)
    ps2_send_raw(bits);
    CHECK_EQ(g_saw_valid, false, "no byte_valid");
    CHECK_EQ(g_saw_error, true,  "frame_error on bad stop");
}

static void test_three_back_to_back() {
    printf("== test_three_back_to_back\n");
    reset();
    uint8_t bytes[3] = {0x1C, 0xE0, 0x5A};   // 'A' make, extended prefix, ENTER
    for (int i = 0; i < 3; i++) {
        clear_outputs();
        ps2_send_byte(bytes[i]);
        char lbl[60];
        snprintf(lbl, sizeof(lbl), "byte[%d] = 0x%02x", i, bytes[i]);
        CHECK_EQ(g_saw_valid,     true,    lbl);
        CHECK_EQ(g_captured_byte, bytes[i], "byte_data");
    }
}

static void test_specific_scan_codes() {
    printf("== test_specific_scan_codes\n");
    reset();
    uint8_t codes[] = {
        0x1C,  // 'A' make
        0xF0,  // release prefix
        0xE0,  // extended prefix
        0x5A,  // ENTER make
        0x66,  // BACKSPACE make
        0x76,  // ESC make
        0xAA,  // BAT (post power-up self-test)
    };
    for (uint8_t c : codes) {
        clear_outputs();
        ps2_send_byte(c);
        char lbl[60];
        snprintf(lbl, sizeof(lbl), "code 0x%02x captured", c);
        CHECK_EQ(g_saw_valid,     true, lbl);
        CHECK_EQ(g_captured_byte, c,    "byte_data matches");
    }
}

// After a malformed frame the PHY must still recover and capture the
// next well-formed one.
static void test_recover_after_error() {
    printf("== test_recover_after_error\n");
    reset();
    // First: a bad-parity frame (consumes 11 bits, ends in frame_error).
    {
        clear_outputs();
        uint8_t b = 0x66;
        uint8_t bits[11];
        bits[0] = 0;
        for (int i = 0; i < 8; i++) bits[1+i] = (b >> i) & 1;
        bits[9]  = odd_parity(b) ^ 1;
        bits[10] = 1;
        ps2_send_raw(bits);
        CHECK_EQ(g_saw_error, true, "first frame errored");
    }
    // Now: a well-formed frame should still come through.
    {
        clear_outputs();
        ps2_send_byte(0x29);    // SPACE make code
        CHECK_EQ(g_saw_valid,     true, "recovered: byte_valid fires");
        CHECK_EQ(g_captured_byte, 0x29, "captured 0x29");
    }
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    dut = new Vio_ps2_phy;
    tfp = new VerilatedVcdC;
    dut->trace(tfp, /*levels=*/99);
    tfp->open("sim/waves/io_ps2_phy.vcd");

    test_reset_no_spurious();
    test_single_byte_0x55();
    test_byte_zero();
    test_byte_ff();
    test_bad_parity();
    test_bad_start();
    test_bad_stop();
    test_three_back_to_back();
    test_specific_scan_codes();
    test_recover_after_error();

    tfp->close();
    delete tfp;
    delete dut;

    if (g_failures == 0) { printf("\nPASS  (all checks)\n"); return 0; }
    printf("\nFAIL  %d check(s) failed\n", g_failures);
    return 1;
}
