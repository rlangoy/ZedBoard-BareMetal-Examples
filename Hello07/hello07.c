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
#include "xuartps.h" /*Maps stdin & stdout to use the RS232 uart */	 

void c_entry()
{
  char strUserName[128];
  init_uart1_RxTx_115200_8N1();
  printf("\nHello i am ZedBoard\n");
  printf("\nWho are you ? ");
  scanf("%127[0-9a-zA-Z \t]s", strUserName);
  printf("\nNice to meet you %s",strUserName);
  
  while(1) ; /*dont exit the program*/
}
        
