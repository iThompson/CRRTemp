#include "OI.h"
#include "Commands/AutonDrive.h"
#include "Commands/Drive/AlignDrive.h"
#include "Commands/Drive/ShiftHigh.h"
#include "Commands/Drive/ShiftLow.h"
#include "Commands/Gate/Deploy.h"
#include "Commands/Gate/Undeploy.h"
#include "Commands/Gate/GateAuto.h"
#include "Commands/Acquirer/RunBelt.h"
#include "Commands/Acquirer/ReverseBelt.h"
#include "Commands/Acquirer/StopBelt.h"
#include "Commands/Shooter/Shoot.h"
#include "Commands/Shooter/ShootOff.h"
#include "Commands/Shooter/ShootManual.h"
#include "Commands/Shooter/ShootAuto.h"
#include "Commands/Loader/Fire.h"
#include "Commands/Loader/LoaderOpen.h"
#include "Commands/Loader/LoaderLock.h"
#include "Commands/Vision/AimHigh.h"
#include "Commands/Vision/AimRight.h"
#include "Commands/Vision/AimLeft.h"
#include "Commands/Vision/AimLow.h"
#include "Commands/Vision/TrimLeft.h"
#include "Commands/Vision/TrimRight.h"
#include "Commands/Drive/JoystickHalfDrive.h"
#include "Commands/Drive/JoystickDrive.h"

#include "Commands/ToggleLower.h"
#include "Commands/ToggleUpper.h"

#include "InvertedIOButton.h"

#include "OIMap.h"


OI::OI() :
		m_dsio(DriverStation::GetInstance()->GetEnhancedIO())
	{
	// Declare joysticks
	lStick = new Joystick(DRV_JOY_LEFT);
	rStick = new Joystick(DRV_JOY_RIGHT);
	// Declare joystick buttons
	highGear = new JoystickButton(rStick,1);
	lowGear = new JoystickButton(lStick,1);
//	fireButton = new JoystickButton(lStick,2);
	halfDrive = new JoystickButton(rStick,3);
	drive = new JoystickButton(rStick,2);

	Button* joyBridge = new JoystickButton(lStick, 2);
//	acquireButton = new JoystickButton(lStick, 6);
//	acquireButtonB = new JoystickButton(lStick, 7);
//	
//	shootManual = new JoystickButton(rStick, 9);
	
//	bridgeButtonC = new JoystickButton(lStick, 9);
//	
	Button* openLoader = new JoystickButton(lStick, 10);
	Button* closeLoader = new JoystickButton(lStick, 11);
	Button* autoAim = new JoystickButton(lStick, 3);
	Button* trimLeft = new JoystickButton(lStick, 4);
	Button* trimRight = new JoystickButton(rStick, 5);
	Button* revDrv = new JoystickButton(lStick, 8);
	
	openLoader->WhenPressed(new ToggleLower());
	closeLoader->WhenPressed(new ToggleUpper());
	
	autoAim->WhileHeld(new AlignDrive());
	
	trimLeft->WhenPressed(new TrimLeft());
	trimRight->WhenPressed(new TrimRight());
	
	revDrv->WhileHeld(new AutonDrive(-.3, -.3));
	
	// Declare other buttons/switches
	bridgeButtonC = new DigitalIOButton(GTE_DIN_DEPLOY);
	bridgeButtonO = new DigitalIOButton(GTE_DIN_UNDEP);
	acquireButton = new DigitalIOButton(LDR_DIN_BTN);
	acquireButtonB = new DigitalIOButton(LDR_DIN_BTNA);
//	shootButton = new DigitalIOButton(SHO_DIN_ON);
	aimHigh = new InvertedIOButton(SHO_DIN_HIGH);
	aimRight = new InvertedIOButton(SHO_DIN_RIGHT);
	aimLeft = new InvertedIOButton(SHO_DIN_LEFT);
	aimLow = new InvertedIOButton(SHO_DIN_LOW);
	fireButton = new DigitalIOButton(SHO_DIN_FIRE);
	shootManual = new DigitalIOButton(SHO_DIN_MAN);
	shootAuto = new DigitalIOButton(SHO_DIN_AUTO);
//	
//	// Declare button funtions
	shootManual->WhileHeld(new ShootManual());
	shootAuto->WhileHeld(new ShootAuto());
	
	// NOTE: These will cancel HalfDrive or AlignDrive and revert the drivetrain to JoystickDrive
	highGear->WhenPressed(new ShiftHigh());
	lowGear->WhenPressed(new ShiftLow());
	
	// Joysticks have the ability to override the Operator's bridge controls
	joyBridge->WhileHeld(new Deploy());
	joyBridge->WhenReleased(new Undeploy());
	bridgeButtonC->WhenPressed(new Deploy());
	bridgeButtonC->WhenReleased(new Undeploy());
//	bridgeButtonO->WhileHeld(new GateAuto());
	
	// Acquisition will be controlled purely manually most likely
	acquireButton->WhileHeld(new RunBelt(true));
	acquireButtonB->WhileHeld(new ReverseBelt(true));
	
	//shootButton->WhileHeld(new Shoot());
	fireButton->WhenPressed(new Fire());
	
	// Vision control buttons
	aimHigh->WhenPressed(new AimHigh());
	aimRight->WhenPressed(new AimRight());
	aimLeft->WhenPressed(new AimLeft());
	aimLow->WhenPressed(new AimLow());
	
	halfDrive->WhenPressed(new JoystickHalfDrive());
	drive->WhenPressed(new JoystickDrive());
}

double OI::GetDial() {
	return 1 - m_dsio.GetAnalogInRatio(SHO_ANA_SPEED);
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
