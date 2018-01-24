#ifndef CompressorStartCmd_H
#define CompressorStartCmd_H

#include <WPILib.h>

#include "Commands/Command.h"

class CompressorStartCmd : public Command
{
public:
	CompressorStartCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // CompressorStartCmd_H
