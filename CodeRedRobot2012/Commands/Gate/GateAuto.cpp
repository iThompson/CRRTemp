#include "GateAuto.h"

GateAuto::GateAuto() {
	Requires(gate);
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}

// Called just before this Command runs the first time
void GateAuto::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void GateAuto::Execute() {
	if (acquirer->GetBallCount() == 3) {
		gate->SetState(1);
	} else {
		gate->SetState(0);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool GateAuto::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void GateAuto::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GateAuto::Interrupted() {
}
