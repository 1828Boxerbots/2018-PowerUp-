#ifndef IntakeCmd_H
#define IntakeCmd_H

#include "Commands/Command.h"

using namespace frc;

class IntakeCmd : public Command {
public:
	IntakeCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // IntakeCmd_H
