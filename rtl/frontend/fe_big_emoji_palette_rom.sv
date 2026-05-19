// =====================================================================
// fe_big_emoji_palette_rom.sv  --  per-emoji RGB888 palette ROM
// ---------------------------------------------------------------------
// 16 entries per emoji x BIG_EMOJI_COUNT emojis. Entry 0 of each emoji
// is the "transparent" marker and is never read; the scan pipeline must
// check pix_idx != 0 before consulting this ROM. Indices 1..15 hold the
// 15 quantised colours produced by scripts/gen_big_emoji.py.
//
// Address = {emoji_id[2:0], idx[3:0]} (7 bits). Hex file has 80 lines
// (5 emojis); the ROM is sized to 128 entries so emoji_id 0..7 are all
// valid addresses (unused slots default to 0).
//
// Stored as a flat 24-bit array; small enough that Vivado typically
// infers distributed RAM.
// =====================================================================

`ifndef FE_BIG_EMOJI_PALETTE_ROM_SV
`define FE_BIG_EMOJI_PALETTE_ROM_SV

module fe_big_emoji_palette_rom (
    input  logic [2:0] emoji_id,
    input  logic [3:0] idx,
    output logic [7:0] r,
    output logic [7:0] g,
    output logic [7:0] b
);

    logic [23:0] mem [128];

    initial begin
`ifdef SYNTHESIS
        $readmemh("fe_big_emoji_palette.hex", mem);
`else
        $readmemh("rtl/frontend/fe_big_emoji_palette.hex", mem);
`endif
    end

    logic [23:0] entry;
    assign entry = mem[{emoji_id, idx}];
    assign r = entry[23:16];
    assign g = entry[15:8];
    assign b = entry[7:0];

endmodule

`endif  // FE_BIG_EMOJI_PALETTE_ROM_SV
