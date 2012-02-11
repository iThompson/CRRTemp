#include "RunBeltBack.h"

RunBeltBack::RunBeltBack() {
	Requires(loader);
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}

// Called just before this Command runs the first time
void RunBeltBack::Initialize() {
	loader->ReverseBelt();
}

// Called repeatedly when this Command is scheduled to run
void RunBeltBack::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool RunBeltBack::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void RunBeltBack::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RunBeltBack::Interrupted() {
}