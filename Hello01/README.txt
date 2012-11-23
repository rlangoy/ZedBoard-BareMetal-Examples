ZedBoardHelloBareMetal
======================

This is a collection of examples of "Bare Metal" programs for the ARM
processon on the ZedBoard.

Makes a .bin file that could be uploaded using u-Boot 
        to the Zedboard and display Hello World  using the serial uart

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


BUILD and HOWTO
================

The hello.bin file is compiled using make :)

hello.bin has its entrypoint / start address at: 0x10000

 a) Connect the Zedboard UART (USB) to the Computer.
 b) use a serial terminal program to comunicate width the UART that can
upload files using the kermit protocol
     (windows users can use Tera Term from
http://hp.vector.co.jp/authors/VA002416/teraterm.html )
 c) power on the ZedBoard and wait for the message:
        Hit any key to stop autoboot:   
     and stop it by pressing a key :)
 d) Upload the program hello.bin  using 
       loadb 0x10000
             now you ned to send the file hello.bin  using the Kermit
protocol
 e)  Run the program using
       go 0x10000

Now you shold se 
       ## Starting application at 0x00010000 ...
       Hello world!
