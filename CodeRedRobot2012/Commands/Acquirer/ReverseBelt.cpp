#include "ReverseBelt.h"

ReverseBelt::ReverseBelt(bool isUserCommand) : CommandBase("ReverseBelt")
{
	Requires(acquirer);
	
	// If the Operator requested this from the Driver Station
	// don't let an automated system cancel it
	SetInterruptible(isUserCommand);
}

// Called just before this Command runs the first time
void ReverseBelt::Initialize() {
	acquirer->BeltSpeed(oi->GetAqsSpeed());
	acquirer->BeltReverse();
}

// Called repeatedly when this Command is scheduled to run
void ReverseBelt::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool ReverseBelt::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ReverseBelt::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ReverseBelt::Interrupted() {
}
