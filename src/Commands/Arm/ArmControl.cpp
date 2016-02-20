#include "ArmControl.h"

ArmControl::ArmControl()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(arm);
}

// Called just before this Command runs the first time
void ArmControl::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ArmControl::Execute()
{
	int anglePOV;

	arm->lifterMotor->Set(oi->threeAxisJoystick->GetY());
	anglePOV = oi->threeAxisJoystick->GetPOV();
	if (anglePOV == -1)
	{
		//POV is not being pressed
		arm->extenderMotor->Set(0);
	}
	else
	{
		if (anglePOV > 180)
		{
			// This should be down, so retracting the arm
			arm->extenderMotor->Set(-1);
		}
		else
		{
			// This should be up, so extend the arm
			arm->extenderMotor->Set(1);
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ArmControl::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ArmControl::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmControl::Interrupted()
{

}
