#include "LoaderOpen.h"

LoaderOpen::LoaderOpen() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(loader);
}

// Called just before this Command runs the first time
void LoaderOpen::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void LoaderOpen::Execute() {
	loader->Rapidfire();
}

// Make this return true when this Command no longer needs to run execute()
bool LoaderOpen::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void LoaderOpen::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LoaderOpen::Interrupted() {
}
