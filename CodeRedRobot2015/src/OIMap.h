#ifndef OIMAP_H
#define OIMAP_H

/* Naming scheme for ports:
* "Subsystem_Type_Function"
*
* Subsystem:
* ACQ - Acquisition
* DRV - Drive
* RBT - No subsystem
* TST - Tote stacker
*
* CST - Container stacker
* WNG - Wings
*
* JOY - Joystick
* ANA - Analog input
* DIN - Digital input
* DOT - Digital output
*/
//Container stacker
#define CST_DIN_MAN_AUTO 2
#define CST_DIN_UP 4
#define CST_DIN_DOWN 6
#define CST_DIN_PLAT_TOG 5
#define CST_DIN_CLAW 3

//Tote stacker
#define TST_DIN_UP 11
#define TST_DIN_DOWN 19
#define TST_DIN_PCKUP 13
#define TST_DIN_PLAT 20
#define TST_DIN_STEP 12

//Acquisition
#define ACQ_DIN_IN 13
#define ACQ_DIN_POS 7
#define ACQ_DIN_OUT 1

//Drive
#define DRV_DIN_CNTR_UP 1
#define DRV_DIN_CNTR_DOWN 2

#endif
