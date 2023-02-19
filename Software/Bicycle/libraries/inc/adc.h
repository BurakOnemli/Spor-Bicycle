/*
 * adc.h
 *
 *  Created on: Jan 15, 2023
 *      Author: burak
 */

#ifndef INC_ADC_H_
#define INC_ADC_H_

#include "stm32l0xx_hal.h"

void ADC_calibrate ( ADC_TypeDef* ADCx );
void ADC_init( ADC_TypeDef* ADCx );
uint16_t ADC_read ( ADC_TypeDef* ADCx );

#endif /* INC_ADC_H_ */
