#ifndef AutoDrive_H
#define AutoDrive_H

#include "Commands/Command.h"

using namespace frc;

class AutoDrive : public Command
{
public:
	AutoDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutoDrive_H
