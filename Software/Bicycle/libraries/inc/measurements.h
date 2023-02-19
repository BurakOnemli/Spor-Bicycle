/*
 * measurements.h
 *
 *  Created on: Jan 2, 2023
 *      Author: burak
 */

#ifndef INC_MEASUREMENTS_H_
#define INC_MEASUREMENTS_H_

#include "stm32l0xx_hal.h"

#define PI 3.14
float calculateSpeedAndDistance(float radius, uint16_t tickBetweenCaptures);

#endif /* INC_MEASUREMENTS_H_ */
