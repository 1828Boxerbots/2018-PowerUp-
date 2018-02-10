#ifndef CompressorStopCmd_H
#define CompressorStopCmd_H

#include <WPILib.h>
#include "Commands/Command.h"

using namespace frc;

class CompressorStopCmd : public Command
{
public:
	CompressorStopCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // CompressorStopCmd_H
