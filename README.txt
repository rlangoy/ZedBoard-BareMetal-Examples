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
.\Hello04 ->  Same example as in Hello03 but seperates the "main" program 
               and the UART functions (located in xuartps.h)
.\Hello05 ->  Same example as in Hello04 but implements printf support for
	       %d,%u,%c,%s,%x%,X
  	       Using the printf libaray Copyright (C) 2004,2008 by  Kustaa Nyholm 
	       More info on: http://www.sparetimelabs.com/printfrevisited/index.html  
               Please read Copy right notice on in the end of this file
.\Hello06 ->  Same exame as in Hello05 but implementing printf using NewLib 
               This allows us to properly display printf("Hello nr %.2f",3.14);
 

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


PLEASE NOTE
============

More information on printf.h & print.c could be found at:
   http://www.sparetimelabs.com/printfrevisited/index.html

The files printf.h & printf.c
=============================

Copyright (C) 2004,2008  Kustaa Nyholm

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
