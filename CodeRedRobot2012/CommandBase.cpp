#include "CommandBase.h"
#include "Commands/Scheduler.h"

CommandBase::CommandBase(const char *name) : Command(name) {
	// EMPTY
}

CommandBase::CommandBase() : Command() {
}

// Initialize a single static instance of all of your subsystems to NULL
OI *CommandBase::oi = NULL;
Drive *CommandBase::drive = NULL;
Shooter *CommandBase::shooter = NULL;
Acquirer *CommandBase::acquirer = NULL;

void CommandBase::init() {
    // Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	oi = new OI();
	drive = new Drive();
	shooter = new Shooter();
	acquirer = new Acquirer();
}
