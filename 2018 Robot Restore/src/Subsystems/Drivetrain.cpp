#include "Drivetrain.h"
#include "../RobotMap.h"

#include <WPILib.h>

using namespace frc;

Drivetrain::Drivetrain() : Subsystem("ExampleSubsystem")
{

}

void Drivetrain::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Drivetrain::Drive(double left, double right)
{
	drive.ArcadeDrive(left, right, false);
	newDrive.ArcadeDrive(left, right, false);
}

void Drivetrain::TeleopDrive(XboxController* controller)
{
	double limit = 1.0;
	double deadzone = 0.1;

	double joyY = controller->GetY(GenericHID::kRightHand);
	double joyX = controller->GetX(GenericHID::kRightHand);

	joyY = Limit2(limit, -limit, -deadzone, deadzone, joyY);
	joyX = Limit2(limit, -limit, -deadzone, deadzone, joyX);

	Drive(joyX, -joyY);

	double leftEncoder = m_leftDriveEncoder.Get();
	double leftEncoderRaw = m_leftDriveEncoder.GetRaw();
	double leftEncoderDistance = m_leftDriveEncoder.GetDistance();
	double leftEncoderPeriod = m_leftDriveEncoder.GetPeriod();
	double leftEncoderRate = m_leftDriveEncoder.GetRate();
	bool leftEncoderDirection = m_leftDriveEncoder.GetDirection();
	bool leftEncoderIsStopped =  m_leftDriveEncoder.GetStopped();


	SmartDashboard::PutNumber("JoyY", joyY);
	SmartDashboard::PutNumber("JoyX", joyX);
	SmartDashboard::PutNumber("Encoder Count", leftEncoder);
	SmartDashboard::PutNumber("Encoder Raw", leftEncoderRaw);
	SmartDashboard::PutNumber("Encoder Distance", leftEncoderDistance);
	SmartDashboard::PutNumber("Encoder Period", leftEncoderPeriod);
	SmartDashboard::PutNumber("Encoder Rate", leftEncoderRate);
	SmartDashboard::PutBoolean("Encoder Direction", leftEncoderDirection);
	SmartDashboard::PutBoolean("Encoder IsStopped",leftEncoderIsStopped);

	double rightEncoder = m_rightDriveEncoder.Get();
	double rightEncoderRaw = m_rightDriveEncoder.GetRaw();
	double rightEncoderDistance = m_rightDriveEncoder.GetDistance();
	double rightEncoderPeriod = m_rightDriveEncoder.GetPeriod();
	double rightEncoderRate = m_rightDriveEncoder.GetRate();
	bool rightEncoderDirection = m_rightDriveEncoder.GetDirection();
	bool rightEncoderIsStopped =  m_rightDriveEncoder.GetStopped();

	SmartDashboard::PutNumber("Encoder Count(Right)", rightEncoder);
	SmartDashboard::PutNumber("Encoder Raw(Right)", rightEncoderRaw);
	SmartDashboard::PutNumber("Encoder Distance(Right)", rightEncoderDistance);
	SmartDashboard::PutNumber("Encoder Period(Right)", rightEncoderPeriod);
	SmartDashboard::PutNumber("Encoder Rate(Right)", rightEncoderRate);
	SmartDashboard::PutBoolean("Encoder Direction(Right)", rightEncoderDirection);
	SmartDashboard::PutBoolean("Encoder IsStopped(Right)",rightEncoderIsStopped);
}


void Drivetrain::MotorInitialization()
{
	//The wheel diameter * pi will find the circumference
	//Divide this by the ticks per full rotation
	float DistancePerPulse = (4 * 3.14)/360;

	m_leftDriveEncoder.SetDistancePerPulse(DistancePerPulse);
	m_leftDriveEncoder.SetReverseDirection(true);
	m_leftDriveEncoder.SetMinRate(10);
	m_leftDriveEncoder.SetMaxPeriod(0.1);
	m_leftDriveEncoder.SetSamplesToAverage(48);

	m_leftDriveMotor.SetInverted(true);
	m_leftDriveMotor2.SetInverted(true);

	m_leftDriveEncoder.Reset();
}

double Drivetrain::Limit2(double upperLimit, double lowerLimit, double leftDeadZone, double rightDeadZone, double value)
{
	if(value >= upperLimit)
	{
		value = upperLimit;
		return value;
	}
	if(value <= lowerLimit)
	{
		value = lowerLimit;
		return value;
	}
	if((value > leftDeadZone) && (value < rightDeadZone))
	{
		value = 0.0;
		return value;
	}
	return value;
}

void Drivetrain::ResetMotors()
{
	m_leftDriveMotor.Set(0);
	m_rightDriveMotor.Set(0);
}

void Drivetrain::AutoDriveTimed(double motorValue)
{
	timer->Start();

	if(timer->Get() <= 15)
	{
		m_leftDriveMotor.Set(motorValue);
		m_rightDriveMotor.Set(motorValue);
	}
}

void Drivetrain::PIDDrive(XboxController* controller)
{
	double joystick = controller->GetX(GenericHID::kRightHand) + controller->GetY(GenericHID::kRightHand);

	m_leftDrivePID->SetSetpoint(joystick);
	m_rightDrivePID->SetSetpoint(joystick);
}

void Drivetrain::PIDControllerInit(XboxController* controller)
{
	if(m_leftDrivePID == NULL)
	{
		m_leftDrivePID = new PIDController{kP, kI, kD, f, &m_leftDriveEncoder, &m_leftDriveMotor, 0.05};
	}

	if(m_rightDrivePID == NULL)
	{
		m_rightDrivePID = new PIDController{kP, kI, kD, f, &m_leftDriveEncoder, &m_leftDriveMotor2, 0.05};
	}


	m_leftDriveEncoder.Reset();
	m_rightDriveEncoder.Reset();

	m_leftDrivePID->Reset();
	m_rightDrivePID->Reset();

	m_leftDrivePID->SetPIDSourceType(PIDSourceType::kRate);
	m_rightDrivePID->SetPIDSourceType(PIDSourceType::kRate);

	m_leftDrivePID->SetAbsoluteTolerance(0.5);
	m_rightDrivePID->SetAbsoluteTolerance(0.5);

	m_leftDrivePID->SetContinuous(false);
	m_rightDrivePID->SetContinuous(false);
}

void Drivetrain::EnablePIDController()
{
	m_leftDrivePID->SetEnabled(true);
	m_rightDrivePID->SetEnabled(true);
}

void Drivetrain::DriveTest(XboxController* controller)
{
	double joystick = controller->GetX(GenericHID::kRightHand) + controller->GetY(GenericHID::kRightHand);

	//joystick = Limit(0.5, -0.5, -0.1, 0.1, joystick);

	m_leftDriveMotor.Set(-joystick);
	m_rightDriveMotor.Set(-joystick);
}

int16_t Drivetrain::RateLimit(int16_t rawInput, int16_t output, int16_t delta)
{
	int16_t increment = 0;
	if((rawInput < delta) && (rawInput > -delta))
	{
		increment = 0;
	}
	else
	{
		int32_t diff = (int32_t)rawInput - output;
		if(diff > delta)
		{
			diff = delta;
		}
		if(diff < -delta)
		{
			diff = -delta;
		}
		increment = output + (int16_t)diff;
	}
	if(output >= rawInput)
	{
		return rawInput;
	}
	if(output <= rawInput)
	{
		return rawInput;
	}
	return increment;
}
