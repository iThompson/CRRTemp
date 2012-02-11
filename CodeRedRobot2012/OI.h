#ifndef OI_H
#define OI_H
#include "DriverStationEnhancedIO.h"
#include "WPILib.h"
#include "DigitalInput.h"
#include "OIMap.h"

class OI {
private:
	DriverStationEnhancedIO& m_dsio;
	
	Joystick *lStick;
	Joystick *rStick;
		
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
	Button *m_halfDrive;
	Button *m_drive;
	

public:
	OI();
	double getDial();
	
	double GetYLeft();
	double GetYRight();
	
};

#endif
