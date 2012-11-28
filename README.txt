ZedBoardHelloBareMetal
======================

This is a collection of examples of "Bare Metal" programs for the ARM
processon on the ZedBoard.


All programs contains a README.txt for a more detailed description

Programs :
.\Hello01 ->  Makes a .bin file that could be uploaded using u-Boot 
              to the Zedboard and displays "Hello World" using the serial uart
.\Hello02 ->  Same as Hello01, but uses printf to displays "Hello World"
	      using the serial uart 
.\Hello03 ->  Same example as in Hello03 initiates the UART to use:
              baudrate: 11,5200 8-N-1 (8-bit no-parity one-stop-bit)
              The example show impements a structure describing the UART
              and some registers bitmask.The sample dosent depent on U-Boot
              (to setup the baudrate etc)

BUILD REQUIREMENTS
==================

Build requirements for  Linux Mint 13 (Maye) (should work for all debian
installation on x86 platfom)

Import binaries by add PPA in your system:
   sudo add-apt-repository ppa:germia/archive3
Refresh list of software available, including the PPA you just added:
   sudo apt-get update

Install the pacgages ARM - tool Chain by installing using 
   sudo apt-get install gcc-arm-none-eabi binutils-arm-none-eabi \
   newlib-arm-none-eabi \
   gdb-arm-none-eabi
