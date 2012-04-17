#include "Compress.h"

Compress::Compress() {
	Requires(loader);
}

// Called just before this Command runs the first time
void Compress::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void Compress::Execute() {
	loader->CompressTest();
}

// Make this return true when this Command no longer needs to run execute()
bool Compress::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Compress::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Compress::Interrupted() {
}
