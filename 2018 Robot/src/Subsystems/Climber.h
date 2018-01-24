#ifndef Climber_H
#define Climber_H

#include <WPILib.h>

#include <XboxController.h>
#include <DoubleSolenoid.h>

#include "RobotMap.h"

#include <Commands/Subsystem.h>

using namespace frc;

class Climber : public Subsystem
{
private:

	DoubleSolenoid m_climberPiston{CLIMB_FORWARD_SOLENOID_PORT, CLIMB_REVERSE_SOLENOID_PORT};

public:
	Climber();
	void InitDefaultCommand();
	void Grab(XboxController* button);
	void Climb(XboxController* button);
};

#endif  // Climber_H
