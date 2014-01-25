// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "OI.h"

#include "SmartDashboard/SmartDashboard.h"
#include "Commands/Acquisition/ArmLower.h"
#include "Commands/Acquisition/ArmRaise.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/Shooter/Fire.h"
#include "Commands/Drive/JoystickAutoDrive.h"
#include "Commands/Drive/JoystickDrive.h"
#include "Commands/Acquisition/RollerSpin.h"
#include "Commands/Acquisition/RollerStop.h"
#include "Commands/Drive/ShiftHigh.h"
#include "Commands/Drive/ShiftLow.h"


OI::OI() {
	// Process operator interface input here.

	m_lStick = new Joystick(DRV_JOY_LEFT);
	m_rStick = new Joystick(DRV_JOY_RIGHT);
	
	m_driveHighBtn = new JoystickButton(m_rStick, 1);
	m_driveHighBtn->WhenPressed(new ShiftHigh());
	
	m_driveLowBtn = new JoystickButton(m_lStick, 1);
	m_driveLowBtn->WhenPressed(new ShiftLow());
     

    // SmartDashboard Buttons
	SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());

	SmartDashboard::PutData("JoystickDrive", new JoystickDrive());

	SmartDashboard::PutData("JoystickAutoDrive", new JoystickAutoDrive(0,0));

	SmartDashboard::PutData("ShiftHigh", new ShiftHigh());

	SmartDashboard::PutData("ShiftLow", new ShiftLow());

	SmartDashboard::PutData("Fire", new Fire(1)); //TODO: Replace potential dummy value

	SmartDashboard::PutData("RollerSpin", new RollerSpin(1)); //TODO: Replace potential dummy value

	SmartDashboard::PutData("RollerStop", new RollerStop());

	SmartDashboard::PutData("ArmRaise", new ArmRaise());

	SmartDashboard::PutData("ArmLower", new ArmLower());

}

double OI::GetYLeft() {
	return m_lStick->GetY();
}

double OI::GetYRight() {
	return m_rStick->GetY();
}

double OI::GetRollerSpeed() {
	return 0; //TODO: Replace with actual call once we get the button
}
