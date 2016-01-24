#include "Deploy.h"

Deploy::Deploy() : CommandBase("Deploy")
{
	Requires(gate);
}

// Called just before this Command runs the first time
void Deploy::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void Deploy::Execute() {
	gate->SetState(true);
}

// Make this return true when this Command no longer needs to run execute()
bool Deploy::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Deploy::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Deploy::Interrupted() {
}
