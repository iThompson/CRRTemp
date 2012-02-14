#include "OI.h"
#include "Commands/Drive/ShiftHigh.h"
#include "Commands/Drive/ShiftLow.h"
#include "Commands/Gate/Deploy.h"
#include "Commands/Acquirer/RunBelt.h"
#include "Commands/Acquirer/ReverseBelt.h"
#include "Commands/Acquirer/StopBelt.h"
#include "Commands/Shooter/Shoot.h"
#include "Commands/Shooter/ShootOff.h"
#include "Commands/Shooter/ShootManual.h"
#include "Commands/Shooter/ShootAuto.h"
#include "Commands/Loader/Fire.h"
#include "Commands/Vision/AimHigh.h"
#include "Commands/Vision/AimRight.h"
#include "Commands/Vision/AimLeft.h"
#include "Commands/Vision/AimLow.h"
#include "Commands/Drive/JoystickHalfDrive.h"
#include "Commands/Drive/JoystickDrive.h"
#include "Commands/Gate/Undeploy.h"


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
	halfDrive = new JoystickButton(rStick,2);
	drive = new JoystickButton(rStick,3);
	
	acquireButton = new JoystickButton(lStick, 6);
	acquireButtonB = new JoystickButton(lStick, 7);
	
	shootManual = new JoystickButton(rStick, 9);
	
	// Declare other buttons/switches
//	bridgeButtonC = new DigitalIOButton(GTE_DIN_DEPLOY);
//	bridgeButtonO = new DigitalIOButton(GTE_DIN_UNDEP);
//	acquireButton = new DigitalIOButton(LDR_DIN_BTN);
//	acquireButtonB = new DigitalIOButton(LDR_DIN_BTNA);
//	shootButton = new DigitalIOButton(SHO_DIN_ON);
//	aimHigh = new DigitalIOButton(SHO_DIN_HIGH);
//	aimRight = new DigitalIOButton(SHO_DIN_RIGHT);
//	aimLeft = new DigitalIOButton(SHO_DIN_LEFT);
//	aimLow = new DigitalIOButton(SHO_DIN_LOW);
//	fireButton = new DigitalIOButton(SHO_DIN_FIRE);
//	shootManual = new DigitalIOButton(SHO_DIN_MAN);
//	shootAuto = new DigitalIOButton(SHO_DIN_AUTO);
//	
//	// Declare button funtions
//	highGear->WhenPressed(new ShiftHigh());
//	lowGear->WhenPressed(new ShiftLow());
//	bridgeButtonC->WhileHeld(new Deploy());
//	bridgeButtonO->WhileHeld(new Undeploy());
//	acquireButton->WhileHeld(new RunBelt(true));
//	acquireButtonB->WhileHeld(new ReverseBelt(true));
	acquireButton->WhenPressed(new RunBelt(true));
	acquireButtonB->WhenPressed(new StopBelt());
//	shootButton->WhileHeld(new Shoot());
//	fireButton->WhenPressed(new Fire());
//	aimHigh->WhenPressed(new AimHigh());
//	aimRight->WhenPressed(new AimRight());
//	aimLeft->WhenPressed(new AimLeft());
//	aimLow->WhenPressed(new AimLow());
//	halfDrive->WhenPressed(new JoystickHalfDrive());
//	drive->WhenPressed(new JoystickDrive());
	shootManual->WhileHeld(new ShootManual());
//	shootAuto->WhileHeld(new ShootAuto());
//	
}

double OI::GetDial() {
	//return m_dsio.GetAnalogInRatio(SHO_ANA_SPEED);
	
	return (rStick->GetZ() + 1) / 2;
}

double OI::GetAqsSpeed() {
	return (lStick->GetZ() + 1) / 2;
}

double OI::GetYLeft() {
	return lStick->GetY();
}

double OI::GetYRight() {
	return rStick->GetY();
}
