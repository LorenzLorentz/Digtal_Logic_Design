# =====================================================================
# build.tcl  --  Stateless Vivado build for chat_top_board
# ---------------------------------------------------------------------
# Two phases:
#   GUI project (vivado/chat.xpr) is created on first run and left
#   alone after that (so any GUI-side state you accumulate -- waveforms,
#   debug breakpoints, IP customization tweaks -- is preserved).
#   Stateless batch build wipes vivado/build/ every run and goes
#   synth -> impl -> write_bitstream from a guaranteed-clean state.
#
# Usage:
#   vivado -mode batch -source vivado/build.tcl
#
# Output bitstream:
#   vivado/build/chat.runs/impl_1/chat_top_board.bit
#
# After the first run you can also double-click vivado/chat.xpr to do
# GUI work (waveform browse, timing reports, etc.).
#
# To force-rebuild the GUI project (e.g. after pulling new IPs):
#   rm vivado/chat.xpr   (or: del vivado\chat.xpr on Windows)
#   then re-run this script.
# =====================================================================

# ---------------------------------------------------------------------
# Path resolution -- script is portable, runs from any cwd
# ---------------------------------------------------------------------
set this_dir  [file dirname [file normalize [info script]]]
set repo_root [file normalize "$this_dir/.."]

set proj_name "chat"
set part      "xc7a200tfbg484-2"
set top       "chat_top_board"
set jobs      4

set gui_dir   $this_dir
set build_dir "$this_dir/build"
set xpr       "$gui_dir/$proj_name.xpr"

puts "==== build.tcl ===="
puts "this_dir  : $this_dir"
puts "repo_root : $repo_root"
puts "part      : $part"
puts "top       : $top"

# =====================================================================
# Helper: add the full design (RTL + IPs + constraints) to the
# currently-open project. Used by both the GUI-project setup and the
# stateless batch build so the two cannot drift.
# =====================================================================
proc add_full_design {repo_root this_dir top} {
    # ---- IP repository (rgb2dvi) ----
    set_property ip_repo_paths "$this_dir/ip_repo" [current_project]
    update_ip_catalog

    # ---- RTL ----
    set total 0
    foreach d {pkg common io comm backend frontend} {
        set files [glob -nocomplain "$repo_root/rtl/$d/*.sv"]
        if {[llength $files] > 0} {
            add_files -fileset sources_1 $files
            incr total [llength $files]
        }
    }
    set top_files [glob "$repo_root/rtl/*.sv"]
    add_files -fileset sources_1 $top_files
    incr total [llength $top_files]
    puts "  added $total RTL file(s) from $repo_root/rtl"

    # ---- Font ROM init file ($readmemh source) ----
    add_files -fileset sources_1 "$repo_root/rtl/frontend/fe_font.hex"
    set_property file_type {Memory Initialization Files} \
        [get_files "*fe_font.hex"]

    # ---- IPs (from the checked-in vivado/ip/) ----
    foreach ip {ip_pll ip_rgb2dvi} {
        set xci "$this_dir/ip/$ip/$ip.xci"
        if {![file exists $xci]} {
            error "IP xci not found: $xci"
        }
        add_files -fileset sources_1 -norecurse $xci
        puts "  added IP $ip from $xci"
    }
    generate_target {synthesis simulation} [get_ips]

    # ---- IO constraints ----
    #   IS_GLOBAL_INCLUDE = 1  forces Vivado to re-apply the .xdc at
    #   every flow step (synth/opt/place/route/bitgen). Defensive --
    #   sidesteps the GUI-flow bug where the .xdc can be silently
    #   dropped between synth and impl on a stale project.
    add_files -fileset constrs_1 "$repo_root/constraints/chat_top_board.xdc"
    set_property IS_GLOBAL_INCLUDE 1 [get_files "*chat_top_board.xdc"]

    # ---- Top ----
    set_property top $top [current_fileset]
}

# =====================================================================
# Phase A: GUI project -- create-on-first-run (idempotent).
# =====================================================================
if {[file exists $xpr]} {
    puts "==== GUI project already exists, leaving alone: $xpr ===="
} else {
    puts "==== Creating GUI project: $xpr ===="
    create_project $proj_name $gui_dir -part $part
    add_full_design $repo_root $this_dir $top
    close_project
    puts "==== GUI project created ===="
}

# =====================================================================
# Phase B: Stateless batch build.
# =====================================================================
if {[file exists $build_dir]} {
    puts "==== Removing previous build dir: $build_dir ===="
    file delete -force $build_dir
}

puts "==== Creating batch project: $build_dir ===="
create_project -force $proj_name $build_dir -part $part
add_full_design $repo_root $this_dir $top

puts "==== Synthesis ===="
launch_runs synth_1 -jobs $jobs
wait_on_run synth_1
if {[get_property PROGRESS [get_runs synth_1]] ne "100%"} {
    puts "ERROR: synthesis did not reach 100%"
    puts "       see $build_dir/$proj_name.runs/synth_1/runme.log"
    exit 1
}
puts "==== Synthesis OK ===="

puts "==== Implementation + write_bitstream ===="
launch_runs impl_1 -to_step write_bitstream -jobs $jobs
wait_on_run impl_1
if {[get_property PROGRESS [get_runs impl_1]] ne "100%"} {
    puts "ERROR: impl/bitgen did not reach 100%"
    puts "       see $build_dir/$proj_name.runs/impl_1/runme.log"
    exit 1
}
puts "==== Implementation + bitgen OK ===="

# =====================================================================
# Phase C: verify + report.
# =====================================================================
set bitfile "$build_dir/$proj_name.runs/impl_1/$top.bit"
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
