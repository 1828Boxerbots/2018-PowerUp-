#ifndef Gantry_H
#define Gantry_H

#include <WPILib.h>

#include <Commands/Subsystem.h>

#include <XboxController.h>
#include <Spark.h>

#include <DigitalInput.h>
#include <Encoder.h>

#include "RobotMap.h"

class Gantry : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Spark m_gantryMotor {GANTRY_MOTOR_PORT};

	DigitalInput upperLimitSwitch {UPPER_LIMIT_PORT};
	DigitalInput lowerLimitSwitch {LOWER_LIMIT_PORT};

	DigitalInput m_lowerHallSensor {LOWER_HALL_EFFECT_SENSOR_PORT};
	DigitalInput m_upperHallSensor {UPPER_HALL_EFFECT_SENSOR_PORT};

	DigitalInput m_upperPhotoSensor {UPPER_GANTRY_PHOTO_SENSOR_PORT};
	DigitalInput m_lowerPhotoSensor {LOWER_GANTRY_PHOTO_SENSOR_PORT};

	const double TIME = 0.001;

	//Encoder *m_gantryEncoder = new Encoder(GANTRY_ENCODER_PORT_A, GANTRY_ENCODER_PORT_B, false, Encoder ::EncodingType::k4X);

public:
	Gantry();
	void InitDefaultCommand();
	bool UpMovement(XboxController* trigger);
	bool DownMovement(XboxController* trigger);
	void StopMotors();
	bool UpperLimitSwitchTripped();
	bool LowerLimitSwitchTripped();
	bool UpperHallTripped();
	bool LowerHallTripped();
	bool UpperPhotoSensorTripped();
	bool LowerPhotoSensorTripped();
	double ReturnEncoder();
	bool ReturnLowerLimits();
	bool ReturnUpperLimits();
};

#endif  // Gantry_H
