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
#include "InvertedIOButton.h"
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
#include "Commands/Ejection/ExtendKicker.h"
#include "Commands/Ejection/RetractKicker.h"
#include "Commands/EjectBall.h"


OI::OI() {
	// Process operator interface input here.

	m_lStick = new Joystick(DRV_JOY_LEFT);
	m_rStick = new Joystick(DRV_JOY_RIGHT);
	
	m_driveHighBtn = new JoystickButton(m_rStick, 1); // Trigger on the right stick
	m_driveLowBtn = new JoystickButton(m_lStick, 1);
	m_driveAutoStop = new JoystickButton(m_rStick, 2);
	
	m_shootTrussBtn = new InvertedIOButton(SHO_DIN_TRUSS);
	m_shootGoalBtn = new InvertedIOButton(SHO_DIN_GOAL);
	m_shootManualBtn = new InvertedIOButton(SHO_DIN_MAN);
	
	m_ejectBtn = new InvertedIOButton(ACQ_DIN_EJECT);
	m_armPositionBtn = new DigitalIOButton(ACQ_DIN_ARM);
	m_acquisitionAutoBtn = new DigitalIOButton(ACQ_DIN_AUTO);
	m_acquisitionManualBtn = new DigitalIOButton(ACQ_DIN_MAN);
	m_acquisitionDirectionBtn = new DigitalIOButton(ACQ_DIN_DIR);
	
	//Separation comment to make it easier to read
	
	m_driveHighBtn->WhenPressed(new ShiftHigh());
	m_driveLowBtn->WhenPressed(new ShiftLow());
	
    m_shootTrussBtn->WhenPressed(new Fire(SHO_DEFAULT_TRUSS));
    m_shootGoalBtn->WhenPressed(new Fire(SHO_DEFAULT_GOAL));
    m_shootManualBtn->WhenPressed(new Fire(Robot::oi->GetManualFire()));
    
    m_armPositionBtn->WhenPressed(new ArmRaise());
    m_armPositionBtn->WhenReleased(new ArmLower());
    m_ejectBtn->WhenPressed(new EjectBall());
    m_acquisitionAutoBtn->WhileHeld(new RollerSpin(false, IsReversed()));
    m_acquisitionManualBtn->WhileHeld(new RollerSpin(true, IsReversed()));

    // SmartDashboard Buttons
	SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());

	SmartDashboard::PutData("JoystickDrive", new JoystickDrive());

	SmartDashboard::PutData("JoystickAutoDrive", new JoystickAutoDrive(0,0)); //TODO: Replace dummy values

	SmartDashboard::PutData("ShiftHigh", new ShiftHigh());

	SmartDashboard::PutData("ShiftLow", new ShiftLow());

	SmartDashboard::PutData("Fire", new Fire(1)); //TODO: Replace potential dummy value

	SmartDashboard::PutData("RollerSpin", new RollerSpin(false, false)); //TODO: Replace potential dummy value

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
	return DriverStation::GetInstance()->GetEnhancedIO().GetAnalogInRatio(1); 
}

double OI::GetManualFire() {
	return DriverStation::GetInstance()->GetEnhancedIO().GetAnalogInRatio(2); 
}

bool OI::IsReversed(){
	return m_acquisitionDirectionBtn->Get();
}
bool OI::IsAutoStop(){
	return m_driveAutoStop->Get();
}

