/*
 * gpio.h
 *
 *  Created on: Jan 2, 2023
 *      Author: burak
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include "stm32l0xx_hal.h"

typedef enum
{

	LOW,
	MEDIUM,
	HIGH,
	VERY_HIGH

}OUTPUT_Speed;

typedef enum
{

	NO_PULL_UP_PULL_DOWN,
	PULL_UP,
	PULL_DOWN

}PUPD; // Pull up pull down
typedef enum
{

	GPIO_LOW = 0,
	GPIO_HIGH = 1

}GPIO_STATE;

void GPIO_Start_Output ( GPIO_TypeDef* GPIOx, uint32_t GPIO_PINx, OUTPUT_Speed OUTPUT_Speedx  );
void GPIO_Start_Input ( GPIO_TypeDef* GPIOx, uint32_t GPIO_PINx, PUPD PUPDx );
void GPIO_Write ( GPIO_TypeDef* GPIOx, uint32_t GPIO_PIN, GPIO_STATE GPIO_STATEx );
uint8_t GPIO_Read ( GPIO_TypeDef* GPIOx, uint32_t GPIO_PIN );

#endif /* INC_GPIO_H_ */
