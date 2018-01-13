#include "DriveTrain.h"
#include "../RobotMap.h"
#include "Util.h"

using namespace frc;
using namespace util;

DriveTrain::DriveTrain() : Subsystem("ExampleSubsystem")
{
	m_joystick = 0;
}

void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void DriveTrain::TeleopDrive()
{

	/* inverts the left Motor and keeps the right motor non-inverted */
	m_leftDriveMotor.SetInverted(true);
	m_rightDriveMotor.SetInverted(false);

	/* Creates a variable that takes on the combined value of the X and Y axis of the right Joystick and limits that value to a certain
	 * number.
	 */
	m_joystick = m_controller.GetX(GenericHID::kRightHand) + m_controller.GetY(GenericHID::kRightHand);
	m_joystick = Limit(0.5, -0.5, m_joystick);


	m_leftDriveMotor.Set(-m_joystick);
	m_rightDriveMotor.Set(-m_joystick);

}

void DriveTrain::AutoDriveTimed()
{
	/* Reset on Startup */
	timer->Reset();

	/* Start the timer */
	timer->Start();

	/* Enter when timer is less than and equal to 15 seconds */
	if(timer->Get() <= 15)
	{
		/* Inverts the left motors */
		m_leftDriveMotor.SetInverted(true);

		/* Set the drive motors to run at 50% power for duration on the timer */
		m_leftDriveMotor.Set(0.5);
		m_rightDriveMotor.Set(0.5);
	}
	/* Enter once time is no longer less than or equal to 15 seconds */
	else
	{
		timer->Reset();
	}

}

void DriveTrain::AutoDrive()
{
	/* Inverts the left motors */
	m_leftDriveMotor.SetInverted(true);

	/* Set the drive motors to run at 75%*/
	m_leftDriveMotor.Set(0.75);
	m_rightDriveMotor.Set(0.75);

	/*Waits for a little bit to at lest allow the entire loop to execute */
	Wait(0.1);
}
