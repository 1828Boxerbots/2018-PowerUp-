#ifndef WristRetractCmd_H
#define WristRetractCmd_H

#include <WPILib.h>

#include "Commands/Command.h"

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
