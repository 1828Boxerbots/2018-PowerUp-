#include "SetCompressorLoopControllerCmd.h"

#include "Robot.h"

SetCompressorLoopControllerCmd::SetCompressorLoopControllerCmd() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::onboardcompressor.get());
}

// Called just before this Command runs the first time
void SetCompressorLoopControllerCmd::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void SetCompressorLoopControllerCmd::Execute()
{
	Robot::onboardcompressor->CompressorLoopController(true);
}

// Make this return true when this Command no longer needs to run execute()
bool SetCompressorLoopControllerCmd::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void SetCompressorLoopControllerCmd::End()
{
	Robot::onboardcompressor->CompressorInterrupted()();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetCompressorLoopControllerCmd::Interrupted()
{
	Robot::onboardcompressor->CompressorEStop();
}
