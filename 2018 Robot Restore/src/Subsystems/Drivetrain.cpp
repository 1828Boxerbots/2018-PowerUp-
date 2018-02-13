#include "Drivetrain.h"
#include "../RobotMap.h"

#include <WPILib.h>

using namespace frc;

Drivetrain::Drivetrain() : Subsystem("ExampleSubsystem") {

}

void Drivetrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Drivetrain::Drive(double left, double right)
{
	//drive.ArcadeDrive(left, right);
}

void Drivetrain::TeleopDrive(XboxController* controller)
{
	//double joyY = controller->GetY(GenericHID::kRightHand);
	//double joyX = controller->GetX(GenericHID::kRightHand);

	//Drive(-joyY, -joyX);
}


void Drivetrain::MotorInitialization()
{
	m_leftDriveMotor.SetInverted(true);
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

	m_leftDrivePID.SetSetpoint(-joystick);
	m_rightDrivePID.SetSetpoint(-joystick);
}

void Drivetrain::PIDControllerInit()
{
	m_leftDrivePID.SetInputRange(-1, 1);
	m_rightDrivePID.SetInputRange(-1,1);
}

void Drivetrain::EnablePIDController()
{
	m_leftDrivePID.Enable();
	m_rightDrivePID.Enable();
}
