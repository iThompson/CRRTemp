#include "Sting.h"

Sting::Sting() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(stinger);
}

// Called just before this Command runs the first time
void Sting::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void Sting::Execute() {
	stinger->SetState(true);
}

// Make this return true when this Command no longer needs to run execute()
bool Sting::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Sting::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Sting::Interrupted() {
}
