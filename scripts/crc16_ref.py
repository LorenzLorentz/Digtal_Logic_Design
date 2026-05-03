#!/usr/bin/env python3
"""Reference CRC16-CCITT (CCITT-FALSE) implementation.

Polynomial: 0x1021, init: 0xFFFF, RefIn=False, RefOut=False, XorOut=0.
Canonical check: crc16("123456789") == 0x29B1.

Used by the verilator test for rtl/common/crc16.sv to cross-check that
the hardware computes the same CRC byte-for-byte.
"""
from __future__ import annotations

POLY = 0x1021
INIT = 0xFFFF


def crc16_step(crc: int, byte: int) -> int:
    crc ^= (byte & 0xFF) << 8
    for _ in range(8):
        if crc & 0x8000:
            crc = ((crc << 1) ^ POLY) & 0xFFFF
        else:
            crc = (crc << 1) & 0xFFFF
    return crc


def crc16(data: bytes, init: int = INIT) -> int:
    crc = init
    for b in data:
        crc = crc16_step(crc, b)
    return crc


if __name__ == "__main__":
    # Self-test against the canonical vector.
    assert crc16(b"123456789") == 0x29B1, "CRC16-CCITT-FALSE check failed"
    print("crc16(\"123456789\") = 0x{:04X}".format(crc16(b"123456789")))
    print("crc16(b\"\") = 0x{:04X}".format(crc16(b"")))
    print("crc16(b\"A\") = 0x{:04X}".format(crc16(b"A")))
