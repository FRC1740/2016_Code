#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

// CAN IDs
#define LEFT_MOTOR_1_ID 4
#define LEFT_MOTOR_2_ID 5
#define RIGHT_MOTOR_1_ID 2
#define RIGHT_MOTOR_2_ID 3
#define LIFTER_MOTOR_ID 1
#define EXTENDER_MOTOR_ID 6

// Motor inputs
#define LEFT_FORWARD -1
#define RIGHT_FORWARD 1
#define LEFT_REVERSE 1
#define RIGHT_REVERSE -1

// Digital I/O Ports
#define LEFT_ENCODER_PORT_2 2
#define LEFT_ENCODER_PORT_3 3
#define RIGHT_ENCODER_PORT_0 0
#define RIGHT_ENCODER_PORT_1 1
#define LIFTER_ENCODER_PORT_4 4
#define LIFTER_ENCODER_PORT_5 5
#define EXTENDER_ENCODER_PORT_6 6
#define EXTENDER_ENCODER_PORT_7 7

// Analog I/O Ports
#define STEERING_GYRO_PORT 0

// Pneumatics
//#define CYLINDER_PORT_0 0 // Gripper solenoid wired to port 0 on pneumatic break-out card
//#define CYLINDER_PORT_1 1 // Release solenoid wired to port 1 on pneumatic break-out card

#endif
