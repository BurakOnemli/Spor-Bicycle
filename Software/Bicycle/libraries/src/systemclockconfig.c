/*
 * systemclockconfig.c
 *
 *  Created on: Jan 5, 2023
 *      Author: burak
 */

#include "systemclockconfig.h"

void SystemClock_Config(void)
{

	RCC->CR |= RCC_CR_HSION; //Activate HSI

	while (RCC->CR & RCC_CR_HSIRDY); //Wait until the HSI is ready

	RCC->APB1ENR |= RCC_APB1ENR_PWREN; //Activating the clock source of PWR
	PWR->CR |= PWR_CR_VOS_0; //Voltage regulator output is 1.8V
	PWR->CR &= ~PWR_CR_VOS_1; //Performance max power consumption max

	FLASH->ACR &= FLASH_ACR_LATENCY; //0 latency

	RCC->CFGR |= RCC_CFGR_HPRE_DIV2; //HCLK prescaler 2 HCLK is 16/2 = 8 MHZ
	RCC->CFGR |= RCC_CFGR_PPRE1_DIV1; //APB1 prescaler 1 APB1 is 8 MHZ
	RCC->CFGR |= RCC_CFGR_PPRE2_DIV1; //APB2 prescaler 1 APB2 is 8 MHZ

	RCC->CFGR |= RCC_CFGR_SW_0; //Set HSI16 as SYSCLK
	RCC->CFGR &= ~RCC_CFGR_SW_1; //Set HSI16 as SYSCLK

	RCC->IOPENR |= RCC_IOPENR_GPIOAEN; //Enable GPIOA clock
	RCC->IOPENR |= RCC_IOPENR_GPIOBEN; //Enable GPIOB clock

	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN; //Enable TIM2 clock

	RCC->APB1ENR |= RCC_APB1ENR_USART2EN; //Enable UART clock

	RCC->AHBENR |= RCC_AHBENR_DMA1EN; //Enable DMA clock

	RCC->APB2ENR |= RCC_APB2ENR_ADCEN; //Enable ADC clock

	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN; //Enable SYSCFG clock

}
