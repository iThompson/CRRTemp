#include "BridgeReverse.h"

BridgeReverse::BridgeReverse() : CommandBase("BridgeReverse", 0.5) {
	Requires(drive);
}

// Called just before this Command runs the first time
void BridgeReverse::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void BridgeReverse::Execute() {
	drive->TankDrive(0.4, 0.4);
}

// Make this return true when this Command no longer needs to run execute()
bool BridgeReverse::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void BridgeReverse::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BridgeReverse::Interrupted() {
}
