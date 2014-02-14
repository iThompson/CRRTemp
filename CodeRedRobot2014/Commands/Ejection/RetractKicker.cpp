#include "RetractKicker.h"

RetractKicker::RetractKicker() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(Robot::ejection);
}

// Called just before this Command runs the first time
void RetractKicker::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void RetractKicker::Execute() {
	Robot::ejection->SetKicker(0);
}

// Make this return true when this Command no longer needs to run execute()
bool RetractKicker::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void RetractKicker::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RetractKicker::Interrupted() {
}
