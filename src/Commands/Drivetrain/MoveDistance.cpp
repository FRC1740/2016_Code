#include "MoveDistance.h"

MoveDistance::MoveDistance(float s, int d)
{
	Requires(drivetrain);
	speed = s;
	distance = d;
}

void MoveDistance::Initialize()
{
	drivetrain->leftEncoder->Reset();
//	drivetrain->rightEncoder->Reset();
	drivetrain->Go(speed, speed);
}

void MoveDistance::Execute()
{
	return;
}

bool MoveDistance::IsFinished()
{
	return drivetrain->leftEncoder->Get() > distance;// and drivetrain->rightEncoder->Get() > distance;
}

void MoveDistance::End()
{
	drivetrain->Stop();
}

void MoveDistance::Interrupted()
{
	drivetrain->Stop();
}
