#ifndef OI_H
#define OI_H
#include "DriverStationEnhancedIO.h"
#include "WPILib.h"
#include "DigitalInput.h"
#include "OIMap.h"

class OI {
private:
	AnalogChannel *shooterDial;
	DriverStationEnhancedIO& m_dsio;
	DigitalInput *acquisitionSwitch;
	
	Joystick *lStick;
	Joystick *rStick;
	
	JoystickButton *m_halfDrive;
	JoystickButton *m_drive;
	
	Button *highGear;
	Button *lowGear;
	Button *bridgeButton;
	Button *acquireButton;
	Button *acquireButtonA;
	Button *shootButton;
	Button *fireButton;
	Button *aimLow;
	Button *aimHigh;
	Button *aimLeft;
	Button *aimRight;

public:
	OI();
	AnalogChannel *getDial();
	DigitalInput *getSwitch();
	
	double GetYLeft();
	double GetYRight();
	
};

#endif
