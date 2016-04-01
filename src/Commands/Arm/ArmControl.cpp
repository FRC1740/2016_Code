#include "ArmControl.h"
#include "math.h"

ArmControl::ArmControl()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(arm);
}

// Called just before this Command runs the first time
void ArmControl::Initialize()
{
	return;
}

// Called repeatedly when this Command is scheduled to run
void ArmControl::Execute()
{
	arm->lifterMotor->Set(oi->threeAxisJoystick->GetY());
	printf("Setting Arm Control... \n");
	int anglePOV;

	/* Fancy code to keep arm from extending too far (Doesn't work)
	int length = arm->extenderEncoder->Get();

	// This mess is to make sure the arm doesn't extend more than 15 inches past the perimeter of the robot
	//int l = 27.9 - arm->lifterEncoder->Get();
	//int d = arm->extenderEncoder->Get();
	//d < -((l+72.15) * sqrt(-0.00001*(pow(l, 4)-1250*pow(l, 2)+290800)) * cos(29) + 0.001532 * (pow(l, 3)+72.15*pow(l, 2)-625.255*l-1200002)) / (sqrt(-0.00001*(pow(l, 4)-1250*pow(l, 2)+290800)) * cos(29) + 0.001532 * (pow(l, 2)-625.255));


	// If the driver tries to move down while the arm is out too far, it won't move
	if (lengthCorrection > 15)
	{
		arm->lifterMotor->Set(oi->threeAxisJoystick->GetY());
	}
	else
	{
		arm->lifterMotor->Set(0);
	}
	/* */

	arm->lifterMotor->Set(oi->threeAxisJoystick->GetY());

	anglePOV = oi->threeAxisJoystick->GetPOV();

	if (anglePOV == -1)
	{
		//POV is not being pressed
		arm->extenderMotor->Set(0);
	}
	else
	{
		if (anglePOV > -90 && anglePOV < 90)
		{
			// This should be up, so extend the arm
			arm->extenderMotor->Set(1);
		}
		else
		{
			arm->extenderMotor->Set(-1);

			/* Fancy code to keep arm from extending too far (Doesn't work)
			// This should be down, so retract the arm

			// If the driver tries to extend the arm while it is out too far, it won't move
			if (lengthCorrection > 15)
			{
				arm->extenderMotor->Set(-1);
			}
			else
			{
				arm->extenderMotor->Set(0);
			}
			/* */

		}
	}
	/* */
}

// Make this return true when this Command no longer needs to run execute()
bool ArmControl::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ArmControl::End()
{
	return;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmControl::Interrupted()
{
	return;
}
