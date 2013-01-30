#include "ShooterShoot.h"

ShooterShoot::ShooterShoot() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}

// Called just before this Command runs the first time
void ShooterShoot::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void ShooterShoot::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool ShooterShoot::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ShooterShoot::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterShoot::Interrupted() {
}
