#include "LoaderLock.h"

LoaderLock::LoaderLock() {
	Requires(loader);
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}

// Called just before this Command runs the first time
void LoaderLock::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void LoaderLock::Execute() {
	loader->Lock();
}

// Make this return true when this Command no longer needs to run execute()
bool LoaderLock::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void LoaderLock::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LoaderLock::Interrupted() {
}
