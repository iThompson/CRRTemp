#include "ArmPosition.h"

ArmPosition::ArmPosition(double elbowPos, double wristPos) : 
															m_elbowPos(elbowPos), 
															m_wristPos(wristPos)

{
	// Use requires() here to declare subsystem dependencies
	Requires(Robot::arm);
}


// Called just before this Command runs the first time
void ArmPosition::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ArmPosition::Execute() {
	Robot::arm->SetElbow(m_elbowPos);
	Robot::arm->SetWrist(m_wristPos);
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
