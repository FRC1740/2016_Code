#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:

public:
	OI();
	Joystick *tankDriveJoystickLeft;
	Joystick *tankDriveJoystickRight;
	Joystick *threeAxisJoystick;
	Joystick *xboxController;
	Joystick *NESController;
	Joystick *launchPad;
	JoystickButton *threeAxis1;
	JoystickButton *threeAxis3;
	JoystickButton *threeAxis4;
	JoystickButton *threeAxis5;
	JoystickButton *threeAxis6;
	JoystickButton *NESStart;
	JoystickButton *NESSelect;
	JoystickButton *NESB;
	JoystickButton *NESA;
};

#endif
