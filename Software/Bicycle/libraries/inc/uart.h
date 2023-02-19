/*
 * uart.h
 *
 *  Created on: Jan 5, 2023
 *      Author: burak
 */

#ifndef INC_UART_H_
#define INC_UART_H_

#include "stm32l0xx_hal.h"

void UART_init( USART_TypeDef* USARTx );
void UART_write( USART_TypeDef* USARTx, char* data, uint8_t lenght );
char UART_read( USART_TypeDef* USARTx );

#endif /* INC_UART_H_ */
