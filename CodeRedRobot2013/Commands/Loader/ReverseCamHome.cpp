#include "ReverseCamHome.h"

ReverseCamHome::ReverseCamHome() : Command("ReverseCamHome") {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(Robot::loader);
}

// Called just before this Command runs the first time
void ReverseCamHome::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void ReverseCamHome::Execute() {
	if (Robot::loader->IsCamHome())
	{
		Robot::loader->CamStop();
	}
	else
	{
		Robot::loader->CamReverse();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ReverseCamHome::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ReverseCamHome::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ReverseCamHome::Interrupted() {
}
