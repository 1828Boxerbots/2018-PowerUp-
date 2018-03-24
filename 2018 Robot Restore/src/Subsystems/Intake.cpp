#include "Intake.h"
#include "../RobotMap.h"

Intake::Intake() : Subsystem("ExampleSubsystem") {

}

void Intake::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Intake::MotorInit()
{
	mLeftMandibleMotor.SetInverted(true);

}

void Intake::PickUp(XboxController* controller)
{
	double trigger = controller->GetTriggerAxis(GenericHID::kLeftHand);

	mLeftMandibleMotor.Set(-trigger);
	mRightMandibleMotor.Set(-trigger);
}

void Intake::OutPut(XboxController* controller)
{
	double trigger = controller->GetTriggerAxis(GenericHID::kRightHand);

	mLeftMandibleMotor.Set(trigger);
	mRightMandibleMotor.Set(trigger);
}
