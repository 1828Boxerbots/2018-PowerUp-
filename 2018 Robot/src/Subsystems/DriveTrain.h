#include <Spark.h>
#include <XboxController.h>
#include <Timer.h>
#include <Encoder.h>
#include <PIDController.h>
#include <PIDSource.h>

#include "RobotMap.h"

#ifndef DriveTrain_H
#define DriveTrain_H

#include <Commands/Subsystem.h>

class DriveTrain : public Subsystem
{
private:
	Spark m_leftDriveMotor {LEFT_DRIVE_MOTOR_PORT};
	Spark m_rightDriveMotor {RIGHT_DRIVE_MOTOR_PORT};

	Encoder *m_leftDriveEncoder = new Encoder(LEFT_DRIVE_ENCODER_PORT, LEFT_DRIVE_ENCODER_PORT, false, Encoder::EncodingType::k4X);
	Encoder *m_rightDriveEncoder = new Encoder(RIGHT_DRIVE_ENCODER_PORT, RIGHT_DRIVE_ENCODER_PORT, false, Encoder::EncodingType::k4X);

	XboxController m_controller {CONTROLLER_PORT};

	double m_joystick;

	Timer *timer = new Timer();

public:
	DriveTrain();
	void InitDefaultCommand();
	void TeleopDrive();
	void AutoDriveTimed();
	void AutoDrive();
};

#endif  // DriveTrain_H
