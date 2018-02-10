#ifndef GantryMovementCmd_H
#define GantryMovementCmd_H

#include "Commands/Command.h"

using namespace frc;

class GantryMovementCmd : public Command
{
public:
	GantryMovementCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // GantryMovementCmd_H
