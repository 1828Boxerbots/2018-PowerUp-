#ifndef GantryMovementCmd_H
#define GantryMovementCmd_H

#include "Commands/Command.h"

#include <Timer.h>

using namespace frc;

class GantryMovementCmd : public Command
{
public:
	GantryMovementCmd();
	void Initialize();
	bool IsFinished();
	void End();
	void Interrupted();
	void Execute();

private:
	void MarinasExecute();

	Timer* time = NULL;
	double previousTime = 0;

	bool isRunning = false;
};

#endif  // GantryMovementCmd_H
