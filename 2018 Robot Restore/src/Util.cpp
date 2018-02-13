/*
 * Util.cpp
 *
 *  Created on: Feb 10, 2018
 *      Author: Science Center 3
 */

#include "Util.h"

double Limit(double upperLimit, double lowerLimit, double leftDeadZone, double rightDeadZone, double value)
{
	if(value >= upperLimit)
	{
		value = upperLimit;
	}
	if(value <= lowerLimit)
	{
		value = lowerLimit;
	}
	if((value < leftDeadZone) && (value > rightDeadZone))
	{
		value = 0.0;
	}
	return value;
}
