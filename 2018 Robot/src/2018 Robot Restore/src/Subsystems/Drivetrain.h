#ifndef Drivetrain_H
#define Drivetrain_H

#include <Commands/Subsystem.h>
#include <Spark.h>
#include <Drive/DifferentialDrive.h>
#include <XboxController.h>
#include <Timer.h>

#include "RobotMap.h"

using namespace frc;

class Drivetrain : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	Drivetrain();
	void InitDefaultCommand();
	void Drive(double left, double right);
	void TeleopDrive(XboxController* controller);
	void MotorInitialization();
	void ResetMotors();
	void AutoDriveTimed(double motorValue);

private:
	Spark m_leftDriveMotor {LEFT_DRIVE_MOTOR_PORT};
	Spark m_rightDriveMotor {RIGHT_DRIVE_MOTOR_PORT};

	Timer *timer = new Timer();

	DifferentialDrive drive {m_leftDriveMotor, m_rightDriveMotor};
};

#endif  // Drivetrain_H
