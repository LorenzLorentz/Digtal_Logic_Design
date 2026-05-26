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
    // Input area is a multi-row buffer so Shift+Enter newlines render on
    // their own physical row. MAX_INPUT_LINES must match the multi-line
    // cap used by the bubble parser (fe_render_decoder MAX_LINES).
    localparam int MAX_INPUT_LINES   = 16;
    localparam int INPUT_ROW_START   = 67;
    localparam int INPUT_ROW_END     = INPUT_ROW_START + MAX_INPUT_LINES - 1;
    // Column layout
    localparam int INPUT_PREFIX_LEN  = 2;     // "> "

    // Bubble layout for history rows
    localparam int BUBBLE_MARGIN_L   = 2;     // left margin for remote bubbles
    localparam int BUBBLE_MARGIN_R   = 2;     // right margin for local bubbles
    localparam int BUBBLE_RIGHT_EDGE = 97;    // col where ] sits for local msgs

    // -----------------------------------------------------------------
    // History ring + visible window
    // -----------------------------------------------------------------
    localparam int N_HIST_STORED   = HIST_ROW_END - HIST_ROW_START + 1;
    localparam int N_HIST_VISIBLE  = 29;
    localparam int N_INPUT_VISIBLE = 5;
    localparam int HIST_W          = (N_HIST_STORED <= 1)
                                       ? 1 : $clog2(N_HIST_STORED);
    localparam int SCROLL_MAX      = N_HIST_STORED - N_HIST_VISIBLE;
    localparam int SCROLL_W        = (SCROLL_MAX <= 1)
                                       ? 1 : $clog2(SCROLL_MAX + 1);
    // Input-side scroll: indexes which input line lands at screen row
    // INPUT_SCREEN_START. Max value puts the bottom of the input buffer
    // at the bottom of the visible input window.
    localparam int INPUT_SCROLL_MAX = (MAX_INPUT_LINES > N_INPUT_VISIBLE)
                                        ? (MAX_INPUT_LINES - N_INPUT_VISIBLE)
                                        : 0;
    localparam int INPUT_SCROLL_W   = (INPUT_SCROLL_MAX <= 1)
                                        ? 1 : $clog2(INPUT_SCROLL_MAX + 1);
    localparam int INPUT_LINE_W     = (MAX_INPUT_LINES <= 1)
                                        ? 1 : $clog2(MAX_INPUT_LINES);
    localparam int INPUT_N_LINES_W  = $clog2(MAX_INPUT_LINES + 1);

    // Screen-pixel layout for the input area (used by mouse region detect).
    //   screen row 0       : title
    //   screen row 1       : separator
    //   screen rows 2..30  : 29 history rows
    //   screen row 31      : separator
    //   screen rows 32..36 : 5 input rows
    //   screen rows 37+    : blank
    localparam int INPUT_SCREEN_START = 2 + N_HIST_VISIBLE + 1;       // 32
    localparam int INPUT_SCREEN_END   = INPUT_SCREEN_START
                                        + N_INPUT_VISIBLE - 1;        // 36
    localparam int INPUT_PIXEL_Y_LO   = INPUT_SCREEN_START * 16;      // 512
    localparam int INPUT_PIXEL_Y_HI   = (INPUT_SCREEN_END + 1) * 16 - 1; // 591
    localparam int INPUT_LIMIT_MARK_COL = BUBBLE_RIGHT_EDGE + 2;       // 99

    // -----------------------------------------------------------------
    // Sprite codes (in 0xF0..0xFF -- the reserved sprite range)
    // -----------------------------------------------------------------
    // Bubble border sprites (0xF0..0xF2 legacy, kept for glyph ROM compat)
    localparam byte_t SPRITE_BL      = 8'hF3;  // normal left border (rounded)
    localparam byte_t SPRITE_BR      = 8'hF4;  // normal right border (rounded)
    localparam byte_t SPRITE_FBL     = 8'hF6;  // fail left border (square)
    localparam byte_t SPRITE_FBR     = 8'hF7;  // fail right border (square)

    // Multi-line bubble border sprites: top-aligned corner + vertical
    // exiting the bottom (SPRITE_*_TOP); pure vertical (SPRITE_*_MID);
    // vertical entering from top + bottom-aligned corner (SPRITE_*_BOT).
    // fe_scan uses the glyph outline to clip the bubble fill.
    localparam byte_t SPRITE_BL_TOP  = 8'hF8;
    localparam byte_t SPRITE_BR_TOP  = 8'hF9;
    localparam byte_t SPRITE_BL_BOT  = 8'hFA;
    localparam byte_t SPRITE_BR_BOT  = 8'hFB;
    localparam byte_t SPRITE_BL_MID  = 8'hFC;
    localparam byte_t SPRITE_BR_MID  = 8'hFD;

    // Per-cell bubble background attribute stored alongside text_ram.
    // The low 8 bits remain the glyph code; this sideband lets scan
    // paint a filled bubble behind ordinary text and spaces.
    localparam logic [1:0] BUBBLE_ATTR_NONE   = 2'd0;
    localparam logic [1:0] BUBBLE_ATTR_REMOTE = 2'd1;
    localparam logic [1:0] BUBBLE_ATTR_LOCAL  = 2'd2;

    // Emoji glyphs produced by backend token expansion.
    localparam byte_t EMOJI_HAPPY = 8'hE0;
    localparam byte_t EMOJI_SAD   = 8'hE1;
    localparam byte_t EMOJI_HEART = 8'hE2;
    localparam byte_t EMOJI_OK    = 8'hE3;
    localparam byte_t EMOJI_LAUGH = 8'hE4;
    localparam byte_t EMOJI_WINK  = 8'hE5;
    localparam byte_t EMOJI_ANGRY = 8'hE6;
    localparam byte_t EMOJI_STAR  = 8'hE7;
    localparam byte_t EMOJI_FIRE  = 8'hE8;
    localparam byte_t EMOJI_YES   = 8'hE9;
    localparam byte_t EMOJI_NO    = 8'hEA;
    localparam byte_t EMOJI_UP    = 8'hEB;
    localparam byte_t EMOJI_DOWN  = 8'hEC;
    localparam byte_t EMOJI_DOGE  = 8'hED;
    localparam byte_t EMOJI_MAIRUO = 8'hEE;

    // Big-emoji tile codes occupy 0x80..(BIG_EMOJI_END_EXCL - 1). One
    // anchor byte per emoji (the user-typed `\Name` token expands to
    // just the anchor); the frontend lays out the bubble as N_ROWS x
    // N_COLS character cells and fills them with codes anchor + (sub_row
    // * N_COLS + sub_col). Pixel ROM is indexed by (code - BASE, gy)
    // and returns a 4 bpp row whose nibbles look up the per-emoji
    // palette (idx 0 = transparent / bubble bg, 1..15 = quantised colour).
`ifdef SYNTHESIS
    `include "fe_big_emoji_codes.svh"
`else
    `include "rtl/pkg/fe_big_emoji_codes.svh"
`endif

    // Standalone status icons. 0xF2 is the "X" mark, drawn to the left
    // of failed local bubbles so the fail is unambiguous even if the
    // rounded vs. square corner sprites are hard to tell apart at a glance.
    localparam byte_t SPRITE_FAIL_X   = 8'hF2;

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

    // Filled chat bubbles, drawn above the SRAM wallpaper.
    localparam logic [7:0] COL_REMOTE_BUBBLE_BG_R = 8'h07;
    localparam logic [7:0] COL_REMOTE_BUBBLE_BG_G = 8'h5E;
    localparam logic [7:0] COL_REMOTE_BUBBLE_BG_B = 8'h54;
    localparam logic [7:0] COL_LOCAL_BUBBLE_BG_R  = 8'h02;
    localparam logic [7:0] COL_LOCAL_BUBBLE_BG_G  = 8'h28;
    localparam logic [7:0] COL_LOCAL_BUBBLE_BG_B  = 8'h23;

    // -----------------------------------------------------------------
    // SRAM-backed visual assets
    // -----------------------------------------------------------------
    // The lab board's BaseRAM is 4 MiB, read as 32-bit little-endian words.
    // Store assets as packed RGB565 pixels in byte order low byte, high byte.
    // Background: 800x600x2 = 960000 bytes at byte offset 0.
    // Avatars: 16x16x2 each, aligned immediately after the background.
    localparam int ASSET_BG_W_PX       = HSIZE;
    localparam int ASSET_BG_H_PX       = VSIZE;
    localparam int ASSET_AVATAR_W_PX   = 16;
    localparam int ASSET_AVATAR_H_PX   = 16;
    localparam int ASSET_BG_BASE_BYTES = 0;
    localparam int ASSET_LOCAL_AVATAR_BASE_BYTES  = ASSET_BG_W_PX
                                                    * ASSET_BG_H_PX * 2;
    localparam int ASSET_REMOTE_AVATAR_BASE_BYTES = ASSET_LOCAL_AVATAR_BASE_BYTES
                                                    + ASSET_AVATAR_W_PX
                                                    * ASSET_AVATAR_H_PX * 2;

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
