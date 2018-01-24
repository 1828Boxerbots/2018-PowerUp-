#ifndef OnBoardCompressor_H
#define OnBoardCompressor_H

#include <WPILib.h>

#include <Compressor.h>

#include <Commands/Subsystem.h>

#include "RobotMap.h"

class OnBoardCompressor : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Compressor compressor {COMPRESSOR_PORT};

public:
	OnBoardCompressor();
	void InitDefaultCommand();
	void ClearPCMErrors();
	void CompressorStart();
	void CompressorStop();
	void CompressorLoopController(bool on);
	void CompressorEStop();
	void CompressorInterrupted();
};

#endif  // OnBoardCompressor_H
