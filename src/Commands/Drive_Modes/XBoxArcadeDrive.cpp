#include "XBoxArcadeDrive.h"
#include "../../RobotMap.h"
#include "../../OI.h"

XBoxArcadeDrive::XBoxArcadeDrive()
{
	Requires(drivetrain);
}

void XBoxArcadeDrive::Initialize()
{
	datalogger->Log("XBoxArcadeDrive::Initialize()", STATUS_MESSAGE);
}

void XBoxArcadeDrive::Execute(){
	datalogger->Log("XBoxDrive::Execute()", VERBOSE_MESSAGE);
	drivetrain->leftMotor1->Set(-1 * oi->xboxController->GetRawAxis(1) + oi->xboxController->GetRawAxis(4));
	drivetrain->leftMotor2->Set(-1 * oi->xboxController->GetRawAxis(1) + oi->xboxController->GetRawAxis(4));
	drivetrain->rightMotor1->Set(oi->xboxController->GetRawAxis(1) + oi->xboxController->GetRawAxis(4));
	drivetrain->rightMotor2->Set(oi->xboxController->GetRawAxis(1) + oi->xboxController->GetRawAxis(4));
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
