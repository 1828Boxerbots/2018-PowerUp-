#ifndef Wrist_H
#define Wrist_H

#include <WPILib.h>

#include <XboxController.h>
#include <DoubleSolenoid.h>

#include <Commands/Subsystem.h>

#include "../RobotMap.h"

class Wrist : public Subsystem
{
public:
	Wrist();
	void InitDefaultCommand();
	void Extend(XboxController* button);
	void Retract(XboxController* button);

private:
	DoubleSolenoid wristSolenoid {WRIST_FORWARD_SOLENOID_PORT, WRIST_REVERSE_SOLENOID_PORT};
};

#endif  // Wrist_H
