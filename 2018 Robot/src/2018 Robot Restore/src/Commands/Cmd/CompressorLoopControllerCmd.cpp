#include "CompressorLoopControllerCmd.h"
#include "Robot.h"

CompressorLoopControllerCmd::CompressorLoopControllerCmd() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void CompressorLoopControllerCmd::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void CompressorLoopControllerCmd::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool CompressorLoopControllerCmd::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void CompressorLoopControllerCmd::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CompressorLoopControllerCmd::Interrupted() {

}
