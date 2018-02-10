#ifndef TeleopDriveCmd_H
#define TeleopDriveCmd_H

#include <Commands/Command.h>
#include <Subsystems/Drivetrain.h>

using namespace frc;

class TeleopDriveCmd : public Command
{
public:
	TeleopDriveCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // TeleopDriveCmd_H
