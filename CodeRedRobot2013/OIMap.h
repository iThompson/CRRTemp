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
 * 
 * Type:
 * JOY - Joystick
 * ANA - Analog input
 * DIN - Digital input
 * DOT - Digital output
 * 
 */

//Default Shooter Speed
//TODO: DUMMY VALUE! REPLACE LATER!
#define SHO_DEFAULT 42

//Drive
#define DRV_JOY_LEFT 1
#define DRV_JOY_RIGHT 2

//Shooter
//TODO: DUMMY VALUES! REPLACE LATER!
#define SHO_DIN_OFF 1
#define SHO_DIN_MANUAL 2
#define SHO_DIN_DEFAULT 3

//Arm
//TODO: DUMMY VALUES! REPLACE LATER!
#define ARM_DIN_STOW 4
#define ARM_DIN_FEED 5
#define ARM_DIN_MID 6
#define ARM_DIN_PYR 7
#define ARM_DIN_TOP 8

#endif
