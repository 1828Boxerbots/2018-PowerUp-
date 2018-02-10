#include "CompressorStopCmd.h"
#include "Robot.h"

CompressorStopCmd::CompressorStopCmd() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::compressor.get());
}

// Called just before this Command runs the first time
void CompressorStopCmd::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void CompressorStopCmd::Execute()
{
	Robot::compressor->CompressorStop();
}

// Make this return true when this Command no longer needs to run execute()
bool CompressorStopCmd::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void CompressorStopCmd::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CompressorStopCmd::Interrupted() {

}
