#include "WristExtendCmd.h"
#include "Robot.h"

WristExtendCmd::WristExtendCmd() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::wrist.get());
}

// Called just before this Command runs the first time
void WristExtendCmd::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void WristExtendCmd::Execute()
{
	Robot::wrist->Extend(Robot::oi->GetJoystick());
}

// Make this return true when this Command no longer needs to run execute()
bool WristExtendCmd::IsFinished() {
	if(Robot::oi->GetJoystick()->GetXButtonPressed())
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Called once after isFinished returns true
void WristExtendCmd::End()
{
	Robot::wrist->Extend(Robot::oi->GetJoystick());
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WristExtendCmd::Interrupted() {

}
