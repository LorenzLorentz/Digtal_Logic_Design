#!/usr/bin/env python3
"""
Build & run a single Verilator testbench under sim/tb/<module>/.

Each TB directory must contain:
  sim_main.cpp   - Verilator C++ harness
  deps.txt       - one RTL .sv file per line (paths relative to repo
                   root), packages first, then modules that import them,
                   then the top RTL module last.

Optional:
  params.txt     - one parameter override per line, e.g.
                   `BAUD=10`, `CLK_FREQ_HZ=160`. Translated to
                   verilator `-G<NAME>=<VAL>`. Lines starting with `#`
                   are ignored.

By convention, the TB folder name matches the top module name in the
deps list (e.g. sim/tb/be_top/ tests rtl/backend/be_top.sv).

Usage:
  python3 scripts/run_test.py be_top
"""

import shutil
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent


def fail(msg: str) -> None:
    print(f"ERROR: {msg}", file=sys.stderr)
    sys.exit(2)


def run(cmd: list, **kw) -> int:
    print("$ " + " ".join(str(c) for c in cmd))
    return subprocess.run(cmd, **kw).returncode


def main() -> int:
    if len(sys.argv) != 2:
        fail("usage: run_test.py <module>")
    mod = sys.argv[1]
    tb_dir = ROOT / "sim" / "tb" / mod
    if not tb_dir.exists():
        fail(f"no such TB dir: {tb_dir}")

    sim_main = tb_dir / "sim_main.cpp"
    deps_txt = tb_dir / "deps.txt"
    for f in (sim_main, deps_txt):
        if not f.exists():
            fail(f"missing: {f}")

    deps = [
        ROOT / line.strip()
        for line in deps_txt.read_text().splitlines()
        if line.strip() and not line.strip().startswith("#")
    ]
    for d in deps:
        if not d.exists():
            fail(f"dep missing: {d}")

    params_txt = tb_dir / "params.txt"
    param_args = []
    if params_txt.exists():
        for line in params_txt.read_text().splitlines():
            s = line.strip()
            if not s or s.startswith("#"):
                continue
            param_args.append(f"-G{s}")

    build = ROOT / "build" / mod
    if build.exists():
        shutil.rmtree(build)
    build.mkdir(parents=True)

    # Make sure the waves dir exists -- the TB writes a VCD there.
    (ROOT / "sim" / "waves").mkdir(parents=True, exist_ok=True)

    cmd = [
        "verilator",
        "--cc", "--exe", "--build",
        "--trace",
        "-Wall",
        "-Wno-UNUSEDPARAM",  # package localparams may look unused per-module
        "--top-module", mod,
        "--Mdir", str(build),
        "-o", f"sim_{mod}",
        *param_args,
        *[str(d) for d in deps],
        str(sim_main),
    ]
    rc = run(cmd, cwd=ROOT)
    if rc != 0:
        fail(f"verilator build failed (rc={rc})")

    bin_path = build / f"sim_{mod}"
    if not bin_path.exists():
        fail(f"build artifact missing: {bin_path}")

    return run([str(bin_path)], cwd=ROOT)


if __name__ == "__main__":
    sys.exit(main())
