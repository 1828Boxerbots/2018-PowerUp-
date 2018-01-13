#include <WPILib.h>
#include <Subsystems/DriveTrain.h>
#include <XboxController.h>

#include "RobotMap.h"
#include "Robot.cpp"

#ifndef TeleopDriveCmd_H
#define TeleopDriveCmd_H

#include <Commands/Command.h>

class TeleopDriveCmd : public Command
{
public:
	TeleopDriveCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	XboxController controller {CONTROLLER_PORT};

	double Joystick = controller.GetX(GenericHID::kRightHand) + controller.GetY(GenericHID::kRightHand);

};

#endif  // TeleopDriveCmd_H
