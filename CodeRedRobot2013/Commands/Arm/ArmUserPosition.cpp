#include "ArmUserPosition.h"

ArmUserPosition::ArmUserPosition() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(Robot::arm);
	SetInterruptible(false);
}

// Called just before this Command runs the first time
void ArmUserPosition::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void ArmUserPosition::Execute() {
	Robot::arm->SetElbow(Robot::oi->GetElbowSetpoint());
	Robot::arm->SetWrist(Robot::oi->GetWristSetpoint());
}

// Make this return true when this Command no longer needs to run execute()
bool ArmUserPosition::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ArmUserPosition::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmUserPosition::Interrupted() {
	
}
