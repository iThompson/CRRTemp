#ifndef OIMAP_H
#define OIMAP_H

/* Naming scheme for ports:
 * "Subsystem_Type_Function"
 * 
 * Subsystem:
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

// Bridge
#define BRD_DIN_DEPLOY 1

// Drive
#define DRV_JOY_LEFT 1
#define DRV_JOY_RIGHT 2

// Loader
#define LDR_DIN_BTN 2
#define LDR_DIN_BTNA 3
#define LDR_ANA_LEFT 4
#define LDR_ANA_RIGHT 5
#define LDR_ANA_HIGH 6
#define LDR_ANA_LOW 7

// Shooter
#define SHO_DIN_ON 4
#define SHO_DIN_HIGH 1
#define SHO_DIN_RIGHT 2
#define SHO_DIN_LEFT 3
#define SHO_DIN_LOW 4
#define SHO_DIN_FIRE 2
#define SHO_ANA_SPEED 1


#endif // OIMAP_H
