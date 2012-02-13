#include "ShootAuto.h"

ShootAuto::ShootAuto() : CommandBase("ShootAuto")
{
	Requires(shooter);
}

// Called just before this Command runs the first time
void ShootAuto::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void ShootAuto::Execute() {
	//TODO   Get value from lookup table and set the speed to that
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
