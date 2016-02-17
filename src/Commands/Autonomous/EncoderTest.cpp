#include "EncoderTest.h"
#include "math.h"

EncoderTest::EncoderTest(int d)
{
	Requires(arm);
	distance = d;
	count = distance;
}

void EncoderTest::Initialize()
{
//	drivetrain->leftEncoder->Reset();
//	drivetrain->rightEncoder->Reset();
//	drivetrain->Go(0.5 * LEFT_FORWARD, 0.5 * RIGHT_FORWARD);
	arm->armEncoder->Reset();
	arm->extenderMotor->Set(0.5);
}

void EncoderTest::Execute()
{
	return;
}

bool EncoderTest::IsFinished()
{
	/*if(abs(drivetrain->leftEncoder->Get()) >= count and abs(drivetrain->rightEncoder->Get()) >= count)
	{
		return true;
	}*/
	if(abs(arm->armEncoder->Get()) >= count)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void EncoderTest::End()
{
	drivetrain->Stop();
}

void EncoderTest::Interrupted()
{
	drivetrain->Stop();
}
