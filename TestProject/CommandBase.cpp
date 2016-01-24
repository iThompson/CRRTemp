#include "CommandBase.h"
#include "Commands/Scheduler.h"

CommandBase::CommandBase(const char *name) : Command(name) {
}

CommandBase::CommandBase() : Command() {
}

// Initialize a single static instance of all of your subsystems to NULL
Drive* CommandBase::drive = NULL;
OI* CommandBase::oi = NULL;
Vision* CommandBase::vision = NULL;

void CommandBase::init() {
    // Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	drive = new Drive();
	
	SmartDashboard::GetInstance()->PutData(drive);
	
	oi = new OI();
	vision = new Vision();
}
