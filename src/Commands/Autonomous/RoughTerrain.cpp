#include "RoughTerrain.h"

RoughTerrain::RoughTerrain(long distance)
{
	Requires(drivetrain);
	count = (distance * 360L) / 280L; // distance (mm) * 1/280 (rev/mm) * 360 counts/rev
	timer = 0;
	printf("RoughTerrain Constructor");
}

void RoughTerrain::Initialize()
{
	drivetrain->Forward(.85); // Kludgy fix for robot driving backwards
	printf("RoughTerrain::Initialize()");
}

void RoughTerrain::Execute()
{
	return;
}

bool RoughTerrain::IsFinished()
{
	// Kludge City... Really want to get the encoder system working
	timer += 20;		// Execute & IsFinished are called every 20 msec
	if (timer > 5500) 	// ... so this should timeout after 5.5 seconds
		return true;

	if(abs(drivetrain->leftEncoder->Get()) >= count or abs(drivetrain->rightEncoder->Get()) >= count)
	{
		printf("RoughTerrain is FINISHED");
		return true;
	}
	else
	{
		printf("RoughTerrain is NOT finished");
		return false;
	}
}

void RoughTerrain::End()
{
	drivetrain->Stop();
}

void RoughTerrain::Interrupted()
{
	drivetrain->Stop();
}
