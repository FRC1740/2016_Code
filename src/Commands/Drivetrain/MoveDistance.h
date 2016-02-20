#ifndef MoveDistance_H
#define MoveDistance_H

#include "../../CommandBase.h"
#include "WPILib.h"

class MoveDistance: public CommandBase
{
public:
	MoveDistance(float, int);
	float speed;
	int distance;
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
