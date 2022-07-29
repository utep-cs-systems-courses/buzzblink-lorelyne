COMMON_OBJECTS =
CPU 	       = msp430g2553
CFLAGS	       = -mmcu=${CPU} -I../h
LDFLAGS	       = -L/opt/ti/msp430_gcc/include

CC 	       = msp430-elf-gcc
AS	       = msp430-elf-as

all: src.elf

src.elf: ${COMMON_OBJECTS} p2_interrupt_handler.o switches.o main.o buzzer.o stateMachines.o led.o wdInterruptHandler.o ../lib/libTimer.a
	 ${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: src.elf
	msp430loader.sh src.elf

clean:
	rm -f *.o *.elf

led.o: led.h

wdInterruptHandler.o: stateMachines.h buzzer.h led.h switches.h

stateMachines.o: led.h buzzer.h stateMachines.h

buzzer.o: buzzer.h

switches.o: switches.h led.h stateMachines.h buzzer.h

p2_interrupt_handler.o: switches.h 
