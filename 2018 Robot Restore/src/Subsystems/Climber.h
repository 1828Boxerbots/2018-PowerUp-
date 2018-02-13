#ifndef Climber_H
#define Climber_H

#include <WPILib.h>

#include <Commands/Subsystem.h>

#include <XboxController.h>
#include <DoubleSolenoid.h>

#include "RobotMap.h"

using namespace frc;

class Climber : public Subsystem
{
public:
	Climber();
	void InitDefaultCommand();
	void Grab(XboxController* button);
	void Climb(XboxController* button);

private:
	DoubleSolenoid m_climberPiston{CLIMB_FORWARD_SOLENOID_PORT, CLIMB_REVERSE_SOLENOID_PORT};
};

#endif  // Climber_H
