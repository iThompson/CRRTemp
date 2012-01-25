#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	RotaryPotentiometer *shooterDial;

public:
	OI();
	RotaryPotentiometer *getDial();
};

#endif
