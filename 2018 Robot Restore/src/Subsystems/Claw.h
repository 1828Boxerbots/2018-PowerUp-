#ifndef Claw_H
#define Claw_H

#include <WPILib.h>

#include <Commands/Subsystem.h>

#include <DoubleSolenoid.h>
#include <XboxController.h>
#include <DigitalOutput.h>

#include "RobotMap.h"

using namespace frc;

class Claw : public Subsystem
{
private:
	DoubleSolenoid m_leftPincerPiston{LEFT_CLAW_FORWARD_SOLENOID_PORT, LEFT_CLAW_REVERSE_SOLENOID_PORT};
	DoubleSolenoid m_rightPincerPiston{RIGHT_CLAW_FORWARD_SOLENOID_PORT, RIGHT_CLAW_REVERSE_SOLENOID_PORT};

public:
	Claw();
	void InitDefaultCommand();
	void ManualCloseClaw(XboxController* button);
	void OpenClaw(XboxController* button);
	void SolenoidIdleing();
};

#endif  // Claw_H
