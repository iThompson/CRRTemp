#include "ToggleLower.h"
#include "Loader/LoaderLaunch.h"
#include "Loader/LoaderLoad.h"
#include "Loader/LoaderLock.h"
#include "Loader/LoaderOpen.h"

ToggleLower::ToggleLower() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	
	launch = new LoaderLaunch();
	load = new LoaderLoad();
	lock = new LoaderLock();
	open = new LoaderOpen();
}

// Called just before this Command runs the first time
void ToggleLower::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void ToggleLower::Execute() {
	if (loader->GetUpper()) {
		if (loader->GetLower()) {
			load->Start();
		} else {
			lock->Start();
		}
	} else {
		if (loader->GetLower()) {
			open->Start();
		} else {
			launch->Start();
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ToggleLower::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ToggleLower::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleLower::Interrupted() {
}
