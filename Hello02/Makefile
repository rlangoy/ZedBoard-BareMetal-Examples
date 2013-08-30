ARMGNU ?= arm-linux-gnueabihf
COPS    =   
ARCH    = -mcpu=cortex-a9 -mfpu=vfpv3 

gcc : hello02.bin

all : gcc clang

clean :
	rm -f *.o
	rm -f *.bin
	rm -f *.hex
	rm -f *.elf
	rm -f *.list
	rm -f *.img
	rm -f *.bc

clang: hello02.bin

startup.o : startup.s
	$(ARMGNU)-as $(ARCH) startup.s -o startup.o

hello02.o : hello02.c
	$(ARMGNU)-gcc $(COPS) $(ARCH) -c hello02.c -o hello02.o

hello02.bin : memmap.ld startup.o hello02.o 
	$(ARMGNU)-ld startup.o hello02.o -T memmap.ld -o hello02.elf
	$(ARMGNU)-objdump -D hello02.elf > hello02.list
	$(ARMGNU)-objcopy hello02.elf -O ihex hello02.hex
	$(ARMGNU)-objcopy hello02.elf -O binary hello02.bin
