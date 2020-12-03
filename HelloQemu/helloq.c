/*
    ZedBoard / Zynq-7000 
    UART info could be found in
        B.33 UART Controller (UART) / Page 1626 in
           Zynq-7000
           All Programmable SoC
           Technical Reference Manual

        http://www.xilinx.com/support/documentation/user_guides/ug585-Zynq-7000-TRM.pdf
*/


#define UART0_BASE 0xe0000000
#define UART0_CTRL      ((unsigned int *) (UART0_BASE + 0x00)) /* UART Control Register */
#define UART0_TxRxFIFO0 ((unsigned int *) (UART0_BASE + 0x30)) /* UART FIFO             */

volatile unsigned int * const TxRxUART0 = UART0_TxRxFIFO0;
volatile unsigned int * const ctrlUART0 = UART0_CTRL;

#define XUARTPS_CR_TXEN    (1<<4)  /* Transmit enable */
#define XUARTPS_CR_RXEN    (1<<2)  /* Receive enable */
#define XUARTPS_CR_TXRES   (1<<1)  /* Software reset for Tx data path */
#define XUARTPS_CR_RXRES   (1<<0)  /* Software reset for Rx data path */

void enable_uart0()
{
  *ctrlUART0= XUARTPS_CR_TXEN | XUARTPS_CR_RXEN | XUARTPS_CR_TXRES | XUARTPS_CR_RXRES;
}


void print_uart0(const char *s) 
{
    while(*s != '\0') 
    {     /* Loop until end of string */
	 *TxRxUART0 = (unsigned int)(*s); /* Transmit char */
	 s++; /* Next char */
    }
}

void c_entry() 
{
   enable_uart0();   
   print_uart0("\r\nHello world!");
   while(1) ; /*dont exit the program*/
}
