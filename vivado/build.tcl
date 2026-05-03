# =====================================================================
# build.tcl  --  Stateless Vivado build for chat_top_board
# ---------------------------------------------------------------------
# Run from anywhere with:
#   vivado -mode batch -source <path>/build.tcl
#
# Or from repo root (Windows cmd):
#   vivado -mode batch -source vivado\build.tcl
#
# Every invocation deletes vivado/build/ first so the project starts
# from a guaranteed-clean state -- no stale runs, no cached constraint
# state, no leftover IP outputs. Output bitstream lands at:
#   vivado/build/chat.runs/impl_1/chat_top_board.bit
# =====================================================================

# ---------------------------------------------------------------------
# Path resolution -- script is portable, runs from anywhere
# ---------------------------------------------------------------------
set this_dir  [file dirname [file normalize [info script]]]
set repo_root [file normalize "$this_dir/.."]

set proj_name "chat"
set proj_dir  "$this_dir/build"
set part      "xc7a200tfbg484-2"
set top       "chat_top_board"

puts "==== build.tcl ===="
puts "this_dir  : $this_dir"
puts "repo_root : $repo_root"
puts "proj_dir  : $proj_dir"
puts "part      : $part"
puts "top       : $top"

# ---------------------------------------------------------------------
# 1. Wipe any previous build dir (this is the "stateless" guarantee)
# ---------------------------------------------------------------------
if {[file exists $proj_dir]} {
    puts "==== Removing previous build dir ===="
    file delete -force $proj_dir
}

# ---------------------------------------------------------------------
# 2. Create the project from scratch
# ---------------------------------------------------------------------
puts "==== Creating project ===="
create_project -force $proj_name $proj_dir -part $part

# ---------------------------------------------------------------------
# 3. Register the rgb2dvi IP repository
# ---------------------------------------------------------------------
puts "==== Registering IP repository ===="
set_property ip_repo_paths "$this_dir/ip_repo" [current_project]
update_ip_catalog

# ---------------------------------------------------------------------
# 4. Add RTL sources from rtl/.
#    Only rtl/ is added -- sim/tb/* stays out so chat_top_pair.sv (a
#    Verilator-only top) does not get pulled into synth.
# ---------------------------------------------------------------------
puts "==== Adding RTL ===="
foreach d {pkg common io comm backend frontend} {
    set files [glob -nocomplain "$repo_root/rtl/$d/*.sv"]
    if {[llength $files] > 0} {
        add_files -fileset sources_1 $files
        puts "  added [llength $files] file(s) from rtl/$d"
    }
}
# Top-level wrappers
set top_files [glob "$repo_root/rtl/*.sv"]
add_files -fileset sources_1 $top_files
puts "  added [llength $top_files] file(s) from rtl/"

# Font ROM init file (consumed by fe_glyph_rom via $readmemh)
add_files -fileset sources_1 "$repo_root/rtl/frontend/fe_font.hex"
set_property file_type {Memory Initialization Files} \
    [get_files "*fe_font.hex"]

# ---------------------------------------------------------------------
# 5. Add the pre-customized IPs (xci files from the original GUI
#    project). Vivado regenerates output products into vivado/build/.
# ---------------------------------------------------------------------
puts "==== Adding IPs ===="
foreach ip {ip_pll ip_rgb2dvi} {
    set xci "$this_dir/chat.srcs/sources_1/ip/$ip/$ip.xci"
    if {![file exists $xci]} {
        puts "ERROR: IP xci not found: $xci"
        exit 1
    }
    add_files -fileset sources_1 -norecurse $xci
    puts "  added $ip from $xci"
}
# Generate IP output products so synth has wrapper / stub files
generate_target {synthesis simulation} [get_ips]

# ---------------------------------------------------------------------
# 6. Add IO constraints.
#    IS_GLOBAL_INCLUDE forces Vivado to re-apply the xdc at every flow
#    step (synth, opt, place, route, bitgen). Defensive: avoids the
#    "constraint silently dropped at impl" symptom seen in GUI runs.
# ---------------------------------------------------------------------
puts "==== Adding constraints ===="
add_files -fileset constrs_1 "$repo_root/constraints/chat_top_board.xdc"
set_property IS_GLOBAL_INCLUDE 1 [get_files "*chat_top_board.xdc"]

# ---------------------------------------------------------------------
# 7. Set top module
# ---------------------------------------------------------------------
set_property top $top [current_fileset]
puts "==== Top set to: $top ===="

# ---------------------------------------------------------------------
# 8. Synthesis
# ---------------------------------------------------------------------
puts "==== Running synthesis ===="
launch_runs synth_1 -jobs 4
wait_on_run synth_1
if {[get_property PROGRESS [get_runs synth_1]] ne "100%"} {
    puts "ERROR: synthesis did not reach 100%"
    puts "       see [file normalize $proj_dir]/$proj_name.runs/synth_1/runme.log"
    exit 1
}
puts "==== Synthesis OK ===="

# ---------------------------------------------------------------------
# 9. Implementation + write_bitstream (one-shot)
# ---------------------------------------------------------------------
puts "==== Running implementation + write_bitstream ===="
launch_runs impl_1 -to_step write_bitstream -jobs 4
wait_on_run impl_1
if {[get_property PROGRESS [get_runs impl_1]] ne "100%"} {
    puts "ERROR: implementation / bitgen did not reach 100%"
    puts "       see [file normalize $proj_dir]/$proj_name.runs/impl_1/runme.log"
    exit 1
}
puts "==== Implementation + bitgen OK ===="

# ---------------------------------------------------------------------
# 10. Verify and report
# ---------------------------------------------------------------------
set bitfile "$proj_dir/${proj_name}.runs/impl_1/${top}.bit"
if {[file exists $bitfile]} {
    puts ""
    puts "================================================================"
    puts "==== BUILD SUCCESS"
    puts "==== Bitstream: $bitfile"
    puts "==== Size:      [file size $bitfile] bytes"
    puts "================================================================"
} else {
    puts "ERROR: bitstream not produced (expected at $bitfile)"
    exit 1
}
