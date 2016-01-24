#include "LoaderLoad.h"

LoaderLoad::LoaderLoad() : CommandBase("LoaderLoad")
{
	Requires(loader);
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
	if (GetGroup() != NULL) {
			return acquirer->IsExitReady();
		} else {
			return false;
		}
}

// Called once after isFinished returns true
void LoaderLoad::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LoaderLoad::Interrupted() {
}
