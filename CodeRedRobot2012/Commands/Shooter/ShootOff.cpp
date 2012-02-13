#include "ShootOff.h"

ShootOff::ShootOff() : CommandBase("ShootOff")
{
	Requires(shooter);
}

// Called just before this Command runs the first time
void ShootOff::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void ShootOff::Execute() {
	shooter->Stop();	
}

// Make this return true when this Command no longer needs to run execute()
bool ShootOff::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ShootOff::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShootOff::Interrupted() {
}
