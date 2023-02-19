/*
 * measurements.c
 *
 *  Created on: Jan 2, 2023
 *      Author: burak
 */
#include "measurements.h"

float calculateSpeedAndDistance(float radius, uint16_t tickBetweenCaptures)
{
	float speedAndDistance = ( 2 * PI * radius ) * tickBetweenCaptures;
	return speedAndDistance;
}
