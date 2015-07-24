#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	static const int LEFT_STICK_PORT = 1;
	static const int RIGHT_STICK_PORT = 2;
	
	Joystick *lStick;
	Joystick *rStick;

public:
	OI();
	Joystick *GetStickL();
	Joystick *GetStickR();
};

#endif
