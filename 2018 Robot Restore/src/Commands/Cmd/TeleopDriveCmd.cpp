#include "TeleopDriveCmd.h"

#include "Robot.h"
#include "OI.h"

TeleopDriveCmd::TeleopDriveCmd()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::drivetrain.get());
}

// Called just before this Command runs the first time
void TeleopDriveCmd::Initialize()
{
	Robot::drivetrain->MotorInitialization();
	Robot::drivetrain->PIDControllerInit();
	Robot::drivetrain->EnablePIDController();
}

// Called repeatedly when this Command is scheduled to run
void TeleopDriveCmd::Execute()
{
	Robot::drivetrain->PIDDrive(Robot::oi->GetJoystick());
}

// Make this return true when this Command no longer needs to run execute()
bool TeleopDriveCmd::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void TeleopDriveCmd::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TeleopDriveCmd::Interrupted()
{

}
