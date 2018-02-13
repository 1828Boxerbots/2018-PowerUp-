#include "FourBarCmd.h"
#include "Robot.h"

FourBarCmd::FourBarCmd() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::fourbar.get());
}

// Called just before this Command runs the first time
void FourBarCmd::Initialize()
{
	Robot::fourbar->SetInversions();
	Robot::fourbar->PIDControllerInit();
	Robot::fourbar->EnablePIDController();
}

// Called repeatedly when this Command is scheduled to run
void FourBarCmd::Execute()
{
	Robot::fourbar->Movement(Robot::oi->GetJoystick());
}

// Make this return true when this Command no longer needs to run execute()
bool FourBarCmd::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void FourBarCmd::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FourBarCmd::Interrupted() {

}
