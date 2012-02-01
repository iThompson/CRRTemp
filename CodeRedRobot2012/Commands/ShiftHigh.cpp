#include "ShiftHigh.h"

ShiftHigh::ShiftHigh() {
	Requires(drive);
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}

// Called just before this Command runs the first time
void ShiftHigh::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void ShiftHigh::Execute() {
	drive->Shift(1);
}

// Make this return true when this Command no longer needs to run execute()
bool ShiftHigh::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ShiftHigh::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShiftHigh::Interrupted() {
}
