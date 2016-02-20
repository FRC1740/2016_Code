#include "DriveToGoal.h"
#include "../Drivetrain/Move.h"
#include "../Drivetrain/DriveUntilRange.h"
#include "../Arm/Down.h"

DriveToGoal::DriveToGoal()
{
	AddSequential(new Down());
	AddSequential(new Move(0.5, 5.0));
}
