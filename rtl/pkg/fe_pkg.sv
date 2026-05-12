// =====================================================================
// fe_pkg.sv  --  Frontend-wide configuration constants
// ---------------------------------------------------------------------
// Single source of truth for everything the frontend pipeline needs:
//   - text_ram dimensions and layout
//   - history ring sizing + visible-window sizing
//   - reserved sprite code points
//   - pixel-timing geometry (HSYNC/VSYNC)
//   - visual constants (blink rate, splash positioning, palette)
//   - font hex path
//
// Modules in rtl/frontend/ import this package and read the constants
// directly. Tweak any value here and every consumer recompiles
// against the new value -- no per-module duplicate parameters.
//
// Generic submodules (fe_text_ram, fe_video_timing) still take
// parameters, but the wrappers above them feed values from fe_pkg.
// =====================================================================

`ifndef FE_PKG_SV
`define FE_PKG_SV

package fe_pkg;

    import chat_pkg::byte_t;

    // -----------------------------------------------------------------
    // text_ram dimensions
    // -----------------------------------------------------------------
    localparam int FE_N_ROWS = 128;
    localparam int FE_N_COLS = 128;
    localparam int FE_ROW_W  = $clog2(FE_N_ROWS);
    localparam int FE_COL_W  = $clog2(FE_N_COLS);

    // -----------------------------------------------------------------
    // text_ram physical row layout
    // -----------------------------------------------------------------
    localparam int TITLE_ROW         = 0;     // titlebar
    localparam int HIST_ROW_START    = 2;     // first ring slot
    localparam int HIST_ROW_END      = 65;    // last ring slot (64 total)
    localparam int INPUT_ROW         = 67;    // "> ..." input bar
    // Column layout
    localparam int INPUT_PREFIX_LEN  = 2;     // "> "

    // Bubble layout for history rows
    localparam int BUBBLE_MARGIN_L   = 2;     // left margin for remote bubbles
    localparam int BUBBLE_MARGIN_R   = 2;     // right margin for local bubbles
    localparam int BUBBLE_RIGHT_EDGE = 97;    // col where ] sits for local msgs

    // -----------------------------------------------------------------
    // History ring + visible window
    // -----------------------------------------------------------------
    localparam int N_HIST_STORED  = HIST_ROW_END - HIST_ROW_START + 1;
    localparam int N_HIST_VISIBLE = 33;
    localparam int HIST_W         = (N_HIST_STORED <= 1)
                                      ? 1 : $clog2(N_HIST_STORED);
    localparam int SCROLL_MAX     = N_HIST_STORED - N_HIST_VISIBLE;
    localparam int SCROLL_W       = (SCROLL_MAX <= 1)
                                      ? 1 : $clog2(SCROLL_MAX + 1);

    // -----------------------------------------------------------------
    // Sprite codes (in 0xF0..0xFF -- the reserved sprite range)
    // -----------------------------------------------------------------
    // Bubble border sprites (0xF0..0xF2 legacy, kept for glyph ROM compat)
    localparam byte_t SPRITE_BL      = 8'hF3;  // normal left border (rounded)
    localparam byte_t SPRITE_BR      = 8'hF4;  // normal right border (rounded)
    localparam byte_t SPRITE_FBL     = 8'hF6;  // fail left border (square)
    localparam byte_t SPRITE_FBR     = 8'hF7;  // fail right border (square)

    // -----------------------------------------------------------------
    // Pixel timing  (800x600 @ 60Hz, pixel clock = 40 MHz)
    //   Switched off the 72Hz example mode: many modern monitors don't
    //   accept 72Hz over HDMI and pop "out of range" even while the
    //   image briefly shows. 60Hz is in every monitor's EDID.
    //   ip_pll must be regenerated to output 40 MHz to match.
    // -----------------------------------------------------------------
    localparam int    HWIDTH = 12;
    localparam int    HSIZE  = 800;
    localparam int    HFP    = 840;
    localparam int    HSP    = 968;
    localparam int    HMAX   = 1056;
    localparam int    VSIZE  = 600;
    localparam int    VFP    = 601;
    localparam int    VSP    = 605;
    localparam int    VMAX   = 628;
    localparam logic  HSPP   = 1'b1;       // hsync polarity (active high)
    localparam logic  VSPP   = 1'b1;       // vsync polarity (active high)

    // -----------------------------------------------------------------
    // Visual constants
    // -----------------------------------------------------------------
    // ~2 Hz cursor blink at 60 Hz frame rate -> toggle every 30 frames.
    localparam int    BLINK_FRAMES = 30;

    // Splash text: SPLASH_COLS chars wide, 2 rows tall, centered.
    localparam int    SPLASH_COLS    = 32;
    localparam int    SPLASH_H_LEFT  = (HSIZE - SPLASH_COLS * 8) / 2;
    localparam int    SPLASH_V_TOP   = (VSIZE - 32) / 2;

    // -----------------------------------------------------------------
    // Colour palette (8-bit per channel, full RGB to ip_rgb2dvi)
    // -----------------------------------------------------------------
    // Foreground (text): bright white.
    localparam logic [7:0] COL_FG_R         = 8'hFF;
    localparam logic [7:0] COL_FG_G         = 8'hFF;
    localparam logic [7:0] COL_FG_B         = 8'hFF;

    // Default background (history rows).
    localparam logic [7:0] COL_BG_R         = 8'h00;
    localparam logic [7:0] COL_BG_G         = 8'h00;
    localparam logic [7:0] COL_BG_B         = 8'h00;

    // Titlebar (row 0): dark blue.
    localparam logic [7:0] COL_TITLE_BG_R   = 8'h10;
    localparam logic [7:0] COL_TITLE_BG_G   = 8'h20;
    localparam logic [7:0] COL_TITLE_BG_B   = 8'h60;

    // Input bar (row INPUT_ROW): dark gray.
    localparam logic [7:0] COL_INPUT_BG_R   = 8'h20;
    localparam logic [7:0] COL_INPUT_BG_G   = 8'h20;
    localparam logic [7:0] COL_INPUT_BG_B   = 8'h20;

    // Splash backgrounds per non-CONNECTED state.
    localparam logic [7:0] COL_BOOT_BG_R    = 8'h08;
    localparam logic [7:0] COL_BOOT_BG_G    = 8'h10;
    localparam logic [7:0] COL_BOOT_BG_B    = 8'h30;
    localparam logic [7:0] COL_HS_BG_R      = 8'h08;
    localparam logic [7:0] COL_HS_BG_G      = 8'h30;
    localparam logic [7:0] COL_HS_BG_B      = 8'h08;
    localparam logic [7:0] COL_DISC_BG_R    = 8'h30;
    localparam logic [7:0] COL_DISC_BG_G    = 8'h08;
    localparam logic [7:0] COL_DISC_BG_B    = 8'h08;

    // Splash text foreground (slightly off-white to avoid burn-in).
    localparam logic [7:0] COL_SPLASH_FG_R  = 8'hF0;
    localparam logic [7:0] COL_SPLASH_FG_G  = 8'hF0;
    localparam logic [7:0] COL_SPLASH_FG_B  = 8'hF0;

    // -----------------------------------------------------------------
    // Font ROM file path
    // ---
    // Hard-coded inside fe_glyph_rom.sv via `ifdef SYNTHESIS` because
    // (a) Vivado's synth subset rejects the SV `string` type, and
    // (b) Verilator and Vivado have different working directories at
    //     $readmemh time, so a single literal could never satisfy both.
    // -----------------------------------------------------------------

endpackage : fe_pkg

`endif  // FE_PKG_SV
