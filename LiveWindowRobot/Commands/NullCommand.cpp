#include "NullCommand.h"

NullCommand::NullCommand(Subsystem* system) {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(system);
	SetInterruptible(false);
}

// Called just before this Command runs the first time
void NullCommand::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void NullCommand::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool NullCommand::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void NullCommand::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void NullCommand::Interrupted() {
}
