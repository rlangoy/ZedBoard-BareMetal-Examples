/*
    ZedBoard / Zynq-7000 
    UART info could be found in
        B.33 UART Controller (UART) / Page 1626 in
           Zynq-7000
           All Programmable SoC
           Technical Reference Manual
        
        http://www.xilinx.com/support/documentation/user_guides/ug585-Zynq-7000-TRM.pdf       
*/

/*
    Page 496
    Simplifyed Table 19-1 UART Parameter Value Examples
    Parameter Value Examples
    Clock 		Baud  BRGR-CD   BDIV-CD 					Actual Baud Rate
    UART Ref clock 	  600   10417     7 
    UART Ref clock 	9,600     651     7 
    UART Ref clock     28,800 	  347     4
    UART Ref clock    115,200 	   62     6 
    UART Ref clock    230,400      31     6
*/
 
/*Baudrates assuming input clock speed is 3125000L */
/*Baud_rate_gen_reg0*/
#define XUARTPS_BRGR_CD_115200       3 /*Baud Rate Clock Divisor*/

/*Register Baud_rate_divider_reg0 Details*/
#define XUARTPS_BDIV_CD_115200       8 /*Baud Rate Clock Divisor*/


#include <stdio.h> 
#define u32 unsigned int

#define UART1_BASE 0xe0001000
// Register Description as found in
//    B.33 UART Controller (UART) p.1626
struct XUARTPS{
        u32 control_reg0;       /* UART Control Register def=0x128 */
        u32 mode_reg0;          /* UART Mode Register def=0 */
        u32 intrpt_en_reg0;     /* Interrupt Enable Register def=0 */
        u32 intrpt_dis_reg0;    /* Interrupt Disable Register def=0 */
        u32 intrpt_mask_reg0;   /* Interrupt Mask Register def=0 */
        u32 chnl_int_sts_reg0;  /* Channel Interrupt Status Register def=x200 */
        u32 baud_rate_gen;      /* Baud Rate Generator Register def=0x28B */
        u32 Rcvr_timeout_reg0;          /* Receiver Timeout Register def=0 */
        u32 Rcvr_FIFO_trigger_level0;   /* Receiver FIFO Trigger Level Register */
        u32 Modem_ctrl_reg0;            /* Modem Control Register def=0 */
        u32 Modem_sts_reg0;     /* Modem Status Register */
        u32 channel_sts_reg0;   /* Channel Status Register def=0 */
        u32 tx_rx_fifo;         /* Transmit and Receive FIFO def=0 */
        u32 baud_rate_divider;  /* Baud Rate Divider def=0xf */
        u32 Flow_delay_reg0;            /* Flow Control Delay Register  def=0*/
        u32 Tx_FIFO_trigger_level;};    /* Transmitter FIFO Trigger Level Register */

static struct XUARTPS *UART1=(struct XUARTPS*) UART1_BASE;        
//volatile unsigned int * const TxRxUART1 = UART1_TxRxFIFO0;

/*
* Initiate UART1  ( /dev/ttyACM0 on host computer )
*   115,200 Baud 8-bit No-Parity 1-stop-bit
*/
void init_uart1_RxTx_115200_8N1()
{
    
}
	 
/* <stdio.h>'s printf uses puts to send chars
   puts so that printf sends char to the serial port*/
int puts(const char *s) 
{
    while(*s != '\0') 
    {     /* Loop until end of string */
	 UART1->tx_rx_fifo= (unsigned int)(*s); /* Transmit char */
	 s++; /* Next char */
    }
    return 0;
}
	 
void c_entry() 
{
   init_uart1_RxTx_115200_8N1();
   printf("\nHello world!\n");
   while(1) ; /*dont exit the program*/
}