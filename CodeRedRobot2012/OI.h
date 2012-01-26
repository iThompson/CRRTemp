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

public:
	OI();
	AnalogChannel *getDial();
	DigitalInput *getSwitch();
	
};

#endif
