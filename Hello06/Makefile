ARMGNU ?= arm-none-eabi
COPS    = -Wall -nodefaultlibs -I /usr/arm-none-eabi/include
ARCH    = -mcpu=cortex-a9 -mfpu=vfpv3 -I /usr/arm-none-eabi/include 
CDIR    = /usr/arm-none-eabi

LIB = -L /usr/arm-none-eabi/lib/ -L /usr/lib/gcc/arm-none-eabi/4.6.2/

gcc : hello06.bin

all : gcc clang

clean :
	rm -f *.o
	rm -f *.bin
	rm -f *.hex
	rm -f *.elf
	rm -f *.list
	rm -f *.img
	rm -f *.bc

clang: hello06.bin

startup.o : startup.s
	$(ARMGNU)-as $(ARCH) startup.s -o startup.o

xuartps.o : xuartps.c
	$(ARMGNU)-gcc $(COPS) $(ARCH) -c xuartps.c -o xuartps.o

syscalls.o: syscalls.c
	$(ARMGNU)-gcc $(COPS) $(ARCH) -c syscalls.c -o syscalls.o

hello06.o : hello06.c
	$(ARMGNU)-gcc $(COPS) $(ARCH) -static  $(CDIR)/lib/libc.a -c hello06.c  -o hello06.o

hello06.bin : memmap.ld startup.o hello06.o 
	$(ARMGNU)-ld startup.o hello06.o -T memmap.ld  -o hello06.elf $(LIB) -lc -lgcc -lg -lm
	$(ARMGNU)-objdump -D hello06.elf > hello06.list
	$(ARMGNU)-objcopy hello06.elf -O ihex hello05.hex
	$(ARMGNU)-objcopy hello06.elf -O binary hello06.bin
