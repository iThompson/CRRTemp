#ifndef OIMAP_H
#define OIMAP_H

/* Naming scheme for ports:
 * "Subsystem_Type_Function"
 * 
 * Subsystem:
 * ACQ - Acquisition
 * DRV - Drive
 * SHO - Shooter
 * RBT - No subsystem
 * EJT - Ejection
 * 
 * Type:
 * JOY - Joystick
 * ANA - Analog input
 * DIN - Digital input
 * DOT - Digital output
 * 
 */

//Robot
#define RBT_JOY_CONTROLLER 3

//Drive
#define DRV_JOY_LEFT 1
#define DRV_JOY_RIGHT 2

#define DRV_JOY_SINGLE 4 //Maybe dummy value

#define DRV_DIN_DIST 2,2

//Shooter
#define SHO_DIN_TRUSS 5
#define SHO_DIN_GOAL 7
#define SHO_DIN_MAN 8

//Acquisition
#define ACQ_DIN_ARM 11
#define ACQ_DIN_AUTO 3
#define ACQ_DIN_MAN 6
#define ACQ_DIN_DIR 10
#define ACQ_DIN_TOSHOOT 12 //TODO: Replace dummy value

//Ejection
#define EJT_DIN_EJECT 9


#endif
