#include "LoaderLaunch.h"
#include "../../ShotLogger.h"

LoaderLaunch::LoaderLaunch() : CommandBase("LoaderLaunch")
{
	Requires(loader);
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
	if (GetGroup() != NULL) {
		return !acquirer->IsExitReady();
	} else {
		return false;
	}
}

// Called once after isFinished returns true
void LoaderLaunch::End() {
	if (GetGroup() != NULL) {
		// Make sure this is not leaving a manual override
		// In theory, since an override is always interrupted, we don't need this check
//		ShotLogger::GetInstance()->Shot(shooter->GetSpeed(), loader->GetCompression());
	}
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LoaderLaunch::Interrupted() {
}
