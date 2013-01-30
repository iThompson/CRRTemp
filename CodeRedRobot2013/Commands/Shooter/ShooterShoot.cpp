#include "ShooterShoot.h"

ShooterShoot::ShooterShoot() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(Robot::shooter);
	
}

// Called just before this Command runs the first time
void ShooterShoot::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void ShooterShoot::Execute() {
	Robot::shooter->SetSpeed(Robot::oi->GetShooterSpeed());
	Robot::shooter->CamRun();
}

// Make this return true when this Command no longer needs to run execute()
bool ShooterShoot::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ShooterShoot::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterShoot::Interrupted() {
	
}
