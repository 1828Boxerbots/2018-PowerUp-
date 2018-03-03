/*
 * Robot.h
 *
 *  Created on: Feb 6, 2018
 *      Author: Ryan Alterboy
 */

#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_

#include <memory>

#include <Commands/Scheduler.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <TimedRobot.h>
#include <Timer.h>

#include "Commands/Cmd/TeleopDriveCmd.h"
#include "Commands/Cmd/GantryMovementCmd.h"
#include "Commands/Cmd/FourBarCmd.h"

#include "Subsystems/Drivetrain.h"
#include "Subsystems/Wrist.h"
#include "Subsystems/Compressor.h"
#include "Subsystems/Climber.h"
#include "Subsystems/Claw.h"
#include "Subsystems/Gantry.h"
#include "Subsystems/Vision.h"
#include "Subsystems/FourBar.h"

#include "OI.h"

using namespace frc;
using namespace std;

class Robot : public frc::TimedRobot
{
public:
	static shared_ptr<Drivetrain> drivetrain;

	static shared_ptr<Wrist> wrist;
	static shared_ptr<OnBoardCompressor> compressor;
	static shared_ptr<Climber> climber;
	static shared_ptr<Claw> claw;
	static shared_ptr<Gantry> gantry;
	static shared_ptr<Vision> vision;
	static shared_ptr<FourBar> fourbar;

	static shared_ptr<OI> oi;

private:

	TeleopDriveCmd m_drive;
	GantryMovementCmd m_gantry;
	FourBarCmd m_fourBar;

	Timer* time = NULL;

	double previousTime = 0;

	void RobotInit() override;
	void DisabledInit() override;
	void DisabledPeriodic() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
	void TestPeriodic() override;
};

#endif /* SRC_ROBOT_H_ */
