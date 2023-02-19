/*
 * gpio.c
 *
 *  Created on: Jan 2, 2023
 *      Author: burak
 */
#include "gpio.h"

void GPIO_Start_Output ( GPIO_TypeDef* GPIOx, uint32_t GPIO_PINx, OUTPUT_Speed OUTPUT_Speedx  )
{
	uint32_t tmp = ( GPIO_PINx * GPIO_PINx );
	uint32_t position = 0;
	while( ( tmp >> position ) != 1)
	{
		position++;
	}
	GPIOx->MODER   |= ( 1 <<  position); // OUTPUT
	GPIOx->MODER   &= ~( 2 << position ); // OUTPUT
	GPIOx->OTYPER  &= ~( 1 << GPIO_PINx ); //OUTPUT PUSH_PULL
	GPIOx->OSPEEDR |= ( OUTPUT_Speedx << ( position ) ); //OUTUT SPEED
}

void GPIO_Start_Input ( GPIO_TypeDef* GPIOx, uint32_t GPIO_PINx, PUPD PUPDx )
{
	GPIOx->MODER &= ~( 3 << (GPIO_PINx * GPIO_PINx)); // INPUT
	GPIOx->PUPDR |= ( PUPDx << ( GPIO_PINx * GPIO_PINx ) ); //PULL_UP PULL_DOWN Selection
}

void GPIO_Write ( GPIO_TypeDef* GPIOx, uint32_t GPIO_PIN, GPIO_STATE GPIO_STATEx )
{
	if( GPIO_STATEx == 1 )
	{
		GPIOx->BSRR |= GPIO_PIN; // Set pin HIGH
	}
	else
	{
		GPIOx->BRR = GPIO_PIN;// Set pin LOW
	}

}

uint8_t GPIO_Read ( GPIO_TypeDef* GPIOx, uint32_t GPIO_PIN )
{
	if ( ( GPIOx->IDR & GPIO_PIN ) == 1 )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
