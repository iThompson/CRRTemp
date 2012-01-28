#include "OI.h"
#include "Robotmap.h"
#include "Subsystems/Shooter.h"

OI::OI() {
	shooterDial = new AnalogChannel(DIAL_PORT);
	m_dsio = &DriverStation::GetInstance()->GetEnhancedIO();
	acquisitionSwitch = new DigitalInput(SWITCH);
	lStick = new Joystick(LEFT_STICK_PORT);
	rStick = new Joystick(RIGHT_STICK_PORT);
}
AnalogChannel *OI::getDial() {
	return shooterDial;
}
Joystick *OI::GetStickL() {
	return lStick;
}

Joystick *OI::GetStickR() {
	return rStick;
}

