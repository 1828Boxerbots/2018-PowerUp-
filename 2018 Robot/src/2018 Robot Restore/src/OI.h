/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <XboxController.h>
#include "RobotMap.h"

using namespace frc;

class OI {
public:
	OI();
	XboxController* GetJoystick();

private:
	XboxController controller {CONTROLLER_PORT};
};
