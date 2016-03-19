#include "Arm.h"
#include "../RobotMap.h"

Arm::Arm(): Subsystem("Arm")
{
	lifterMotor = new CANTalon(LIFTER_MOTOR_ID);
	extenderMotor = new CANTalon(EXTENDER_MOTOR_ID);
	lifterEncoder = new Encoder(LIFTER_ENCODER_PORT_4, LIFTER_ENCODER_PORT_5);
	extenderEncoder = new Encoder(EXTENDER_ENCODER_PORT_6, EXTENDER_ENCODER_PORT_7);
	armCamera = new USBCamera("cam0", true);
	//armCamera->OpenCamera();
	//armCamera->StartCapture();
	//armCamera->GetInstance()->StartAutomaticCapture("cam0");
}
