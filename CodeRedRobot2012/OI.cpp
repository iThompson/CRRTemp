#include "OI.h"
#include "Robotmap.h"
#include "Subsystems/Shooter.h"

OI::OI() {
	shooterDial = new AnalogChannel(DIAL_PORT);
	m_dsio = &DriverStation::GetInstance()->GetEnhancedIO();
	acquisitionSwitch = new DigitalInput(SWITCH);
}
AnalogChannel *OI::getDial() {
	return shooterDial;
}
