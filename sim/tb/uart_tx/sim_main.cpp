// =====================================================================
// sim_main.cpp  --  Tests for rtl/comm/uart_tx.sv
// ---------------------------------------------------------------------
// We compile uart_tx with a small BAUD_DIV (CLK_FREQ_HZ=160, BAUD=10
// -> BAUD_DIV=16) so the test runs in seconds rather than minutes.
//
// What we check:
//   1. Reset: tx idles high, in_ready high.
//   2. Sending a byte: observe 10 bits on the wire (start=0, 8 data
//      LSB first, stop=1) each lasting BAUD_DIV cycles.
//   3. in_ready drops during transmission and rises after stop.
//   4. Back-to-back bytes: send 2 bytes, both come out cleanly.
//   5. ASCII pattern bytes (0x55, 0xAA, 0x00, 0xFF, 'A').
// =====================================================================

#include "Vuart_tx.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <cstdint>
#include <cstdio>
#include <vector>

// Must match the parameter override in deps via -G or compile-time
// override. We pass the BAUD_DIV here as a constant matching the
// override on the verilator command line.
static constexpr int BAUD_DIV = 16;

static vluint64_t      g_time_ns  = 0;
static int             g_failures = 0;
static Vuart_tx*       dut        = nullptr;
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
    dut->rst_n    = 0;
    dut->in_valid = 0;
    dut->in_data  = 0;
    dut->clk      = 0;
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

// Sample tx around the middle of the next bit. We assume the caller
// just observed the START transition (tx == 0); from that point we
// advance BAUD_DIV cycles per sampled bit.
//
// Returns: 8 data bits LSB-first, plus the stop bit, captured as
// shown on the wire.
struct UartFrame {
    int start;
    uint8_t data;
    int stop;
};
static UartFrame capture_frame() {
    UartFrame f{};
    // We're at the cycle where tx just went low (start). Sample at the
    // middle of the start bit by advancing BAUD_DIV/2 cycles.
    for (int i = 0; i < BAUD_DIV / 2; i++) tick();
    f.start = dut->tx;
    // Advance to the middle of each subsequent bit.
    for (int b = 0; b < 8; b++) {
        for (int i = 0; i < BAUD_DIV; i++) tick();
        if (dut->tx) f.data |= (1 << b);
    }
    // Middle of the stop bit.
    for (int i = 0; i < BAUD_DIV; i++) tick();
    f.stop = dut->tx;
    return f;
}

static void send_byte_and_capture(uint8_t byte, UartFrame& f) {
    // Wait until ready.
    while (!dut->in_ready) tick();
    // Apply the byte and assert valid.
    dut->in_data  = byte;
    dut->in_valid = 1;
    tick();   // sample point: in_valid&&in_ready -> latched
    dut->in_valid = 0;
    // Wait for tx to drop -- this is when the start bit hits the wire.
    int guard = BAUD_DIV * 4;
    while (dut->tx && guard-- > 0) tick();
    if (guard <= 0) {
        ++g_failures;
        printf("  [FAIL] tx never went low after send_byte\n");
        return;
    }
    f = capture_frame();
}

// 1) After reset, tx idle high, in_ready high.
static void test_idle_after_reset() {
    printf("== test_idle_after_reset\n");
    reset();
    CHECK_EQ((int)dut->tx,       1, "tx idle high");
    CHECK_EQ((int)dut->in_ready, 1, "in_ready high");
}

// 2) Send 0x55, capture the wire.
static void test_send_0x55() {
    printf("== test_send_0x55\n");
    reset();
    UartFrame f;
    send_byte_and_capture(0x55, f);
    CHECK_EQ(f.start, 0,    "start bit = 0");
    CHECK_EQ(f.data,  0x55, "data byte = 0x55");
    CHECK_EQ(f.stop,  1,    "stop bit = 1");
}

// 3) in_ready falls during transmission, rises after stop.
static void test_ready_pattern() {
    printf("== test_ready_pattern\n");
    reset();
    while (!dut->in_ready) tick();
    dut->in_data  = 0xA3;
    dut->in_valid = 1;
    tick();
    dut->in_valid = 0;
    // ready should be low now
    CHECK_EQ((int)dut->in_ready, 0, "in_ready low while busy");
    // wait long enough for full frame: 10 bits * BAUD_DIV + slack
    for (int i = 0; i < 10 * BAUD_DIV + 4; i++) tick();
    CHECK_EQ((int)dut->in_ready, 1, "in_ready high after frame");
}

// 4) Back-to-back: two bytes in a row.
static void test_back_to_back() {
    printf("== test_back_to_back\n");
    reset();
    UartFrame f0, f1;
    send_byte_and_capture(0xC3, f0);
    CHECK_EQ(f0.start, 0,    "f0 start");
    CHECK_EQ(f0.data,  0xC3, "f0 data");
    CHECK_EQ(f0.stop,  1,    "f0 stop");
    // After the stop bit was sampled (mid-stop), wait until tx returns
    // to idle and ready goes high. send_byte_and_capture does that for
    // the next byte automatically.
    send_byte_and_capture(0x3C, f1);
    CHECK_EQ(f1.start, 0,    "f1 start");
    CHECK_EQ(f1.data,  0x3C, "f1 data");
    CHECK_EQ(f1.stop,  1,    "f1 stop");
}

// 5) Stress: a few canonical patterns.
static void test_pattern_bytes() {
    printf("== test_pattern_bytes\n");
    reset();
    uint8_t bytes[] = {0x00, 0xFF, 0xAA, 'A', 0x7E};
    for (uint8_t b : bytes) {
        UartFrame f;
        send_byte_and_capture(b, f);
        char lbl[64];
        std::snprintf(lbl, sizeof(lbl), "byte 0x%02X data", b);
        CHECK_EQ(f.data, b, lbl);
        CHECK_EQ(f.start, 0, "start");
        CHECK_EQ(f.stop,  1, "stop");
    }
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    dut = new Vuart_tx;
    tfp = new VerilatedVcdC;
    dut->trace(tfp, /*levels=*/99);
    tfp->open("sim/waves/uart_tx.vcd");

    test_idle_after_reset();
    test_send_0x55();
    test_ready_pattern();
    test_back_to_back();
    test_pattern_bytes();

    tfp->close();
    delete tfp;
    delete dut;

    if (g_failures == 0) { printf("\nPASS  (all checks)\n"); return 0; }
    printf("\nFAIL  %d check(s) failed\n", g_failures);
    return 1;
}
