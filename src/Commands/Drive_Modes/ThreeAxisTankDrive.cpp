#include "ThreeAxisTankDrive.h"

ThreeAxisTankDrive::ThreeAxisTankDrive()
{
	Requires(drivetrain);
}

void ThreeAxisTankDrive::Initialize()
{
	datalogger->Log("ThreeAxisTankDrive::Initialize()", STATUS_MESSAGE);
}

void ThreeAxisTankDrive::Execute()
{

	// The drivetrain->Go() method has built in handling for reversing motors on the left side...

	float y = 0, t = 0; // floats for the axes x, twist
	float l = 0, r = 0; // floats for the motor outputs

	if (oi->threeAxisJoystick->GetY() > DEADBAND_YAXIS || oi->threeAxisJoystick->GetY() < -DEADBAND_YAXIS)  // Deadband
	{
		y = oi->threeAxisJoystick->GetY();
	}
	if (oi->threeAxisJoystick->GetTwist() > DEADBAND_TWIST || oi->threeAxisJoystick->GetTwist() < -DEADBAND_TWIST)  // Deadband
	{
		t = SCALE_TWIST  * oi->threeAxisJoystick->GetTwist();
	}
	l = -y + t;
	r = y + t;
#if (DEBUG_LEVEL == 4) // CRE Not sure if this is legit

	if (gl!=l || gr!=r) // Only log the movement if something changed
	{
		gl=l;
		gr=r;
		char *data = new char[128];
		sprintf(data, "We're moving: %2.1f, %2.1f, Y=%2.1f, Twist=%2.1f", l, r, y, t);
		datalogger->Log(data, DEBUG_MESSAGE);
	}

#endif

	drivetrain->Go(l, r);

}

bool ThreeAxisTankDrive::IsFinished()
{
	return false;
}

void ThreeAxisTankDrive::End()
{
	drivetrain->Stop();
	datalogger->Log("ThreeAxisTankDrive::End()", ERROR_MESSAGE);
}

void ThreeAxisTankDrive::Interrupted()
{
	drivetrain->Stop();
	datalogger->Log("ThreeAxisTankDrive::Interrupted()", STATUS_MESSAGE);
}
