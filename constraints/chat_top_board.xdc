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

# Configuration bank voltage for this 3.3 V lab board.
set_property CFGBVS VCCO [current_design]
set_property CONFIG_VOLTAGE 3.3 [current_design]

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

# PS/2 Mouse  --  enabled (bidirectional for host-to-device init).
set_property -dict {PACKAGE_PIN H13 IOSTANDARD LVCMOS33} [get_ports ps2_mouse_clk]
set_property -dict {PACKAGE_PIN G13 IOSTANDARD LVCMOS33} [get_ports ps2_mouse_data]

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
# BaseRAM / SRAM  --  read-only visual asset storage.
# ---------------------------------------------------------------------
set_property -dict {PACKAGE_PIN T19 IOSTANDARD LVCMOS33} [get_ports {base_ram_addr[0]}]
set_property -dict {PACKAGE_PIN V18 IOSTANDARD LVCMOS33} [get_ports {base_ram_addr[1]}]
set_property -dict {PACKAGE_PIN T18 IOSTANDARD LVCMOS33} [get_ports {base_ram_addr[2]}]
set_property -dict {PACKAGE_PIN V17 IOSTANDARD LVCMOS33} [get_ports {base_ram_addr[3]}]
set_property -dict {PACKAGE_PIN U17 IOSTANDARD LVCMOS33} [get_ports {base_ram_addr[4]}]
set_property -dict {PACKAGE_PIN R20 IOSTANDARD LVCMOS33} [get_ports {base_ram_addr[5]}]
set_property -dict {PACKAGE_PIN R23 IOSTANDARD LVCMOS33} [get_ports {base_ram_addr[6]}]
set_property -dict {PACKAGE_PIN T23 IOSTANDARD LVCMOS33} [get_ports {base_ram_addr[7]}]
set_property -dict {PACKAGE_PIN U22 IOSTANDARD LVCMOS33} [get_ports {base_ram_addr[8]}]
set_property -dict {PACKAGE_PIN Y22 IOSTANDARD LVCMOS33} [get_ports {base_ram_addr[9]}]
set_property -dict {PACKAGE_PIN AB24 IOSTANDARD LVCMOS33} [get_ports {base_ram_addr[10]}]
set_property -dict {PACKAGE_PIN AA23 IOSTANDARD LVCMOS33} [get_ports {base_ram_addr[11]}]
set_property -dict {PACKAGE_PIN Y21 IOSTANDARD LVCMOS33} [get_ports {base_ram_addr[12]}]
set_property -dict {PACKAGE_PIN Y20 IOSTANDARD LVCMOS33} [get_ports {base_ram_addr[13]}]
set_property -dict {PACKAGE_PIN AA22 IOSTANDARD LVCMOS33} [get_ports {base_ram_addr[14]}]
set_property -dict {PACKAGE_PIN W19 IOSTANDARD LVCMOS33} [get_ports {base_ram_addr[15]}]
set_property -dict {PACKAGE_PIN W21 IOSTANDARD LVCMOS33} [get_ports {base_ram_addr[16]}]
set_property -dict {PACKAGE_PIN W20 IOSTANDARD LVCMOS33} [get_ports {base_ram_addr[17]}]
set_property -dict {PACKAGE_PIN W18 IOSTANDARD LVCMOS33} [get_ports {base_ram_addr[18]}]
set_property -dict {PACKAGE_PIN V19 IOSTANDARD LVCMOS33} [get_ports {base_ram_addr[19]}]

set_property -dict {PACKAGE_PIN L20 IOSTANDARD LVCMOS33} [get_ports {base_ram_be_n[0]}]
set_property -dict {PACKAGE_PIN L22 IOSTANDARD LVCMOS33} [get_ports {base_ram_be_n[1]}]
set_property -dict {PACKAGE_PIN L23 IOSTANDARD LVCMOS33} [get_ports {base_ram_be_n[2]}]
set_property -dict {PACKAGE_PIN K25 IOSTANDARD LVCMOS33} [get_ports {base_ram_be_n[3]}]

set_property -dict {PACKAGE_PIN L24 IOSTANDARD LVCMOS33} [get_ports {base_ram_data[0]}]
set_property -dict {PACKAGE_PIN L25 IOSTANDARD LVCMOS33} [get_ports {base_ram_data[1]}]
set_property -dict {PACKAGE_PIN M26 IOSTANDARD LVCMOS33} [get_ports {base_ram_data[2]}]
set_property -dict {PACKAGE_PIN M25 IOSTANDARD LVCMOS33} [get_ports {base_ram_data[3]}]
set_property -dict {PACKAGE_PIN N26 IOSTANDARD LVCMOS33} [get_ports {base_ram_data[4]}]
set_property -dict {PACKAGE_PIN P24 IOSTANDARD LVCMOS33} [get_ports {base_ram_data[5]}]
set_property -dict {PACKAGE_PIN P26 IOSTANDARD LVCMOS33} [get_ports {base_ram_data[6]}]
set_property -dict {PACKAGE_PIN P25 IOSTANDARD LVCMOS33} [get_ports {base_ram_data[7]}]
set_property -dict {PACKAGE_PIN AA24 IOSTANDARD LVCMOS33} [get_ports {base_ram_data[8]}]
set_property -dict {PACKAGE_PIN Y23 IOSTANDARD LVCMOS33} [get_ports {base_ram_data[9]}]
set_property -dict {PACKAGE_PIN V21 IOSTANDARD LVCMOS33} [get_ports {base_ram_data[10]}]
set_property -dict {PACKAGE_PIN W24 IOSTANDARD LVCMOS33} [get_ports {base_ram_data[11]}]
set_property -dict {PACKAGE_PIN W23 IOSTANDARD LVCMOS33} [get_ports {base_ram_data[12]}]
set_property -dict {PACKAGE_PIN V22 IOSTANDARD LVCMOS33} [get_ports {base_ram_data[13]}]
set_property -dict {PACKAGE_PIN V23 IOSTANDARD LVCMOS33} [get_ports {base_ram_data[14]}]
set_property -dict {PACKAGE_PIN U21 IOSTANDARD LVCMOS33} [get_ports {base_ram_data[15]}]
set_property -dict {PACKAGE_PIN P21 IOSTANDARD LVCMOS33} [get_ports {base_ram_data[16]}]
set_property -dict {PACKAGE_PIN M21 IOSTANDARD LVCMOS33} [get_ports {base_ram_data[17]}]
set_property -dict {PACKAGE_PIN P23 IOSTANDARD LVCMOS33} [get_ports {base_ram_data[18]}]
set_property -dict {PACKAGE_PIN P19 IOSTANDARD LVCMOS33} [get_ports {base_ram_data[19]}]
set_property -dict {PACKAGE_PIN N19 IOSTANDARD LVCMOS33} [get_ports {base_ram_data[20]}]
set_property -dict {PACKAGE_PIN M20 IOSTANDARD LVCMOS33} [get_ports {base_ram_data[21]}]
set_property -dict {PACKAGE_PIN N24 IOSTANDARD LVCMOS33} [get_ports {base_ram_data[22]}]
set_property -dict {PACKAGE_PIN N21 IOSTANDARD LVCMOS33} [get_ports {base_ram_data[23]}]
set_property -dict {PACKAGE_PIN T22 IOSTANDARD LVCMOS33} [get_ports {base_ram_data[24]}]
set_property -dict {PACKAGE_PIN R22 IOSTANDARD LVCMOS33} [get_ports {base_ram_data[25]}]
set_property -dict {PACKAGE_PIN R21 IOSTANDARD LVCMOS33} [get_ports {base_ram_data[26]}]
set_property -dict {PACKAGE_PIN P20 IOSTANDARD LVCMOS33} [get_ports {base_ram_data[27]}]
set_property -dict {PACKAGE_PIN N22 IOSTANDARD LVCMOS33} [get_ports {base_ram_data[28]}]
set_property -dict {PACKAGE_PIN N23 IOSTANDARD LVCMOS33} [get_ports {base_ram_data[29]}]
set_property -dict {PACKAGE_PIN M24 IOSTANDARD LVCMOS33} [get_ports {base_ram_data[30]}]
set_property -dict {PACKAGE_PIN M22 IOSTANDARD LVCMOS33} [get_ports {base_ram_data[31]}]

set_property -dict {PACKAGE_PIN U19 IOSTANDARD LVCMOS33} [get_ports base_ram_ce_n]
set_property -dict {PACKAGE_PIN T20 IOSTANDARD LVCMOS33} [get_ports base_ram_oe_n]
set_property -dict {PACKAGE_PIN U20 IOSTANDARD LVCMOS33} [get_ports base_ram_we_n]

# ---------------------------------------------------------------------
# DDR3 SDRAM, QSPI Flash, QSPI PSRAM, SD Card, RGMII Ethernet,
# PMOD2..5  --  none used by chat_top_board.
# ---------------------------------------------------------------------
