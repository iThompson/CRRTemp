#include "AimLow.h"

AimLow::AimLow() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(vision);
}

// Called just before this Command runs the first time
void AimLow::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void AimLow::Execute() {
	vision->SelectTarget(3);
}

// Make this return true when this Command no longer needs to run execute()
bool AimLow::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void AimLow::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AimLow::Interrupted() {
}
