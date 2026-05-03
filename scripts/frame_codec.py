#!/usr/bin/env python3
"""Reference encode/decode for the link-layer frame protocol.

Frame layout (LEN-based, no byte stuffing):

    SOF(0x7E) | TYPE(byte, low 3 bits) | SEQ(byte) | LEN(byte) | PAYLOAD | CRC16(big-endian, 2 bytes)

CRC16 covers TYPE..PAYLOAD (NOT SOF, NOT CRC bytes themselves).

This file is the cross-check oracle used by the verilator tests.
"""
from __future__ import annotations
from typing import Optional, Tuple

from crc16_ref import crc16

SOF_BYTE = 0x7E
MAX_PAYLOAD = 64

FRAME_DATA     = 0
FRAME_ACK      = 1
FRAME_NAK      = 2
FRAME_HELLO    = 3
FRAME_REHELLO  = 4
FRAME_USERNAME = 5
FRAME_GOODBYE  = 6


def encode_frame(ftype: int, seq: int, payload: bytes = b"") -> bytes:
    if len(payload) > MAX_PAYLOAD:
        raise ValueError(f"payload too long: {len(payload)} > {MAX_PAYLOAD}")
    head = bytes([ftype & 0x07, seq & 0xFF, len(payload) & 0xFF]) + payload
    c = crc16(head)
    return bytes([SOF_BYTE]) + head + bytes([(c >> 8) & 0xFF, c & 0xFF])


def decode_frame(stream: bytes, start: int = 0) -> Optional[Tuple[int, int, bytes, int]]:
    """Decode the single frame starting at offset `start` (which must
    point at SOF). Returns (ftype, seq, payload, end_index) on success
    where end_index is one past the last consumed byte. Returns None
    if the frame is malformed or the CRC does not match.
    """
    s = stream
    if start >= len(s) or s[start] != SOF_BYTE:
        return None
    if start + 4 > len(s):
        return None
    ftype = s[start + 1] & 0x07
    seq   = s[start + 2]
    plen  = s[start + 3]
    if plen > MAX_PAYLOAD:
        return None
    body_end = start + 4 + plen
    if body_end + 2 > len(s):
        return None
    payload = s[start + 4 : body_end]
    rx_crc = (s[body_end] << 8) | s[body_end + 1]
    head_for_crc = bytes([ftype, seq, plen]) + payload
    if crc16(head_for_crc) != rx_crc:
        return None
    return ftype, seq, payload, body_end + 2


if __name__ == "__main__":
    samples = [
        (FRAME_DATA,     0, b"hello"),
        (FRAME_HELLO,    1, b"Alice"),
        (FRAME_ACK,      0, b""),
        (FRAME_GOODBYE,  3, b""),
        (FRAME_DATA,     1, b"\x7E\x7E\x7E"),  # SOF inside payload (no escape)
    ]
    for s in samples:
        enc = encode_frame(*s)
        dec = decode_frame(enc)
        print(f"{s!r:50}  -> {enc.hex()}   roundtrip ok={dec is not None}")
        assert dec is not None
        assert (dec[0], dec[1], dec[2]) == s
