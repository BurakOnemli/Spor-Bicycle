/*
 * exti.h
 *
 *  Created on: Jan 12, 2023
 *      Author: burak
 */

#ifndef INC_EXTI_H_
#define INC_EXTI_H_

#include "stm32l0xx_hal.h"

void EXTI_Start ( void );
volatile extern uint16_t countPerInterrupt;

#endif /* INC_EXTI_H_ */
