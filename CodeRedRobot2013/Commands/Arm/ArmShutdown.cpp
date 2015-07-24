#include "ArmShutdown.h"

ArmShutdown::ArmShutdown() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(Robot::arm);
	SetInterruptible(false);
}

// Called just before this Command runs the first time
void ArmShutdown::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void ArmShutdown::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool ArmShutdown::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ArmShutdown::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmShutdown::Interrupted() {
}
