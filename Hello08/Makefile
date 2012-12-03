
# Name of main file to by compiled 
MFILE =hello08

ARMGNU ?= arm-none-eabi
COPS    = -Wall -nodefaultlibs -I /usr/arm-none-eabi/include
ARCH    = -mcpu=cortex-a9 -mfpu=vfpv3 -I /usr/arm-none-eabi/include 
CDIR    = /usr/arm-none-eabi

DRIVERS =../drivers/
STARTUP =../arch/

LIB = -L /usr/arm-none-eabi/lib/ -L /usr/lib/gcc/arm-none-eabi/4.6.2/

gcc : $(MFILE).bin

all : gcc clang

clean :
	rm -f *.o
	rm -f *.bin
	rm -f *.hex
	rm -f *.elf
	rm -f *.list
	rm -f *.img
	rm -f *.bc

clang: $(MFILE).bin

startup.o : $(STARTUP)startup.s
	$(ARMGNU)-as $(ARCH) $(STARTUP)startup.s -o startup.o

xuartps.o : $(DRIVERS)xuartps.c
	$(ARMGNU)-gcc $(COPS) $(ARCH) -c $(DRIVERS)xuartps.c -o xuartps.o

$(MFILE).o : $(MFILE).c
	$(ARMGNU)-gcc $(COPS) $(ARCH) -I $(DRIVERS) -c $(MFILE).c  -o $(MFILE).o

$(MFILE).bin : $(STARTUP)memmap.ld startup.o xuartps.o $(MFILE).o 
	$(ARMGNU)-ld startup.o xuartps.o $(MFILE).o -T $(STARTUP)memmap.ld  -o $(MFILE).elf $(LIB) -lc -lgcc -lg -lm
	$(ARMGNU)-objdump -D $(MFILE).elf > $(MFILE).list
	$(ARMGNU)-objcopy $(MFILE).elf -O ihex $(MFILE).hex
	$(ARMGNU)-objcopy $(MFILE).elf -O binary  $(MFILE).bin
exec:
	cp $(MFILE).elf startup.elf
	xmd -tcl "../scrips/xmd_exec.tcl $(MFILE).elf"