#include "OI.h"
#include "Robotmap.h"

OI::OI() {
	shooterDial = new AnalogChannel(DIAL_PORT);
	m_dsio = &DriverStation::GetInstance()->GetEnhancedIO();
	acquisitionSwitch = new DigitalInput(SWITCH);
}
AnalogChannel *OI::getDial() {
	return shooterDial;
}


