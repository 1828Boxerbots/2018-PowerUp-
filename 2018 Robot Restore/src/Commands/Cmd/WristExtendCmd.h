#ifndef WristExtendCmd_H
#define WristExtendCmd_H

#include "Commands/Command.h"

using namespace frc;

class WristExtendCmd : public Command
{
public:
	WristExtendCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // WristExtendCmd_H
