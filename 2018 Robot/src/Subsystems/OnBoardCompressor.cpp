#include <iostream>

#include "OnBoardCompressor.h"
#include "../RobotMap.h"

using namespace std;

OnBoardCompressor::OnBoardCompressor() : Subsystem("ExampleSubsystem")
{

}

void OnBoardCompressor::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void OnBoardCompressor::ClearPCMErrors()
{
	compressor.ClearAllPCMStickyFaults();
}

void OnBoardCompressor::CompressorStart()
{
	if(compressor.GetClosedLoopControl() && (compressor.GetPressureSwitchValue() == false))
	{
		compressor.Start();
	}
}

void OnBoardCompressor::CompressorStop()
{
	compressor.Stop();
}

void OnBoardCompressor::CompressorLoopController(bool on)
{
	compressor.SetClosedLoopControl(on);
}

void OnBoardCompressor::CompressorEStop()
{
	if(compressor.GetCompressorShortedStickyFault() || compressor.GetCompressorCurrentTooHighFault() ||
			compressor.GetCompressorNotConnectedStickyFault())
	{
		compressor.Stop();
		cout << "Compressor E-Stop Engaged" << endl;
	}
}

void OnBoardCompressor::CompressorInterrupted()
{
	compressor.Stop();
}
