#include "Arm.h"
#include "../RobotMap.h"

Arm::Arm(): Subsystem("Arm")
{
	lifterMotor = new CANTalon(LIFTER_MOTOR_ID);
	extenderMotor = new CANTalon(EXTENDER_MOTOR_ID);
	armEncoder = new Encoder(ARM_ENCODER_PORT_0, ARM_ENCODER_PORT_1);
}
