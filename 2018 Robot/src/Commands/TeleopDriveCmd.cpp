#include "TeleopDriveCmd.h"

TeleopDriveCmd::TeleopDriveCmd() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::drivetrain);
}

// Called just before this Command runs the first time
void TeleopDriveCmd::Initialize()
{
	Robot::drivetrain->ResetMotors();
}

// Called repeatedly when this Command is scheduled to run
void TeleopDriveCmd::Execute()
{
	Robot::drivetrain->TeleopDrive(Joystick);
}

// Make this return true when this Command no longer needs to run execute()
bool TeleopDriveCmd::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TeleopDriveCmd::End()
{
	Robot::drivetrain->StopMotors();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TeleopDriveCmd::Interrupted()
{
	Robot::drivetrain->StopMotors();
}
