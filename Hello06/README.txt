Hello06
=========

Same example as i  Hello04 but implementing printf using the NewLib Library
       This allows us to properly display printf("Hello mr %.2f",3.14);

NewLib
==================

We need to link width the option -lc and -gcc to use libc.a and libgcc.a

To figure out where the sudo apt-get instll newlib-arm-eabi installed it's
files we need to enter the folowing in an terminal window:
    dpkg -L newlib-arm-none-eabi
This gives you a list like:
   /usr/arm-none-eabi/include/utmp.h
   /usr/arm-none-eabi/include/string.h
   ...

The Needed files is located in /usr/amr-none-eabi/ and
/usr/lib/gcc/arm-none-eabi/4.6.2/
and we need to update the Make file so that it know where to get the include
and obj files from..


  
BUILD REQUIREMENTS
===================

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


BUILD 
======

The hello05.bin file is compiled using make :)


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
