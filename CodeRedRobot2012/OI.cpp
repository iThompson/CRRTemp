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
#include "Commands/JoystickHalfDrive.h"
#include "Commands/JoystickDrive.h"

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
	bridgeButton = new DigitalIOButton(BRD_DIN_DEPLOY);
	acquireButton = new DigitalIOButton(AQS_DIN_BTN);
	acquireButtonA = new DigitalIOButton(AQS_DIN_BTNA);
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
	shootButton->WhileHeld(new ShootOn());
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
