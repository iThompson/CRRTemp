#include "ShooterStop.h"

ShooterStop::ShooterStop() : Command("ShooterStop") {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(Robot::shooter);
}

// Called just before this Command runs the first time
void ShooterStop::Initialize() {
	Robot::shooter->Stop();
}

// Called repeatedly when this Command is scheduled to run
void ShooterStop::Execute() {
//	Robot::shooter->Stop();
	Robot::shooter->SetSpeed(0.0); // Not strictly necessary, but a good measure
}

// Make this return true when this Command no longer needs to run execute()
bool ShooterStop::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ShooterStop::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterStop::Interrupted() {
	
}
