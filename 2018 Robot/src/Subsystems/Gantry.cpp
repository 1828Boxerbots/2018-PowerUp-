#include "Gantry.h"
#include "../RobotMap.h"

#include <WPILib.h>

using namespace frc;

Gantry::Gantry() : Subsystem("ExampleSubsystem") {

}

void Gantry::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Gantry::UpMovement(XboxController* trigger)
{
	double triggerAxis = trigger->GetTriggerAxis(GenericHID::kLeftHand);

	m_gantryMotor.Set(triggerAxis);
}

void Gantry::DownMovement(XboxController* trigger)
{
	double triggerAxis = trigger->GetTriggerAxis(GenericHID::kLeftHand);

	m_gantryMotor.Set(-triggerAxis);
}
