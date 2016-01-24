#include "Shoot.h"

Shoot::Shoot() : CommandBase("Shoot")
{
	Requires(shooter);
}

// Called just before this Command runs the first time
void Shoot::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void Shoot::Execute() {
	shooter->Run();
	
}

// Make this return true when this Command no longer needs to run execute()
bool Shoot::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Shoot::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Shoot::Interrupted() {
}
