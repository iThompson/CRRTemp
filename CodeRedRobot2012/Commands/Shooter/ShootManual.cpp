#include "ShootManual.h"

ShootManual::ShootManual() : CommandBase("ShootManual")
{
	Requires(shooter);
}

// Called just before this Command runs the first time
void ShootManual::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void ShootManual::Execute() {
	shooter->SetSpeed(oi->GetDial());
	shooter->Run();
}

// Make this return true when this Command no longer needs to run execute()
bool ShootManual::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ShootManual::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShootManual::Interrupted() {
}
