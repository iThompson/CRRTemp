#include "OI.h"
#include "OIMap.h"
#include "Robotmap.h"

OI::OI() {
	shooterDial = new double(DIAL_PORT);
	
	m_dsio = &DriverStation::GetInstance()->GetEnhancedIO();
}
double OI::getDial() {
	
	return *shooterDial;	
}
