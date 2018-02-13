#include "GrabBoxCmd.h"
#include "Robot.h"

GrabBoxCmd::GrabBoxCmd() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::claw.get());
}

// Called just before this Command runs the first time
void GrabBoxCmd::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void GrabBoxCmd::Execute()
{
	Robot::claw->AutomaticCloseClaw();
}

// Make this return true when this Command no longer needs to run execute()
bool GrabBoxCmd::IsFinished()
{
	if(Robot::oi->GetJoystick()->GetBButtonPressed())
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Called once after isFinished returns true
void GrabBoxCmd::End()
{
	Robot::claw->OpenClaw(Robot::oi->GetJoystick());
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GrabBoxCmd::Interrupted() {

}
