#!/usr/bin/env python3
r"""
Build big-emoji ROM contents + SystemVerilog/C++ headers from
assets/big_emoji/*.{jpg,png}.

Outputs (all under repo root):
  rtl/frontend/fe_big_emoji_pixels.hex   tile pixel ROM, 4bpp packed 32-bit/row
  rtl/frontend/fe_big_emoji_palette.hex  per-emoji palette ROM, 24-bit RGB
  rtl/pkg/fe_big_emoji_codes.svh         anchor byte constants
  rtl/backend/be_big_emoji_tokens.svh    encoder if-elseif branches
  sim/tb/common/big_emoji_codes.h        C++ mirror for tests

Asset convention:
  assets/big_emoji/<Name>.<jpg|png>
  Filename stem = token name; backend matches "\<Name>" (Name starts with
  a capital letter, which is what differentiates big from small emoji).
  Emojis are sorted alphabetically; their order fixes their anchor codes.

Image processing:
  - Resize to 48x48 px, then split into N_ROWS x N_COLS tiles (3 x 6).
  - Each tile is one 8x16 character cell, MSB-first per row (matches fe_font).
  - 4 bpp per pixel; index 0 = transparent (renders as bubble bg), 1..15 are
    quantized colors per-emoji via PIL median-cut.
  - Background is auto-detected from the four corners (median) and keyed out
    with a per-channel tolerance (default 25). --no-key disables keying;
    --bg-tol overrides the tolerance.

Run:
  python3 scripts/gen_big_emoji.py
"""

import argparse
import sys
from pathlib import Path

import numpy as np
from PIL import Image

# ---------- layout constants (must match fe_pkg.sv) ---------------------
EMOJI_W_PX = 48
EMOJI_H_PX = 48
TILE_W_PX  = 8
TILE_H_PX  = 16
N_COLS     = EMOJI_W_PX // TILE_W_PX        # 6
N_ROWS     = EMOJI_H_PX // TILE_H_PX        # 3
TILES_PER_EMOJI = N_ROWS * N_COLS           # 18

ANCHOR_BASE = 0x80
MAX_EMOJIS  = 5
PIXEL_ROM_SLOTS = 96                        # 0x80..0xDF available range

PALETTE_ENTRIES_PER_EMOJI = 16              # index 0 unused, 1..15 colors
DEFAULT_BG_TOL = 25

# ---------- paths -------------------------------------------------------
ROOT        = Path(__file__).resolve().parent.parent
ASSET_DIR   = ROOT / "assets" / "big_emoji"
PIXEL_HEX   = ROOT / "rtl" / "frontend" / "fe_big_emoji_pixels.hex"
PALETTE_HEX = ROOT / "rtl" / "frontend" / "fe_big_emoji_palette.hex"
CODES_SVH   = ROOT / "rtl" / "pkg"      / "fe_big_emoji_codes.svh"
TOKENS_SVH  = ROOT / "rtl" / "backend"  / "be_big_emoji_tokens.svh"
TEST_H      = ROOT / "sim" / "tb" / "common" / "big_emoji_codes.h"


# ---------- image -> indices + palette ----------------------------------
def detect_bg(arr: np.ndarray) -> np.ndarray:
    """Estimate background colour as the per-channel median of the four corners."""
    corners = np.stack([arr[0, 0], arr[0, -1], arr[-1, 0], arr[-1, -1]])
    return np.median(corners, axis=0).astype(int)


def key_and_quantize(img: Image.Image, bg_tol: int, no_key: bool):
    """Return (indices[H,W] uint8 in 0..15, palette[15,3] uint8).

    Index 0 always means "transparent" (the renderer falls back to bubble
    bg). Indices 1..15 map into palette[0..14]. When --no-key is set,
    index 0 is left unused and all 16 quantizer slots map to 1..15+1 (the
    16th is dropped to keep the SV-side single transparency convention).
    """
    img = img.convert("RGB").resize(
        (EMOJI_W_PX, EMOJI_H_PX), Image.Resampling.LANCZOS
    )
    arr = np.asarray(img)  # H, W, 3
    bg  = detect_bg(arr)

    if no_key:
        # No keying: quantize the whole image to 15 colours, map 0..14 -> 1..15.
        quant = img.quantize(
            colors=15, method=Image.Quantize.MEDIANCUT, dither=Image.Dither.NONE
        )
        idx = np.asarray(quant).astype(np.uint8) + 1
        pal = np.asarray(quant.getpalette()[: 15 * 3]).reshape(15, 3).astype(np.uint8)
        return idx, pal

    # Build the keying mask first (relative to *original* pixel colour,
    # before any quantisation rounding).
    diff = np.abs(arr.astype(int) - bg)
    mask_bg = np.all(diff <= bg_tol, axis=-1)

    if not np.any(~mask_bg):
        # Pathological: whole image read as background. Emit blank emoji.
        return (
            np.zeros(arr.shape[:2], dtype=np.uint8),
            np.zeros((15, 3), dtype=np.uint8),
        )

    # Normalise background pixels to exactly `bg` so the quantiser only
    # spends one palette slot on them.
    norm = arr.copy()
    norm[mask_bg] = bg

    quant = Image.fromarray(norm).quantize(
        colors=16, method=Image.Quantize.MEDIANCUT, dither=Image.Dither.NONE
    )
    quant_arr = np.asarray(quant).astype(np.uint8)               # 0..15
    full_pal  = np.asarray(quant.getpalette()[: 16 * 3]).reshape(16, 3).astype(int)

    # Identify which quantiser bucket holds the bg colour, then drop it.
    pal_diff   = np.linalg.norm(full_pal - bg, axis=-1)
    bg_pal_idx = int(np.argmin(pal_diff))

    remap = np.zeros(16, dtype=np.uint8)
    palette = np.zeros((15, 3), dtype=np.uint8)
    next_i  = 1
    for i in range(16):
        if i == bg_pal_idx:
            continue
        remap[i] = next_i
        palette[next_i - 1] = full_pal[i]
        next_i += 1

    indices = remap[quant_arr]
    indices[mask_bg] = 0  # mask wins (covers jpg edge halo the quantiser missed)
    return indices, palette


# ---------- emit ROM hex files -----------------------------------------
def emit_pixel_hex(emojis):
    """One line per (tile_id_offset, gy) = PIXEL_ROM_SLOTS * TILE_H_PX lines.
    Each line is 32 bits packed as 8 nibbles, MSB = gx=0 (matches fe_font row order).
    Used slots: emoji_i * TILES_PER_EMOJI + (sub_row*N_COLS + sub_col) for
    each emoji and tile. Unused slots are zero-filled.
    """
    lines = []
    for slot in range(PIXEL_ROM_SLOTS):
        emoji_i  = slot // TILES_PER_EMOJI
        tile_in  = slot %  TILES_PER_EMOJI
        if emoji_i >= len(emojis):
            for _ in range(TILE_H_PX):
                lines.append("00000000")
            continue
        _, indices, _ = emojis[emoji_i]
        tile_r = tile_in // N_COLS
        tile_c = tile_in %  N_COLS
        py = tile_r * TILE_H_PX
        px = tile_c * TILE_W_PX
        for gy in range(TILE_H_PX):
            row = indices[py + gy, px : px + TILE_W_PX]
            word = 0
            for gx in range(TILE_W_PX):
                word |= int(row[gx]) << ((TILE_W_PX - 1 - gx) * 4)
            lines.append(f"{word:08x}")
    PIXEL_HEX.write_text("\n".join(lines) + "\n")


def emit_palette_hex(emojis):
    """5 emojis * 16 palette entries each = 80 lines. Entry 0 of each
    emoji is unused (transparent marker) and written as 000000."""
    lines = []
    for _, _, palette in emojis:
        lines.append("000000")  # idx 0 = transparent placeholder, never read
        for i in range(15):
            r, g, b = palette[i]
            lines.append(f"{int(r):02x}{int(g):02x}{int(b):02x}")
    # Pad up to MAX_EMOJIS * 16 so the .hex size is stable across runs even
    # if a user later removes images.
    while len(lines) < MAX_EMOJIS * PALETTE_ENTRIES_PER_EMOJI:
        lines.append("000000")
    PALETTE_HEX.write_text("\n".join(lines) + "\n")


# ---------- emit SV/C++ headers ----------------------------------------
def emit_codes_svh(emojis):
    lines = [
        "// AUTO-GENERATED by scripts/gen_big_emoji.py -- do not edit by hand.",
        "// Anchor codes + sizing constants for big-emoji bubbles. Tile codes",
        "// for one emoji occupy [anchor, anchor + N_TILES - 1]; both the pixel",
        "// ROM and palette derive offsets from these constants.",
        "",
        f"localparam int BIG_EMOJI_BASE     = 'h{ANCHOR_BASE:02X};",
        f"localparam int BIG_EMOJI_N_ROWS   = {N_ROWS};",
        f"localparam int BIG_EMOJI_N_COLS   = {N_COLS};",
        f"localparam int BIG_EMOJI_N_TILES  = {TILES_PER_EMOJI};",
        f"localparam int BIG_EMOJI_COUNT    = {len(emojis)};",
        f"localparam int BIG_EMOJI_END_EXCL = 'h{ANCHOR_BASE + len(emojis) * TILES_PER_EMOJI:02X};",
        "",
    ]
    for i, (name, _, _) in enumerate(emojis):
        anchor = ANCHOR_BASE + i * TILES_PER_EMOJI
        last   = anchor + TILES_PER_EMOJI - 1
        lines.append(
            f"localparam byte_t BIG_EMOJI_{name.upper()}_ANCHOR = 8'h{anchor:02X};"
            f"  // tiles 0x{anchor:02X}..0x{last:02X}"
        )
    lines.append("")
    CODES_SVH.write_text("\n".join(lines))


def emit_tokens_svh(emojis):
    # Encoder branches dropped verbatim into be_top.sv's single-step
    # encoder always_comb via `include. Each branch starts with `else
    # if` (the previous block's `end` is in be_top.sv) and ends with
    # `end`. The block writes to enc_emit_byte / enc_src_delta -- one
    # match per cycle, no `dst` walk (that's the FSM's job).
    lines = [
        "// AUTO-GENERATED by scripts/gen_big_emoji.py -- do not edit by hand.",
        "// Big-emoji backslash tokens. Each branch matches \"\\Name\"",
        "// (capital first letter) and emits the single anchor byte; the",
        "// frontend expands the anchor into a 3x6 tile bubble on render.",
        "",
    ]
    for i, (name, _, _) in enumerate(emojis):
        anchor   = ANCHOR_BASE + i * TILES_PER_EMOJI
        n_chars  = len(name)          # bytes after the leading backslash
        # Token total bytes = n_chars + 1 (for '\'). Last byte index from src
        # = n_chars. Check needs src+n_chars < len_q so byte n_chars is valid.
        checks = [
            "(line_buf[src + 0] == 8'h5C)"
        ] + [
            f'(line_buf[src + {j+1}] == "{ch}")'
            for j, ch in enumerate(name)
        ]
        body = ["else if ((src + " + str(n_chars) + " < int'(len_q))"]
        for c in checks:
            body.append(f"      && {c}")
        # Close the condition + open the block.
        body[-1] = body[-1] + ") begin"
        body.append(f"    enc_emit_byte = 8'h{anchor:02X};  // \\{name}")
        body.append(f"    enc_src_delta = 4'd{n_chars + 1};")
        body.append( "end")
        lines.extend(body)
    lines.append("")
    TOKENS_SVH.write_text("\n".join(lines))


def emit_test_header(emojis):
    lines = [
        "// AUTO-GENERATED by scripts/gen_big_emoji.py -- do not edit by hand.",
        "#pragma once",
        "",
        f"static constexpr int BIG_EMOJI_BASE    = 0x{ANCHOR_BASE:02X};",
        f"static constexpr int BIG_EMOJI_N_ROWS  = {N_ROWS};",
        f"static constexpr int BIG_EMOJI_N_COLS  = {N_COLS};",
        f"static constexpr int BIG_EMOJI_N_TILES = {TILES_PER_EMOJI};",
        f"static constexpr int BIG_EMOJI_COUNT   = {len(emojis)};",
        "",
    ]
    for i, (name, _, _) in enumerate(emojis):
        anchor = ANCHOR_BASE + i * TILES_PER_EMOJI
        lines.append(f"static constexpr int BIG_EMOJI_{name.upper()}_ANCHOR = 0x{anchor:02X};")
    lines.append("")
    TEST_H.write_text("\n".join(lines))


# ---------- main --------------------------------------------------------
def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--bg-tol", type=int, default=DEFAULT_BG_TOL,
                    help=f"per-channel background-key tolerance (default {DEFAULT_BG_TOL})")
    ap.add_argument("--no-key", action="store_true",
                    help="disable background keying (keeps the source bg colour)")
    args = ap.parse_args()

    files = sorted(
        list(ASSET_DIR.glob("*.jpg"))
        + list(ASSET_DIR.glob("*.jpeg"))
        + list(ASSET_DIR.glob("*.png"))
    )
    if not files:
        sys.exit(f"error: no images in {ASSET_DIR}")
    if len(files) > MAX_EMOJIS:
        sys.exit(f"error: found {len(files)} images, v1 supports max {MAX_EMOJIS}")

    emojis = []
    for f in files:
        name = f.stem
        if not name or not name[0].isupper():
            sys.exit(f"error: {f.name} stem must start with a capital letter")
        if not name.isalpha():
            sys.exit(f"error: {f.name} stem must be ASCII letters only (got {name!r})")
        img = Image.open(f)
        indices, palette = key_and_quantize(img, args.bg_tol, args.no_key)
        emojis.append((name, indices, palette))

    for p in (PIXEL_HEX, PALETTE_HEX, CODES_SVH, TOKENS_SVH, TEST_H):
        p.parent.mkdir(parents=True, exist_ok=True)

    emit_pixel_hex(emojis)
    emit_palette_hex(emojis)
    emit_codes_svh(emojis)
    emit_tokens_svh(emojis)
    emit_test_header(emojis)

    print(f"{len(emojis)} emoji(s):")
    for i, (name, _, _) in enumerate(emojis):
        anchor = ANCHOR_BASE + i * TILES_PER_EMOJI
        print(f"  \\{name:<14}  anchor=0x{anchor:02X}  tiles=0x{anchor:02X}..0x{anchor + TILES_PER_EMOJI - 1:02X}")
    print(f"wrote {PIXEL_HEX.relative_to(ROOT)}")
    print(f"wrote {PALETTE_HEX.relative_to(ROOT)}")
    print(f"wrote {CODES_SVH.relative_to(ROOT)}")
    print(f"wrote {TOKENS_SVH.relative_to(ROOT)}")
    print(f"wrote {TEST_H.relative_to(ROOT)}")


if __name__ == "__main__":
    main()
