source init.tcl 

cd $working_dir

read_verilog -sv -quiet [glob -nocomplain $src_dir/*.svh]
set_property IS_GLOBAL_INCLUDE 1 [get_files $src_dir/defs.svh]
read_verilog -sv -quiet [glob -nocomplain $src_dir/*.sv]
read_verilog -quiet [glob -nocomplain $src_dir/*.v]
# read_verilog -quiet [glob -nocomplain $src_dir/ips/*.v]
read_vhdl -quiet [glob -nocomplain $src_dir/*.vhdl]
read_xdc -quiet [glob $src_dir/xdc/*.xdc]

set synth_checkpoint "$checkpoints_dir/post_synth.dcp"
set opt_checkpoint "$checkpoints_dir/post_opt.dcp"
set place_checkpoint "$checkpoints_dir/post_place.dcp"
set route_checkpoint "$checkpoints_dir/post_route.dcp"

set source_files [concat [glob -nocomplain $src_dir/*.sv] [glob -nocomplain $src_dir/*.svh] [glob -nocomplain $src_dir/*.v] [glob -nocomplain $src_dir/*.vhdl] [glob $src_dir/xdc/*.xdc] [glob $ips_dir/*/*.xci]]

proc files_changed {files checkpoints} {
    foreach file $files {
        set file_mtime [file mtime $file]
        if {![file exists $checkpoints]} {
            return 1
        }
        set checkpoint_mtime [file mtime $checkpoints]
        if {$file_mtime > $checkpoint_mtime} {
            return 1
        }
    }
    return 0
}

# if {![file exists $outputDir]} {
#     file mkdir $outputDir
# }

# Read IP cores
foreach folder [glob -nocomplain $ips_dir/*] {
	set checkpoint [glob -nocomplain $folder/*.dcp]
	set xcis [glob -nocomplain $folder/*.xci]
	set ip [file tail $folder]

	if {[llength $xcis]} {
	    set xci [lindex $xcis 0]
	    read_ip -quiet $xci
	} 	
    # read_verilog -quiet [glob -nocomplain $folder/*.v]
	# if {![files_changed $xcis $checkpoint]} {
    # read_checkpoint -incremental $checkpoint
	    # write_checkpoint -force $checkpoint
	# } else {
	# 	read_ip -quiet $xcis
	#     write_checkpoint -force $checkpoint
	# }
}


# Incremental Design Flow
if {![files_changed $source_files $synth_checkpoint]} {
    puts "No source changes detected. Reading existing synthesis checkpoint."
    read_checkpoint $synth_checkpoint
    link_design
} else {
    puts "Source files changed. Synthesizing design..."
	# generate_target all [get_ips *]
	# synth_ip [get_ips *] 
    synth_design -top main -part $partNum -incremental_mode quick
    write_checkpoint -force $synth_checkpoint
}

# create_debug_core u_ila_0 ila
# #set debug core properties
# set_property C_DATA_DEPTH 16384 [get_debug_cores u_ila_0]
# set_property C_TRIGIN_EN false [get_debug_cores u_ila_0]
# set_property C_TRIGOUT_EN false [get_debug_cores u_ila_0]
# set_property C_ADV_TRIGGER false [get_debug_cores u_ila_0]
# set_property C_INPUT_PIPE_STAGES 0 [get_debug_cores u_ila_0]
# set_property C_EN_STRG_QUAL false [get_debug_cores u_ila_0]
# set_property ALL_PROBE_SAME_MU true [get_debug_cores u_ila_0]
# set_property ALL_PROBE_SAME_MU_CNT 1 [get_debug_cores u_ila_0]
# #connect the probe ports in the debug core to the signals being probed in the design
# set_property port_width 1 [get_debug_ports u_ila_0/clk]
# connect_debug_port u_ila_0/clk [get_nets [list pclk]]

# set_property port_width 8 [get_debug_ports u_ila_0/probe0]
# connect_debug_port u_ila_0/probe0 [get_nets [list wcfb]]
# # create_debug_port u_ila_0 probe

# create_debug_port u_ila_0 probe
# set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_0/probe1]
# set_property port_width 1 [get_debug_ports u_ila_0/probe1]
# connect_debug_port u_ila_0/probe1 [get_nets [list enc_rst_n]]

# set_property C_CLK_INPUT_FREQ_HZ 25000000 [get_debug_cores dbg_hub]
# set_property C_ENABLE_CLK_DIVIDER false [get_debug_cores dbg_hub]
# set_property C_USER_SCAN_CHAIN 1 [get_debug_cores dbg_hub]
# connect_debug_port dbg_hub/clk [get_nets clk_BUFG]
# save_constraints

# put $first_arg
# if { $first_arg eq "debug"} {
#     create_debug_core u_ila_0 ila 
#     set_property C_DATA_DEPTH 1024 [get_debug_cores u_ila_0]
#     set_property C_TRIGIN_EN false [get_debug_cores u_ila_0]
#     set_property C_TRIGOUT_EN false [get_debug_cores u_ila_0]
#     set_property C_ADV_TRIGGER false [get_debug_cores u_ila_0]
#     set_property C_INPUT_PIPE_STAGES 0 [get_debug_cores u_ila_0]
#     set_property C_EN_STRG_QUAL false [get_debug_cores u_ila_0]
#     set_property ALL_PROBE_SAME_MU true [get_debug_cores u_ila_0]
#     set_property ALL_PROBE_SAME_MU_CNT 1 [get_debug_cores u_ila_0]}

#     set_property port_width 1 [get_debug_ports u_ila_0/clk]
#     connect_debug_port u_ila_0/clk [get_nets [list clk ]]
#     set_property port_width 1 [get_debug_ports u_ila_0/probe0]
#     connect_debug_port u_ila_0/probe0 [get_nets [list A_or_B]]
#     create_debug_port u_ila_0 probe
# }
# read_checkpoint $synth_checkpoint
# link_design
# synth_design -top main -part $partNum -incremental_mode quick
# write_checkpoint -force $synth_checkpoint

# link_design

if {![files_changed $source_files $opt_checkpoint]} {
    puts "Reading existing optimization checkpoint."
    read_checkpoint -incremental $opt_checkpoint
} else {
    puts "Optimizing design..."
    opt_design
    write_checkpoint -force $opt_checkpoint
}

if {![files_changed $source_files $place_checkpoint]} {
    puts "Reading existing placement checkpoint."
    read_checkpoint -incremental $place_checkpoint
} else {
    puts "Placing design..."
    place_design
    write_checkpoint -force $place_checkpoint
}

# Check for timing violations
if {[get_property SLACK [get_timing_paths -max_paths 1 -nworst 1 -setup]] < 0} {
    puts "Found setup timing violations => running physical optimization."
    phys_opt_design
}

# Read route checkpoint or perform routing if none exists
if {![files_changed $source_files $route_checkpoint]} {
    puts "Reading existing routing checkpoint."
    read_checkpoint -incremental $route_checkpoint
} else {
    puts "Routing design..."
    route_design -directive Explore -ultrathreads
    write_checkpoint -force $route_checkpoint
}

# Generate reports
report_route_status -file $report_dir/post_route_status.rpt
report_timing_summary -file $report_dir/post_route_timing_summary.rpt
report_power -file $report_dir/post_route_power.rpt
report_drc -file $report_dir/post_imp_drc.rpt

# Write the bitstream
write_bitstream -force $output_dir/BASYS3.bit
