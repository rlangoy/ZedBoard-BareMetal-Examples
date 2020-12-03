ARMGNU ?= arm-linux-gnueabihf
COPS    =
ARCH    = -mcpu=cortex-a9 -mfpu=vfpv3

gcc : helloq.bin

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

helloq.o : helloq.c
	$(ARMGNU)-gcc $(COPS) $(ARCH) -c helloq.c -o helloq.o

helloq.bin : memmap.ld startup.o helloq.o
	$(ARMGNU)-ld startup.o helloq.o -T memmap.ld -o helloq.elf
	$(ARMGNU)-objdump -D helloq.elf > helloq.list
	$(ARMGNU)-objcopy helloq.elf -O ihex helloq.hex
	$(ARMGNU)-objcopy helloq.elf -O binary helloq.bin
