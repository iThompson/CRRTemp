#include "ToggleUpper.h"
#include "Loader/LoaderLaunch.h"
#include "Loader/LoaderLoad.h"
#include "Loader/LoaderLock.h"
#include "Loader/LoaderOpen.h"

ToggleUpper::ToggleUpper() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);

	launch = new LoaderLaunch();
	load = new LoaderLoad();
	lock = new LoaderLock();
	open = new LoaderOpen();
}

// Called just before this Command runs the first time
void ToggleUpper::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ToggleUpper::Execute() {
	if (loader->GetLower()) {
		if (loader->GetUpper()) {
			launch->Start();
		} else {
			lock->Start();
		}
	} else {
		if (loader->GetUpper()) {
			open->Start();
		} else {
			load->Start();
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ToggleUpper::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ToggleUpper::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleUpper::Interrupted() {
}
