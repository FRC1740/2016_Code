#include "GyroTest.h"

GyroTest::GyroTest()
{
	Requires(drivetrain);
}

void GyroTest::Initialize()
{
	drivetrain->steeringGyro->Reset();
}

void GyroTest::Execute()
{
	float angle = drivetrain->steeringGyro->GetAngle();
	drivetrain->Go(-angle * KP, -angle * KP);
}

bool GyroTest::IsFinished()
{
	return false;
}

void GyroTest::End()
{
	drivetrain->Stop();
}

void GyroTest::Interrupted()
{
	drivetrain->Stop();
}
