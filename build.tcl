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
set debug_checkpoint "$checkpoints_dir/post_debug.dcp"
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

# implement_debug_core

# Incremental Design Flow
if {![files_changed $source_files $synth_checkpoint]} {
    puts "No source changes detected. Reading existing synthesis checkpoint."
    read_checkpoint $synth_checkpoint
    # read_checkpoint -incremental $synth_checkpoint
    link_design
} else {
    puts "Source files changed. Synthesizing design..."
	# generate_target all [get_ips *]
	# synth_ip [get_ips *] 
    synth_design -top main -part $partNum -incremental_mode quick
    write_checkpoint -force $synth_checkpoint
}


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
# 
if {![files_changed $source_files $debug_checkpoint]} {
    puts "Reading existing debug checkpoint."
    read_checkpoint -incremental $debug_checkpoint
} 
    set debug_cores [get_debug_cores]

    if {[llength $debug_cores] == 0} {
        # Create and configure a new debug
        # create_debug_core u_ila_0 ila
        # set_property C_DATA_DEPTH 1024 [get_debug_cores u_ila_0]
        # set_property C_TRIGIN_EN false [get_debug_cores u_ila_0]
        # set_property C_TRIGOUT_EN false [get_debug_cores u_ila_0]
        # set_property C_ADV_TRIGGER false [get_debug_cores u_ila_0]
        # set_property C_INPUT_PIPE_STAGES 0 [get_debug_cores u_ila_0]
        # set_property C_EN_STRG_QUAL false [get_debug_cores u_ila_0]
        # set_property ALL_PROBE_SAME_MU true [get_debug_cores u_ila_0]
        # set_property ALL_PROBE_SAME_MU_CNT 1 [get_debug_cores u_ila_0]
        # connect_debug_port u_ila_0/clk [get_nets [list pclk_BUFG ]]
        # set_property port_width 8 [get_debug_ports u_ila_0/probe0]
        # set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_0/probe0]
        # connect_debug_port u_ila_0/probe0 [get_nets [list {wcfb[0][0]} {wcfb[0][1]} {wcfb[0][2]} {wcfb[0][3]} {wcfb[0][4]} {wcfb[0][5]} {wcfb[0][6]} {wcfb[0][7]} ]]
        # create_debug_port u_ila_0 probe
        # set_property port_width 8 [get_debug_ports u_ila_0/probe1]
        # set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_0/probe1]
        # connect_debug_port u_ila_0/probe1 [get_nets [list {wcfb[1][0]} {wcfb[1][1]} {wcfb[1][2]} {wcfb[1][3]} {wcfb[1][4]} {wcfb[1][5]} {wcfb[1][6]} {wcfb[1][7]} ]]
        # create_debug_port u_ila_0 probe
        # set_property port_width 8 [get_debug_ports u_ila_0/probe2]
        # set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_0/probe2]
        # connect_debug_port u_ila_0/probe2 [get_nets [list {wcfb[5][0]} {wcfb[5][1]} {wcfb[5][2]} {wcfb[5][3]} {wcfb[5][4]} {wcfb[5][5]} {wcfb[5][6]} {wcfb[5][7]} ]]
        # create_debug_port u_ila_0 probe
        # set_property port_width 8 [get_debug_ports u_ila_0/probe3]
        # set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_0/probe3]
        # connect_debug_port u_ila_0/probe3 [get_nets [list {wcfb[2][0]} {wcfb[2][1]} {wcfb[2][2]} {wcfb[2][3]} {wcfb[2][4]} {wcfb[2][5]} {wcfb[2][6]} {wcfb[2][7]} ]]
        # create_debug_port u_ila_0 probe
        # set_property port_width 1 [get_debug_ports u_ila_0/probe4]
        # set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_0/probe4]
        # connect_debug_port u_ila_0/probe4 [get_nets [list enc_rst_n_reg_n_0 ]]
        # create_debug_port u_ila_0 probe
        # set_property port_width 12 [get_debug_ports u_ila_0/probe5]
        # set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_0/probe5]
        # connect_debug_port u_ila_0/probe5 [get_nets [list {crgb_reg_n_0_[0]} {crgb_reg_n_0_[1]} {crgb_reg_n_0_[2]} {crgb_reg_n_0_[3]} {crgb_reg_n_0_[4]} {crgb_reg_n_0_[5]} {crgb_reg_n_0_[6]} {crgb_reg_n_0_[7]} {crgb_reg_n_0_[8]} {crgb_reg_n_0_[9]} {crgb_reg_n_0_[10]} {crgb_reg_n_0_[11]} ]]
        # create_debug_port u_ila_0 probe
        # set_property port_width 1 [get_debug_ports u_ila_0/probe6]
        # set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_0/probe6]
        # connect_debug_port u_ila_0/probe6 [get_nets [list enc_en_reg_n_0 ]]
        # create_debug_port u_ila_0 probe
        # set_property port_width 1 [get_debug_ports u_ila_0/probe7]
        # set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_0/probe7]
        # connect_debug_port u_ila_0/probe7 [get_nets [list write_to_buffer_reg_n_0 ]]
        # create_debug_port u_ila_0 probe
        # set_property port_width 9 [get_debug_ports u_ila_0/probe8]
        # set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_0/probe8]
        # connect_debug_port u_ila_0/probe8 [get_nets [list {fb/addra[8]} {fb/addra[7]} {fb/addra[6]} {fb/addra[5]} {fb/addra[4]} {fb/addra[3]} {fb/addra[2]} {fb/addra[1]} {fb/addra[0]}]]
        # create_debug_port u_ila_0 probe
        # set_property port_width 1 [get_debug_ports u_ila_0/probe9]
        # set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_0/probe9]
        # connect_debug_port u_ila_0/probe9 [get_nets [list {JC_IBUF[2]}]]

        create_debug_core u_ila_1 ila
        set_property C_DATA_DEPTH 1024 [get_debug_cores u_ila_1]
        set_property C_TRIGIN_EN false [get_debug_cores u_ila_1]
        set_property C_TRIGOUT_EN false [get_debug_cores u_ila_1]
        set_property C_ADV_TRIGGER false [get_debug_cores u_ila_1]
        set_property C_INPUT_PIPE_STAGES 0 [get_debug_cores u_ila_1]
        set_property C_EN_STRG_QUAL false [get_debug_cores u_ila_1]
        set_property ALL_PROBE_SAME_MU true [get_debug_cores u_ila_1]
        set_property ALL_PROBE_SAME_MU_CNT 1 [get_debug_cores u_ila_1]
        connect_debug_port u_ila_1/clk [get_nets [list clk_108 ]]
        set_property port_width 6 [get_debug_ports u_ila_1/probe0]
        set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_1/probe0]
        connect_debug_port u_ila_1/probe0 [get_nets [list {dd/icntr[0]} {dd/icntr[1]} {dd/icntr[2]} {dd/icntr[3]} {dd/icntr[4]} {dd/icntr[5]} ]]
        # connect_debug_port u_ila_1/probe0 [get_nets [list {fb/doutb[0]} {fb/doutb[1]} {fb/doutb[2]} {fb/doutb[3]} {fb/doutb[4]} {fb/doutb[5]} {fb/doutb[6]} {fb/doutb[7]} ]]
        create_debug_port u_ila_1 probe
        set_property port_width 9 [get_debug_ports u_ila_1/probe1]
        set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_1/probe1]
        connect_debug_port u_ila_1/probe1 [get_nets [list {dd/stream_ind_reg[0]} {dd/stream_ind_reg[1]} {dd/stream_ind_reg[2]} {dd/stream_ind_reg[3]} {dd/stream_ind_reg[4]} {dd/stream_ind_reg[5]} {dd/stream_ind_reg[6]} {dd/stream_ind_reg[7]} {dd/stream_ind_reg[8]} ]]
        create_debug_port u_ila_1 probe
        set_property port_width 12 [get_debug_ports u_ila_1/probe2]
        set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_1/probe2]
        connect_debug_port u_ila_1/probe2 [get_nets [list {dec_rgb[0]} {dec_rgb[1]} {dec_rgb[2]} {dec_rgb[3]} {dec_rgb[4]} {dec_rgb[5]} {dec_rgb[6]} {dec_rgb[7]} {dec_rgb[8]} {dec_rgb[9]} {dec_rgb[10]} {dec_rgb[11]}]]
        create_debug_port u_ila_1 probe
        set_property port_width 8 [get_debug_ports u_ila_1/probe3]
        set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_1/probe3]
        connect_debug_port u_ila_1/probe3 [get_nets [list {dd/current_input[7]} {dd/current_input[6]} {dd/current_input[5]} {dd/current_input[4]} {dd/current_input[3]} {dd/current_input[2]} {dd/current_input[1]} {dd/current_input[0]}]]
        # set_property port_width 9 [get_debug_ports u_ila_1/probe3]
        # set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_1/probe3]
        # connect_debug_port u_ila_1/probe3 [get_nets [list {fb/addrb[8]} {fb/addrb[7]} {fb/addrb[6]} {fb/addrb[5]} {fb/addrb[4]} {fb/addrb[3]} {fb/addrb[2]} {fb/addrb[1]} {fb/addrb[0]}]]
        # connect_debug_port u_ila_1/probe3 [get_nets [list {fb/addrb[5]} {fb/addrb[4]} {fb/addrb[3]} {fb/addrb[2]} {fb/addrb[1]} {fb/addrb[0]}]]
        create_debug_port u_ila_1 probe
        set_property port_width 1 [get_debug_ports u_ila_1/probe4]
        set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_1/probe4]
        connect_debug_port u_ila_1/probe4 [get_nets [list {fb/enb} ]]

        create_debug_port u_ila_1 probe
        set_property port_width 1 [get_debug_ports u_ila_1/probe5]
        set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_1/probe5]
        connect_debug_port u_ila_1/probe5 [get_nets [list {dec_en} ]]

        create_debug_port u_ila_1 probe
        set_property port_width 1 [get_debug_ports u_ila_1/probe6]
        set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_1/probe6]
        connect_debug_port u_ila_1/probe6 [get_nets [list {dec_done} ]]
        # create_debug_port u_ila_1 probe
        # set_property port_width 1 [get_debug_ports u_ila_1/probe10]
        # set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_1/probe10]
        # connect_debug_port u_ila_1/probe10 [get_nets [list {crgb_reg_n_0_[1]} ]]
        # create_debug_port u_ila_1 probe
        # set_property port_width 1 [get_debug_ports u_ila_1/probe10]
        # set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_1/probe10]
        # connect_debug_port u_ila_1/probe10 [get_nets [list {crgb_reg_n_0_[2]} ]]
        # create_debug_port u_ila_1 probe
        # set_property port_width 1 [get_debug_ports u_ila_1/probe11]
        # set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_1/probe11]
        # connect_debug_port u_ila_1/probe12 [get_nets [list {crgb_reg_n_0_[3]} ]]
        # create_debug_port u_ila_1 probe
        # set_property port_width 1 [get_debug_ports u_ila_1/probe13]
        # set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_1/probe13]
        # connect_debug_port u_ila_1/probe13 [get_nets [list {crgb_reg_n_0_[4]} ]]
        # create_debug_port u_ila_1 probe
        # set_property port_width 1 [get_debug_ports u_ila_1/probe14]
        # set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_1/probe14]
        # connect_debug_port u_ila_1/probe14 [get_nets [list {crgb_reg_n_0_[5]} ]]
        # create_debug_port u_ila_1 probe
        # set_property port_width 1 [get_debug_ports u_ila_1/probe15]
        # set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_1/probe15]
        # connect_debug_port u_ila_1/probe15 [get_nets [list {crgb_reg_n_0_[6]} ]]
        # create_debug_port u_ila_1 probe
        # set_property port_width 1 [get_debug_ports u_ila_1/probe16]
        # set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_1/probe16]
        # connect_debug_port u_ila_1/probe16 [get_nets [list {crgb_reg_n_0_[7]} ]]
        # create_debug_port u_ila_1 probe
        # set_property port_width 1 [get_debug_ports u_ila_1/probe17]
        # set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_1/probe17]
        # connect_debug_port u_ila_1/probe17 [get_nets [list {crgb_reg_n_0_[8]} ]]
        # create_debug_port u_ila_1 probe
        # set_property port_width 1 [get_debug_ports u_ila_1/probe18]
        # set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_1/probe18]
        # connect_debug_port u_ila_1/probe18 [get_nets [list {crgb_reg_n_0_[9]} ]]
        # create_debug_port u_ila_1 probe
        # set_property port_width 1 [get_debug_ports u_ila_1/probe19]
        # set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_1/probe19]
        # connect_debug_port u_ila_1/probe19 [get_nets [list {crgb_reg_n_0_[10]} ]]
        # create_debug_port u_ila_1 probe
        # set_property port_width 1 [get_debug_ports u_ila_1/probe20]
        # set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_1/probe20]
        # connect_debug_port u_ila_1/probe20 [get_nets [list {crgb_reg_n_0_[11]} ]]
        # create_debug_port u_ila_1 probe
        # set_property port_width 1 [get_debug_ports u_ila_1/probe21]
        # set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_1/probe21]
        # connect_debug_port u_ila_1/probe21 [get_nets [list enc_en_reg_n_0 ]]
        set_property C_CLK_INPUT_FREQ_HZ 108000000 [get_debug_cores dbg_hub]
        set_property C_ENABLE_CLK_DIVIDER false [get_debug_cores dbg_hub]
        set_property C_USER_SCAN_CHAIN 1 [get_debug_cores dbg_hub]
        connect_debug_port dbg_hub/clk [get_nets clk_108]
        implement_debug_core
        write_checkpoint -force $debug_checkpoint
    } else {
        implement_debug_core
    }
    # implement_debug_core
    # write_checkpoint -force $debug_checkpoint
# }

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
write_debug_probes -force $output_dir/debug.ltx
