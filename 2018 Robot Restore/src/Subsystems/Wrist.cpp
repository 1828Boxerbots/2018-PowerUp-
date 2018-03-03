#include "Wrist.h"
#include "../RobotMap.h"

Wrist::Wrist() : Subsystem("ExampleSubsystem")
{

}

void Wrist::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Wrist::Extend(XboxController* button)
{
	if(button->GetBumperPressed(GenericHID::kLeftHand))
	{
		wristSolenoid.Set(DoubleSolenoid::kForward);
	}
}

void Wrist::Retract(XboxController* button)
{
	if(button->GetBumperReleased(GenericHID::kLeftHand))
	{
		wristSolenoid.Set(DoubleSolenoid::kReverse);
	}
}
