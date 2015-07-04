#include "SendCamHome.h"

SendCamHome::SendCamHome() : Command("SendCamHome") {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(Robot::loader);
}

// Called just before this Command runs the first time
void SendCamHome::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void SendCamHome::Execute() {
	if (Robot::loader->IsCamHome())
	{
		Robot::loader->CamStop();
	}
	else
	{
		Robot::loader->CamSlow();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool SendCamHome::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void SendCamHome::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SendCamHome::Interrupted() {
}
