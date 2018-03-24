#include "IntakeCmd.h"
#include "Robot.h"

IntakeCmd::IntakeCmd() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::intake.get());
}

// Called just before this Command runs the first time
void IntakeCmd::Initialize()
{
	Robot::intake->MotorInit();
}

// Called repeatedly when this Command is scheduled to run
void IntakeCmd::Execute()
{
	Robot::intake->PickUp(Robot::oi->GetJoystick());
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeCmd::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void IntakeCmd::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeCmd::Interrupted() {

}
