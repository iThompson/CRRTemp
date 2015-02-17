// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "SetClawPos.h"

SetClawPos::SetClawPos() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::containerStacker);
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// Called just before this Command runs the first time
void SetClawPos::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void SetClawPos::Execute() {
	SmartDashboard::PutNumber("Encoder container current", Robot::containerStacker->GetCurrentPos());
	SmartDashboard::PutNumber("Error", Robot::containerStacker->GetCurrentError());
	SmartDashboard::PutBoolean("Limit Pressed1", Robot::containerStacker->GetLimit1());
	SmartDashboard::PutBoolean("Limit Pressed2", Robot::containerStacker->GetLimit2());
	SmartDashboard::PutBoolean("Hall container", Robot::containerStacker->Hall());
	if(Robot::containerStacker->GetManual()) {
		Robot::containerStacker->SetPos(Robot::oi->GetDial());
	}
	else {
		Robot::containerStacker->SetPos(Robot::containerStacker->GetTargetPos());
	}
}

// Make this return true when this Command no longer needs to run execute()
bool SetClawPos::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void SetClawPos::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetClawPos::Interrupted() {

}
