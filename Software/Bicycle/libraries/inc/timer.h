/*
 * timer.h
 *
 *  Created on: Jan 2, 2023
 *      Author: burak
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include "stm32l0xx_hal.h"

void TIM_Start( TIM_TypeDef* TIMx );
volatile extern uint8_t oneSecondIsOver;

#endif /* INC_TIMER_H_ */
