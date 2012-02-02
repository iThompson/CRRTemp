#ifndef OIMAP_H
#define OIMAP_H

/* Naming scheme for ports:
 * "Subsystem_Type_Function"
 * 
 * Subsystem:
 * AQS - Acquisition
 * BRG - Bridge
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

// Acquisition
#define AQS_DIN_BTN 2
#define AQS_DIN_BTNA 3

// Bridge
#define BRD_DIN_DEPLOY 1

// Drive
#define DRV_JOY_LEFT 1
#define DRV_JOY_RIGHT 2

// Loader

// Shooter
#define SHO_DIN_ON 4
#define SHO_DIN_FIRE 5
#define SHO_DIN_HIGH 1
#define SHO_DIN_RIGHT 2
#define SHO_DIN_LEFT 3
#define SHO_DIN_LOW 4


#endif
