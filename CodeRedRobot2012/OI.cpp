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
#include "Commands/Fire.h"
#include "Commands/AimHigh.h"
#include "Commands/AimRight.h"
#include "Commands/AimLeft.h"
#include "Commands/AimLow.h"

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
	fireButton = new DigitalIOButton(FIRE);
	aimHigh = new DigitalIOButton(AIM_HIGH);
	aimRight = new DigitalIOButton(AIM_RIGHT);
	aimLeft = new DigitalIOButton(AIM_LEFT);
	aimLow = new DigitalIOButton(AIM_LOW);
	
	highGear->WhenPressed(new ShiftHigh());
	lowGear->WhenPressed(new ShiftLow());
	bridgeButton->WhileHeld(new Deploy());
	acquireButton->WhenPressed(new RunBelt());
	acquireButtonA->WhenPressed(new StopBelt());
	shootButton->WhileHeld(new ShootOn());
	fireButton->WhenPressed(new Fire());
	aimHigh->WhenPressed(new AimHigh());
	aimRight->WhenPressed(new AimRight());
	aimLeft->WhenPressed(new AimLeft());
	aimLow->WhenPressed(new AimLow());
	
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

