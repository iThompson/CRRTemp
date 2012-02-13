#include "RunBelt.h"

RunBelt::RunBelt() {
	Requires(acquirer);
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}

// Called just before this Command runs the first time
void RunBelt::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void RunBelt::Execute() {
	acquirer->BeltRun();
}

// Make this return true when this Command no longer needs to run execute()
bool RunBelt::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void RunBelt::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RunBelt::Interrupted() {
}
