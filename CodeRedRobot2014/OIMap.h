#ifndef OIMAP_H
#define OIMAP_H

/* Naming scheme for ports:
 * "Subsystem_Type_Function"
 * 
 * Subsystem:
 * ARM - Arm
 * DRV - Drive
 * SHO - Shooter
 * RBT - No subsystem
 * LDR - Loader
 * 
 * Type:
 * JOY - Joystick
 * ANA - Analog input
 * DIN - Digital input
 * DOT - Digital output
 * 
 */

//TODO: Dummy Values replace later!
//Acquisition default speeds
#define ACQ_DEFAULT_FORWARD 1
#define ACQ_DEFAULT_REVERSE 1

//TODO: Dummy Values replace later!
//Shooting default times
#define SHO_DEFAULT_TRUSS 1
#define SHO_DEFAULT_GOAL 1

//Drive
#define DRV_JOY_LEFT 1
#define DRV_JOY_RIGHT 2

//TODO: Dummy Values replace later!
//Shooter
#define SHO_DIN_TRUSS 3
#define SHO_DIN_GOAL 4
#define SHO_DIN_MAN 5

//TODO: Dummy Values replace later!
//Acquisition
#define ACQ_DIN_RAISE 6
#define ACQ_DIN_LOWER 7
#define ACQ_DIN_AUTO 8
#define ACQ_DIN_OFF 9
#define ACQ_DIN_MAN 10
#define ACQ_DIN_RUN 11
#define ACQ_DIN_REVERSE 12
#define ACQ_DIN_EJECT 13


#endif
