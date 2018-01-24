/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/


#include "Robot.h"

#include <iostream>

using namespace frc;
using namespace std;

shared_ptr<DriveTrain> Robot::drivetrain = make_shared<DriveTrain>();
shared_ptr<Wrist> Robot::wrist = make_shared<Wrist>();
shared_ptr<OnBoardCompressor> Robot::onboardcompressor = make_shared<OnBoardCompressor>();
shared_ptr<Climber> Robot::climber = make_shared<Climber>();
shared_ptr<Claw> Robot::claw = make_shared<Claw>();

shared_ptr<OI> Robot::oi = make_shared<OI>();

void Robot::RobotInit()
{
	m_compressorCmdGrp.Start();
	cout << "Booting Up ..." << endl;
}

/**
 * This function is called once each time the robot enters Disabled
 * mode.
 * You can use it to reset any subsystem information you want to clear
 * when
 * the robot is disabled.
 */
void Robot::DisabledInit()
{
	cout << "Starting Disabled" << endl;
}

void Robot::DisabledPeriodic()
{
	frc::Scheduler::GetInstance()->Run();
}

/**
 * This autonomous (along with the chooser code above) shows how to
 * select
 * between different autonomous modes using the dashboard. The sendable
 * chooser code works with the Java SmartDashboard. If you prefer the
 * LabVIEW Dashboard, remove all of the chooser code and uncomment the
 * GetString code to get the auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional commands to
 * the
 * chooser code above (like the commented example) or additional
 * comparisons
 * to the if-else structure below with additional strings & commands.
 */
void Robot::AutonomousInit()
{
	m_compressorCmdGrp.Start();
	m_autoDriveCmd.Start();

	cout << "Starting Autonomous ... " << endl;
}

void Robot::AutonomousPeriodic()
{
	frc::Scheduler::GetInstance()->Run();

	//m_compressorCmdGrp.Start();
}

void Robot::TeleopInit()
{
	m_autoDriveCmd.Cancel();

	m_compressorCmdGrp.Start();

	m_teleopDriveCmd.Start();

	cout << "Starting Teleop ... " << endl;
}

void Robot::TeleopPeriodic()
{
	frc::Scheduler::GetInstance()->Run();

	m_compressorCmdGrp.Start();
}

void Robot::TestPeriodic()
{

}

START_ROBOT_CLASS(Robot)
