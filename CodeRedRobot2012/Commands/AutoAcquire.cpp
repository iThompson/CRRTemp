#include "AutoAcquire.h"

AutoAcquire::AutoAcquire() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}

// Called just before this Command runs the first time
void AutoAcquire::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void AutoAcquire::Execute() {
	acquirer->Acquire(1);
	
}

// Make this return true when this Command no longer needs to run execute()
bool AutoAcquire::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void AutoAcquire::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoAcquire::Interrupted() {
}
