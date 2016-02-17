#include "CommandBase.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
OI* CommandBase::oi = NULL;
Arm* CommandBase::arm = NULL;
DataLogger* CommandBase::datalogger = NULL;
DriveTrain*	CommandBase::drivetrain = NULL;
Piston* CommandBase::piston = NULL;
RangeFinder* CommandBase::rangefinder = NULL;

CommandBase::CommandBase(char const *name): Command(name) {}

CommandBase::CommandBase(): Command() {}

void CommandBase::init()
{
	oi = new OI();
	arm = new Arm();
	datalogger = new DataLogger();
	drivetrain = new DriveTrain();
	piston = new Piston();
	rangefinder = new RangeFinder();
}
