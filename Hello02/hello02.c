/*
    ZedBoard / Zynq-7000 
    UART info could be found in
        B.33 UART Controller (UART) / Page 1626 in
           Zynq-7000
           All Programmable SoC
           Technical Reference Manual
        
        http://www.xilinx.com/support/documentation/user_guides/ug585-Zynq-7000-TRM.pdf       
*/

#include <stdio.h> 
#define UART1_BASE 0xe0001000
#define UART1_TxRxFIFO0 ((unsigned int *) (UART1_BASE + 0x30))

volatile unsigned int * const TxRxUART1 = UART1_TxRxFIFO0;
	 
/* <stdio.h>'s printf uses puts to send chars
   puts so that printf sends char to the serial port*/
int puts(const char *s) 
{
    while(*s != '\0') 
    {     /* Loop until end of string */
	 *TxRxUART1 = (unsigned int)(*s); /* Transmit char */
	 s++; /* Next char */
    }
    return 0;
}
	 
void c_entry() 
{
   printf("\nHello world!\n");
   while(1) ; /*dont exit the program*/
}