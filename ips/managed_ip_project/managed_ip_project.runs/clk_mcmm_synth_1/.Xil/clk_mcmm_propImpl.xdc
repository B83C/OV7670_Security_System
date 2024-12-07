set_property SRC_FILE_INFO {cfile:/home/b83c/fpga/vga/src/ips/clk_mcmm/clk_mcmm.xdc rfile:../../../../clk_mcmm/clk_mcmm.xdc id:1 order:EARLY scoped_inst:inst} [current_design]
current_instance inst
set_property src_info {type:SCOPED_XDC file:1 line:54 export:INPUT save:INPUT read:READ} [current_design]
set_input_jitter [get_clocks -of_objects [get_ports clk]] 0.100
