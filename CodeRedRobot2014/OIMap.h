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
 * 
 * Type:
 * JOY - Joystick
 * ANA - Analog input
 * DIN - Digital input
 * DOT - Digital output
 * 
 */


//Shooting default times
#define SHO_DEFAULT_TRUSS 1 	//TODO: Dummy Value -- replace later!
#define SHO_DEFAULT_GOAL 1		

//Drive
#define DRV_JOY_LEFT 1
#define DRV_JOY_RIGHT 2

//Shooter
#define SHO_DIN_TRUSS 3			//TODO: Dummy Value -- replace later!
#define SHO_DIN_GOAL 4			
#define SHO_DIN_MAN 5			

//Acquisition
#define ACQ_DIN_RAISE 6			//TODO: Dummy Value -- replace later!
#define ACQ_DIN_LOWER 7
#define ACQ_DIN_AUTO 8
#define ACQ_DIN_MAN 9
#define ACQ_DIN_REVERSE 10
#define ACQ_DIN_EJECT 11


#endif
