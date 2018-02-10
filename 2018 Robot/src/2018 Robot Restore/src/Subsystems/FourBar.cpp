#include "FourBar.h"
#include "../RobotMap.h"

FourBar::FourBar() : Subsystem("ExampleSubsystem") {

}

void FourBar::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void FourBar::Movement(XboxController* controller)
{
	double joystick = controller->GetX(GenericHID::kRightHand) + controller->GetY(GenericHID::kRightHand);

	if(m_pot.Get() <= 350)
	{
		while(-joystick < 0)
		{
			m_leftFourBarMotor.Set(0);
			m_rightFourBarMotor.Set(0);
		}
	}
	if(m_pot.Get() >= 20)
	{
		while(-joystick > 0)
		{
			m_leftFourBarMotor.Set(0);
			m_rightFourBarMotor.Set(0);
		}
	}
	if((m_pot.Get() >= 350) || (m_pot.Get() <= 20))
	{
		m_leftFourBarMotor.Set(-joystick);
		m_rightFourBarMotor.Set(-joystick);
	}
}

void FourBar::SetInversions()
{
	m_leftFourBarMotor.SetInverted(false);
	m_rightFourBarMotor.SetInverted(true);
}
