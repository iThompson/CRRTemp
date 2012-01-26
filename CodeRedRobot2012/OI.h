#ifndef OI_H
#define OI_H
#include "DriverStationEnhancedIO.h"
#include "WPILib.h"

class OI {
private:
	AnalogChannel *shooterDial;
	
	DriverStationEnhancedIO *m_dsio;

public:
	OI();
	AnalogChannel *getDial();
};

#endif
