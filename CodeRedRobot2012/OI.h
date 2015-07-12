#ifndef OI_H
#define OI_H
#include "DriverStationEnhancedIO.h"
#include "WPILib.h"
#include "DigitalInput.h"

class OI {
private:
	DriverStationEnhancedIO& m_dsio;
	
	Joystick *lStick;
	Joystick *rStick;
	
	Button *highGear;
	Button *lowGear;
	Button *bridgeButtonC;
	Button *bridgeButtonO;
	Button *acquireButton;
	Button *acquireButtonB;
	Button *shootButton;
	Button *fireButton;
	Button *aimLow;
	Button *aimHigh;
	Button *aimLeft;
	Button *aimRight;
	Button *halfDrive;
	Button *drive;
	Button *shootManual;
	Button *shootAuto;
	Button *safeMode;
	

public:
	OI();
	double GetDial();
	
	double GetAqsSpeed();
	int GetAqsState();
	
	bool GetFireButton();
	
	bool GetAllowFire();
	
	double GetYLeft();
	double GetYRight();
	
};

#endif
