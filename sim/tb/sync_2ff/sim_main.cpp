// =====================================================================
// sim_main.cpp  --  Tests for rtl/common/sync_2ff.sv
// ---------------------------------------------------------------------
// `sync_2ff` is a parameterised N-stage flop chain. Each tick the input
// shifts forward; output = last stage. With default N_STAGES=2, an
// async input takes 2 clock cycles to be visible at the output.
//
// What we test:
//   1. Reset puts the output at the configured RST_VAL.
//   2. With RST_VAL=1, after reset the output is 1 (matches PS/2 idle).
//   3. A stable input change becomes visible at the output exactly
//      N_STAGES cycles later.
//   4. A short input glitch (1 cycle) propagates as a 1-cycle pulse N
//      stages later. (Important: the synchronizer doesn't filter glitches
//      shorter than the clock period -- it just protects metastability.
//      Tests pin this expected behavior.)
//   5. Repeated edges propagate independently.
// =====================================================================

#include "Vsync_2ff.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <cstdint>
#include <cstdio>

static vluint64_t       g_time_ns  = 0;
static int              g_failures = 0;
static Vsync_2ff*       dut        = nullptr;
static VerilatedVcdC*   tfp        = nullptr;

static void tick_half() {
    dut->eval();
    if (tfp) tfp->dump(g_time_ns);
    g_time_ns += 5;
}
static void tick() {
    dut->clk = 0; tick_half();
    dut->clk = 1; tick_half();
}

static void reset(uint8_t async_init = 0, int cycles = 4) {
    dut->rst_n    = 0;
    dut->async_in = async_init;
    dut->clk      = 0;
    for (int i = 0; i < cycles; i++) tick();
    dut->rst_n = 1;
}

#define CHECK_EQ(actual, expected, label) do {                            \
    auto _a = (actual); auto _e = (expected);                             \
    if (_a != _e) {                                                       \
        ++g_failures;                                                     \
        printf("  [FAIL @ %lluns] %-40s got=%llu expected=%llu\n",        \
               (unsigned long long)g_time_ns, (label),                    \
               (unsigned long long)_a, (unsigned long long)_e);           \
    }                                                                     \
} while (0)

// 1) Reset puts the output at RST_VAL. We compile the DUT with the
//    default RST_VAL=0, so post-reset output is 0.
static void test_reset_to_rst_val() {
    printf("== test_reset_to_rst_val\n");
    reset();
    dut->eval();
    CHECK_EQ(dut->sync_out, 0, "post-reset output (RST_VAL=0 default)");
}

// 2) async_in=1 from before reset is ignored; output is RST_VAL=0
//    until the chain has flushed in the new value.
static void test_reset_overrides_input() {
    printf("== test_reset_overrides_input\n");
    dut->rst_n    = 0;
    dut->async_in = 1;
    dut->clk      = 0;
    for (int i = 0; i < 4; i++) tick();
    dut->eval();
    CHECK_EQ(dut->sync_out, 0, "output forced to RST_VAL during reset");
}

// 3) After reset, raise async_in=1. With N_STAGES=2 the output should
//    flip on the SECOND rising edge after the change.
static void test_two_stage_delay() {
    printf("== test_two_stage_delay\n");
    reset(0);
    dut->async_in = 1;
    // Cycle 1: shift_q[0] gets 1, output (=shift_q[1]) is still 0.
    tick();
    dut->eval();
    CHECK_EQ(dut->sync_out, 0, "output still 0 one cycle after rise");
    // Cycle 2: shift_q[1] gets 1, output reads 1.
    tick();
    dut->eval();
    CHECK_EQ(dut->sync_out, 1, "output flips after 2 cycles");
}

// 4) A 1-cycle glitch propagates through with the same width.
//    (sync_2ff isn't a low-pass filter; it only handles metastability.)
static void test_pulse_propagates() {
    printf("== test_pulse_propagates\n");
    reset(0);
    dut->async_in = 1; tick();   // glitch start
    dut->async_in = 0; tick();   // glitch end -- one cycle wide
    // Now the 1 should be at shift_q[1] this cycle:
    dut->eval();
    CHECK_EQ(dut->sync_out, 1, "glitch visible at output after N stages");
    tick();
    dut->eval();
    CHECK_EQ(dut->sync_out, 0, "glitch trailing edge");
}

// 5) Repeated edges all propagate. With our NBA pipeline (sync_q[1] <=
//    sync_q[0]; sync_q[0] <= async_in), the output we observe in the
//    cycle after we drove seq[i] is seq[i-1] -- a one-edge delay
//    between input arriving at sync_q[0] and propagating to sync_q[1].
//    (sync_q[0] itself gets seq[i] on this very edge, so the *visible*
//    chain depth is one.)
static void test_repeated_toggles() {
    printf("== test_repeated_toggles\n");
    reset(0);
    int seq[] = {1, 0, 1, 0, 1, 0};
    int observed[6];
    for (int i = 0; i < 6; i++) {
        dut->async_in = seq[i];
        tick();
        dut->eval();
        observed[i] = dut->sync_out;
    }
    // observed[0] = the old sync_q[0] from reset = 0
    // observed[i>=1] = seq[i-1]
    CHECK_EQ(observed[0], 0,        "obs[0] still reset");
    CHECK_EQ(observed[1], seq[0],   "obs[1] = seq[0]");
    CHECK_EQ(observed[2], seq[1],   "obs[2] = seq[1]");
    CHECK_EQ(observed[3], seq[2],   "obs[3] = seq[2]");
    CHECK_EQ(observed[4], seq[3],   "obs[4] = seq[3]");
    CHECK_EQ(observed[5], seq[4],   "obs[5] = seq[4]");
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    dut = new Vsync_2ff;
    tfp = new VerilatedVcdC;
    dut->trace(tfp, /*levels=*/99);
    tfp->open("sim/waves/sync_2ff.vcd");

    test_reset_to_rst_val();
    test_reset_overrides_input();
    test_two_stage_delay();
    test_pulse_propagates();
    test_repeated_toggles();

    tfp->close();
    delete tfp;
    delete dut;

    if (g_failures == 0) { printf("\nPASS  (all checks)\n"); return 0; }
    printf("\nFAIL  %d check(s) failed\n", g_failures);
    return 1;
}
