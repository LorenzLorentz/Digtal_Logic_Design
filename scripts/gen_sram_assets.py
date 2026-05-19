#!/usr/bin/env python3
"""
Pack uploaded chat visuals into the lab board BaseRAM binary format.

Memory map, byte offsets:
  0x000000  background RGB565 800x600, 960000 bytes
  0x0EA600  local avatar RGB565 16x16, 512 bytes
  0x0EA800  remote avatar RGB565 16x16, 512 bytes

The board control panel expects a raw binary file, not COE/MIF. Upload the
generated file at SRAM start address 0x0. The control panel uses byte
addresses and little-endian 32-bit words; this script emits each RGB565 pixel
as low byte then high byte, so two adjacent pixels occupy one SRAM word.
"""

import argparse
from pathlib import Path

from PIL import Image, ImageOps


BG_SIZE = (800, 600)
AVATAR_SIZE = (16, 16)


def rgb888_to_rgb565(r: int, g: int, b: int) -> int:
    return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3)


def pack_rgb565(img: Image.Image, size: tuple[int, int]) -> bytes:
    fitted = ImageOps.fit(img.convert("RGB"), size, method=Image.Resampling.LANCZOS)
    out = bytearray()
    raw = fitted.tobytes()
    for i in range(0, len(raw), 3):
        r, g, b = raw[i], raw[i + 1], raw[i + 2]
        px = rgb888_to_rgb565(r, g, b)
        out.append(px & 0xFF)
        out.append((px >> 8) & 0xFF)
    return bytes(out)


def load_or_solid(path: str | None, size: tuple[int, int], color: tuple[int, int, int]) -> Image.Image:
    if path:
        return Image.open(path)
    return Image.new("RGB", size, color)


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--background", required=True, help="background image, cropped to 800x600")
    parser.add_argument("--local-avatar", help="local/user avatar, cropped to 16x16")
    parser.add_argument("--remote-avatar", help="peer avatar, cropped to 16x16")
    parser.add_argument("--out", default="chat_assets.bin", help="raw binary output path")
    args = parser.parse_args()

    bg = Image.open(args.background)
    local = load_or_solid(args.local_avatar, AVATAR_SIZE, (40, 120, 220))
    remote = load_or_solid(args.remote_avatar, AVATAR_SIZE, (220, 120, 40))

    data = bytearray()
    data += pack_rgb565(bg, BG_SIZE)
    data += pack_rgb565(local, AVATAR_SIZE)
    data += pack_rgb565(remote, AVATAR_SIZE)

    out = Path(args.out)
    out.write_bytes(data)
    print(f"wrote {out} ({len(data)} bytes)")
    print("upload to SRAM byte address 0x0 with the board control panel")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
