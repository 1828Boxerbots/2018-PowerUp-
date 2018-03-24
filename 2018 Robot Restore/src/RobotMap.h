/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// constexpr int kLeftMotor = 1;
// constexpr int kRightMotor = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// constexpr int kRangeFinderPort = 1;
// constexpr int kRangeFinderModule = 1;

/*PWM Ports*/
constexpr int LEFT_DRIVE_MOTOR_PORT = 3;
constexpr int LEFT_DRIVE_TEST_PORT = 9;
constexpr int RIGHT_DRIVE_MOTOR_PORT = 4;
constexpr int RIGHT_DRIVE_TEST_PORT = 9;
constexpr int GANTRY_MOTOR_PORT = 2;
constexpr int LEFT_MANDIBLE_PORT = 0;
constexpr int RIGHT_MANDIBLE_PORT = 1;

/*Compressor Port*/
constexpr int COMPRESSOR_PORT = 0;

/*Solenoid Ports*/
constexpr int LEFT_CLAW_FORWARD_SOLENOID_PORT = 0;
constexpr int LEFT_CLAW_REVERSE_SOLENOID_PORT = 1;
constexpr int RIGHT_CLAW_FORWARD_SOLENOID_PORT = 2;
constexpr int RIGHT_CLAW_REVERSE_SOLENOID_PORT = 3;
constexpr int WRIST_FORWARD_SOLENOID_PORT = 4;
constexpr int WRIST_REVERSE_SOLENOID_PORT = 5;
constexpr int CLIMB_FORWARD_SOLENOID_PORT = 6;
constexpr int CLIMB_REVERSE_SOLENOID_PORT = 7;

/*USB Ports*/
constexpr int CONTROLLER_PORT = 0;
constexpr int SWITCH_BOARD_PORT = 1;

/*DIO Port*/
constexpr int UPPER_LIMIT_PORT = 9;
constexpr int LOWER_LIMIT_PORT = 8;
constexpr int UPPER_GANTRY_PHOTO_SENSOR_PORT = 6;
constexpr int LOWER_GANTRY_PHOTO_SENSOR_PORT = 7;

constexpr int LEFT_DRIVE_ENCODER_PORT_A = 0;
constexpr int LEFT_DRIVE_ENCODER_PORT_B = 1;
constexpr int RIGHT_DRIVE_ENCODER_PORT_A = 2;
constexpr int RIGHT_DRIVE_ENCODER_PORT_B = 3;
constexpr int GANTRY_ENCODER_PORT_A = 5;
constexpr int GANTRY_ENCODER_PORT_B = 4;


/*Analog Ports*/
constexpr int FOUR_BAR_POTENTIOMETER_PORT = 0;
