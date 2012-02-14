#include "CommandBase.h"
#include "Commands/Scheduler.h"

CommandBase::CommandBase(const char *name) : Command(name) {
	// EMPTY
}

CommandBase::CommandBase() : Command() {
}

// Initialize a single static instance of all of your subsystems to NULL
OI *CommandBase::oi = NULL;
Acquirer *CommandBase::acquirer = NULL;
Drive *CommandBase::drive = NULL;
Gate *CommandBase::gate = NULL;
Shooter *CommandBase::shooter = NULL;
Loader *CommandBase::loader = NULL;
Vision *CommandBase::vision = NULL;


void CommandBase::init() {
    // Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	acquirer = new Acquirer();
	drive = new Drive();
	shooter = new Shooter();
	loader = new Loader();
	gate = new Gate();
	
	// Will spawn a server task
	vision = new Vision();
	
	oi = new OI();
}
