ARMGNU ?= arm-linux-gnueabihf
COPS    =   
ARCH    = -mcpu=cortex-a9 -mfpu=vfpv3 

gcc : hello03.bin

all : gcc clang

clean :
	rm -f *.o
	rm -f *.bin
	rm -f *.hex
	rm -f *.elf
	rm -f *.list
	rm -f *.img
	rm -f *.bc

clang: hello03.bin

startup.o : startup.s
	$(ARMGNU)-as $(ARCH) startup.s -o startup.o

hello03.o : hello03.c
	$(ARMGNU)-gcc $(COPS) $(ARCH) -c hello03.c -o hello03.o

hello03.bin : memmap.ld startup.o hello03.o 
	$(ARMGNU)-ld startup.o hello03.o -T memmap.ld -o hello03.elf
	$(ARMGNU)-objdump -D hello03.elf > hello03.list
	$(ARMGNU)-objcopy hello03.elf -O ihex hello03.hex
	$(ARMGNU)-objcopy hello03.elf -O binary hello03.bin
