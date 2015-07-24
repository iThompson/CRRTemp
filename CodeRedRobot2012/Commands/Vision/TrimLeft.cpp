#include "TrimLeft.h"

TrimLeft::TrimLeft() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}

// Called just before this Command runs the first time
void TrimLeft::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void TrimLeft::Execute() {
	vision->TrimLeft();
}

// Make this return true when this Command no longer needs to run execute()
bool TrimLeft::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void TrimLeft::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TrimLeft::Interrupted() {
}
