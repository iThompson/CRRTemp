#ifndef OIMAP_H
#define OIMAP_H

/* Naming scheme for ports:
 * "Subsystem_Type_Function"
 * 
 * Subsystem:
 * GTE - Gate
 * DRV - Drive
 * LDR - Loader
 * RBT - No subsystem
 * SHO - Shooter
 * 
 * Type:
 * JOY - Joystick
 * ANA - Analog input
 * DIN - Digital input
 * DOT - Digital output
 * 
 */

// Gate
#define GTE_DIN_DEPLOY 8
#define GTE_DIN_UNDEP 6

// Drive
#define DRV_JOY_LEFT 1
#define DRV_JOY_RIGHT 2

// Loader
#define LDR_DIN_BTN 14
#define LDR_DIN_BTNA 16
//Loader--the below are still random numbers
#define LDR_ANA_LEFT 2
#define LDR_ANA_RIGHT 3
#define LDR_ANA_HIGH 1
#define LDR_ANA_LOW 4

// Shooter
#define SHO_ANA_SPEED 2
#define SHO_DIN_ON 4 // still a random number
#define SHO_DIN_HIGH 1
#define SHO_DIN_LEFT 2
#define SHO_DIN_RIGHT 3
#define SHO_DIN_LOW 4
#define SHO_DIN_FIRE 5
#define SHO_DIN_AUTO 10
#define SHO_DIN_MAN 12

#endif // OIMAP_H
