#ifndef WristRetractCmd_H
#define WristRetractCmd_H

#include "Commands/Command.h"

using namespace frc;

class WristRetractCmd : public Command
{
public:
	WristRetractCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // WristRetractCmd_H
