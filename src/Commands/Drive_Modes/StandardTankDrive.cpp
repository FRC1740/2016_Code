#include "StandardTankDrive.h"

StandardTankDrive::StandardTankDrive()
{
	Requires(drivetrain);
}

void StandardTankDrive::Initialize()
{
	datalogger->Log("StandardTankDrive::Initialize()", STATUS_MESSAGE);
}
void StandardTankDrive::Execute()
{
	datalogger->Log("StandardTankDrive::Execute()", VERBOSE_MESSAGE);
	drivetrain->leftMotor1->Set(-1 * oi->tankDriveJoystickLeft->GetY());
	drivetrain->leftMotor2->Set(-1 * oi->tankDriveJoystickLeft->GetY());
	drivetrain->rightMotor1->Set(oi->tankDriveJoystickRight->GetY());
	drivetrain->rightMotor2->Set(oi->tankDriveJoystickRight->GetY());
}

bool StandardTankDrive::IsFinished()
{
	return false;
}

void StandardTankDrive::End()
{
	datalogger->Log("StandardTankDrive::End()", ERROR_MESSAGE);
	drivetrain->Stop();
}

void StandardTankDrive::Interrupted()
{
	datalogger->Log("StandardTankDrive::Interrupted()", STATUS_MESSAGE);
	drivetrain->Stop();
}
