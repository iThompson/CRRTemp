#ifndef OI_H
#define OI_H
#include "DriverStationEnhancedIO.h"
#include "WPILib.h"
#include "DigitalInput.h"

class OI {
private:
	AnalogChannel *shooterDial;
	DriverStationEnhancedIO *m_dsio;
	DigitalInput *acquisitionSwitch;
	static const int LEFT_STICK_PORT = 1;
	static const int RIGHT_STICK_PORT = 2;
	
	Joystick *lStick;
	Joystick *rStick;

public:
	OI();
	AnalogChannel *getDial();
	DigitalInput *getSwitch();
	Joystick *GetStickL();
	Joystick *GetStickR();
	
};

#endif
