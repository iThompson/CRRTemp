#include "Fire.h"

Fire::Fire() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}

// Called just before this Command runs the first time
void Fire::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void Fire::Execute() {
	Robot::loader->CamRun();
}

// Make this return true when this Command no longer needs to run execute()
bool Fire::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Fire::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Fire::Interrupted() {
}
