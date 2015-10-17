// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "ToteDriveToOffset.h"

ToteDriveToOffset::ToteDriveToOffset(int offset) :
			m_offset(offset)
{
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::toteStackerNew);
	Requires(Robot::acquisition);
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// Called just before this Command runs the first time
void ToteDriveToOffset::Initialize() {
	SmartDashboard::PutNumber("TOTE ENCODER", Robot::toteStackerNew->GetPos());
	Robot::toteStackerNew->SetManual(Robot::oi->GetAutoManTote());
	if(!Robot::toteStackerNew->GetManual()) {
		Robot::acquisition->SetArmsOpen(true);
		Robot::toteStackerNew->SetResting(false);
		Robot::toteStackerNew->SetOffset(m_offset);
	}
}

// Called repeatedly when this Command is scheduled to run
void ToteDriveToOffset::Execute() {
	Robot::toteStackerNew->SetManual(Robot::oi->GetAutoManTote());
	if(!Robot::toteStackerNew->GetManual()) {
		Robot::toteStackerNew->SetJustManTote(false);
		Robot::toteStackerNew->DriveToPoint();
	}
	else {
		Robot::toteStackerNew->DriveToPoint(Robot::oi->GetDialTote());
		Robot::toteStackerNew->SetOffset(Robot::oi->GetDialTote());
		Robot::toteStackerNew->SetJustManTote(true);
		if(Robot::toteStackerNew->GetPos() < 5000) {
			Robot::acquisition->SetArmsOpen(true);
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ToteDriveToOffset::IsFinished() {
	return Robot::toteStackerNew->IsAtSetPoint();
}

// Called once after isFinished returns true
void ToteDriveToOffset::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToteDriveToOffset::Interrupted() {

}
