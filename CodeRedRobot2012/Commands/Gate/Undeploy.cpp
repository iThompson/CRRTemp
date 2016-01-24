#include "Undeploy.h"

Undeploy::Undeploy() : CommandBase("Undeploy")
{
	Requires(gate);
}

// Called just before this Command runs the first time
void Undeploy::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void Undeploy::Execute() {
	gate->SetState(false);
}

// Make this return true when this Command no longer needs to run execute()
bool Undeploy::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Undeploy::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Undeploy::Interrupted() {
}
