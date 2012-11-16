#define UART_FIFO_OFFSET	0x30 
#define USART_BASE        0xe0001000

volatile unsigned int * const UART0DR = (unsigned int *) 0xe0001030;
	 
void print_uart0(const char *s) 
{
    while(*s != '\0') 
    {     /* Loop until end of string */
	 *UART0DR = (unsigned int)(*s); /* Transmit char */
	 s++; /* Next char */
    }
}
	 
void c_entry() 
{
   print_uart0("Hello world!\n");
}