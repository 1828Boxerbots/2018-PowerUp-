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

class Drivetrain : public Subsystem
{

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

	int16_t RateLimit(int16_t rawInput, int16_t output, int16_t delta);

	void EnablePIDController();
	void PIDControllerInit(XboxController* controller);

	double Limit2(double upperLimit, double lowerLimit, double leftDeadZone, double rightDeadZone, double value);

	void DriveTest(XboxController* controller);

private:
	Spark m_leftDriveMotor {LEFT_DRIVE_MOTOR_PORT};
	Spark m_leftDriveMotor2 {LEFT_DRIVE_TEST_PORT};
	Spark m_rightDriveMotor {RIGHT_DRIVE_MOTOR_PORT};
	Spark m_rightDriveMotor2 {RIGHT_DRIVE_TEST_PORT};

	Timer *timer = new Timer();

	Encoder m_leftDriveEncoder {LEFT_DRIVE_ENCODER_PORT_A, LEFT_DRIVE_ENCODER_PORT_B, CounterBase::k4X};
	Encoder m_rightDriveEncoder {RIGHT_DRIVE_ENCODER_PORT_A, RIGHT_DRIVE_ENCODER_PORT_B, CounterBase::k4X};

	DifferentialDrive drive {m_leftDriveMotor, m_rightDriveMotor};
	DifferentialDrive newDrive {m_leftDriveMotor2, m_rightDriveMotor2};

	PIDController* m_leftDrivePID = NULL;
	PIDController* m_rightDrivePID = NULL;

	static constexpr double kP = 0.1;
	static constexpr double kI = 0.0;
	static constexpr double kD = 0.0;
	static constexpr double f = 1.0;
};

#endif  // Drivetrain_H
