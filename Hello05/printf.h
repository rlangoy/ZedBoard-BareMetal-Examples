/*
File: printf.h

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

This library is realy just two files: 'printf.h' and 'printf.c'.

They provide a simple and small (+100 loc) printf functionality to 
be used in embedded systems.

I've found them so usefull in debugging that I do not bother with a 
debugger at all.

They are distributed in source form, so to use them, just compile them 
into your project. 

The formats supported by this implementation are: 'd' 'u' 'c' 's' 'x' 'X'.

Zero padding and field width (limited to 255) are also supported.

The memory foot print of course depends on the target cpu, compiler and 
compiler options, but a rough guestimate (based on a HC08 target) is about 
600 - 1100 bytes for code and some twenty bytes of static data.  Note
that this printf is not re-entrant. 

Note that the code expects that int size is 16 bits, and that char is
8 bits.

To use the printf you need to supply your own character output function, 
something like :

void putchar (char c)
	{
	while (!SERIAL_PORT_EMPTY) ;
	SERIAL_PORT_TX_REGISTER = c;
	}


The printf function is actually a macro that translates to 'tfp_printf'. 
This makes it possible to use it along with 'stdio.h' printf's in a single 
source file. You just need to undef the names before you include the 'stdio.h'.
Note that these are not function-like macros, so if you have variables
or struct members with these names, things will explode in your face.
Without variadic macros this is the best we can do. If it is a  problem 
just give up the macros and use the functions directly or rename them.

For further details see source code.

regs Kusti, 26.2.2008
*/


#ifndef __TFP_PRINTF__
#define __TFP_PRINTF__

#include <stdarg.h>

void tfp_printf(char *fmt, ...);

#define printf tfp_printf 

#endif



