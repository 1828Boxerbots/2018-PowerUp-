#ifndef Gantry_H
#define Gantry_H

#include <Commands/Subsystem.h>

#include <XboxController.h>
#include <Spark.h>

#include "RobotMap.h"

using namespace frc;

class Gantry : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Spark m_gantryMotor {GANTRY_MOTOR_PORT};

public:
	Gantry();
	void InitDefaultCommand();
	void UpMovement(XboxController* trigger);
	void DownMovement(XboxController* trigger);

};

#endif  // Gantry_H
