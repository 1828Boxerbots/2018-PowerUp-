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

}


// Called repeatedly when this Command is scheduled to run

void GantryMovementCmd::Execute()
{
	bool UpperLimitTripped = Robot::gantry->UpperLimitSwitchTripped();
	bool LowerLimitTripped = Robot::gantry->LowerLimitSwitchTripped();

	bool UpperPhotoTripped = Robot::gantry->UpperPhotoSensorTripped();
	bool LowerPhotoTripped = Robot::gantry->LowerPhotoSensorTripped();

	 //If gantry has not tripped either DIO/ exceeded it's height
	 // =position: enter this case*/

		if((!UpperLimitTripped && !LowerLimitTripped) && (!UpperPhotoTripped && !LowerPhotoTripped))
		{
			bool downMove = Robot::gantry->DownMovement(Robot::oi->GetJoystick());
			bool upMove = Robot::gantry->UpMovement(Robot::oi->GetJoystick());

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
		//If a DIO has been tripped, then enter this loop
		else
		{
			//Checks if the lower DIO has been tripped
			if(LowerLimitTripped || LowerPhotoTripped)
			{
				Robot::gantry->UpMovement(Robot::oi->GetJoystick());
			}
			//Checks if the upper DIO is tripped
			if(UpperLimitTripped || UpperPhotoTripped)
			{
				Robot::gantry->DownMovement(Robot::oi->GetJoystick());
			}
		}

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

