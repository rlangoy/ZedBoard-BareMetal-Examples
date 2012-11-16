ARMGNU ?= arm-none-eabi
COPS    = -Wall -O2 -nostdlib -nostartfiles -ffreestanding 
ARCH    = -mcpu=cortex-a9 -mfpu=vfpv3 

gcc : hello.bin

all : gcc clang

clean :
	rm -f *.o
	rm -f *.bin
	rm -f *.hex
	rm -f *.elf
	rm -f *.list
	rm -f *.img
	rm -f *.bc

clang: hello.bin

startup.o : startup.s
	$(ARMGNU)-as $(ARCH) startup.s -o startup.o

hello.o : hello.c
	$(ARMGNU)-gcc $(COPS) $(ARCH) -c hello.c -o hello.o

hello.bin : memmap.ld startup.o hello.o 
	$(ARMGNU)-ld startup.o hello.o -T memmap.ld -o hello.elf
	$(ARMGNU)-objdump -D hello.elf > hello.list
	$(ARMGNU)-objcopy hello.elf -O ihex hello.hex
	$(ARMGNU)-objcopy hello.elf -O binary hello.bin
