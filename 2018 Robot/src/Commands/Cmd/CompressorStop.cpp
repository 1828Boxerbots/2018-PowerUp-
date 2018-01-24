#include "CompressorStop.h"

#include "Robot.h"

#include "Subsystems/OnBoardCompressor.h"

CompressorStop::CompressorStop() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::onboardcompressor.get());
}

// Called just before this Command runs the first time
void CompressorStop::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void CompressorStop::Execute()
{
	Robot::onboardcompressor->CompressorStop();
}

// Make this return true when this Command no longer needs to run execute()
bool CompressorStop::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void CompressorStop::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CompressorStop::Interrupted() {

}
