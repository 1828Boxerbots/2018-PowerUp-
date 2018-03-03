#include "GantryTestCmd.h"
#include "Robot.h"

GantryTestCmd::GantryTestCmd()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::gantry.get());
}

// Called just before this Command runs the first time
void GantryTestCmd::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void GantryTestCmd::Execute()
{
	Robot::gantry->GantryTest(Robot::oi->GetJoystick());
}

// Make this return true when this Command no longer needs to run execute()
bool GantryTestCmd::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void GantryTestCmd::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GantryTestCmd::Interrupted() {

}
