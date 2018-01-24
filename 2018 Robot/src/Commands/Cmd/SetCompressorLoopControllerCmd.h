#ifndef SetCompressorLoopControllerCmd_H
#define SetCompressorLoopControllerCmd_H

#include <WPILib.h>

#include "Commands/Command.h"

class SetCompressorLoopControllerCmd : public Command
{
public:
	SetCompressorLoopControllerCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // SetCompressorLoopControllerCmd_H
