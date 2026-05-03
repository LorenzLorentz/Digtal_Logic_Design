// =====================================================================
// fe_text_ram.sv  --  Dual-port character grid for the frontend
// ---------------------------------------------------------------------
// Storage shape: N_ROWS x N_COLS bytes. Each cell is a "code point"
// (printable ASCII or sprite index in 0xF0..0xFF). Glyph translation
// happens at scan time, not here.
//
// Two clock domains:
//   wr_clk  - decoder side (chat clock, currently 100 MHz)
//   rd_clk  - pixel scan side (HDMI pixel clock, e.g. 50 MHz)
// Tied together in chat_top for now. The two-process pattern below
// is the canonical dual-port BRAM style on Xilinx/Intel toolchains
// and synthesizes as true-dual-port BRAM when wr_clk != rd_clk.
//
// Init / reset:
//   Memory is initialised to 0x20 (ASCII space) via an `initial` block.
//   Xilinx and Intel BRAM honour this. There is no synchronous clear --
//   that would cost N_ROWS*N_COLS cycles on every reset, far more than
//   the user ever waits to see a fresh boot screen.
//
// Read latency:
//   1 cycle (registered output). Scan side must add 1 column of
//   pipeline delay when computing horizontal addresses.
// =====================================================================

`ifndef FE_TEXT_RAM_SV
`define FE_TEXT_RAM_SV

module fe_text_ram
    import chat_pkg::*;
    import fe_pkg::*;
#(
    // Defaults pulled from fe_pkg; instances can still override if a
    // future board needs a different grid.
    parameter int N_ROWS = FE_N_ROWS,
    parameter int N_COLS = FE_N_COLS,
    parameter int ROW_W  = $clog2(N_ROWS),
    parameter int COL_W  = $clog2(N_COLS)
) (
    // ---- Write port (decoder side) ----
    input  logic               wr_clk,
    input  logic               wr_en,
    input  logic [ROW_W-1:0]   wr_row,
    input  logic [COL_W-1:0]   wr_col,
    input  byte_t              wr_code,

    // ---- Read port A (scan side, registered output) ----
    input  logic               rd_clk,
    input  logic [ROW_W-1:0]   rd_row,
    input  logic [COL_W-1:0]   rd_col,
    output byte_t              rd_code,

    // ---- Read port B (observability / test, registered output) ----
    input  logic               rd2_clk,
    input  logic [ROW_W-1:0]   rd2_row,
    input  logic [COL_W-1:0]   rd2_col,
    output byte_t              rd2_code
);

    localparam int DEPTH = N_ROWS * N_COLS;

    byte_t mem [DEPTH];

    initial begin
        for (int i = 0; i < DEPTH; i++)
            mem[i] = 8'h20;  // ASCII space
    end

    // Address = {row, col}. N_COLS must be a power of two so the
    // concat equals row*N_COLS + col without an explicit multiplier.
    // (Default N_COLS=128 satisfies this.)
    always_ff @(posedge wr_clk) begin
        if (wr_en) mem[{wr_row, wr_col}] <= wr_code;
    end

    byte_t rd_code_q;
    always_ff @(posedge rd_clk) begin
        rd_code_q <= mem[{rd_row, rd_col}];
    end
    assign rd_code = rd_code_q;

    byte_t rd2_code_q;
    always_ff @(posedge rd2_clk) begin
        rd2_code_q <= mem[{rd2_row, rd2_col}];
    end
    assign rd2_code = rd2_code_q;

endmodule

`endif  // FE_TEXT_RAM_SV
