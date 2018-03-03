#include "ClawOpenCmd.h"
#include "Robot.h"

ClawOpenCmd::ClawOpenCmd()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::claw.get());
}

// Called just before this Command runs the first time
void ClawOpenCmd::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ClawOpenCmd::Execute()
{
	Robot::claw->OpenClaw(Robot::oi->GetJoystick());
}

// Make this return true when this Command no longer needs to run execute()
bool ClawOpenCmd::IsFinished()
{
	if(Robot::oi->GetJoystick()->GetAButton())
	{
		return false;
	}
	else
	{
		return true;
	}
}

// Called once after isFinished returns true
void ClawOpenCmd::End()
{
	Robot::claw->SolenoidIdleing();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClawOpenCmd::Interrupted()
{

}
