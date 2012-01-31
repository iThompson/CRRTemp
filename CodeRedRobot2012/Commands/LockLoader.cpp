#include "LockLoader.h"

LockLoader::LockLoader() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}

// Called just before this Command runs the first time
void LockLoader::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void LockLoader::Execute() {
	loader->Lock();
}

// Make this return true when this Command no longer needs to run execute()
bool LockLoader::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void LockLoader::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LockLoader::Interrupted() {
}
