// =====================================================================
// sim_main.cpp  --  chat_top boot smoke test
// ---------------------------------------------------------------------
// Single chat_top instance. PS/2 pins idle high (no keys), uart_rxd
// idle high (no peer). After reset we expect the boot HELLO frame to
// appear on uart_txd autonomously.
//
// Coverage:
//   1. Elaboration succeeds (compile-only check).
//   2. After de-asserting reset, uart_txd produces traffic within the
//      ARQ timeout window. We decode the bits via a TB-side UART rx
//      model and verify the first frame byte is SOF (0x7E) and the
//      second byte is TYPE=HELLO (3).
// =====================================================================

#include "Vchat_top.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <cstdint>
#include <cstdio>
#include <vector>

static vluint64_t       g_time_ns  = 0;
static int              g_failures = 0;
static Vchat_top*       dut        = nullptr;
static VerilatedVcdC*   tfp        = nullptr;

// Test parameters: CLK_FREQ_HZ=160, BAUD=10 -> BAUD_DIV=16. Override
// in params.txt.
static constexpr int BAUD_DIV = 16;
static constexpr uint8_t SOF_BYTE     = 0x7E;
static constexpr uint8_t FRAME_HELLO  = 3;

static void tick_half() {
    dut->eval();
    if (tfp) tfp->dump(g_time_ns);
    g_time_ns += 5;
}
static void tick() {
    dut->clk = 0; dut->clk_pix = 0; tick_half();
    dut->clk = 1; dut->clk_pix = 1; tick_half();
}

#define CHECK_EQ(actual, expected, label) do {                            \
    auto _a = (actual); auto _e = (expected);                             \
    if (_a != _e) {                                                       \
        ++g_failures;                                                     \
        printf("  [FAIL @ %lluns] %-44s got=0x%llX expected=0x%llX\n",    \
               (unsigned long long)g_time_ns, (label),                    \
               (unsigned long long)_a, (unsigned long long)_e);           \
    }                                                                     \
} while (0)

static void reset() {
    dut->btn_rst  = 1;             // active-high: hold reset
    dut->ps2_clk  = 1;             // idle high
    dut->ps2_data = 1;
    dut->uart_rxd = 1;
    dut->asset_sram_data = 0;
    dut->clk      = 0;
    dut->clk_pix  = 0;
    for (int i = 0; i < 8; i++) tick();
    dut->btn_rst = 0;              // release; sync_2ff takes 2 cycles
    // No extra ticks here -- the test's wait_falling_edge will tick
    // and observe the first start bit cleanly. (Ticking too long here
    // would put us mid-frame and we'd lock onto a data bit's falling
    // edge instead of the SOF byte's.)
}

// Wait for the next falling edge on uart_txd (= UART start bit).
// Returns false on timeout.
static bool wait_falling_edge(int max_cycles) {
    int prev = (int)dut->uart_txd;
    for (int i = 0; i < max_cycles; i++) {
        tick();
        int cur = (int)dut->uart_txd;
        if (prev == 1 && cur == 0) return true;
        prev = cur;
    }
    return false;
}

// Sample one full UART byte starting from "we just saw the falling edge
// of the start bit". Advance to the centre of the start bit, verify
// it's still low, then sample 8 data bits LSB-first at every BAUD_DIV
// cycles, then sample the stop bit.
static bool sample_byte(uint8_t& out) {
    out = 0;
    for (int i = 0; i < BAUD_DIV / 2; i++) tick();
    if (dut->uart_txd != 0) return false;     // not really a start bit
    for (int b = 0; b < 8; b++) {
        for (int i = 0; i < BAUD_DIV; i++) tick();
        if (dut->uart_txd) out |= (uint8_t)(1u << b);
    }
    for (int i = 0; i < BAUD_DIV; i++) tick();
    if (dut->uart_txd != 1) return false;     // bad stop
    return true;
}

static void test_boot_hello() {
    printf("== test_boot_hello\n");
    reset();
    // Wait for the first start bit. 4096 cycles is plenty -- backend
    // emits HELLO immediately after S_BOOT_REDRAW.
    bool got = wait_falling_edge(4096);
    CHECK_EQ(got ? 1 : 0, 1, "uart_txd start bit detected");
    if (!got) return;

    // SOF byte.
    uint8_t b;
    bool ok = sample_byte(b);
    CHECK_EQ(ok ? 1 : 0, 1, "first byte clean framing");
    CHECK_EQ((int)b, (int)SOF_BYTE, "first byte = SOF (0x7E)");

    // Wait for the next start bit (TYPE byte).
    got = wait_falling_edge(BAUD_DIV * 4);
    CHECK_EQ(got ? 1 : 0, 1, "TYPE start bit detected");
    if (!got) return;
    ok = sample_byte(b);
    CHECK_EQ(ok ? 1 : 0, 1, "TYPE byte clean framing");
    CHECK_EQ((int)b, (int)FRAME_HELLO, "second byte = FRAME_HELLO");
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    dut = new Vchat_top;
    tfp = new VerilatedVcdC;
    dut->trace(tfp, /*levels=*/99);
    tfp->open("sim/waves/chat_top.vcd");

    test_boot_hello();

    tfp->close();
    delete tfp;
    delete dut;

    if (g_failures == 0) { printf("\nPASS  (all checks)\n"); return 0; }
    printf("\nFAIL  %d check(s) failed\n", g_failures);
    return 1;
}
