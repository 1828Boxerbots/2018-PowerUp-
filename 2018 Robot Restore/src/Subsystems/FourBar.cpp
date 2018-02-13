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
	bool upValue = controller->GetStartButtonPressed();
	bool downValue = controller->GetBackButtonPressed();

	if(upValue)
	{
		m_index = (m_index + 1) % (sizeof(kSetPoints) / 8);
	}

	if(downValue)
	{
		m_index = (m_index - 1) % (sizeof(kSetPoints) / 8);
	}

	m_leftGantryPID.SetSetpoint(kSetPoints[m_index]);
	m_rightGantryPID.SetSetpoint(kSetPoints[m_index]);


}

void FourBar::SetInversions()
{
	m_leftFourBarMotor.SetInverted(false);
	m_rightFourBarMotor.SetInverted(true);
}

void FourBar::EnablePIDController()
{
	m_leftGantryPID.Enable();
	m_rightGantryPID.Enable();
}

void FourBar::PIDControllerInit()
{
	m_leftGantryPID.SetInputRange(0, 5);
	m_rightGantryPID.SetInputRange(0,5);
}

constexpr std::array<double, 3> FourBar::kSetPoints;
