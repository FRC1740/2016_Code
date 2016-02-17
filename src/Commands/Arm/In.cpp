#include "In.h"

In::In()
{
	Requires(arm);
}

void In::Initialize()
{
	datalogger->Log("In::Initialize()", STATUS_MESSAGE);
	arm->extenderMotor->Set(-1.0);
}

void In::Execute()
{
	return;
}

bool In::IsFinished()
{
	return false;
}

void In::End()
{
	datalogger->Log("In::End()", ERROR_MESSAGE);
	arm->extenderMotor->Set(0);
}

void In::Interrupted()
{
	datalogger->Log("In::Interrupted()", STATUS_MESSAGE);
	arm->extenderMotor->Set(0);
}
