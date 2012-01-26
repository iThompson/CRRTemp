#include "OI.h"
#include "Robotmap.h"

OI::OI() {
	shooterDial = new AnalogChannel(DIAL_PORT);
	
	m_dsio = &DriverStation::GetInstance()->GetEnhancedIO();
}
AnalogChannel *OI::getDial() {
	return shooterDial;
}
