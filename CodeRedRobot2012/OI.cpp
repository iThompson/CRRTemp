#include "OI.h"
#include "Robotmap.h"
#include "Subsystems/Shooter.h"
#include "Commands/ShiftHigh.h"
#include "Commands/ShiftLow.h"
#include "Commands/Deploy.h"

OI::OI() {
	m_dsio = &DriverStation::GetInstance()->GetEnhancedIO();
	lStick = new Joystick(LEFT_STICK_PORT);
	rStick = new Joystick(RIGHT_STICK_PORT);
	highGear = new JoystickButton(rStick,1);
	lowGear = new JoystickButton(lStick,1);
	bridgeButton = new AnalogIOButton(BRIDGE_BUTTON);
	
	highGear->WhenPressed(new ShiftHigh());
	lowGear->WhenPressed(new ShiftLow());
	bridgeButton->WhileHeld(new Deploy());
	
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

