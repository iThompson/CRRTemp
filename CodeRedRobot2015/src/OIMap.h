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
#define CST_ANA_MAN_CTRL 1 // ☢ WATCH OUT: REPLACE DUMMY VALUE ☢
#define CST_DIN_MAN_AUTO 2
#define CST_DIN_UP 4
#define CST_DIN_DOWN 5
#define CST_DIN_PLAT_TOG 6
#define CST_DIN_CLAW 7

//Tote stacker
#define TST_DIN_UP 1
#define TST_DIN_DOWN 2
#define TST_DIN_PCKUP 3
#define TST_DIN_PLAT 4
#define TST_DIN_STEP 5

//Acquisition
#define ACQ_DIN_IN 1
#define ACQ_DIN_POS 2
#define ACQ_DIN_OUT 3

//Drive
#define DRV_DIN_CNTR_UP 1
#define DRV_DIN_CNTR_DOWN 2

#endif
