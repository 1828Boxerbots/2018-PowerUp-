#include "WristRetractCmd.h"

#include "Robot.h"

WristRetractCmd::WristRetractCmd() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::wrist.get());
}

// Called just before this Command runs the first time
void WristRetractCmd::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void WristRetractCmd::Execute()
{
	Robot::wrist->Retract(Robot::oi->GetJoystick());
}

// Make this return true when this Command no longer needs to run execute()
bool WristRetractCmd::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void WristRetractCmd::End()
{
	Robot::wrist->Retract(Robot::oi->GetJoystick());
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WristRetractCmd::Interrupted() {

}
