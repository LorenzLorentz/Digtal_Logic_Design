// =====================================================================
// sim_main.cpp  --  Tests for rtl/comm/uart_rx.sv
// ---------------------------------------------------------------------
// Test parameters: CLK_FREQ_HZ=160, BAUD=10  =>  BAUD_DIV = 16.
//
// Coverage:
//   1. Reset: outputs idle low (no pulses).
//   2. A clean transmit at the right cadence -> byte_valid + correct
//      byte data.
//   3. Several pattern bytes (0x00, 0xFF, 0xAA, 0x55, 'A', 0x7E).
//   4. Bad stop bit (held low) -> frame_error, no byte_valid.
//   5. Two bytes back-to-back (with a single stop+1 idle gap).
// =====================================================================

#include "Vuart_rx.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <cstdint>
#include <cstdio>

static constexpr int BAUD_DIV = 16;

static vluint64_t      g_time_ns  = 0;
static int             g_failures = 0;
static Vuart_rx*       dut        = nullptr;
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
    dut->rst_n = 0;
    dut->rx    = 1;     // line idles high
    dut->clk   = 0;
    for (int i = 0; i < 4; i++) tick();
    dut->rst_n = 1;
    // Let the synchroniser settle.
    for (int i = 0; i < 4; i++) tick();
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

// Drive a level for `cycles` clk ticks while polling for byte_valid /
// frame_error. Captures the first pulse seen (if any) into the
// observed_* outputs and continues driving until `cycles` is exhausted.
struct Observed {
    bool   byte_valid = false;
    uint8_t byte      = 0;
    bool   frame_err  = false;
};
static void drive(int level, int cycles, Observed* obs = nullptr) {
    dut->rx = level & 1;
    for (int i = 0; i < cycles; i++) {
        tick();
        if (obs) {
            if (dut->byte_valid && !obs->byte_valid) {
                obs->byte_valid = true;
                obs->byte       = (uint8_t)dut->byte_data;
            }
            if (dut->frame_error && !obs->frame_err) {
                obs->frame_err = true;
            }
        }
    }
}

// Send a clean 10-bit frame with `data`. Optionally override the stop
// bit value (1 = good, 0 = framing error). The byte_valid / frame_error
// pulse occurs near the end of the stop bit, so we poll throughout the
// frame and into a trailing idle window.
static Observed send_byte(uint8_t data, int stop = 1) {
    Observed obs;
    drive(0, BAUD_DIV, &obs);
    for (int b = 0; b < 8; b++)
        drive((data >> b) & 1, BAUD_DIV, &obs);
    drive(stop, BAUD_DIV, &obs);
    drive(1, BAUD_DIV, &obs);   // trailing idle so we always see the pulse
    return obs;
}

// 1) Reset: outputs idle low.
static void test_reset_idle() {
    printf("== test_reset_idle\n");
    reset();
    CHECK_EQ((int)dut->byte_valid,  0, "byte_valid low");
    CHECK_EQ((int)dut->frame_error, 0, "frame_error low");
}

// 2) Send 0x55, capture byte.
static void test_recv_0x55() {
    printf("== test_recv_0x55\n");
    reset();
    drive(1, BAUD_DIV);
    Observed obs = send_byte(0x55, /*stop=*/1);
    CHECK_EQ(obs.byte_valid ? 1 : 0, 1, "byte_valid pulsed");
    CHECK_EQ((int)obs.byte, 0x55, "byte_data");
    CHECK_EQ(obs.frame_err ? 1 : 0, 0, "no frame_error");
}

// 3) Several patterns.
static void test_pattern_bytes() {
    printf("== test_pattern_bytes\n");
    reset();
    drive(1, BAUD_DIV);
    uint8_t bytes[] = {0x00, 0xFF, 0xAA, 0x55, 'A', 0x7E};
    for (uint8_t b : bytes) {
        Observed obs = send_byte(b, 1);
        char lbl[64];
        std::snprintf(lbl, sizeof(lbl), "byte 0x%02X valid", b);
        CHECK_EQ(obs.byte_valid ? 1 : 0, 1, lbl);
        std::snprintf(lbl, sizeof(lbl), "byte 0x%02X data ", b);
        CHECK_EQ((int)obs.byte, (int)b, lbl);
        drive(1, BAUD_DIV);
    }
}

// 4) Stop bit held low -> frame_error, no byte_valid.
static void test_bad_stop() {
    printf("== test_bad_stop\n");
    reset();
    drive(1, BAUD_DIV);
    Observed obs = send_byte(0x33, /*stop=*/0);
    CHECK_EQ(obs.frame_err ? 1 : 0, 1, "frame_error pulsed");
    CHECK_EQ(obs.byte_valid ? 1 : 0, 0, "byte_valid did NOT fire");
    drive(1, BAUD_DIV * 2);
}

// 5) Back-to-back bytes (stop bit immediately followed by new start).
static void test_back_to_back() {
    printf("== test_back_to_back\n");
    reset();
    drive(1, BAUD_DIV);
    Observed o0 = send_byte(0xC3, 1);
    CHECK_EQ(o0.byte_valid ? 1 : 0, 1, "first byte_valid");
    CHECK_EQ((int)o0.byte,   0xC3, "first byte data");
    Observed o1 = send_byte(0x3C, 1);
    CHECK_EQ(o1.byte_valid ? 1 : 0, 1, "second byte_valid");
    CHECK_EQ((int)o1.byte,   0x3C, "second byte data");
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    dut = new Vuart_rx;
    tfp = new VerilatedVcdC;
    dut->trace(tfp, /*levels=*/99);
    tfp->open("sim/waves/uart_rx.vcd");

    test_reset_idle();
    test_recv_0x55();
    test_pattern_bytes();
    test_bad_stop();
    test_back_to_back();

    tfp->close();
    delete tfp;
    delete dut;

    if (g_failures == 0) { printf("\nPASS  (all checks)\n"); return 0; }
    printf("\nFAIL  %d check(s) failed\n", g_failures);
    return 1;
}
