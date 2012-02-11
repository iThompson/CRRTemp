#include "AlignDrive.h"

AlignDrive::AlignDrive() {
	Requires(drive);
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}

// Called just before this Command runs the first time
void AlignDrive::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void AlignDrive::Execute() {
	UINT16 angle = vision->GetTargetAngle();
	float scaledAngle = angle / 42; // placeholder for actual max angle
	scaledAngle /= 3;
	drive->TankDrive(oi->GetYLeft() - scaledAngle, oi->GetYRight() + scaledAngle);
}

// Make this return true when this Command no longer needs to run execute()
bool AlignDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void AlignDrive::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AlignDrive::Interrupted() {
}
