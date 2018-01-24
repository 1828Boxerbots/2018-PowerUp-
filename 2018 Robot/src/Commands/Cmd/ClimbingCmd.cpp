#include "ClimbingCmd.h"
#include "Robot.h"

ClimbingCmd::ClimbingCmd() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::climber.get());
}

// Called just before this Command runs the first time
void ClimbingCmd::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ClimbingCmd::Execute()
{
	Robot::climber->Grab(Robot::oi->GetJoystick());
}

// Make this return true when this Command no longer needs to run execute()
bool ClimbingCmd::IsFinished()
{
	if(Robot::oi->GetJoystick()->GetBumperReleased(GenericHID::kRightHand))
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Called once after isFinished returns true
void ClimbingCmd::End()
{
	Robot::climber->Climb(Robot::oi->GetJoystick());;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClimbingCmd::Interrupted() {

}
