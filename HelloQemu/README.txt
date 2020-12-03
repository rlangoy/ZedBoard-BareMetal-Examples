HelloQemu
======================

Makes a .bin file that could be uploaded to qemu (the FAST! processor emulator) 
        emulator display Hello World using the emulated serial uart

BUILD REQUIREMENTS
===================

Build requirements for  Linux Mint 15 (Olivia) (should work for all debian
installation on x86 platfom)

Install ARM Cross-Compiler:

   Refresh list of software available
      sudo apt-get update

   Install the ARM Cross-Compiler using 
      sudo apt-get install gcc-arm-linux-gnueabihf

Install qemu using:
    sudo apt-get install quemu qemu-utils qemu-system-arm

BUILD 
======

The helloq.bin file is compiled using make :)


UPLOAD AND RUNNING USING QEMU
===============================

Start xuilinx-zynq qemu emulation by uploading helloq.bin to 0x1000 and run it.
     qemu-system-arm -machine xilinx-zynq-a9 -kernel ./helloq.bin -nographic

Kill emulation by:
     
     Ctrl-A X

     1) First press [Ctrl] and [a] 
     2) Release the keys
     3) Press [x]


UPLOAD AND RUNNING USING QEMU & GDB
====================================

Install gdb for multi architecture
    sudo apt install gdb-multiarch



Start xuilinx-zynq qemu emulation :
    qemu-system-arm -machine xilinx-zynq-a9 -s -S


Start gdb in the current diectory
    gdb-multiarch -d $PWD

Run the commands:
    target remote 127.0.0.1:1234
    load helloq.elf
    c

(or gdb-multiarch -d $PWD -x cmd.txt )

In QEMU click "View | serial0"  and see the text :)
To run the program once more click  "machine | reset"



LICENSE
==========

Copyright (C) 2020  Rune Langoy

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
