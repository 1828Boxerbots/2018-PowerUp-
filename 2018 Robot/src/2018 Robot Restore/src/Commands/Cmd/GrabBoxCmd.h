#ifndef GrabBoxCmd_H
#define GrabBoxCmd_H

#include "Commands/Command.h"

using namespace frc;

class GrabBoxCmd : public Command {
public:
	GrabBoxCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // GrabBoxCmd_H
