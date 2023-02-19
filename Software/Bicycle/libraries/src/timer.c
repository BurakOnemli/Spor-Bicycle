/*
 * timer.c
 *
 *  Created on: Jan 2, 2023
 *      Author: burak
 */

#include "timer.h"

void TIM_Start( TIM_TypeDef* TIMx )
{
	  // Clock divided by 7999 + 1
	  TIM2->PSC = 7999;
	  // ARR is 999 + 1
	  TIM2->ARR = 999;
	  //So the maximum time can be measured is 1s

	  TIM2->DIER |= TIM_DIER_UIE;
	  NVIC_EnableIRQ(TIM2_IRQn);

	  TIM2->CR1 |= TIM_CR1_CEN;
}

void TIM2_IRQHandler ( void )
{
	if((TIM2->SR & TIM_SR_UIF) == 1)
	{
		oneSecondIsOver = 1;
		TIM2->SR &= ~TIM_SR_UIF;
	}
}







