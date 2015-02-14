// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "OI.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/HalfSpeedToggle.h"
#include "Commands/JoystickAutoDrive.h"
#include "Commands/JoystickHDrive.h"
#include "Commands/JoystickHDriveField.h"
#include "Commands/LowerCenterWheel.h"
#include "Commands/RaiseCenterWheel.h"
#include "Commands/NOSToggle.h"
#include "Commands/ZeroHeading.h"
#include "Commands/HoldTest.h"

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

OI::OI() {
	// Process operator interface input here.
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

	sStick = new Joystick(1);
	cStick = new Joystick(0);
	
	m_halfSpeed = new JoystickButton(sStick, 1);
	m_raiseWheel = new JoystickButton(sStick, 4);
	m_lowerWheel = new JoystickButton(sStick, 3);
	//m_NOS = new JoystickButton(sStick, 2);
	m_resetDirection = new JoystickButton(sStick, 10);
	m_zero = new JoystickButton(sStick, 2);
	m_holdTest = new InvertedIOButton(cStick, 19);

	m_halfSpeed->WhenPressed(new HalfSpeedToggle());
	m_halfSpeed->WhenReleased(new HalfSpeedToggle());
	m_raiseWheel->WhenPressed(new RaiseCenterWheel());
	m_lowerWheel->WhenPressed(new LowerCenterWheel());
	m_resetDirection->WhenPressed(new ZeroHeading());
	//m_NOS->WhenPressed(new NOSToggle());
	m_zero->WhenPressed(new ZeroHeading());
	m_holdTest->WhileHeld(new HoldTest());

        // SmartDashboard Buttons
	SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());
        // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

Joystick* OI::getsStick() {
	return sStick;
}

double OI::GetSingleY() {
	double magnitude = sStick->GetY();
	SmartDashboard::PutNumber("Y value", magnitude);
	if(magnitude > .01 || magnitude < -.01) return magnitude;
	else return 0;
}

double OI::GetSingleX() {
	double magnitude = sStick->GetX();
	SmartDashboard::PutNumber("X value", magnitude);
	if(magnitude > .01 || magnitude < -.01) return magnitude;
	else return 0;
}

double OI::GetSingleTwist() {
	double magnitude = sStick->GetThrottle();
	SmartDashboard::PutNumber("Twist value", magnitude);
	if(magnitude > .01 || magnitude < -.01) return magnitude;
	else return 0;
}

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
