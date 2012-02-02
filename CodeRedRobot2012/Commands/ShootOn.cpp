#include "ShootOn.h"

ShootOn::ShootOn() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}

// Called just before this Command runs the first time
void ShootOn::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void ShootOn::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool ShootOn::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ShootOn::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShootOn::Interrupted() {
}
