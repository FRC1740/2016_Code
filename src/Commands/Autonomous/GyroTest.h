#ifndef GyroTest_H
#define GyroTest_H

#include "../../CommandBase.h"
#include "WPILib.h"

#define KP 0.1

class GyroTest: public CommandBase
{
public:
	GyroTest();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
