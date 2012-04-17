#include "AimLeft.h"

AimLeft::AimLeft() : CommandBase("AimLeft")
{
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(vision);
}

// Called just before this Command runs the first time
void AimLeft::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void AimLeft::Execute() {
	vision->SelectTarget(Vision::kTargetLeft);
}

// Make this return true when this Command no longer needs to run execute()
bool AimLeft::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void AimLeft::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AimLeft::Interrupted() {
}
