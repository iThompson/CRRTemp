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
#define CST_ANA_MANCTRL 1 // ☢ WATCH OUT: REPLACE DUMMY VALUE ☢
#define CST_DIN_MANAUTO 2

#define CST_DIN_SWTCH1 3
#define CST_DIN_SWTCH2 3
#define CST_DIN_SWTCH3 3
#define CST_DIN_SWTCH4 3
#define CST_DIN_SWTCH5 3

#define CST_DIN_GOTO 4
#define CST_DIN_TOGCLAW 5

//Tote stacker
#define TST_DIN_UP 1
#define TST_DIN_DOWN 2
#define TST_DIN_PCKUP 3
#define TST_DIN_PLTFRM 4
#define TST_DIN_STEP 5

//Acquisition
#define ACQ_DIN_INTOTE 1
#define ACQ_DIN_TOGGLE 2
#define ACQ_DIN_OUTTOTE 3


#endif
