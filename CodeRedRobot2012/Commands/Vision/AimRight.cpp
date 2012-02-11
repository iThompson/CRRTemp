#include "AimRight.h"

AimRight::AimRight() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(vision);
}

// Called just before this Command runs the first time
void AimRight::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void AimRight::Execute() {
	vision->SelectTarget(2);
}

// Make this return true when this Command no longer needs to run execute()
bool AimRight::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void AimRight::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AimRight::Interrupted() {
}
