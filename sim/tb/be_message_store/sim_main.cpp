// =====================================================================
// sim_main.cpp -- Tests for rtl/backend/be_message_store.sv
// ---------------------------------------------------------------------
// What `be_message_store` does:
//   - 64-slot indexed storage of chat-message records.
//   - Each record: {valid, msg_id, side, status, len, payload[64 bytes]}.
//   - Operations (one cycle each):
//       wr_en  : atomic record write at wr_idx; sets valid=1.
//       upd_en : status-only update at upd_idx; valid bit unchanged.
//       rd     : combinational read at rd_idx.
//       lookup : combinational find of LOWEST valid idx whose msg_id
//                matches lookup_msg_id.
//   - Conflict policy: if wr_en && upd_en target the same slot in the
//     same cycle, the write wins.
//   - Reset: every slot's valid bit is cleared; other fields keep
//     prior values (don't-care because every read gates on valid).
//
// Conventions / encoding mirrored from rtl/pkg/chat_pkg.sv:
//   side:    MSG_LOCAL=0, MSG_REMOTE=1, MSG_SYSTEM=2
//   status:  MSG_PENDING=0, MSG_SUCCESS=1, MSG_FAIL=2
//   payload bytes: byte i lives at bits [i*8 +: 8] of the wide signal
//                  (little-endian byte ordering inside the 512-bit bus).
//
// Tests (in order):
//   1.  test_reset_invalidates_all     - all 64 slots read invalid post-reset
//   2.  test_basic_write_read          - single record round-trips
//   3.  test_multiple_slots_independent- writes to different slots don't bleed
//   4.  test_status_update             - upd_en flips only status
//   5.  test_status_update_invalid_slot- upd_en does NOT make a slot valid
//   6.  test_wide_payload              - all 64 payload bytes round-trip
//   7.  test_lookup_hit                - find an existing msg_id
//   8.  test_lookup_miss               - return hit=0 when no match
//   9.  test_lookup_collision_lowest   - duplicate msg_id -> lowest idx wins
//  10.  test_simul_wr_upd_same_slot    - wr beats upd on same slot
//  11.  test_simul_wr_upd_diff_slot    - both apply when slots differ
//  12.  test_reset_after_writes        - mid-stream reset wipes everything
// =====================================================================

#include "Vbe_message_store.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <vector>

// --- Constants mirrored from chat_pkg.sv -----------------------------
static constexpr int MAX_MSG_NUM = 64;
static constexpr int MAX_MSG_LEN = 64;          // bytes per payload
static constexpr int PAYLOAD_W   = MAX_MSG_LEN * 8 / 32;  // 32-bit words

enum : uint8_t { MSG_LOCAL = 0, MSG_REMOTE = 1, MSG_SYSTEM = 2 };
enum : uint8_t { MSG_PENDING = 0, MSG_SUCCESS = 1, MSG_FAIL = 2 };

// --- Globals ---------------------------------------------------------
static vluint64_t       g_time_ns  = 0;
static int              g_failures = 0;
static Vbe_message_store* dut      = nullptr;
static VerilatedVcdC*   tfp        = nullptr;

// --- Clock helpers ---------------------------------------------------
static void tick_half() {
    dut->eval();
    if (tfp) tfp->dump(g_time_ns);
    g_time_ns += 5;
}
static void tick() {
    dut->clk = 0; tick_half();
    dut->clk = 1; tick_half();
}

// --- Wide-signal byte access ----------------------------------------
//
// The 512-bit payload bus is laid out as 16 little-endian 32-bit words
// in Verilator's generated header. Byte i sits at:
//     word index   = i / 4
//     bit position = (i % 4) * 8
// We poke bytes through these helpers so callers don't have to remember
// the bit-packing trick.
static void payload_set_byte(uint32_t* sig, int i, uint8_t b) {
    int w   = i >> 2;
    int sh  = (i & 3) * 8;
    sig[w]  = (sig[w] & ~(0xFFu << sh)) | (((uint32_t)b) << sh);
}
static uint8_t payload_get_byte(const uint32_t* sig, int i) {
    int w  = i >> 2;
    int sh = (i & 3) * 8;
    return (sig[w] >> sh) & 0xFF;
}
static void payload_clear(uint32_t* sig) {
    for (int w = 0; w < PAYLOAD_W; w++) sig[w] = 0;
}
static void payload_load(uint32_t* sig, const std::vector<uint8_t>& bytes) {
    payload_clear(sig);
    for (size_t i = 0; i < bytes.size() && i < MAX_MSG_LEN; i++)
        payload_set_byte(sig, (int)i, bytes[i]);
}

// --- Reset / idle helpers --------------------------------------------
static void clear_all_inputs() {
    dut->wr_en = 0; dut->wr_idx = 0; dut->wr_msg_id = 0;
    dut->wr_side = 0; dut->wr_status = 0; dut->wr_len = 0;
    payload_clear(&dut->wr_payload[0]);

    dut->upd_en = 0; dut->upd_idx = 0; dut->upd_status = 0;
    dut->clear_en = 0;
    dut->rd_idx = 0; dut->lookup_msg_id = 0;
}
static void reset(int cycles = 4) {
    dut->rst_n = 0;
    clear_all_inputs();
    dut->clk = 0;
    for (int i = 0; i < cycles; i++) tick();
    dut->rst_n = 1;
    tick();
}

// --- Stimulus: drive a write for exactly one cycle -------------------
static void do_write(int idx, uint8_t msg_id, uint8_t side,
                     uint8_t status, uint8_t len,
                     const std::vector<uint8_t>& payload) {
    dut->wr_en     = 1;
    dut->wr_idx    = idx;
    dut->wr_msg_id = msg_id;
    dut->wr_side   = side;
    dut->wr_status = status;
    dut->wr_len    = len;
    payload_load(&dut->wr_payload[0], payload);
    tick();
    dut->wr_en = 0;
    payload_clear(&dut->wr_payload[0]);
}

// --- Stimulus: drive a status update for exactly one cycle ----------
static void do_status_update(int idx, uint8_t status) {
    dut->upd_en     = 1;
    dut->upd_idx    = idx;
    dut->upd_status = status;
    tick();
    dut->upd_en = 0;
}

// --- Helper: read a slot at idx (combinational) ---------------------
//
// We set the address, call eval() once so the combinational read
// outputs settle, then return them. Note we intentionally do NOT tick
// the clock -- the read port is purely combinational.
struct ReadResult {
    uint8_t valid;
    uint8_t msg_id;
    uint8_t side;
    uint8_t status;
    uint8_t len;
};
static ReadResult do_read(int idx) {
    dut->rd_idx = idx;
    dut->eval();
    return {(uint8_t)dut->rd_valid, (uint8_t)dut->rd_msg_id,
            (uint8_t)dut->rd_side,  (uint8_t)dut->rd_status,
            (uint8_t)dut->rd_len};
}

// --- Helper: lookup msg_id (combinational) ---------------------------
struct LookupResult { uint8_t hit; uint8_t idx; };
static LookupResult do_lookup(uint8_t msg_id) {
    dut->lookup_msg_id = msg_id;
    dut->eval();
    return {(uint8_t)dut->lookup_hit, (uint8_t)dut->lookup_idx};
}

// --- Assertion macro -------------------------------------------------
#define CHECK_EQ(actual, expected, label) do {                            \
    auto _a = (actual); auto _e = (expected);                             \
    if (_a != _e) {                                                       \
        ++g_failures;                                                     \
        printf("  [FAIL @ %lluns] %-40s got=0x%02llx expected=0x%02llx\n",\
               (unsigned long long)g_time_ns, (label),                    \
               (unsigned long long)_a, (unsigned long long)_e);           \
    }                                                                     \
} while (0)

// =====================================================================
// Tests
// =====================================================================

// 1) Right after reset, every slot should be invalid AND every lookup
//    should miss. Why: a stuck valid bit would mask later writes.
static void test_reset_invalidates_all() {
    printf("== test_reset_invalidates_all\n");
    reset();
    for (int i = 0; i < MAX_MSG_NUM; i++) {
        auto r = do_read(i);
        char label[40]; snprintf(label, sizeof(label), "slot[%d].valid", i);
        CHECK_EQ(r.valid, 0, label);
    }
    auto l = do_lookup(0);
    CHECK_EQ(l.hit, 0, "lookup miss on empty store");
}

// 2) Write one record, read it back. Confirms every field wires up.
static void test_basic_write_read() {
    printf("== test_basic_write_read\n");
    reset();
    std::vector<uint8_t> p = {'p','i','n','g'};
    do_write(/*idx=*/5, /*msg_id=*/42, MSG_LOCAL, MSG_PENDING,
             /*len=*/4, p);

    auto r = do_read(5);
    CHECK_EQ(r.valid,  1,           "valid set");
    CHECK_EQ(r.msg_id, 42,          "msg_id round-trip");
    CHECK_EQ(r.side,   MSG_LOCAL,   "side round-trip");
    CHECK_EQ(r.status, MSG_PENDING, "status round-trip");
    CHECK_EQ(r.len,    4,           "len round-trip");
    for (int i = 0; i < 4; i++) {
        char label[40]; snprintf(label, sizeof(label), "payload[%d]", i);
        CHECK_EQ(payload_get_byte(&dut->rd_payload[0], i), p[i], label);
    }
}

// 3) Three writes at three different slots: all coexist, no bleed.
//    Why: catches a bug where wr_idx is ignored / always writes slot 0.
static void test_multiple_slots_independent() {
    printf("== test_multiple_slots_independent\n");
    reset();
    do_write( 0,  1, MSG_LOCAL,  MSG_PENDING, 1, {'A'});
    do_write(31,  2, MSG_REMOTE, MSG_SUCCESS, 2, {'B','b'});
    do_write(63,  3, MSG_SYSTEM, MSG_FAIL,    3, {'C','c','c'});

    auto r0 = do_read(0);
    CHECK_EQ(r0.msg_id, 1, "slot 0 msg_id");
    CHECK_EQ(r0.side,   MSG_LOCAL,  "slot 0 side");
    CHECK_EQ(r0.status, MSG_PENDING,"slot 0 status");
    CHECK_EQ(r0.len,    1, "slot 0 len");

    auto r31 = do_read(31);
    CHECK_EQ(r31.msg_id, 2, "slot 31 msg_id");
    CHECK_EQ(r31.side,   MSG_REMOTE,"slot 31 side");
    CHECK_EQ(r31.status, MSG_SUCCESS,"slot 31 status");

    auto r63 = do_read(63);
    CHECK_EQ(r63.msg_id, 3, "slot 63 msg_id");
    CHECK_EQ(r63.side,   MSG_SYSTEM,"slot 63 side");
    CHECK_EQ(r63.status, MSG_FAIL,  "slot 63 status");

    // And every other slot is still invalid.
    auto r5 = do_read(5);
    CHECK_EQ(r5.valid, 0, "untouched slot stays invalid");
}

// 4) upd_en flips status, leaves the rest of the record alone.
//    Why: this is the HANDLE_TX_STATUS path -- PENDING -> SUCCESS/FAIL.
static void test_status_update() {
    printf("== test_status_update\n");
    reset();
    do_write(7, 99, MSG_LOCAL, MSG_PENDING, 3, {'a','b','c'});
    do_status_update(7, MSG_SUCCESS);
    auto r = do_read(7);
    CHECK_EQ(r.valid,  1,           "valid still 1");
    CHECK_EQ(r.msg_id, 99,          "msg_id unchanged");
    CHECK_EQ(r.side,   MSG_LOCAL,   "side unchanged");
    CHECK_EQ(r.status, MSG_SUCCESS, "status updated");
    CHECK_EQ(r.len,    3,           "len unchanged");
    CHECK_EQ(payload_get_byte(&dut->rd_payload[0], 0), 'a', "payload[0] unchanged");
}

// 5) upd_en at a never-written slot does NOT make it valid.
//    Why: a controller bug should fail closed (invalid stays invalid),
//    not advertise garbage data via lookup/read.
static void test_status_update_invalid_slot() {
    printf("== test_status_update_invalid_slot\n");
    reset();
    do_status_update(10, MSG_SUCCESS);
    auto r = do_read(10);
    CHECK_EQ(r.valid, 0, "slot stays invalid after upd-only");
    auto l = do_lookup(0);  // also confirms no spurious hits
    CHECK_EQ(l.hit, 0, "no lookup hits on invalid slot");
}

// 6) Full 64-byte payload, distinct value in every slot.
//    Why: catches off-by-one / endian flips in the wide bus packing.
static void test_wide_payload() {
    printf("== test_wide_payload\n");
    reset();
    std::vector<uint8_t> p(MAX_MSG_LEN);
    for (int i = 0; i < MAX_MSG_LEN; i++) p[i] = (uint8_t)(i * 3 + 7);

    do_write(11, 5, MSG_REMOTE, MSG_SUCCESS, MAX_MSG_LEN, p);
    do_read(11);
    for (int i = 0; i < MAX_MSG_LEN; i++) {
        char label[40]; snprintf(label, sizeof(label), "byte[%d]", i);
        CHECK_EQ(payload_get_byte(&dut->rd_payload[0], i), p[i], label);
    }
}

// 7) Lookup finds the right slot by msg_id.
static void test_lookup_hit() {
    printf("== test_lookup_hit\n");
    reset();
    do_write(3, 17, MSG_LOCAL, MSG_PENDING, 1, {'x'});
    auto l = do_lookup(17);
    CHECK_EQ(l.hit, 1, "lookup hit on existing msg_id");
    CHECK_EQ(l.idx, 3, "lookup idx is the right slot");
}

// 8) Lookup miss when no valid slot has the msg_id.
static void test_lookup_miss() {
    printf("== test_lookup_miss\n");
    reset();
    do_write(3, 17, MSG_LOCAL, MSG_PENDING, 1, {'x'});
    auto l = do_lookup(99);
    CHECK_EQ(l.hit, 0, "lookup miss for absent msg_id");
}

// 9) Two valid slots share a msg_id (which is unusual but possible if
//    msg_id wraps after 256 sends): lookup must return the LOWEST idx.
//    Why: pin down the policy so callers and the lookup match.
static void test_lookup_collision_lowest_idx() {
    printf("== test_lookup_collision_lowest_idx\n");
    reset();
    do_write(7,  5, MSG_LOCAL,  MSG_PENDING, 1, {'a'});
    do_write(20, 5, MSG_REMOTE, MSG_SUCCESS, 1, {'b'});
    auto l = do_lookup(5);
    CHECK_EQ(l.hit, 1, "lookup hit on collision");
    CHECK_EQ(l.idx, 7, "lowest matching idx wins");
}

// 10) wr_en and upd_en hit the SAME slot in the same cycle. The write
//     wins (status takes wr_status, not upd_status). Why: this is the
//     priority we declared in the module header; tests lock it in.
static void test_simul_wr_upd_same_slot() {
    printf("== test_simul_wr_upd_same_slot\n");
    reset();

    // Drive both wr and upd on slot 4 in a single cycle.
    dut->wr_en     = 1;
    dut->wr_idx    = 4;
    dut->wr_msg_id = 33;
    dut->wr_side   = MSG_LOCAL;
    dut->wr_status = MSG_PENDING;     // <-- write side
    dut->wr_len    = 1;
    payload_load(&dut->wr_payload[0], {'q'});

    dut->upd_en     = 1;
    dut->upd_idx    = 4;
    dut->upd_status = MSG_SUCCESS;    // <-- update side, should be ignored

    tick();
    dut->wr_en  = 0;
    dut->upd_en = 0;

    auto r = do_read(4);
    CHECK_EQ(r.valid,  1,           "slot is valid");
    CHECK_EQ(r.status, MSG_PENDING, "wr_status wins over upd_status");
}

// 11) wr at one slot, upd at a different slot, in the same cycle:
//     both should apply.
static void test_simul_wr_upd_diff_slot() {
    printf("== test_simul_wr_upd_diff_slot\n");
    reset();
    // Pre-populate slot 8 so upd has something to update.
    do_write(8, 50, MSG_REMOTE, MSG_PENDING, 1, {'r'});

    // Same-cycle: wr to slot 0, upd to slot 8.
    dut->wr_en     = 1;
    dut->wr_idx    = 0;
    dut->wr_msg_id = 60;
    dut->wr_side   = MSG_LOCAL;
    dut->wr_status = MSG_PENDING;
    dut->wr_len    = 1;
    payload_load(&dut->wr_payload[0], {'L'});

    dut->upd_en     = 1;
    dut->upd_idx    = 8;
    dut->upd_status = MSG_SUCCESS;

    tick();
    dut->wr_en  = 0;
    dut->upd_en = 0;

    auto r0 = do_read(0);
    CHECK_EQ(r0.valid,  1,           "slot 0 written");
    CHECK_EQ(r0.msg_id, 60,          "slot 0 msg_id");

    auto r8 = do_read(8);
    CHECK_EQ(r8.valid,  1,           "slot 8 still valid");
    CHECK_EQ(r8.msg_id, 50,          "slot 8 msg_id unchanged");
    CHECK_EQ(r8.status, MSG_SUCCESS, "slot 8 status updated");
}

// 13a) clear_en single-pulse invalidates every slot in one cycle.
static void test_clear_en_invalidates_all() {
    printf("== test_clear_en_invalidates_all\n");
    reset();
    do_write(0,  1, MSG_LOCAL,  MSG_PENDING, 1, {'a'});
    do_write(20, 2, MSG_REMOTE, MSG_SUCCESS, 1, {'b'});
    do_write(63, 3, MSG_SYSTEM, MSG_FAIL,    1, {'c'});

    // Pulse clear_en for one cycle.
    dut->clear_en = 1;
    tick();
    dut->clear_en = 0;

    for (int i : {0, 20, 63}) {
        auto r = do_read(i);
        char lbl[40]; snprintf(lbl, sizeof(lbl), "slot[%d] cleared", i);
        CHECK_EQ(r.valid, 0, lbl);
    }
    auto l1 = do_lookup(1); CHECK_EQ(l1.hit, 0, "msg_id 1 gone after clear");
    auto l2 = do_lookup(2); CHECK_EQ(l2.hit, 0, "msg_id 2 gone after clear");
}

// 13b) clear_en wins over wr_en in the same cycle.
//      Why: when peer-name change clears the store, any racing local
//      write should be discarded, not preserved.
static void test_clear_en_beats_wr_same_cycle() {
    printf("== test_clear_en_beats_wr_same_cycle\n");
    reset();
    do_write(5, 10, MSG_LOCAL, MSG_PENDING, 1, {'A'});

    dut->wr_en     = 1;
    dut->wr_idx    = 5;
    dut->wr_msg_id = 99;
    dut->wr_side   = MSG_LOCAL;
    dut->wr_status = MSG_PENDING;
    dut->wr_len    = 1;
    payload_load(&dut->wr_payload[0], {'Z'});

    dut->clear_en = 1;
    tick();
    dut->wr_en    = 0;
    dut->clear_en = 0;

    auto r = do_read(5);
    CHECK_EQ(r.valid, 0, "wr suppressed by clear");
}

// 13c) After clear, normal writes work again.
static void test_clear_then_writes_succeed() {
    printf("== test_clear_then_writes_succeed\n");
    reset();
    do_write(2, 1, MSG_LOCAL, MSG_PENDING, 1, {'a'});

    dut->clear_en = 1; tick(); dut->clear_en = 0;

    do_write(2, 7, MSG_REMOTE, MSG_SUCCESS, 1, {'z'});
    auto r = do_read(2);
    CHECK_EQ(r.valid,  1,           "writable post-clear");
    CHECK_EQ(r.msg_id, 7,           "new msg_id");
    CHECK_EQ(r.side,   MSG_REMOTE,  "new side");
    CHECK_EQ(r.status, MSG_SUCCESS, "new status");
    CHECK_EQ(payload_get_byte(&dut->rd_payload[0], 0), 'z', "new payload");
}

// 12) Reset mid-stream invalidates everything again.
static void test_reset_after_writes() {
    printf("== test_reset_after_writes\n");
    reset();
    do_write(2,  1, MSG_LOCAL,  MSG_PENDING, 1, {'a'});
    do_write(40, 2, MSG_REMOTE, MSG_SUCCESS, 1, {'b'});
    reset();
    for (int i : {0, 2, 40, 63}) {
        auto r = do_read(i);
        char label[40]; snprintf(label, sizeof(label), "slot[%d] cleared", i);
        CHECK_EQ(r.valid, 0, label);
    }
    auto l1 = do_lookup(1); CHECK_EQ(l1.hit, 0, "msg_id 1 gone after reset");
    auto l2 = do_lookup(2); CHECK_EQ(l2.hit, 0, "msg_id 2 gone after reset");
}

// =====================================================================
int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    dut = new Vbe_message_store;
    tfp = new VerilatedVcdC;
    dut->trace(tfp, /*levels=*/99);
    tfp->open("sim/waves/be_message_store.vcd");

    test_reset_invalidates_all();
    test_basic_write_read();
    test_multiple_slots_independent();
    test_status_update();
    test_status_update_invalid_slot();
    test_wide_payload();
    test_lookup_hit();
    test_lookup_miss();
    test_lookup_collision_lowest_idx();
    test_simul_wr_upd_same_slot();
    test_simul_wr_upd_diff_slot();
    test_clear_en_invalidates_all();
    test_clear_en_beats_wr_same_cycle();
    test_clear_then_writes_succeed();
    test_reset_after_writes();

    tfp->close();
    delete tfp;
    delete dut;

    if (g_failures == 0) { printf("\nPASS  (all checks)\n"); return 0; }
    printf("\nFAIL  %d check(s) failed\n", g_failures);
    return 1;
}
