set_param general.maxThreads 16
set partNum xc7a35tcpg236-1
set_part xc7a35tcpg236-1
set script_dir [file dirname [file normalize [info script]]]

set root_dir $script_dir
set working_dir $root_dir/target
set output_dir $working_dir/out
set report_dir $working_dir/report
set checkpoints_dir $working_dir/checkpoints
set src_dir $root_dir/src
set ips_dir $root_dir/ips

file mkdir $working_dir
file mkdir $output_dir
file mkdir $report_dir
file mkdir $checkpoints_dir
