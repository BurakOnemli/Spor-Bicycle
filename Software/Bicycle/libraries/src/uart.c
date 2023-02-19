/*
 * uart.c
 *
 *  Created on: Jan 5, 2023
 *      Author: burak
 */

#include "uart.h"

void UART_init( USART_TypeDef* USARTx )
{
	//1 Start bit, 8 data bits, n stop bits
	USARTx->BRR = 0x341;
	USARTx->CR1 = USART_CR1_TE | USART_CR1_UE | USART_CR1_RE;
}

void UART_write( USART_TypeDef* USARTx, char* data, uint8_t lenght )
{
	uint8_t index = 0;
	while(lenght > index)
	{
		USARTx->TDR = *(data + index);
		while( ( USARTx->ISR & USART_ISR_TC ) == 0 ); // Wait until the transmission is completed
		index++;
	}
}

char UART_read( USART_TypeDef* USARTx )
{
	char dataRead = 0;
	while( ( USARTx->ISR & ( USART_ISR_RXNE ) ) == 0 );
	dataRead = USARTx->RDR;
	return dataRead;
}
