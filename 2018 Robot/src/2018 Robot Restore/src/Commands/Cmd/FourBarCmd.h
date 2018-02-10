#ifndef FourBarCmd_H
#define FourBarCmd_H

#include "Commands/Command.h"

using namespace frc;

class FourBarCmd : public Command
{
public:
	FourBarCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // FourBarCmd_H
