#include "Down.h"

Down::Down()
{
	Requires(arm);
}

void Down::Initialize()
{
	datalogger->Log("Down::Initialize()", STATUS_MESSAGE);
	arm->lifterMotor->Set(-1.0 * SPEED);
}

void Down::Execute()
{
	return;
}

bool Down::IsFinished()
{
	return false;
}

void Down::End()
{
	datalogger->Log("Down::End()", ERROR_MESSAGE);
	arm->lifterMotor->Set(0);
}

void Down::Interrupted()
{
	datalogger->Log("Down::Interrupted()", STATUS_MESSAGE);
	arm->lifterMotor->Set(0);
}
