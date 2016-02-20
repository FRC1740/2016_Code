#ifndef EncoderTest_H
#define EncoderTest_H

#include "../../CommandBase.h"
#include "WPILib.h"

class EncoderTest: public CommandBase
{
public:
	EncoderTest(int);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	int distance;
	int count;
};

#endif
