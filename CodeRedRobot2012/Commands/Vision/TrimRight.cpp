#include "TrimRight.h"

TrimRight::TrimRight() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}

// Called just before this Command runs the first time
void TrimRight::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void TrimRight::Execute() {
	vision->TrimRight();
}

// Make this return true when this Command no longer needs to run execute()
bool TrimRight::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void TrimRight::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TrimRight::Interrupted() {
}
