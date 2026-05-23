# =====================================================================
# Makefile -- top-level entry for sim and bitstream
# ---------------------------------------------------------------------
# Usage:
#   make                    -- run all Verilator testbenches
#   make test               -- ditto
#   make test-fe_top        -- run a single TB by name
#   make font               -- regenerate rtl/frontend/fe_font.hex
#   make bitstream          -- batch-build the FPGA bitstream
#                              (needs Vivado in PATH; runs build.tcl)
#   make clean              -- wipe build artifacts (sim + vivado)
#   make clean-sim          -- only Verilator artifacts
#   make clean-vivado       -- only vivado/build/
# =====================================================================

PYTHON  ?= python3
VIVADO  ?= vivado

# All sim TBs that have a non-empty sim_main.cpp.
# (fe_render_decoder/sim_main.cpp is an empty stub -- excluded.)
TESTS := \
    sync_2ff \
    handshake_fifo \
    crc16 \
    uart_tx \
    uart_rx \
    uart_loopback \
    io_ps2_phy \
    io_ps2_decoder \
    io_top \
    io_be_integration \
    comm_frame_encoder \
    comm_frame_decoder \
    comm_tx_fsm \
    comm_rx_fsm \
    comm_top_lb \
    be_message_store \
    be_top \
    fe_scan \
    fe_sram_asset_fetch \
    fe_top \
    chat_top \
    chat_top_pair

# ---------------------------------------------------------------------
# Default
# ---------------------------------------------------------------------
.PHONY: all
all: test

# ---------------------------------------------------------------------
# Verilator simulation
# ---------------------------------------------------------------------
.PHONY: test
test:
	@pass=0; fail=0; failed=""; \
	for tb in $(TESTS); do \
	    printf "==== %-22s " "$$tb"; \
	    if $(PYTHON) scripts/run_test.py $$tb >/tmp/_test_$$tb.log 2>&1; then \
	        echo "PASS"; pass=$$((pass+1)); \
	    else \
	        echo "FAIL  (see /tmp/_test_$$tb.log)"; \
	        fail=$$((fail+1)); failed="$$failed $$tb"; \
	    fi; \
	done; \
	echo; \
	echo "==== $$pass PASS / $$fail FAIL ===="; \
	if [ $$fail -gt 0 ]; then echo "Failed:$$failed"; exit 1; fi

# Pattern rule: `make test-be_top` runs one TB and prints its full
# log (no /tmp redirect, so you see what's happening live).
test-%:
	$(PYTHON) scripts/run_test.py $*

# ---------------------------------------------------------------------
# Font ROM regeneration
# ---------------------------------------------------------------------
.PHONY: font
font:
	$(PYTHON) scripts/gen_font.py

# ---------------------------------------------------------------------
# Bitstream (Vivado batch build, fully stateless)
# ---------------------------------------------------------------------
.PHONY: bitstream
bitstream:
	$(VIVADO) -mode batch -source vivado/build.tcl

# ---------------------------------------------------------------------
# Clean
# ---------------------------------------------------------------------
.PHONY: clean clean-sim clean-vivado
clean: clean-sim clean-vivado

clean-sim:
	rm -rf build/
	rm -f sim/waves/*.vcd

clean-vivado:
	rm -rf vivado/build/
	rm -f vivado/*.jou vivado/*.log vivado/*.str
	rm -rf vivado/.Xil/
