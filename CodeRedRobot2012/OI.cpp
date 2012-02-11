#include "OI.h"
#include "Commands/Drive/ShiftHigh.h"
#include "Commands/Drive/ShiftLow.h"
#include "Commands/Gate/Deploy.h"
#include "Commands/Loader/RunBelt.h"
#include "Commands/Loader/StopBelt.h"
#include "Commands/Shooter/Shoot.h"
#include "Commands/Shooter/ShootOff.h"
#include "Commands/Loader/Fire.h"
#include "Commands/Vision/AimHigh.h"
#include "Commands/Vision/AimRight.h"
#include "Commands/Vision/AimLeft.h"
#include "Commands/Vision/AimLow.h"
#include "Commands/Drive/JoystickHalfDrive.h"
#include "Commands/Drive/JoystickDrive.h"

OI::OI() :
		m_dsio(DriverStation::GetInstance()->GetEnhancedIO())
	{
	// Declare joysticks
	lStick = new Joystick(DRV_JOY_LEFT);
	rStick = new Joystick(DRV_JOY_RIGHT);
	// Declare joystick buttons
	highGear = new JoystickButton(rStick,1);
	lowGear = new JoystickButton(lStick,1);
	fireButton = new JoystickButton(lStick,2);
	m_halfDrive = new JoystickButton(rStick,2);
	m_drive = new JoystickButton(rStick,3);
	
	// Declare other buttons/switches
	bridgeButton = new DigitalIOButton(GTE_DIN_DEPLOY);
	acquireButton = new DigitalIOButton(LDR_DIN_BTN);
	acquireButtonA = new DigitalIOButton(LDR_DIN_BTNA);
	shootButton = new DigitalIOButton(SHO_DIN_ON);
	aimHigh = new DigitalIOButton(SHO_DIN_HIGH);
	aimRight = new DigitalIOButton(SHO_DIN_RIGHT);
	aimLeft = new DigitalIOButton(SHO_DIN_LEFT);
	aimLow = new DigitalIOButton(SHO_DIN_LOW);
	fireButton = new DigitalIOButton(SHO_DIN_FIRE);
	
	// Declare button funtions
	highGear->WhenPressed(new ShiftHigh());
	lowGear->WhenPressed(new ShiftLow());
	bridgeButton->WhileHeld(new Deploy());
	acquireButton->WhenPressed(new RunBelt());
	acquireButtonA->WhenPressed(new StopBelt());
	shootButton->WhileHeld(new Shoot());
	fireButton->WhenPressed(new Fire());
	aimHigh->WhenPressed(new AimHigh());
	aimRight->WhenPressed(new AimRight());
	aimLeft->WhenPressed(new AimLeft());
	aimLow->WhenPressed(new AimLow());
	m_halfDrive->WhenPressed(new JoystickHalfDrive());
	m_drive->WhenPressed(new JoystickDrive());
	
}

double OI::getDial() {
	return m_dsio.GetAnalogInRatio(SHO_ANA_SPEED);
}

double OI::GetYLeft() {
	return lStick->GetY();
}

double OI::GetYRight() {
	return rStick->GetY();
}
