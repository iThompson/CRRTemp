#include "OI.h"
#include "Robotmap.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/Acquirer.h"
#include "Commands/ShiftHigh.h"
#include "Commands/ShiftLow.h"
#include "Commands/Deploy.h"
#include "Commands/RunBelt.h"
#include "Commands/StopBelt.h"
#include "Commands/ShootOn.h"
#include "Commands/ShootOff.h"

OI::OI() {
	m_dsio = &DriverStation::GetInstance()->GetEnhancedIO();
	lStick = new Joystick(LEFT_STICK_PORT);
	rStick = new Joystick(RIGHT_STICK_PORT);
	highGear = new JoystickButton(rStick,1);
	lowGear = new JoystickButton(lStick,1);
	bridgeButton = new DigitalIOButton(BRIDGE_BUTTON);
	acquireButton = new DigitalIOButton(ACQUIRE_BUTTON);
	acquireButtonA = new DigitalIOButton(ACQUIRE_BUTTONA);
	shootButton = new DigitalIOButton(SHOOT_ONOFF);
	
	highGear->WhenPressed(new ShiftHigh());
	lowGear->WhenPressed(new ShiftLow());
	bridgeButton->WhileHeld(new Deploy());
	acquireButton->WhenPressed(new RunBelt());
	acquireButtonA->WhenPressed(new StopBelt());
	shootButton->WhileHeld(new ShootOn());
	
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

