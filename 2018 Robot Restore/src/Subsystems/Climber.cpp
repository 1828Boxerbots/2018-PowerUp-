#include "Climber.h"
#include "../RobotMap.h"

using namespace frc;

Climber::Climber() : Subsystem("ExampleSubsystem") {

}

void Climber::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Climber::Grab(XboxController* button)
{
	if(button->GetBumperPressed(GenericHID::kLeftHand))
	{
		m_climberPiston.Set(DoubleSolenoid::kForward);
	}
}

void Climber::Climb(XboxController* button)
{
	if(button->GetBumperReleased(GenericHID::kLeftHand))
	{
		m_climberPiston.Set(DoubleSolenoid::kReverse);
	}
}
