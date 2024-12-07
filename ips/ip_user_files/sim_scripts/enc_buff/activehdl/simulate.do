transcript off
onbreak {quit -force}
onerror {quit -force}
transcript on

asim +access +r +m+enc_buff  -L xpm -L blk_mem_gen_v8_4_8 -L xil_defaultlib -L unisims_ver -L unimacro_ver -L secureip -O2 xil_defaultlib.enc_buff xil_defaultlib.glbl

do {enc_buff.udo}

run

endsim

quit -force
