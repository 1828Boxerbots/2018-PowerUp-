#ifndef CompressorLoopControllerCmd_H
#define CompressorLoopControllerCmd_H

#include <WPILib.h>
#include "Commands/Command.h"

using namespace frc;

class CompressorLoopControllerCmd : public Command
{
public:
	CompressorLoopControllerCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // CompressorLoopControllerCmd_H
