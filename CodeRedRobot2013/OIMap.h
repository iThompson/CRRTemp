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

//Arm Positions
//TODO: All placeholder values; replace later
#define ARM_POS_STOW_EL 1
#define ARM_POS_STOW_WR 1
#define ARM_POS_FEED_EL 2
#define ARM_POS_FEED_WR 2
#define ARM_POS_MID_EL 3
#define ARM_POS_MID_WR 3
#define ARM_POS_PYR_EL 4
#define ARM_POS_PYR_WR 4
#define ARM_POS_TOP_EL 5
#define ARM_POS_TOP_WR 5

//Default Shooter Speed
#define SHO_DEFAULT 42 //Placeholder value; replace later

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
