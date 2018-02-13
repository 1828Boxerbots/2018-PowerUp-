#ifndef Wrist_H
#define Wrist_H

#include <Commands/Subsystem.h>

#include <WPILib.h>

#include <XboxController.h>
#include <DoubleSolenoid.h>

#include <RobotMap.h>

using namespace frc;

class Wrist : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	DoubleSolenoid wristSolenoid {WRIST_FORWARD_SOLENOID_PORT,WRIST_REVERSE_SOLENOID_PORT};

public:
	Wrist();
	void InitDefaultCommand();
	void Extend(XboxController* button);
	void Retract(XboxController* button);
};

#endif  // Wrist_H
