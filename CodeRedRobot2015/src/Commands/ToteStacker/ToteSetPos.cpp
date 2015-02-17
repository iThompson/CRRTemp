// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "ToteSetPos.h"
#include "ResetTote.h"

ToteSetPos::ToteSetPos(int totes):
		m_totes(totes)
{
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::toteStacker);
	Requires(Robot::acquisition);
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// Called just before this Command runs the first time
void ToteSetPos::Initialize() {
	Robot::toteStacker->SetTotes(m_totes);
	Robot::acquisition->SetArmsOpen(true);
	Robot::acquisition->WheelStop();
}

// Called repeatedly when this Command is scheduled to run
void ToteSetPos::Execute() {
	Robot::toteStacker->DriveToPoint();
}

// Make this return true when this Command no longer needs to run execute()
bool ToteSetPos::IsFinished() {
	return Robot::toteStacker->IsAtSetPoint();
}

// Called once after isFinished returns true
void ToteSetPos::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToteSetPos::Interrupted() {

}
