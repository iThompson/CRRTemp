#ifndef OI_H
#define OI_H
#include "DriverStationEnhancedIO.h"
#include "WPILib.h"
#include "DigitalInput.h"
#include "OIMap.h"

class OI {
private:
	AnalogChannel *shooterDial;
	DriverStationEnhancedIO *m_dsio;
	DigitalInput *acquisitionSwitch;
	static const int LEFT_STICK_PORT = 1;
	static const int RIGHT_STICK_PORT = 2;
	
	Joystick *lStick;
	Joystick *rStick;
	JoystickButton *highGear;
	JoystickButton *lowGear;
	Button *bridgeButton;
	Button *acquireButton;
	Button *acquireButtonA;
	
	

public:
	OI();
	AnalogChannel *getDial();
	DigitalInput *getSwitch();
	Joystick *GetStickL();
	Joystick *GetStickR();
	
};

#endif
