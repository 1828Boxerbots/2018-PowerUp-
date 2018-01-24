#ifndef WristExtend_H
#define WristExtend_H

#include "Commands/Command.h"

#include "Subsystems/Wrist.h"

class WristExtend : public Command {
public:
	WristExtend();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // WristExtend_H
