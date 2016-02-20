#include "Up.h"

Up::Up()
{
	Requires(arm);
}

void Up::Initialize()
{
	datalogger->Log("Up::Initialize()", STATUS_MESSAGE);
	arm->lifterMotor->Set(SPEED);


}

void Up::Execute()
{
	return;
}

bool Up::IsFinished()
{
	return arm->lifterMotor->IsFwdLimitSwitchClosed();;
}

void Up::End()
{
	datalogger->Log("Up::End()", ERROR_MESSAGE);
	arm->lifterMotor->Set(0);

}

void Up::Interrupted()
{
	datalogger->Log("Up::Interrupted()", STATUS_MESSAGE);
	arm->lifterMotor->Set(0);
}
