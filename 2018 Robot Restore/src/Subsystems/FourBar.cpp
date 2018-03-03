#include "FourBar.h"
#include "util.h"
#include "../RobotMap.h"

#include <WPILib.h>

using namespace frc;
using namespace Util;

FourBar::FourBar() : Subsystem("ExampleSubsystem")
{

}

void FourBar::InitDefaultCommand()
{
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
	m_leftGantryPID.SetInputRange(0.0, 5.0);
	m_rightGantryPID.SetInputRange(0.0,5.0);
}
/*
void FourBar::SetAngle(int setpoint)
{
	if(setpoint >= 0)
	{
		if(setpoint >= SETPOINTSNUMBER)
		{
			setpoint = SETPOINTSNUMBER - 1;
		}
	}
	else
	{
		setpoint = 0;
	}
	m_index = setpoint;
	m_leftGantryPID.SetSetpoint(kSetPoints[m_index]);
	m_rightGantryPID.SetSetpoint(kSetPoints[m_index]);

	// Waiting until the potentionmeter reads the set point.
	while(NotEqual(m_pot.GetVoltage(), ))
}
*/

constexpr std::array<double, FourBar::SETPOINTSNUMBER> FourBar::kSetPoints;
