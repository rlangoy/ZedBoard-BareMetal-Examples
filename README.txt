ZedBoard Hello BareMetal
========================

This is a collection of examples of "Bare Metal" programs for the ARM
processon on the ZedBoard.

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
	         http://www.sparetimelabs.com/printfrevisited/index.html  
               Please read Copy right notice on in the end of this file

.\HelloQemu -> Simple example and doc for simulation using QEMU
               The sample uses UART0


.\drivers ->  Driver for serial-port
.\arch    ->  Startup scripts
.\scripts ->  xmd scripts


All programs contains a README.txt for a more detailed description


BUILD REQUIREMENTS
==================

Build requirements for  Linux Mint 15 (Olivia) (should work for all debian
installation on x86 platfom)

Install ARM Cross-Compiler:

   Refresh list of software available                        
      sudo apt-get update

   Install the ARM Cross-Compiler using
      sudo apt-get install gcc-arm-linux-gnueabihf


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


LICENSE for all files excluding printf.c and printf.h
=====================================================

Copyright (C) 2012-2020  Rune Langoy

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to
deal in the Software without restriction, including without limitation the
rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
IN THE SOFTWARE.
