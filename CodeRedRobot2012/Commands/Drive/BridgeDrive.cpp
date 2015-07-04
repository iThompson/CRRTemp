#include "BridgeDrive.h"

BridgeDrive::BridgeDrive() {
	Requires(drive);
}

// Called just before this Command runs the first time
void BridgeDrive::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void BridgeDrive::Execute() {
	if (drive->HasBridge()) {
		drive->TankDrive(0.0, 0.0);
	} else {
		drive->TankDrive(oi->GetYLeft(), oi->GetYRight());
	}
}

// Make this return true when this Command no longer needs to run execute()
bool BridgeDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void BridgeDrive::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BridgeDrive::Interrupted() {
}
