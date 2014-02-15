#include "ExtendKicker.h"

#define TIME_TO_EXTEND .5 //TODO: Replace potential dummy value

ExtendKicker::ExtendKicker() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(Robot::ejection);
	extendTime.Start();
}

// Called just before this Command runs the first time
void ExtendKicker::Initialize() {
	extendTime.Reset();
}

// Called repeatedly when this Command is scheduled to run
void ExtendKicker::Execute() {
	Robot::ejection->SetKicker(1);
}

// Make this return true when this Command no longer needs to run execute()
bool ExtendKicker::IsFinished() {
	return (extendTime.Get() > TIME_TO_EXTEND);
}

// Called once after isFinished returns true
void ExtendKicker::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ExtendKicker::Interrupted() {
}
