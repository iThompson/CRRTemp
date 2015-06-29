// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "JoystickToteNew.h"

JoystickToteNew::JoystickToteNew() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::toteStackerNew);
	Requires(Robot::drive);

	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// Called just before this Command runs the first time
void JoystickToteNew::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void JoystickToteNew::Execute() {
	SmartDashboard::PutNumber("TOTE ENCODER", Robot::toteStackerNew->GetPos());
	Robot::toteStackerNew->SetSpeed(Robot::oi->GetSingleY());
	Robot::drive->HDrive(0,0,0);
	SmartDashboard::PutBoolean("Interrupted", false);
}

// Make this return true when this Command no longer needs to run execute()
bool JoystickToteNew::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void JoystickToteNew::End() {
	SmartDashboard::PutBoolean("Interrupted", true);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void JoystickToteNew::Interrupted() {
	SmartDashboard::PutBoolean("Interrupted", true);
}
