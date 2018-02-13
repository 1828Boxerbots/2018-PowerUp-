#include "Vision.h"
#include "../RobotMap.h"

Vision::Vision() : Subsystem("ExampleSubsystem") {

}

void Vision::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	CameraServer::GetInstance()->StartAutomaticCapture();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
