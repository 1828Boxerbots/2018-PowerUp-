/*
 * Util.h
 *
 *  Created on: Feb 10, 2018
 *      Author: Science Center 3
 */

#pragma once

namespace Util
{
	double Limit(double upperLimit, double lowerLimit, double leftDeadZone, double rightDeadZone, double value);
	bool NotEqual(double current, double target, double delta = 0.1);
}
