/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <WPILib.h>

#include <iostream>

using namespace frc;
using namespace std;

shared_ptr<Drivetrain> Robot::drivetrain = make_shared<Drivetrain>();
shared_ptr<Gantry> Robot::gantry =  make_shared<Gantry>();
shared_ptr<Wrist> Robot::wrist = make_shared<Wrist>();
shared_ptr<OnBoardCompressor> Robot::compressor = make_shared<OnBoardCompressor>();
shared_ptr<Climber> Robot::climber = make_shared<Climber>();
shared_ptr<Claw> Robot::claw = make_shared<Claw>();
shared_ptr<Vision> Robot::vision = make_shared<Vision>();
//shared_ptr<FourBar> Robot::fourbar = make_shared<FourBar>();
shared_ptr<Intake> Robot::intake = make_shared<Intake>();

shared_ptr<OI> Robot::oi = make_shared<OI>();

void Robot::RobotInit()
{

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
	 * hi if you see this ryan lol
	 */
void Robot::AutonomousInit()
{

}

void Robot::AutonomousPeriodic()
{
		frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit()
{
	m_drive.Start();

	//m_fourBar.Start();

	m_gantry.Start();

	m_intake.Start();

	m_outtake.Start();

	time = new Timer();
	previousTime = time->Get();
}

void Robot::TeleopPeriodic()
{
	frc::Scheduler::GetInstance()->Run();

	double loopTime = time->Get() - previousTime;
	previousTime = time->Get();

	SmartDashboard::PutNumber("Teleop Loop Time: ", loopTime * 1000);
}

void Robot::TestPeriodic()
{

}

START_ROBOT_CLASS(Robot)
