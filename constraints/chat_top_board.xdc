# =====================================================================
# chat_top_board.xdc  --  IO constraints for the synthesis wrapper.
# ---------------------------------------------------------------------
# Pin assignments and signal names mirror example/project-template-
# xilinx/.../io.xdc. Do NOT rename ports here; the names must match
# the chat_top_board ports exactly. Pin numbers (PACKAGE_PIN ...) are
# tied to a specific board; if you target a different board, look up
# the new package pins from that board's manual but keep the signal
# names so the wrapper continues to bind.
#
# Lines for peripherals chat_top_board does NOT use (LED scan, 7-seg,
# dip switches, push-button keys, etc.) are kept as `# `-prefixed
# templates so they can be brought back without re-typing the pin
# numbers.
# =====================================================================

# ---------------------------------------------------------------------
# 100 MHz Input Clock
# ---------------------------------------------------------------------
set_property -dict {PACKAGE_PIN K4 IOSTANDARD LVCMOS33} [get_ports clk_100m]
create_clock -period 10.000 [get_ports clk_100m]

# ---------------------------------------------------------------------
# Push Buttons -- only the active-high reset is wired through chat_top.
# ---------------------------------------------------------------------
# set_property -dict {PACKAGE_PIN AB11 IOSTANDARD LVCMOS33} [get_ports btn_clk]
set_property -dict {PACKAGE_PIN AA11 IOSTANDARD LVCMOS33} [get_ports btn_rst]
# set_property -dict {PACKAGE_PIN Y11  IOSTANDARD LVCMOS33} [get_ports btn_push[0]]
# set_property -dict {PACKAGE_PIN AB10 IOSTANDARD LVCMOS33} [get_ports btn_push[1]]
# set_property -dict {PACKAGE_PIN AA10 IOSTANDARD LVCMOS33} [get_ports btn_push[2]]
# set_property -dict {PACKAGE_PIN AA9  IOSTANDARD LVCMOS33} [get_ports btn_push[3]]

# ---------------------------------------------------------------------
# 16 DIP switches  --  not used.
# ---------------------------------------------------------------------
# set_property -dict {PACKAGE_PIN AA14 IOSTANDARD LVCMOS33} [get_ports dip_sw[0]]
# (... see example/io.xdc for the full set ...)

# ---------------------------------------------------------------------
# 32 LEDs  --  not used.
# ---------------------------------------------------------------------
# set_property -dict {PACKAGE_PIN D22 IOSTANDARD LVCMOS33} [get_ports led_bit[0]]
# (... see example/io.xdc for the full set ...)

# ---------------------------------------------------------------------
# 7-Segment Display  --  not used.
# ---------------------------------------------------------------------
# (... see example/io.xdc for the full set ...)

# ---------------------------------------------------------------------
# PS/2 Keyboard  --  enabled.
# Names ps2_keyboard_clk / ps2_keyboard_data are required by io.xdc;
# chat_top_board re-wires them onto chat_top.ps2_clk / .ps2_data.
# ---------------------------------------------------------------------
set_property -dict {PACKAGE_PIN H15 IOSTANDARD LVCMOS33} [get_ports ps2_keyboard_clk]
set_property -dict {PACKAGE_PIN H14 IOSTANDARD LVCMOS33} [get_ports ps2_keyboard_data]

# PS/2 Mouse  --  not used.
# set_property -dict {PACKAGE_PIN H13 IOSTANDARD LVCMOS33} [get_ports ps2_mouse_clk]
# set_property -dict {PACKAGE_PIN G13 IOSTANDARD LVCMOS33} [get_ports ps2_mouse_data]

# ---------------------------------------------------------------------
# UART over PMOD1  --  for board-to-board chat link.
# Pin choice follows Digilent PMOD UART convention: pin2=TXD, pin3=RXD.
# Self-loopback test: short pin2 and pin3 on the same board.
# Two-board link (jumper wires, NOT a ribbon cable):
#   board_A pin2 (G1, txd) <-> board_B pin3 (F1, rxd)
#   board_A pin3 (F1, rxd) <-> board_B pin2 (G1, txd)
#   board_A pin5 (GND)     <-> board_B pin5 (GND)
# Do NOT bridge VCC (pin6/pin12). LAB UART (D17/E17) is no longer used.
# ---------------------------------------------------------------------
set_property -dict {PACKAGE_PIN G1 IOSTANDARD LVCMOS33} [get_ports uart_txd]
set_property -dict {PACKAGE_PIN F1 IOSTANDARD LVCMOS33} [get_ports uart_rxd]

# RS232  --  alternative UART, not used.
# set_property -dict {PACKAGE_PIN E16 IOSTANDARD LVCMOS33} [get_ports rs232_rts]
# set_property -dict {PACKAGE_PIN F16 IOSTANDARD LVCMOS33} [get_ports rs232_txd]
# set_property -dict {PACKAGE_PIN D15 IOSTANDARD LVCMOS33} [get_ports rs232_rxd]
# set_property -dict {PACKAGE_PIN D16 IOSTANDARD LVCMOS33} [get_ports rs232_cts]

# ---------------------------------------------------------------------
# HDMI TMDS  --  enabled. Differential pairs, TMDS_33 standard.
# ---------------------------------------------------------------------
set_property -dict {PACKAGE_PIN C15 IOSTANDARD TMDS_33} [get_ports {hdmi_tmds_n[0]}]
set_property -dict {PACKAGE_PIN C14 IOSTANDARD TMDS_33} [get_ports {hdmi_tmds_p[0]}]
set_property -dict {PACKAGE_PIN A14 IOSTANDARD TMDS_33} [get_ports {hdmi_tmds_n[1]}]
set_property -dict {PACKAGE_PIN A13 IOSTANDARD TMDS_33} [get_ports {hdmi_tmds_p[1]}]
set_property -dict {PACKAGE_PIN B13 IOSTANDARD TMDS_33} [get_ports {hdmi_tmds_n[2]}]
set_property -dict {PACKAGE_PIN C13 IOSTANDARD TMDS_33} [get_ports {hdmi_tmds_p[2]}]
set_property -dict {PACKAGE_PIN A16 IOSTANDARD TMDS_33} [get_ports hdmi_tmds_c_n]
set_property -dict {PACKAGE_PIN A15 IOSTANDARD TMDS_33} [get_ports hdmi_tmds_c_p]

# ---------------------------------------------------------------------
# DDR3 SDRAM, BaseRAM (SRAM), QSPI Flash, QSPI PSRAM, SD Card,
# RGMII Ethernet, PMOD1..5  --  none used by chat_top_board.
# Refer to example/project-template-xilinx/.../io.xdc for the
# complete pin list if a future revision wants to hook them up;
# port names there must match the wrapper's signals.
# ---------------------------------------------------------------------
