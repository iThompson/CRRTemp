#include "LoaderLoad.h"

LoaderLoad::LoaderLoad() {
	Requires(loader);
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}

// Called just before this Command runs the first time
void LoaderLoad::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void LoaderLoad::Execute() {
	loader->Load();
}

// Make this return true when this Command no longer needs to run execute()
bool LoaderLoad::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void LoaderLoad::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LoaderLoad::Interrupted() {
}
