#ifndef CompressorStop_H
#define CompressorStop_H

#include "Commands/Command.h"

using namespace frc;

class CompressorStop : public Command {
public:
	CompressorStop();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // CompressorStop_H
