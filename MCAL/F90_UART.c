


#include "F90_UART.h"
#include "avr/io.h"
#include "util/delay.h"
#include <avr/interrupt.h>

volatile unsigned char x = 0;
void F90_void_UART_init(unsigned long baud)
{
	UCSRB = 0;
	UCSRC = 0;
	UCSRA = 0;
	UBRRH = 0;
	UBRRL = 0;
	unsigned char reg = 0;
	unsigned long baudrate = (F_CPU / (16 * baud))- 1 ;
	UBRRH = (unsigned char)(baudrate >> 8);
	UBRRL = (unsigned char)baudrate;

	SET_BIT(reg , RXEN);
	SET_BIT(reg , TXEN);
	SET_BIT(reg , RXCIE);
	UCSRB = reg;
	reg = 0;

	SET_BIT(reg , URSEL);
	SET_BIT(reg , UCSZ0);
	SET_BIT(reg , UCSZ1);


	UCSRC = reg;


	sei();

}


void F90_void_UART_Write(char data)
{
	while(!(READ_BIT(UCSRA , UDRE)));
	UDR = (unsigned char)data;
}








void F90_void_UART_SendString(char *arr)
{
	int i = 0;
	while (arr[i] != 0)
	{
		F90_void_UART_Write(arr[i]);
		i++;
	}
}










char F90_char_UART_Read()
{
	while(!(READ_BIT(UCSRA , RXC)));
	return UDR;
}





ISR(USART_RXC_vect)
{
	x = UDR;
}
