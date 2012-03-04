#include "OI.h"
#include "Commands/AlignDrive.h"

OI::OI() {
	lStick = new Joystick(LEFT_STICK_PORT);
	rStick = new Joystick(RIGHT_STICK_PORT);
	
	Button* align = new JoystickButton(rStick, 3);
	align->WhileHeld(new AlignDrive());
}

Joystick *OI::GetStickL() {
	return lStick;
}

Joystick *OI::GetStickR() {
	return rStick;
}
