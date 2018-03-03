#ifndef ClawOpenCmd_H
#define ClawOpenCmd_H

#include "Commands/Command.h"

using namespace frc;

class ClawOpenCmd : public Command
{
public:
	ClawOpenCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ClawOpenCmd_H
