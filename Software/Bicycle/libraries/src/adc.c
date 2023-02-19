/*
 * adc.c
 *
 *  Created on: Jan 14, 2023
 *      Author: burak
 */
#include "adc.h"

void ADC_calibrate ( ADC_TypeDef* ADCx )
{
	if ((ADCx->CR & ADC_CR_ADEN) != 0) /* (1) */ {
	ADCx->CR |= ADC_CR_ADDIS; /* (2) */ }
	ADCx->CR |= ADC_CR_ADCAL; /* (3) */
	while ((ADCx->ISR & ADC_ISR_EOCAL) == 0) /* (4) */ {
	             /* For robust implementation, add here time-out management */
	}
	ADCx->ISR |= ADC_ISR_EOCAL; /* (5) */
}

void ADC_init ( ADC_TypeDef* ADCx )
{

    // Configure the ADC resolution and data alignment
//	static bool initialized;
//	if (!initialized) {
//	   initialized = true;
//	   // do the initialization part
//	}
    ADCx->CFGR1 &= ~ADC_CFGR1_RES; // Clear the RES bits
    ADCx->CFGR1 |= ADC_CFGR1_RES_1; // Set the ADC resolution to 8-bit
    ADCx->CFGR1 &= ~ADC_CFGR1_ALIGN; // Clear the ALIGN bit
    ADCx->SMPR |= (ADC_SMPR_SMP_0 | ADC_SMPR_SMP_1 | ADC_SMPR_SMP_2); //Sampling time 12.5 + 160.5 clock cycles

    // Configure the input channel
    ADCx->CHSELR = ADC_CHSELR_CHSEL4; // Select channel 4 PA4 nucleo32 A3

    // Enable the ADC
    ADCx->CR |= ADC_CR_ADEN;
    while(!(ADCx->ISR & ADC_ISR_ADRDY));
}

uint16_t ADC_read ( ADC_TypeDef* ADCx )
{
    // Start the ADC conversion
    ADCx->CR |= ADC_CR_ADSTART;
    while(!(ADCx->ISR & ADC_ISR_EOC));

    // Read the ADC conversion result
    return ADCx->DR;
}
