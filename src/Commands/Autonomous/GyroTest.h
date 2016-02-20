#ifndef GyroTest_H
#define GyroTest_H

#include "../../CommandBase.h"
#include "WPILib.h"

#define PID_KP 0.1
#define PID_KI 0.1
#define PID_KD 0.1
#define PID_INTEGRAL_LIMIT 1000

class GyroTest: public CommandBase
{
public:
	GyroTest();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	float pidError;
	float pidLastError;
	float pidIntegral;
	float pidDerivative;
};

#endif
