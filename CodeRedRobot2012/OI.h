#ifndef OI_H
#define OI_H
#include "DriverStationEnhancedIO.h"
#include "WPILib.h"

class OI {
private:
	double *shooterDial;
	
	DriverStationEnhancedIO *m_dsio;

public:
	OI();
	double getDial();
};

#endif
