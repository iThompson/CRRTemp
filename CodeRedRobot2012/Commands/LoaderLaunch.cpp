#include "LoaderLaunch.h"

LoaderLaunch::LoaderLaunch() {
	Requires(loader);
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}

// Called just before this Command runs the first time
void LoaderLaunch::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void LoaderLaunch::Execute() {
	loader->Launch();
}

// Make this return true when this Command no longer needs to run execute()
bool LoaderLaunch::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void LoaderLaunch::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LoaderLaunch::Interrupted() {
}
