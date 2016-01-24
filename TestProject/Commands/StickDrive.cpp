#include "StickDrive.h"

StickDrive::StickDrive() : CommandBase("StickDrive") {
	Requires(drive);
}

// Called just before this Command runs the first time
void StickDrive::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void StickDrive::Execute() {
	drive->TankDrive(oi->GetStickL()->GetY(), oi->GetStickR()->GetY());
}

// Make this return true when this Command no longer needs to run execute()
bool StickDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void StickDrive::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void StickDrive::Interrupted() {
}
