Hello05
=========

Same example as in Hello04 but implements printf support for %d,%u,%c,%s,%x%,X
  Using the printf libaray Copyright (C) 2004,2008 by  Kustaa Nyholm 
  More info on: http://www.sparetimelabs.com/printfrevisited/index.html  
  Please read Copy right notice on in the end of this file
  
BUILD REQUIREMENTS
===================

Build requirements for  Linux Mint 15 (Olivia) (should work for all debian
installation on x86 platfom)

Install ARM Cross-Compiler:

   Refresh list of software available                        
      sudo apt-get update

   Install the ARM Cross-Compiler using
      sudo apt-get install gcc-arm-linux-gnueabihf


BUILD 
======

The hello05.bin file is compiled using make :)


UPLOAD AND RUNNING USING U-BOOT
===============================

hello05.bin has its entrypoint / start address at: 0x10000

 a) Connect the Zedboard UART (USB) to the Computer.
 b)  use a serial terminal program to comunicate width the ZedBoard's UART 
        Windows:  can use Tera Term from
         http://hp.vector.co.jp/authors/VA002416/teraterm.html )
        Linux:
           Start a new terminal
	   Install minicom:
              sudo apt-install minicom
	      minicom -D/dev/ttyACM0 -b115200 -o                 

 c) power on the ZedBoard and wait for the message:
        Hit any key to stop autoboot:   
     and stop it by pressing a key :)

 d) Upload the program hello03.bin  using 
       loady 0x10000
             Send the file hello01.bin using the y-modem protocol
               Push ([Ctrl] + 'a') and then 'S' Select ymodem
               And select the file hello01.bin (using space) and [enter]
               (enter folders pushing space)         
       Linux:
             Stop screen by pushing ( [Ctrl] + 'a') and then 'k'
 
 e)  Run the program using
       go 0x10000

Now you shold se 
       ## Starting application at 0x00010000 ...
       Hello number 1


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

LICENSE all files except printf.c and printf.h
===============================================

Copyright (C) Rune Langoy 2012

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
