#ifndef FourBar_H
#define FourBar_H

#include <WPILIb.h>

#include <Commands/Subsystem.h>

#include <AnalogPotentiometer.h>
#include <Spark.h>
#include <XboxController.h>

#include "RobotMap.h"

using namespace frc;

class FourBar : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Spark m_leftFourBarMotor {LEFT_FOUR_BAR_MOTOR_PORT};
	Spark m_rightFourBarMotor {RIGHT_FOUR_BAR_MOTOR_PORT};

	AnalogPotentiometer m_pot {FOUR_BAR_POTENTIOMETER_PORT};

public:
	FourBar();
	void InitDefaultCommand();
	void Movement(XboxController* controller);
	void SetInversions();
};

#endif  // FourBar_H
