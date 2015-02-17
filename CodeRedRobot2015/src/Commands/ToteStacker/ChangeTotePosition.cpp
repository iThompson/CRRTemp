// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "ChangeTotePosition.h"

ChangeTotePosition::ChangeTotePosition(int changeInTotes):
		m_changeInTotes(changeInTotes)
{
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::toteStacker);
	Requires(Robot::acquisition);
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// Called just before this Command runs the first time
void ChangeTotePosition::Initialize() {
	Robot::toteStacker->SetTotes(Robot::toteStacker->GetTotes() + m_changeInTotes);
	Robot::acquisition->SetArmsOpen(true);
}

// Called repeatedly when this Command is scheduled to run
void ChangeTotePosition::Execute() {
	Robot::toteStacker->DriveToPoint();
}

// Make this return true when this Command no longer needs to run execute()
bool ChangeTotePosition::IsFinished() {
	return Robot::toteStacker->IsAtSetPoint();
}

// Called once after isFinished returns true
void ChangeTotePosition::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ChangeTotePosition::Interrupted() {

}
