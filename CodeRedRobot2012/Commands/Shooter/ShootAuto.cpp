#include "ShootAuto.h"

ShootAuto::ShootAuto() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}

// Called just before this Command runs the first time
void ShootAuto::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void ShootAuto::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool ShootAuto::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ShootAuto::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShootAuto::Interrupted() {
}
