 
#define UART0_BASE 0xe0001000
#define UART0_TxBUFR ((unsigned int *) (UART0_BASE + 0x30))

volatile unsigned int * const UART0TX = UART0_TxBUFR;
	 
void print_uart0(const char *s) 
{
    while(*s != '\0') 
    {     /* Loop until end of string */
	 *UART0TX = (unsigned int)(*s); /* Transmit char */
	 s++; /* Next char */
    }
}
	 
void c_entry() 
{
   print_uart0("Hello world!\n");
}