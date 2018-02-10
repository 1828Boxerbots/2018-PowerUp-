#include "Gantry.h"
#include "../RobotMap.h"

#include <WPILib.h>

using namespace frc;

Gantry::Gantry() : Subsystem("ExampleSubsystem")
{

}

void Gantry::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

bool Gantry::UpMovement(XboxController* trigger)
{
	double triggerAxis = trigger->GetTriggerAxis(GenericHID::kRightHand);

	m_gantryMotor.Set(triggerAxis);

	return triggerAxis >= 0.1;
}

bool Gantry::DownMovement(XboxController* trigger)
{
	double triggerAxis = trigger->GetTriggerAxis(GenericHID::kLeftHand);

	m_gantryMotor.Set(-triggerAxis);

	return triggerAxis >= 0.1;
}

void Gantry::StopMotors()
{
	m_gantryMotor.Set(0);
}

bool Gantry::UpperLimitSwitchTripped()
{
	bool flag = upperLimitSwitch.Get();
	Wait(TIME);
	return flag;
}

bool Gantry::LowerLimitSwitchTripped()
{
	bool flag = lowerLimitSwitch.Get();
	Wait(TIME);
	return flag;
}

bool Gantry::UpperHallTripped()
{
	bool flag = m_upperHallSensor.Get();
	Wait(TIME);
	return flag;
}

bool Gantry::LowerHallTripped()
{
	bool flag = m_lowerHallSensor.Get();
	Wait(TIME);
	return flag;
}

bool Gantry::UpperPhotoSensorTripped()
{
	bool flag = m_upperPhotoSensor.Get();
	Wait(TIME);
	return flag;
}

bool Gantry::LowerPhotoSensorTripped()
{
	bool flag = m_lowerPhotoSensor.Get();
	Wait(TIME);
	return flag;

}

double Gantry::ReturnEncoder()
{
	//return m_gantryEncoder->Get();
	return 0;
}

bool Gantry::ReturnLowerLimits()
{
	bool variable = LowerLimitSwitchTripped() && LowerPhotoSensorTripped();
	return variable;
}

bool Gantry::ReturnUpperLimits()
{
	bool variable = UpperLimitSwitchTripped() && UpperPhotoSensorTripped();
	return variable;
}
