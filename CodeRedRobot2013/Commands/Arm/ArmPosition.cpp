#include "ArmPosition.h"

ArmPosition::ArmPosition() {
	// Use requires() here to declare subsystem dependencies
	Requires(Robot::arm);
}


// Called just before this Command runs the first time
void ArmPosition::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void ArmPosition::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool ArmPosition::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ArmPosition::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmPosition::Interrupted() {
}
