#include "XBoxTankDrive.h"
#include "../../RobotMap.h"
#include "../../OI.h"

XBoxTankDrive::XBoxTankDrive()
{
	Requires(drivetrain);
}

void XBoxTankDrive::Initialize()
{
	datalogger->Log("XBoxTankDrive::Initialize()", STATUS_MESSAGE);
}

void XBoxTankDrive::Execute(){
	datalogger->Log("XBoxTankDrive::Execute()", VERBOSE_MESSAGE);
	drivetrain->leftMotor1->Set(-1 * oi->xboxController->GetRawAxis(1));
	drivetrain->leftMotor2->Set(-1 * oi->xboxController->GetRawAxis(1));
	drivetrain->rightMotor1->Set(oi->xboxController->GetRawAxis(5));
	drivetrain->rightMotor2->Set(oi->xboxController->GetRawAxis(5));
}

bool XBoxTankDrive::IsFinished()
{
	return false;
}

void XBoxTankDrive::End()
{
	datalogger->Log("XBoxTankDrive::End()", ERROR_MESSAGE);
	drivetrain->Stop();
}

void XBoxTankDrive::Interrupted()
{
	datalogger->Log("XBoxTankDrive::Interrupted()", STATUS_MESSAGE);
	drivetrain->Stop();
}
