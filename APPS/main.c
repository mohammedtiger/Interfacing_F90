
//#include "../MCAL/F90_TIMER_0.h"
#include "string.h"
#include "stdio.h"
#include "../MCAL/F90_UART.h"
#include "../MCAL/F90_SPI.h"
#include "../HAL/F90_RTC.h"
#include "../HAL/F90_Temperature.h"
#include "../MCAL/F90_PWM.h"

#include <util/delay.h>

 char data[50];

int main ()
{

	F90_void_UART_init(9600);
	F90_void_PWM_init();
	int i = 0;
	while(1)
	{
		memset(data , 0 , sizeof(data));
		int temp = F90_int_Temp_Read();
		sprintf(data , "Temp : %d\n" , temp);
		F90_void_UART_SendString(data);

		F90_void_PWM_Set(i+=10);
		_delay_ms(100);

		i%=250;


	}

	return 0;
}
