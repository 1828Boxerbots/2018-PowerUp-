#include "WristExtendCmd.h"

#include "Robot.h"
#include "OI.h"

WristExtend::WristExtend()
{
	Requires(Robot::wrist.get());
}

// Called just before this Command runs the first time
void WristExtend::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void WristExtend::Execute()
{
	Robot::wrist->Extend(Robot::oi->GetJoystick());
}

// Make this return true when this Command no longer needs to run execute()
bool WristExtend::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void WristExtend::End()
{
	Robot::wrist->Extend(Robot::oi->GetJoystick());
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WristExtend::Interrupted()
{

}
