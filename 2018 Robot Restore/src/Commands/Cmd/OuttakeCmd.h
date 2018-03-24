#ifndef OuttakeCmd_H
#define OuttakeCmd_H

#include "Commands/Command.h"

using namespace frc;

class OuttakeCmd : public Command {
public:
	OuttakeCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // OuttakeCmd_H
