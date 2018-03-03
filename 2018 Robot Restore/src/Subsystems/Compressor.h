#ifndef Compressor_H
#define Compressor_H

#include <Commands/Subsystem.h>
#include <iostream>

#include <WPILib.h>

#include <Compressor.h>

#include "RobotMap.h"

using namespace frc;
using namespace std;

class OnBoardCompressor : public Subsystem
{
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
	void CompressorLoopController();
	void CompressorEStop();
	void CompressorInterupted();
};

#endif  // Compressor_H
