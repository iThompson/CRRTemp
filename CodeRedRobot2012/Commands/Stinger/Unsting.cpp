#include "Unsting.h"

Unsting::Unsting() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(stinger); 
}

// Called just before this Command runs the first time
void Unsting::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void Unsting::Execute() {
	stinger->SetState(false);
}

// Make this return true when this Command no longer needs to run execute()
bool Unsting::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Unsting::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Unsting::Interrupted() {
}
