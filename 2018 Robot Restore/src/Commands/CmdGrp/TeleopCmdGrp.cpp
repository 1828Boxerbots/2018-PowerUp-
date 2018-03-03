#include "TeleopCmdGrp.h"
//#include "Robot.h"

#include "Commands/Cmd/TeleopDriveCmd.h"
#include "Commands/Cmd/GantryMovementCmd.h"
#include "Commands/Cmd/FourBarCmd.h"
#include "Commands/Cmd/ClimbingCmd.h"
#include "Commands/Cmd/ClawOpenCmd.h"
#include "Commands/Cmd/GrabBoxCmd.h"
#include "Commands/Cmd/WristExtendCmd.h"
#include "Commands/Cmd/WristRetractCmd.h"

TeleopCmdGrp::TeleopCmdGrp() {
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.

	AddParallel(new TeleopDriveCmd());
	//AddParallel(new FourBarCmd());
	AddParallel(new GantryMovementCmd());
	AddParallel(new ClimbingCmd());
	AddParallel(new ClawOpenCmd());
	AddParallel(new GrabBoxCmd());
	AddParallel(new WristExtendCmd());
	AddParallel(new WristRetractCmd());

}
