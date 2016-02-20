#include "DriveTrain.h"
#include "../RobotMap.h"
#include "math.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain")
{
	leftMotor1 = new CANTalon(LEFT_MOTOR_1_ID);
	leftMotor2 = new CANTalon(LEFT_MOTOR_2_ID);
	rightMotor1 = new CANTalon(RIGHT_MOTOR_1_ID);
	rightMotor2 = new CANTalon(RIGHT_MOTOR_2_ID);
	leftEncoder = new Encoder(LEFT_ENCODER_PORT_2, LEFT_ENCODER_PORT_3);
	rightEncoder = new Encoder(RIGHT_ENCODER_PORT_0, RIGHT_ENCODER_PORT_1);
	steeringGyro = new AnalogGyro(STEERING_GYRO_PORT);
}

void DriveTrain::Go(float leftSpeed, float rightSpeed)
{
	leftMotor1->Set(leftSpeed);
	leftMotor2->Set(leftSpeed);
	rightMotor1->Set(rightSpeed);
	rightMotor2->Set(rightSpeed);
}

void DriveTrain::Stop()
{
	leftMotor1->Set(0);
	leftMotor2->Set(0);
	rightMotor1->Set(0);
	rightMotor2->Set(0);
}
