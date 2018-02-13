#ifndef Drivetrain_H
#define Drivetrain_H

#include <Commands/Subsystem.h>
#include <Spark.h>
#include <Encoder.h>
#include <PIDController.h>
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
	void PIDDrive(XboxController* controller);
	void MotorInitialization();
	void ResetMotors();
	void AutoDriveTimed(double motorValue);
	void EnablePIDController();
	void PIDControllerInit();

private:
	Spark m_leftDriveMotor {LEFT_DRIVE_MOTOR_PORT};
	Spark m_rightDriveMotor {RIGHT_DRIVE_MOTOR_PORT};

	Timer *timer = new Timer();

	Encoder m_leftDriveEncoder {LEFT_DRIVE_ENCODER_PORT_A, LEFT_DRIVE_ENCODER_PORT_B};
	Encoder m_rightDriveEncoder {RIGHT_DRIVE_ENCODER_PORT_A, RIGHT_DRIVE_ENCODER_PORT_B};

	//DifferentialDrive drive {m_leftDriveMotor, m_rightDriveMotor};

	PIDController m_leftDrivePID {kP, kI, kD, &m_leftDriveEncoder, &m_leftDriveMotor};
	PIDController m_rightDrivePID {kP, kI, kD, &m_rightDriveEncoder, &m_rightDriveMotor};

	static constexpr double kP = -5.0;
	static constexpr double kI = -0.02;
	static constexpr double kD = -2.0;
};

#endif  // Drivetrain_H
