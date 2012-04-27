#include "StopBelt.h"

StopBelt::StopBelt(bool isInterruptible) : CommandBase("StopBelt")
{
	Requires(acquirer);
	SetInterruptible(isInterruptible);
}

// Called just before this Command runs the first time
void StopBelt::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void StopBelt::Execute() {
	acquirer->BeltStop();
}

// Make this return true when this Command no longer needs to run execute()
bool StopBelt::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void StopBelt::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void StopBelt::Interrupted() {
}
