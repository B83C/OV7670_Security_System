transcript off
onbreak {quit -force}
onerror {quit -force}
transcript on

asim +access +r +m+clk_mcmm  -L xpm -L xil_defaultlib -L unisims_ver -L unimacro_ver -L secureip -O5 xil_defaultlib.clk_mcmm xil_defaultlib.glbl

do {clk_mcmm.udo}

run 1000ns

endsim

quit -force
