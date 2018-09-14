/*
 * F90_UART.h
 *
 *  Created on: Sep 7, 2018
 *      Author: root
 */

#ifndef F90_UART_H_
#define F90_UART_H_

#define SET_BIT(REG , BIT) (REG |= (1 << BIT))
#define CLEAR_BIT(REG , BIT) (REG &= ~(1 << BIT))
#define READ_BIT(REG , BIT) (REG & (1 << BIT))


void F90_void_UART_init(unsigned long baud);
void F90_void_UART_Write(char data);
void F90_void_UART_SendString(char *arr);
char F90_char_UART_Read();


#endif /* F90_UART_H_ */
