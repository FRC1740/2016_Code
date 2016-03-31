#include "XBoxArcadeDrive.h"
#include "../../RobotMap.h"
#include "../../OI.h"

XBoxArcadeDrive::XBoxArcadeDrive()
{
	Requires(drivetrain);
	leftDrive = 0;
	rightDrive = 0;
	reverseMode = false;
	slowMode = false;
}

void XBoxArcadeDrive::Initialize()
{
	datalogger->Log("XBoxArcadeDrive::Initialize()", STATUS_MESSAGE);
}

void XBoxArcadeDrive::Execute()
{
	leftDrive = oi->xboxController->GetRawAxis(1) - oi->xboxController->GetRawAxis(4);
	rightDrive = oi->xboxController->GetRawAxis(1) + oi->xboxController->GetRawAxis(4);


	/*

	if(oi->xboxB->Get()) // B is reverse
	{
		reverseMode = not reverseMode;
		printf("Toggling reverse mode %d", reverseMode);
	}
	if(oi->xboxA->Get()) // A is half speed
	{
		slowMode = not slowMode;
		printf("Toggling slow mode %d", slowMode);
	}
	// Bumpers and triggers for small adjustments
	if(oi->xboxLB->Get())
	{
		leftDrive = 0.5 * LEFT_REVERSE;
	}
	if(oi->xboxRB->Get())
	{
		rightDrive = 0.5 * RIGHT_REVERSE;
	}
	if(oi->xboxController->GetRawAxis(2) > 0.5)
	{
		leftDrive = 0.5 * LEFT_FORWARD;
	}
	if(oi->xboxController->GetRawAxis(3) > 0.5)
	{
		rightDrive = 0.5 * RIGHT_FORWARD;
	}
	if(reverseMode)
	{
		leftDrive *= -1;
		rightDrive *= -1;
	}
	if(slowMode)
	{
		leftDrive *= 0.5;
		rightDrive *= 0.5;
	}
	/* */

	drivetrain->Go(leftDrive, rightDrive);
}

bool XBoxArcadeDrive::IsFinished()
{
	return false;
}

void XBoxArcadeDrive::End()
{
	datalogger->Log("XBoxArcadeDrive::End()", ERROR_MESSAGE);
	drivetrain->Stop();
}

void XBoxArcadeDrive::Interrupted()
{
	datalogger->Log("XBoxArcadeDrive::Interrupted()", STATUS_MESSAGE);
	drivetrain->Stop();
}
