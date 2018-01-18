/*
 * Robot.h
 *
 *  Created on: Jan 13, 2018
 *      Author: ralte
 */

#ifndef ROBOT_H_
#define ROBOT_H_

#include <WPILib.h>

#include <memory>

//#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <TimedRobot.h>

#include "Commands/Cmd/AutoDriveCmd.h"
#include "Commands/Cmd/TeleopDriveCmd.h"

#include "Subsystems/DriveTrain.h"
#include "Subsystems/Wrist.h"
#include "Subsystems/OnBoardCompressor.h"

#include "OI.h"

using namespace std;
using namespace frc;

class Robot : public frc::TimedRobot
{
public:

	static shared_ptr<DriveTrain> drivetrain;
	static shared_ptr<Wrist> wrist;
	static shared_ptr<OnBoardCompressor> onboardcompressor;

	static shared_ptr<OI> oi;

private:

	TeleopDriveCmd m_teleopDriveCmd;
	AutoDriveCmd m_autoDriveCmd;

	void RobotInit() override;
	void DisabledInit() override;
	void DisabledPeriodic() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
	void TestPeriodic() override;
};

#endif /* ROBOT_H_ */
