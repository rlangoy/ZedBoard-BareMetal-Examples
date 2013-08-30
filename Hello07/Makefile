ARMGNU ?= arm-linux-gnueabihf
COPS    = -Wall -nodefaultlibs -I /usr/arm-none-eabi/include
ARCH    = -mcpu=cortex-a9 -mfpu=vfpv3 -I /usr/arm-none-eabi/include 
CDIR    = /usr/arm-none-eabi

LIB = -L /usr/arm-none-eabi/lib/ -L /usr/lib/gcc/arm-none-eabi/4.6.2/

gcc : hello07.bin

all : gcc clang

clean :
	rm -f *.o
	rm -f *.bin
	rm -f *.hex
	rm -f *.elf
	rm -f *.list
	rm -f *.img
	rm -f *.bc

clang: hello07.bin

startup.o : startup.s
	$(ARMGNU)-as $(ARCH) startup.s -o startup.o

xuartps.o : xuartps.c
	$(ARMGNU)-gcc $(COPS) $(ARCH) -c xuartps.c -o xuartps.o

hello07.o : hello07.c
	$(ARMGNU)-gcc $(COPS) $(ARCH) -c hello07.c  -o hello07.o

hello07.bin : memmap.ld startup.o xuartps.o hello07.o 
	$(ARMGNU)-ld startup.o xuartps.o hello07.o -T memmap.ld  -o hello07.elf $(LIB) -lc -lgcc -lg -lm
	$(ARMGNU)-objdump -D hello07.elf > hello07.list
	$(ARMGNU)-objcopy hello07.elf -O ihex hello07.hex
	$(ARMGNU)-objcopy hello07.elf -O binary hello07.bin
