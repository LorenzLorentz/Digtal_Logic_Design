// =====================================================================
// sim_main.cpp  --  chat_top_pair end-to-end test
// ---------------------------------------------------------------------
// Two backends + comms cross-wired through UART. Verifies:
//   1. Both sides reach S_CONNECTED autonomously after reset.
//   2. Each side learns the peer's username.
//   3. A keypress on Alice -> KEY_ENTER commits a message that arrives
//      in Bob's message store.
// =====================================================================

#include "Vchat_top_pair.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <cstdint>
#include <cstdio>
#include <cstring>

static vluint64_t       g_time_ns  = 0;
static int              g_failures = 0;
static Vchat_top_pair*  dut        = nullptr;
static VerilatedVcdC*   tfp        = nullptr;

static constexpr int MAX_NAME_LEN = 16;
static constexpr int MAX_MSG_LEN  = 64;
static constexpr int PAYLOAD_W    = MAX_MSG_LEN * 8 / 32;
static constexpr int NAME_W       = MAX_NAME_LEN * 8 / 32;

enum : uint8_t {
    KEY_CHAR = 0, KEY_ENTER = 1, KEY_BACKSPACE = 2,
    KEY_LEFT = 3, KEY_RIGHT = 4, KEY_ESC = 5,
};
enum : uint8_t {
    CONN_BOOT = 0, CONN_HANDSHAKE = 1,
    CONN_CONNECTED = 2, CONN_DISCONNECTED = 3,
};
enum : uint8_t { MSG_LOCAL = 0, MSG_REMOTE = 1 };
enum : uint8_t { MSG_PENDING = 0, MSG_SUCCESS = 1, MSG_FAIL = 2 };

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
    dut->rst_n          = 0;
    dut->a_io_key_valid = 0;
    dut->a_io_key_type  = 0;
    dut->a_io_key_ascii = 0;
    dut->b_io_key_valid = 0;
    dut->b_io_key_type  = 0;
    dut->b_io_key_ascii = 0;
    dut->a_store_rd_idx = 0;
    dut->b_store_rd_idx = 0;
    dut->clk            = 0;
    for (int i = 0; i < 4; i++) tick();
    dut->rst_n = 1;
    tick();
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

static uint8_t name_byte(const uint32_t* sig, int i) {
    int w = i >> 2, sh = (i & 3) * 8;
    return (sig[w] >> sh) & 0xFF;
}
static uint8_t payload_byte(const uint32_t* sig, int i) {
    int w = i >> 2, sh = (i & 3) * 8;
    return (sig[w] >> sh) & 0xFF;
}

// Wait until both sides report CONN_CONNECTED, with timeout.
static bool wait_both_connected(int max_cycles = 200000) {
    for (int i = 0; i < max_cycles; i++) {
        if (dut->a_conn_state == CONN_CONNECTED
         && dut->b_conn_state == CONN_CONNECTED) return true;
        tick();
    }
    return false;
}

// Drive a one-cycle key event on one side.
static void send_key(bool a_side, uint8_t type, uint8_t ascii) {
    if (a_side) {
        while (!dut->a_io_key_ready) tick();
        dut->a_io_key_type  = type;
        dut->a_io_key_ascii = ascii;
        dut->a_io_key_valid = 1;
        tick();
        dut->a_io_key_valid = 0;
    } else {
        while (!dut->b_io_key_ready) tick();
        dut->b_io_key_type  = type;
        dut->b_io_key_ascii = ascii;
        dut->b_io_key_valid = 1;
        tick();
        dut->b_io_key_valid = 0;
    }
}

// 1) Boot both sides; verify they handshake.
static void test_handshake() {
    printf("== test_handshake\n");
    reset();
    bool ok = wait_both_connected();
    CHECK_EQ(ok ? 1 : 0, 1, "both sides reach CONNECTED");

    // Alice should know Bob's name; Bob should know Alice's name.
    CHECK_EQ((int)dut->a_peer_name_len, 3, "Alice sees peer_name_len=3");
    CHECK_EQ((int)name_byte(dut->a_peer_name, 0), 'B', "Alice peer[0]=B");
    CHECK_EQ((int)name_byte(dut->a_peer_name, 1), 'o', "Alice peer[1]=o");
    CHECK_EQ((int)name_byte(dut->a_peer_name, 2), 'b', "Alice peer[2]=b");

    CHECK_EQ((int)dut->b_peer_name_len, 5, "Bob sees peer_name_len=5");
    CHECK_EQ((int)name_byte(dut->b_peer_name, 0), 'A', "Bob peer[0]=A");
    CHECK_EQ((int)name_byte(dut->b_peer_name, 1), 'l', "Bob peer[1]=l");
    CHECK_EQ((int)name_byte(dut->b_peer_name, 2), 'i', "Bob peer[2]=i");
    CHECK_EQ((int)name_byte(dut->b_peer_name, 3), 'c', "Bob peer[3]=c");
    CHECK_EQ((int)name_byte(dut->b_peer_name, 4), 'e', "Bob peer[4]=e");
}

// 2) Alice types a message and presses Enter; verify it lands in Bob's store.
static void test_alice_to_bob_message() {
    printf("== test_alice_to_bob_message\n");
    reset();
    if (!wait_both_connected()) {
        ++g_failures;
        printf("  [FAIL] handshake didn't complete\n");
        return;
    }
    // Give backends a moment to settle into chat S_IDLE (post-render).
    for (int i = 0; i < 2000; i++) tick();
    // Alice types "hi"
    send_key(true, KEY_CHAR, 'h');
    send_key(true, KEY_CHAR, 'i');
    send_key(true, KEY_ENTER, 0);

    // Wait for Bob's store slot 0 to become a remote "hi" with SUCCESS.
    bool found = false;
    dut->b_store_rd_idx = 0;
    for (int i = 0; i < 400000; i++) {
        if (dut->b_store_rd_valid
         && dut->b_store_rd_side == MSG_REMOTE
         && dut->b_store_rd_status == MSG_SUCCESS
         && dut->b_store_rd_len   == 2) {
            uint8_t p0 = payload_byte(dut->b_store_rd_payload, 0);
            uint8_t p1 = payload_byte(dut->b_store_rd_payload, 1);
            if (p0 == 'h' && p1 == 'i') { found = true; break; }
        }
        tick();
    }
    CHECK_EQ(found ? 1 : 0, 1, "Bob receives Alice's 'hi'");

    // Also verify Alice's local store slot 0 went PENDING -> SUCCESS.
    dut->a_store_rd_idx = 0;
    bool a_ok = false;
    for (int i = 0; i < 200000; i++) {
        if (dut->a_store_rd_valid
         && dut->a_store_rd_side == MSG_LOCAL
         && dut->a_store_rd_status == MSG_SUCCESS) {
            a_ok = true;
            break;
        }
        tick();
    }
    CHECK_EQ(a_ok ? 1 : 0, 1, "Alice's local message marked SUCCESS");
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    dut = new Vchat_top_pair;
    tfp = new VerilatedVcdC;
    dut->trace(tfp, /*levels=*/99);
    tfp->open("sim/waves/chat_top_pair.vcd");

    test_handshake();
    test_alice_to_bob_message();

    tfp->close();
    delete tfp;
    delete dut;

    if (g_failures == 0) { printf("\nPASS  (all checks)\n"); return 0; }
    printf("\nFAIL  %d check(s) failed\n", g_failures);
    return 1;
}
