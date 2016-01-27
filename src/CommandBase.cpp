#include "CommandBase.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
OI* CommandBase::oi = NULL;
DriveTrain* CommandBase::drivetrain = NULL;
DataLogger* CommandBase::datalogger = NULL;
Piston*	CommandBase::piston = NULL;
Arm* CommandBase::arm = NULL;
RangeFinder* CommandBase::rangefinder = NULL;

CommandBase::CommandBase(char const *name): Command(name) {}

CommandBase::CommandBase(): Command() {}

void CommandBase::init()
{
	drivetrain = new DriveTrain();
	oi = new OI();
	datalogger = new DataLogger();
	piston = new Piston();
	arm = new Arm();
	rangefinder = new RangeFinder();
}
