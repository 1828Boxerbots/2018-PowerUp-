#include "Gantry.h"
#include "../RobotMap.h"

#include <WPILib.h>

using namespace frc;

Gantry::Gantry() : Subsystem("ExampleSubsystem")
{

}

double Gantry::Limit2(double upperLimit, double lowerLimit, double leftDeadZone, double rightDeadZone, double value)
{
	if(value >= upperLimit)
	{
		value = upperLimit;
		return value;
	}
	if(value <= lowerLimit)
	{
		value = lowerLimit;
		return value;
	}
	if((value > leftDeadZone) && (value < rightDeadZone))
	{
		value = 0.0;
		return value;
	}
	return value;
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

	SmartDashboard::PutNumber("RightTrigger", triggerAxis);

	//triggerAxis = Limit2(1.0, 0.1, 0, 0.1, triggerAxis);

	bool isTriggered = triggerAxis >= 0.01;
	if (isTriggered)
	{
		m_gantryMotor.Set(-triggerAxis);
	}
	return isTriggered;
}

bool Gantry::DownMovement(XboxController* trigger)
{
	double triggerAxis = trigger->GetTriggerAxis(GenericHID::kLeftHand);

	SmartDashboard::PutNumber("LeftTrigger", triggerAxis);

	//triggerAxis = Limit2(1.0, 0.1, 0, 0.1, triggerAxis);

	bool isTriggered = triggerAxis >= 0.01;
	if (isTriggered)
	{
		m_gantryMotor.Set(-triggerAxis);
	}
	return isTriggered;
}

void Gantry::StopMotors()
{
	m_gantryMotor.Set(0);
}

bool Gantry::UpperLimitSwitchTripped()
{
	bool flag = upperLimitSwitch.Get();
	//Wait(TIME);
	return !flag;
}

bool Gantry::LowerLimitSwitchTripped()
{

	bool flag = lowerLimitSwitch.Get();
	//Wait(TIME);
	return !flag;
}

bool Gantry::UpperPhotoSensorTripped()
{
	bool flag = m_upperPhotoSensor.Get();
	//Wait(TIME);
	return flag;
}

bool Gantry::LowerPhotoSensorTripped()
{
	bool flag = m_lowerPhotoSensor.Get();
	//Wait(TIME);
	return flag;

}

double Gantry::ReturnEncoder()
{
	return m_gantryEncoder->Get();
	//return 0;
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

void Gantry::GantryTest(XboxController* controller)
{
	double joystick = controller->GetY(GenericHID::kLeftHand);

	m_gantryMotor.Set(-joystick);
}

void Gantry::PrintVars()
{
	SmartDashboard::PutBoolean("UpLimitSwitch", UpperLimitSwitchTripped());
	SmartDashboard::PutBoolean("LowLimitSwitch", LowerLimitSwitchTripped());
	SmartDashboard::PutBoolean("UpPhotoSwitch", UpperPhotoSensorTripped());
	SmartDashboard::PutBoolean("LowPhotoSwitch", LowerPhotoSensorTripped());
}
