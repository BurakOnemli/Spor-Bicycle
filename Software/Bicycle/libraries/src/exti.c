/*
 * exti.c
 *
 *  Created on: Jan 12, 2023
 *      Author: burak
 */

#include "exti.h"

void EXTI_Start ( void )
{
	SYSCFG->EXTICR[0] |= (uint16_t)SYSCFG_EXTICR1_EXTI0_PB;
	EXTI->IMR |= 0x0001; //Interrupt request from Line x is not masked
	EXTI->RTSR |= 0x0001; //Rising trigger enabled (for Event and Interrupt) for input line x

	NVIC_EnableIRQ(EXTI0_1_IRQn);
	NVIC_SetPriority(EXTI0_1_IRQn,0);
}

void EXTI0_1_IRQHandler ( void )
{
	countPerInterrupt++;
}
