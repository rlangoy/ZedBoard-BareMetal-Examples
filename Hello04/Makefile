ARMGNU ?= arm-none-eabi
COPS    =   
ARCH    = -mcpu=cortex-a9 -mfpu=vfpv3 

gcc : hello04.bin

all : gcc clang

clean :
	rm -f *.o
	rm -f *.bin
	rm -f *.hex
	rm -f *.elf
	rm -f *.list
	rm -f *.img
	rm -f *.bc

clang: hello04.bin

startup.o : startup.s
	$(ARMGNU)-as $(ARCH) startup.s -o startup.o

xuartps.o : xuartps.c
	$(ARMGNU)-gcc $(COPS) $(ARCH) -c xuartps.c -o xuartps.o

hello04.o : hello04.c
	$(ARMGNU)-gcc $(COPS) $(ARCH) -c hello04.c -o hello04.o

hello04.bin : memmap.ld startup.o hello04.o xuartps.o 
	$(ARMGNU)-ld startup.o xuartps.o hello04.o -T memmap.ld -o hello04.elf
	$(ARMGNU)-objdump -D hello04.elf > hello04.list
	$(ARMGNU)-objcopy hello04.elf -O ihex hello04.hex
	$(ARMGNU)-objcopy hello04.elf -O binary hello04.bin
