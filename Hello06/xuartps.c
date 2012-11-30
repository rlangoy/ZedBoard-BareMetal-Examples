/*
    ZedBoard / Zynq-7000 
    UART info could be found in
        B.33 UART Controller (UART) / Page 1626 in
           Zynq-7000
           All Programmable SoC
           Technical Reference Manual
        
        http://www.xilinx.com/support/documentation/user_guides/ug585-Zynq-7000-TRM.pdf       
*/
/*  NewLib How to use:
 *  https://docs.blackfin.uclinux.org/doku.php?id=toolchain:bare_metal:newlib
 *
 */

#include <errno.h>
#include <sys/stat.h>
extern int errno;

#include "xuartps.h"

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
	 
/* <stdio.h>'s printf uses puts to send chars
   puts so that printf sends char to the serial port*/
int puts(const char *s) 
{
    while(*s != '\0') 
    { 
	  if(*s=='\n')
		  sendUART1char('\r');
	   
	   sendUART1char(*s); //Send char to the UART1	   
	   s++; // Next char 
    }
    return 0;
}

void putc(char ch)
{
	  if(ch=='\n')
		  sendUART1char('\r');
	   
	   sendUART1char(ch); //Send char to the UART1	     
}

///////////////////////////////////////////////////////////////
//	LOW LEVEL STUBS                                          //
///////////////////////////////////////////////////////////////


int
_isatty (int fd)
{
  return 1;
}

int
_kill (int n, int m)
{
    return(0);
}

void _exit(int status) 
{
    while(1)  {/* Loop until reset*/ }
}

    
int
_getpid (int n)
{
  return 1;
}
        

 
int
_open (const char *name,
       int         flags,
       int         mode)
{
  //errno = ENOSYS;
  return -1;                    /* Always fails */
 
}       /* _open () */
 
int
_close (int   file)
{
  //errno = EBADF;
  return -1;                    /* Always fails */
 
}       /* _close () */
 
int
_write (int   file,
        char *buf,
        int   nbytes)
{
  int i;
 
  /* Output character at at time */
  for (i = 0; i < nbytes; i++)
    {
	  //UART_putc( *buf++ );
    }
 
  //UART_waitForTransferCompletion();
 
  return nbytes;
 
}       /* _write () */
 
int
_read (int   file,
	   char *buf,
	   int   nbytes)
{
 
  int result = 0;//UART_gets( (char *) buf, nbytes );
 
  return result;                          /* EOF */
 
}       /* _read () */
 
int
_fstat (int          file,
        struct stat *st)
{
  st->st_mode = S_IFCHR;
  return  0;
 
}       /* _fstat () */
 
int
_lseek (int   file,
        int   offset,
        int   whence)
{
  return  0;
 
}       /* _lseek () */
 
void *
_sbrk (int nbytes)
{
/*	  extern char heap_low[];		// Defined by the linker.  
	  extern char heap_start[];		// Defined by the linker.  
 
	  static char *heap_end;
	  char *prev_heap_end;
 
	  if (heap_end == NULL)
	    heap_end = &heap_start;
 
	  prev_heap_end = heap_end;
 	    {
	      errno = ENOMEM;
	      return (void *) -1;
	    }
 
	  heap_end += nbytes;
 
	  return prev_heap_end;
 */
 return 0;
} // _sbrk () //
