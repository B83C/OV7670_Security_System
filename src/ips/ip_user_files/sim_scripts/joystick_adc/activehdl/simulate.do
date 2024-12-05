transcript off
onbreak {quit -force}
onerror {quit -force}
transcript on

asim +access +r +m+joystick_adc  -L xpm -L xil_defaultlib -L unisims_ver -L unimacro_ver -L secureip -O2 xil_defaultlib.joystick_adc xil_defaultlib.glbl

do {joystick_adc.udo}

run

endsim

quit -force
