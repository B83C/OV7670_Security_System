source init.tcl

read_ip [glob -nocomplain $root_dir/ips/*/*.xci]

# set_property generate_synth_checkpoint true [get_files buffer_mem.xci]
# generate_target all [get_ips buffer_mem]
# set buffer_mem_xdc [get_files -of_objects \
# [get_files buffer_mem.xci] -filter {FILE_TYPE == XDC}]
# set_property is_enabled false [get_files $buffer_mem_xdc]


synth_ip -force [get_ips joystick_adc clk_mcmm enc_buff rgb_stack]


