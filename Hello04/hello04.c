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
#include "xuartps.h" /*Maps stdout to use the RS232 uart*/
	 
void c_entry() 
{
   init_uart1_RxTx_115200_8N1();
   printf("\nHello world!\n");
   while(1) ; /*dont exit the program*/
}
