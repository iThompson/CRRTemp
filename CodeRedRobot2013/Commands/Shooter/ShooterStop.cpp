#include "ShooterStop.h"

ShooterStop::ShooterStop() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}

// Called just before this Command runs the first time
void ShooterStop::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void ShooterStop::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool ShooterStop::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ShooterStop::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterStop::Interrupted() {
}
