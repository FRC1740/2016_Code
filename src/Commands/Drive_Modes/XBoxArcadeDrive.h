#ifndef XBoxArcadeDrive_H
#define XBoxArcadeDrive_H

#include "../../CommandBase.h"
#include "WPILib.h"

class XBoxArcadeDrive: public CommandBase
{
public:
	XBoxArcadeDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
