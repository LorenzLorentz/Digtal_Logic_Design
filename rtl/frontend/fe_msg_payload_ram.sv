// =====================================================================
// fe_msg_payload_ram.sv  --  History-slot payload BRAM
// ---------------------------------------------------------------------
// Per-message byte storage backing fe_render_decoder's history ring.
// Without this module the decoder kept N_HIST_STORED full-row
// register copies (slot_payload_q[]) of every message; at
// MAX_MSG_LEN >= 128 that exploded LUT usage on Artix-7.
//
// Layout (byte-addressed, flat):
//   address = {wr_slot[HIST_W-1:0], wr_byte_idx[$clog2(MAX_MSG_LEN)-1:0]}
//   N_HIST_STORED must be a power of two so the concat == slot*MAX + idx.
//
// Ports: simple dual-port (one synchronous write, one synchronous read,
// both in the chat clock domain). Read data is registered, so it
// appears one clock AFTER the address is driven. The same
// coding-style Vivado uses for fe_text_ram, so synthesis cleanly
// infers BRAM (4-8 BRAM18 blocks for N_HIST_STORED=64, MAX_MSG_LEN=128).
//
// No initialisation: garbage on power-up is fine. Slots only become
// observable after the corresponding RENDER_APPEND_* writes valid
// payload bytes.
// =====================================================================

`ifndef FE_MSG_PAYLOAD_RAM_SV
`define FE_MSG_PAYLOAD_RAM_SV

module fe_msg_payload_ram
    import chat_pkg::*;
    import fe_pkg::*;
#(
    parameter int BYTE_IDX_W = $clog2(MAX_MSG_LEN)
) (
    input  logic                       wr_clk,
    input  logic                       wr_en,
    input  logic [HIST_W-1:0]          wr_slot,
    input  logic [BYTE_IDX_W-1:0]      wr_byte_idx,
    input  byte_t                      wr_data,

    input  logic                       rd_clk,
    input  logic [HIST_W-1:0]          rd_slot,
    input  logic [BYTE_IDX_W-1:0]      rd_byte_idx,
    output byte_t                      rd_data
);

    localparam int DEPTH = N_HIST_STORED * MAX_MSG_LEN;

    byte_t mem [DEPTH];

    always_ff @(posedge wr_clk) begin
        if (wr_en) mem[{wr_slot, wr_byte_idx}] <= wr_data;
    end

    byte_t rd_q;
    always_ff @(posedge rd_clk) begin
        rd_q <= mem[{rd_slot, rd_byte_idx}];
    end
    assign rd_data = rd_q;

endmodule

`endif  // FE_MSG_PAYLOAD_RAM_SV
