#include "RunBelt.h"

RunBelt::RunBelt(bool isUserCommand) : CommandBase("RunBelt")
{
	Requires(acquirer);
	
	// If the Operator requested this from the Driver Station
	// don't let an automated system cancel it
	SetInterruptible(isUserCommand);
}

// Called just before this Command runs the first time
void RunBelt::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void RunBelt::Execute() {
	acquirer->BeltSpeed(oi->GetAqsSpeed());
	acquirer->BeltRun();
}

// Make this return true when this Command no longer needs to run execute()
bool RunBelt::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void RunBelt::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RunBelt::Interrupted() {
}
