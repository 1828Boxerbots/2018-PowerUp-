#ifndef ClimbingCmd_H
#define ClimbingCmd_H

#include "Commands/Command.h"

using namespace frc;

class ClimbingCmd : public Command {
public:
	ClimbingCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ClimbingCmd_H
