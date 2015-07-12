#include "BridgeAutoDrive.h"

BridgeAutoDrive::BridgeAutoDrive(double left, double right) :
															m_left(left),
															m_right(right)
{
	Requires(drive);
}

// Called just before this Command runs the first time
void BridgeAutoDrive::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void BridgeAutoDrive::Execute() {
	if (drive->HasBridge()) {
		drive->TankDrive(0.0, 0.0);
	} else {
		drive->TankDrive(m_left, m_right);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool BridgeAutoDrive::IsFinished() {
	return drive->HasBridge();
}

// Called once after isFinished returns true
void BridgeAutoDrive::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BridgeAutoDrive::Interrupted() {
}
