#include <WPILib.h>
#include <XboxController.h>
#include <Joystick.h>

#include "RobotMap.h"

/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

class OI {
public:
	OI();

private:
	XboxController controller {CONTROLLER_PORT};
};