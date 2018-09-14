
//#include "../MCAL/F90_TIMER_0.h"
#include "string.h"
#include "stdio.h"
#include "../MCAL/F90_UART.h"
#include "../MCAL/F90_SPI.h"
#include "../HAL/F90_RTC.h"

#include <avr/io.h>
#include <util/delay.h>

#define MASTERMODE
//#define SLAVEMODE

 char data[50];

int main ()
{

	F90_void_UART_init(9600);

	F90_void_RTC_init();

	//F90_void_RTC_Settime(9 , 19 , 00);

	unsigned char HH ,MM ,SS;
	while(1)
	{

		F90_void_RTC_Gettime(&HH , &MM , &SS);
		sprintf(data , "Hour : %d , Minute : %d , Sencond : %d\n" , HH, MM,SS);
		F90_void_UART_SendString(data);

		_delay_ms(1000);


	}

	return 0;
}
