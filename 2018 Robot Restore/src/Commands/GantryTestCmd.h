#ifndef GantryTestCmd_H
#define GantryTestCmd_H

#include "Commands/Command.h"

using namespace frc;

class GantryTestCmd : public Command
{
public:
	GantryTestCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // GantryTestCmd_H
