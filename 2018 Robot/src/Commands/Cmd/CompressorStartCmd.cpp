#include "CompressorStartCmd.h"

#include "Subsystems/OnBoardCompressor.h"

#include "Robot.h"

CompressorStartCmd::CompressorStartCmd() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::onboardcompressor.get());
}

// Called just before this Command runs the first time
void CompressorStartCmd::Initialize()
{
	Robot::onboardcompressor->ClearPCMErrors();
}

// Called repeatedly when this Command is scheduled to run
void CompressorStartCmd::Execute()
{
	Robot::onboardcompressor->CompressorStart();
}

// Make this return true when this Command no longer needs to run execute()
bool CompressorStartCmd::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void CompressorStartCmd::End()
{
	Robot::onboardcompressor->CompressorStop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CompressorStartCmd::Interrupted()
{
	Robot::onboardcompressor->CompressorEStop();
}
