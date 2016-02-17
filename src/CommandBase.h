#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

//Include all subsystems
#include <string>
#include "Commands/Command.h"
#include "WPILib.h"
#include "OI.h"
#include "Subsystems/Arm.h"
#include "Subsystems/DataLogger.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/Piston.h"
#include "Subsystems/RangeFinder.h"

class CommandBase: public Command
{
public:
	CommandBase(char const *name);
	CommandBase();
	static void init();
	// Create a single static instance of all of your subsystems
	static OI *oi;
	static Arm *arm;
	static DataLogger *datalogger;
	static DriveTrain *drivetrain;
	static Piston *piston;
	static RangeFinder *rangefinder;
};

#endif
