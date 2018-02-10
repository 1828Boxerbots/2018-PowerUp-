#include "AutoDrive.h"
#include "Robot.h"

AutoDrive::AutoDrive() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::drivetrain.get());
}

// Called just before this Command runs the first time
void AutoDrive::Initialize()
{
	Robot::drivetrain->ResetMotors();
	SetTimeout(15);
}

// Called repeatedly when this Command is scheduled to run
void AutoDrive::Execute()
{
	Robot::drivetrain->AutoDriveTimed(1);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoDrive::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void AutoDrive::End()
{
	Robot::drivetrain->ResetMotors();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDrive::Interrupted()
{
	Robot::drivetrain->ResetMotors();
}
