#include "ShiftLow.h"

ShiftLow::ShiftLow() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}

// Called just before this Command runs the first time
void ShiftLow::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void ShiftLow::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool ShiftLow::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ShiftLow::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShiftLow::Interrupted() {
}
