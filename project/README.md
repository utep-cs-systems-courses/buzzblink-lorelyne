## Description

Switch                                 | Description
-------------------------------------- | ----------------------------------------
1: Red Light on                        | Turn on red LED
2: Dimming led w/ buzzer               | Dim green led, toggle red light to restart dimming
3: Buzz and LED pattern                | Alternate between green and red LED with buzz pattern sound
4: Reset                               | Turn off the leds and stop buzzing.

## How to Use

Run `make all`. To load the program into the MSP430 run `make load-c` to use the C code, or `make load-s` to use the assembly code. Run `make clean` to clean unnecessary files like object files, executables, and two libraries, 'h' and 'lib'.



