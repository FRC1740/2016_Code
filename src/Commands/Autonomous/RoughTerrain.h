#ifndef RoughTerrain_H
#define RoughTerrain_H

#include "../../CommandBase.h"
#include "WPILib.h"

class RoughTerrain: public CommandBase
{
public:
	RoughTerrain(int);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	int count;
};

#endif
