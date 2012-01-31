#include "ShootIdle.h"

ShootIdle::ShootIdle() {
	Requires(shooter);
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}

// Called just before this Command runs the first time
void ShootIdle::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void ShootIdle::Execute() {
	shooter->Stop();	
}

// Make this return true when this Command no longer needs to run execute()
bool ShootIdle::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ShootIdle::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShootIdle::Interrupted() {
}
