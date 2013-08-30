Hello08
=========

Same example as in Hello07 but aragned so that it is a beter startingpoint 
for new projects added "make exec" for uploading hello08.elf and running it
using xmd


Rearanged the the files into new diectories:                      

   DRIVERS =../drivers/   <- Drivers
   STARTUP =../arch/      <- Startup scripts 
   SCRIPTS =../scripts/   <- xmd scripts

NewLib
==================

We need to link width the option -lc and -gcc to use libc.a and libgcc.a

For libc.a
To figure out where the sudo apt-get instll newlib-arm-eabi installed it's
files we need to enter the folowing in an terminal window:
    dpkg -L newlib-arm-none-eabi
This gives you a list like:
   /usr/arm-none-eabi/include/utmp.h
   /usr/arm-none-eabi/include/string.h
   ...
And for the libgcc.a
   dpkg -L gcc-arm-none-eabi
 
The Needed files is located in /usr/amr-none-eabi/ and
/usr/lib/gcc/arm-none-eabi/4.6.2/
and we need to update the Make file so that it know where to get the include
and obj files from..


  
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

The hello08 is compiled using make :)


UPLOAD AND RUNNING USING U-BOOT
===============================

hello01.bin has its entrypoint / start address at: 0x10000

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
       Hello world!

LICENSE
==============

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
