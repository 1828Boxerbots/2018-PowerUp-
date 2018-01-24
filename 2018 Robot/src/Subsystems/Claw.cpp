#include "Claw.h"
#include "../RobotMap.h"

Claw::Claw() : Subsystem("ExampleSubsystem") {

}

void Claw::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Claw::ManualCloseClaw(XboxController* button)
{
	if(button->GetAButtonPressed())
	{
		m_leftPincerPiston.Set(DoubleSolenoid::kForward);
		m_rightPincerPiston.Set(DoubleSolenoid::kForward);
	}
}

void Claw::AutomaticCloseClaw()
{
	if(m_clawDIO.Get() == true)
	{
		m_leftPincerPiston.Set(DoubleSolenoid::kForward);
		m_rightPincerPiston.Set(DoubleSolenoid::kForward);
	}
}

void Claw::OpenClaw(XboxController* button)
{
	if(button->GetBButtonPressed())
	{
		m_leftPincerPiston.Set(DoubleSolenoid::kReverse);
		m_rightPincerPiston.Set(DoubleSolenoid::kReverse);
	}
}
