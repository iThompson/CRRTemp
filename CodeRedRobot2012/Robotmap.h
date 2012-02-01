#ifndef ROBOTMAP_H
#define ROBOTMAP_H

//Shooters May Change
#define SHOOTER_A 2
#define SHOOTER_B 3
#define SHOOTER_C 4
#define SHOOTER_D 5
#define DRIVE_LEFT_A 6
#define DRIVE_LEFT_B 7
#define DRIVE_RIGHT_A 8
#define DRIVE_RIGHT_B 9
#define GATE_TOP 2
#define GATE_BOT 3
#define COMP_TEST 4
#define ACQUIRE_VICTOR 5
#define ACQUIRE_GATE 6
#define DRIVE_SOLENOID 1

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// #define LEFTMOTOR 1
// #define RIGHTMOTOR 2

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// #define RANGE_FINDER_PORT 1
// #define RANGE_FINDER_MODULE 1

#endif
