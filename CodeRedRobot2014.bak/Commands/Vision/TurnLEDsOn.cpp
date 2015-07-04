#include "TurnLEDsOn.h"

TurnLEDsOn::TurnLEDsOn() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(Robot::vision);
}

// Called just before this Command runs the first time
void TurnLEDsOn::Initialize() {
	Robot::vision->SetLEDs(Relay::kForward);
}

// Called repeatedly when this Command is scheduled to run
void TurnLEDsOn::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool TurnLEDsOn::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TurnLEDsOn::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurnLEDsOn::Interrupted() {
}
