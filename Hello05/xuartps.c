/*
    ZedBoard / Zynq-7000 
    UART info could be found in
        B.33 UART Controller (UART) / Page 1626 in
           Zynq-7000
           All Programmable SoC
           Technical Reference Manual
        
        http://www.xilinx.com/support/documentation/user_guides/ug585-Zynq-7000-TRM.pdf       
*/

#include <stdarg.h>
#include "printf.h" /*From http://www.sparetimelabs.com/tinyprintf/index.html */
#include "xuartps.h"

void putc(int *p ,char c);

/*
* Initiate UART1  ( /dev/ttyACM0 on host computer )
*   115,200 Baud 8-bit No-Parity 1-stop-bit
*/
void init_uart1_RxTx_115200_8N1()
{
  /* Disable the transmitter and receiver before writing to the Baud Rate Generator */
  UART1->control_reg0=0; 

  /* Set Baudrate to 115,200 Baud */
  UART1->baud_rate_divider =XUARTPS_BDIV_CD_115200;
  UART1->baud_rate_gen=     XUARTPS_BRGR_CD_115200;

  /*Set 8-bit NoParity 1-StopBit*/
  UART1->mode_reg0   =   XUARTPS_MR_PAR_NONE;  
  
  /*Enable Rx & Tx*/
  UART1->control_reg0=   XUARTPS_CR_TXEN | XUARTPS_CR_RXEN | XUARTPS_CR_TXRES | XUARTPS_CR_RXRES ;      
  

}

void sendUART1char(char s)
{
  /*Make sure that the uart is ready for new char's before continuing*/
  while ((( UART1->channel_sts_reg0 ) & UART_STS_TXFULL) > 0) ;
  
  /* Loop until end of string */
  UART1->tx_rx_fifo= (unsigned int) s; /* Transmit char */
}

/* "print.h" uses this function for is's printf implementation */
void putchar(char c)
{
  if(c=='\n')
    sendUART1char('\r');
  sendUART1char(c);
}
	 
/* <stdio.h>'s printf uses puts to send chars
   puts so that printf sends char to the serial port*/
int puts(const char *s) 
{
    while(*s != '\0') 
    { 
	  if(*s=='\n')
		  sendUART1char('\r');
	   
	   sendUART1char(*s); /*Send char to the UART1*/	   
	   s++; /* Next char */
    }
    return 0;
}
