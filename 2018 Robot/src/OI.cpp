/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

#include <WPILib.h>

#include "Commands/WristExtendCmd.h"
#include "Commands/WristRetractCmd.h"

using namespace frc;

OI::OI()
{
	// Process operator interface input here.
	m_leftBumperButton.WhenPressed(new WristExtend());
	m_leftBumperButton.WhenReleased(new WristRetractCmd());

}

XboxController* OI::GetJoystick()
{
	return &controller;
}

