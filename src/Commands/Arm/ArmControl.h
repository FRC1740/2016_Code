#ifndef ArmControl_H
#define ArmControl_H

#include "../../CommandBase.h"
#include "WPILib.h"

class ArmControl: public CommandBase
{
public:
	ArmControl();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
