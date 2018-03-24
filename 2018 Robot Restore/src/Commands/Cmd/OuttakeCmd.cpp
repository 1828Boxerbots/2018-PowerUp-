#include "OuttakeCmd.h"
#include "Robot.h"

OuttakeCmd::OuttakeCmd() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::intake.get());
}

// Called just before this Command runs the first time
void OuttakeCmd::Initialize()
{
	Robot::intake->MotorInit();
}

// Called repeatedly when this Command is scheduled to run
void OuttakeCmd::Execute()
{
	Robot::intake->OutPut(Robot::oi->GetJoystick());
}

// Make this return true when this Command no longer needs to run execute()
bool OuttakeCmd::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void OuttakeCmd::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void OuttakeCmd::Interrupted() {

}
