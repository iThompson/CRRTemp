// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "AccelControl.h"
#define RAMP_CONSTANT 2

AccelControl::AccelControl() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::drive);
//	Requires(Robot::sensors);
	Requires(Robot::containerStacker);
	Requires(Robot::toteStacker);
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// Called just before this Command runs the first time
void AccelControl::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void AccelControl::Execute() {

	SmartDashboard::PutBoolean("Tote hall", Robot::toteStacker->Hall());
	/*double sum = 0;
	if(Robot::sensors->GetState()->bin) {
		sum += Robot::containerStacker->GetCurrentPos() / 2438.0;
	}
	else {
		sum += Robot::containerStacker->GetCurrentPos() / 12190.0;
	}
	if(Robot::sensors->GetState()->tote1) {
		sum+= 1;
	}
	if(Robot::sensors->GetState()->tote2) {
		sum+= 2;
	}
	if(Robot::sensors->GetState()->tote3) {
		sum+= 3;
	}
	if(Robot::sensors->GetState()->tote4) {
		sum+= 4;
	}
	if(Robot::sensors->GetState()->tote5) {
		sum+= 5;
	}

	Robot::drive->SetRampRate(48 + (sum * RAMP_CONSTANT));
	*/
}

// Make this return true when this Command no longer needs to run execute()
bool AccelControl::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void AccelControl::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AccelControl::Interrupted() {

}
