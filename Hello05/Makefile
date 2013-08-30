ARMGNU ?= arm-linux-gnueabihf
COPS    =   
ARCH    = -mcpu=cortex-a9 -mfpu=vfpv3 

gcc : hello05.bin

all : gcc clang

clean :
	rm -f *.o
	rm -f *.bin
	rm -f *.hex
	rm -f *.elf
	rm -f *.list
	rm -f *.img
	rm -f *.bc

clang: hello05.bin

startup.o : startup.s
	$(ARMGNU)-as $(ARCH) startup.s -o startup.o

printf.o  : printf.c
	$(ARMGNU)-gcc $(COPS) $(ARCH) -c printf.c -o printf.o


xuartps.o : xuartps.c
	$(ARMGNU)-gcc $(COPS) $(ARCH) -c xuartps.c -o xuartps.o

hello05.o : hello05.c
	$(ARMGNU)-gcc $(COPS) $(ARCH) -c hello05.c -o hello05.o

hello05.bin : memmap.ld startup.o hello05.o xuartps.o printf.o
	$(ARMGNU)-ld startup.o printf.o xuartps.o hello05.o -T memmap.ld -o hello05.elf
	$(ARMGNU)-objdump -D hello05.elf > hello05.list
	$(ARMGNU)-objcopy hello05.elf -O ihex hello05.hex
	$(ARMGNU)-objcopy hello05.elf -O binary hello05.bin
