#include "GyroTest.h"

GyroTest::GyroTest()
{
	Requires(drivetrain);
	pidError = 0.0;
	pidLastError = 0.0;
	pidIntegral = 0.0;
	pidDerivative = 0.0;
}

void GyroTest::Initialize()
{
	drivetrain->steeringGyro->Reset();
	pidError = 0.0;
	pidLastError = 0.0;
	pidIntegral = 0.0;
	pidDerivative = 0.0;
	printf("Error: %f\n", pidError);
	printf("Integral: %f\n", pidIntegral);
	printf("Derivative: %f\n", pidDerivative);
}

void GyroTest::Execute()
{
	pidError = drivetrain->steeringGyro->GetAngle();
	if(pidIntegral > PID_INTEGRAL_LIMIT)
	{
		pidIntegral = 0;
	}
	else
	{
		pidIntegral += pidError;
	}
	pidDerivative = pidError - pidLastError;
	pidLastError = pidError;
	drivetrain->Go(pidError * PID_KP + pidIntegral * PID_KI + pidDerivative * PID_KD, pidError * PID_KP + pidIntegral * PID_KI + pidDerivative * PID_KD);
	printf("Error: %f\n", pidError);
	printf("Integral: %f\n", pidIntegral);
	printf("Derivative: %f\n", pidDerivative);
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
