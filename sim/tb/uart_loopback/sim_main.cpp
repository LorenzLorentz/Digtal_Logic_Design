// =====================================================================
// sim_main.cpp  --  uart_tx -> uart_rx loopback integration
// ---------------------------------------------------------------------
// Wraps both UART halves (BAUD_DIV=16 for fast sim) and pushes bytes
// through. Confirms they recover exactly on the receive side.
// =====================================================================

#include "Vuart_loopback.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <cstdint>
#include <cstdio>
#include <queue>
#include <vector>

static constexpr int BAUD_DIV = 16;

static vluint64_t        g_time_ns  = 0;
static int               g_failures = 0;
static Vuart_loopback*   dut        = nullptr;
static VerilatedVcdC*    tfp        = nullptr;

static std::queue<uint8_t> rx_q;

static void tick_half() {
    dut->eval();
    if (tfp) tfp->dump(g_time_ns);
    g_time_ns += 5;
}
static void tick() {
    dut->clk = 0; tick_half();
    dut->clk = 1; tick_half();
    if (dut->rx_byte_valid) rx_q.push((uint8_t)dut->rx_byte_data);
}

static void reset() {
    dut->rst_n       = 0;
    dut->tx_in_valid = 0;
    dut->tx_in_data  = 0;
    dut->clk         = 0;
    for (int i = 0; i < 4; i++) tick();
    dut->rst_n = 1;
    for (int i = 0; i < 4; i++) tick();
    while (!rx_q.empty()) rx_q.pop();
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

// Push one byte into tx, wait for it to land in rx_q.
static bool send_recv(uint8_t b, uint8_t& got) {
    while (!dut->tx_in_ready) tick();
    dut->tx_in_data  = b;
    dut->tx_in_valid = 1;
    tick();
    dut->tx_in_valid = 0;
    int guard = BAUD_DIV * 12;
    while (rx_q.empty() && guard-- > 0) tick();
    if (rx_q.empty()) return false;
    got = rx_q.front(); rx_q.pop();
    return true;
}

static void test_single_byte() {
    printf("== test_single_byte\n");
    reset();
    uint8_t got = 0;
    bool ok = send_recv(0xA5, got);
    CHECK_EQ(ok ? 1 : 0, 1, "round trip success");
    CHECK_EQ((int)got, 0xA5, "round trip byte");
}

static void test_many_bytes() {
    printf("== test_many_bytes\n");
    reset();
    std::vector<uint8_t> v = {
        0x00, 0xFF, 0x55, 0xAA, 0x7E, 0x7D, 'H', 'i', 0x01, 0xFE
    };
    for (uint8_t b : v) {
        uint8_t got = 0;
        bool ok = send_recv(b, got);
        char lbl[64];
        std::snprintf(lbl, sizeof(lbl), "byte 0x%02X", b);
        CHECK_EQ(ok ? 1 : 0, 1, lbl);
        CHECK_EQ((int)got, (int)b, lbl);
    }
}

// Sanity: no spurious frame_error for clean traffic.
static void test_no_frame_errors() {
    printf("== test_no_frame_errors\n");
    reset();
    bool seen_err = false;
    for (uint8_t b : {0x12, 0x34, 0x56, 0x78}) {
        if (dut->rx_frame_error) seen_err = true;
        uint8_t got = 0;
        send_recv(b, got);
    }
    CHECK_EQ(seen_err ? 1 : 0, 0, "no frame_error during clean traffic");
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    dut = new Vuart_loopback;
    tfp = new VerilatedVcdC;
    dut->trace(tfp, /*levels=*/99);
    tfp->open("sim/waves/uart_loopback.vcd");

    test_single_byte();
    test_many_bytes();
    test_no_frame_errors();

    tfp->close();
    delete tfp;
    delete dut;

    if (g_failures == 0) { printf("\nPASS  (all checks)\n"); return 0; }
    printf("\nFAIL  %d check(s) failed\n", g_failures);
    return 1;
}
