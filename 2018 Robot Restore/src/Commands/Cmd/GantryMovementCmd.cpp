#include "GantryMovementCmd.h"

#include "Robot.h"

GantryMovementCmd::GantryMovementCmd()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::gantry.get());
}

// Called just before this Command runs the first time
void GantryMovementCmd::Initialize()
{
	time = new Timer();
	time->Start();
	previousTime = time->Get();
}

// Called repeatedly when this Command is scheduled to run

void GantryMovementCmd::Execute()
{
	if(isRunning == true)
	{
		Wait(0.005);
		return ;
	}
	isRunning = true;

	double elapsedTime = time->Get();

	double loopTime = (elapsedTime - previousTime) * 1000;
	SmartDashboard::PutNumber("Loop Time: ", loopTime);

	previousTime = elapsedTime;

	Robot::gantry->PrintVars();


	bool downMove = Robot::gantry->DownMovement(Robot::oi->GetJoystick());
	bool upMove = Robot::gantry->UpMovement(Robot::oi->GetJoystick());

	bool UpperLimitTripped = Robot::gantry->UpperLimitSwitchTripped();
	bool LowerLimitTripped = Robot::gantry->LowerLimitSwitchTripped();

	bool UpperPhotoTripped = Robot::gantry->UpperPhotoSensorTripped();
	bool LowerPhotoTripped = Robot::gantry->LowerPhotoSensorTripped();

	 //If gantry has not tripped either DIO/ exceeded it's height
	 // =position: enter this case
	if(LowerLimitTripped || LowerPhotoTripped)
	{
		Robot::gantry->UpMovement(Robot::oi->GetJoystick());

		SmartDashboard::PutBoolean("In Lower Tripped: ", true);
	}
	else
	{
		if((!UpperLimitTripped && !LowerLimitTripped) && (!UpperPhotoTripped && !LowerPhotoTripped))
		{
			SmartDashboard::PutString("Limits Block", "We are there!");

			//Neither DIO tripped or both buttons are pressed
			if ((!downMove && !upMove) || (downMove && upMove))
			{
				Robot::gantry->StopMotors();
			}
			//If the above statement is not true, enter this loop
			else
			{
				// Only one button is pressed; set motor accordingly
				if (downMove == true)
				{
					Robot::gantry->DownMovement(Robot::oi->GetJoystick());
				}
				if (upMove == true)
				{
					Robot::gantry->UpMovement(Robot::oi->GetJoystick());
				}
			}
		}
	}
	if(UpperLimitTripped || UpperPhotoTripped)
	{
		Robot::gantry->DownMovement(Robot::oi->GetJoystick());

		SmartDashboard::PutBoolean("In Upper Tripped: ", true);
	}
	else
	{
		if((!UpperLimitTripped && !LowerLimitTripped) && (!UpperPhotoTripped && !LowerPhotoTripped))
		{
			SmartDashboard::PutString("Limits Block", "We are there!");

			//Neither DIO tripped or both buttons are pressed
			if ((!downMove && !upMove) || (downMove && upMove))
			{
				Robot::gantry->StopMotors();
			}
			//If the above statement is not true, enter this loop
			else
			{
				// Only one button is pressed; set motor accordingly
				if (downMove == true)
				{
					Robot::gantry->DownMovement(Robot::oi->GetJoystick());
				}
				if (upMove == true)
				{
					Robot::gantry->UpMovement(Robot::oi->GetJoystick());
				}
			}
		}
	}
	double runTime = time->Get();
	double deltaTime = (runTime - elapsedTime) * 1000;

	SmartDashboard::PutNumber("Loop Execution Time: ", deltaTime);

	isRunning = false;

	//elapsedTime = time->Reset();
}


// Make this return true when this Command no longer needs to run execute()
bool GantryMovementCmd::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void GantryMovementCmd::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GantryMovementCmd::Interrupted()
{

}

