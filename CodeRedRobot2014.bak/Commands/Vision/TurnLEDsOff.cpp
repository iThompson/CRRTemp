#include "TurnLEDsOff.h"

TurnLEDsOff::TurnLEDsOff() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(Robot::vision);
}

// Called just before this Command runs the first time
void TurnLEDsOff::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void TurnLEDsOff::Execute() {
	Robot::vision->SetLEDs(Relay::kReverse);
}

// Make this return true when this Command no longer needs to run execute()
bool TurnLEDsOff::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void TurnLEDsOff::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurnLEDsOff::Interrupted() {
}
