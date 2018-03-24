#ifndef Intake_H
#define Intake_H

#include <WPILib.h>

#include <Commands/Subsystem.h>
#include <XboxController.h>
#include <Spark.h>

#include "RobotMap.h"

using namespace frc;

class Intake : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	Intake();
	void InitDefaultCommand();

	void MotorInit();
	void PickUp(XboxController* controller);
	void OutPut(XboxController* controller);

private:
	Spark mLeftMandibleMotor {LEFT_MANDIBLE_PORT};
	Spark mRightMandibleMotor {RIGHT_MANDIBLE_PORT};
};

#endif  // Intake_H
