/*
    ZedBoard / Zynq-7000 
    UART info could be found in
        B.33 UART Controller (UART) / Page 1626 in
           Zynq-7000
           All Programmable SoC
           Technical Reference Manual
        
        http://www.xilinx.com/support/documentation/user_guides/ug585-Zynq-7000-TRM.pdf       
*/


#ifndef u32
   #define u32 unsigned int
#endif

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

/*
    Page 496
    Simplifyed Table 19-1 UART Parameter Value Examples
    Parameter Value Examples
    Clock 			     Baud  BRGR-CD   BDIV-CD 					Actual Baud Rate
    UART Ref clock 	      600   10417     7 
    UART Ref clock 	    9,600     651     7 
    UART Ref clock     28,800 	  347     4
    UART Ref clock    115,200 	   62     6 
    UART Ref clock    230,400      31     6
*/
 
/*Baudrates assuming input clock speed is 3125000L */
/*Baud_rate_gen_reg0*/
#define XUARTPS_BRGR_CD_115200       62 /*Baud Rate Clock Divisor*/

/*Register Baud_rate_divider_reg0 Details*/
#define XUARTPS_BDIV_CD_115200       6  /*Baud Rate Clock Divisor*/

/* Bits defined in the Register Channel_sts_reg0 */
#define UART_STS_TXFULL 1<<4    /* Transmitter FIFO Full continuous status:
                                 0: Tx FIFO is not full
                                 1: Tx FIFO is full*/
#define UART_STS_RXEMPTY 1<<1	/*Receiver FIFO Full continuous status:
								  0: Rx FIFO is not empty
								  1: Rx FIFO is empty*/

/*Register Control_reg0 BitMask */
#define XUARTPS_CR_STOPBRK (1<<8)  /* Stop transmitter break */
#define XUARTPS_CR_STTBRK  (1<<7)  /* Start transmitter break */
#define XUARTPS_CR_RSTTO   (1<<6)  /* Restart receiver timeout counter */
#define XUARTPS_CR_TXDIS   (1<<5)  /* Transmit disable */
#define XUARTPS_CR_TXEN    (1<<4)  /* Transmit enable */
#define XUARTPS_CR_RXDIS   (1<<3)  /* Receive disable */
#define XUARTPS_CR_RXEN    (1<<2)  /* Receive enable */
#define XUARTPS_CR_TXRES   (1<<1)  /* Software reset for Tx data path */
#define XUARTPS_CR_RXRES   (1<<0)  /* Software reset for Rx data path */

/*Register Control mode_reg0 BitMask*/
#define XUARTPS_MR_PAR                  /*Parity type select [5:3]*/
#define XUARTPS_MR_PAR_EVEN     0       /* 000: even parity
                                           001: odd parity
                                           010: forced to 0 parity (space)
                                           011: forced to 1 parity (mark)*/
#define XUARTPS_MR_PAR_NONE (1<<5)      /* 1xx: no parity*/
#define XUARTPS_MR_CHRL                 /* Character length select:
                                             11: 6 bits
                                             10: 7 bits*/
#define XUARTPS_MR_CHRL_8               /*   0x: 8 bits*/
                                                                                                                                                                     
#define XUARTPS_MR_CLKS                 /* Clock source select:*/
#define XUARTPS_MR_CLKS_REF_CLK 0       /*  0: clock source is uart_ref_clk*/

/*
* Initiate UART1  ( /dev/ttyACM0 on host computer )
*   115,200 Baud 8-bit No-Parity 1-stop-bit
*/
void init_uart1_RxTx_115200_8N1();
void sendUART1char(char s);
int  puts(const char *s);
