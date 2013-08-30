ARMGNU ?= arm-linux-gnueabihf
COPS    =   
ARCH    = -mcpu=cortex-a9 -mfpu=vfpv3 

gcc : hello01.bin

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

hello01.o : hello01.c
	$(ARMGNU)-gcc $(COPS) $(ARCH) -c hello01.c -o hello01.o

hello01.bin : memmap.ld startup.o hello01.o 
	$(ARMGNU)-ld startup.o hello01.o -T memmap.ld -o hello01.elf
	$(ARMGNU)-objdump -D hello01.elf > hello01.list
	$(ARMGNU)-objcopy hello01.elf -O ihex hello01.hex
	$(ARMGNU)-objcopy hello01.elf -O binary hello01.bin
