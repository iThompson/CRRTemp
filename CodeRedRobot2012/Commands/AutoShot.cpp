#include "AutoShot.h"
#include "../CommandBase.h"
#include "../Subsystems/Shooter.h"

AutoShot::AutoShot() : CommandBase("AutoShot")
{
	Requires(shooter);	
}

// Called just before this Command runs the first time
void AutoShot::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void AutoShot::Execute() {
	shooter->UsePIDOutput(255); //66
}

// Make this return true when this Command no longer needs to run execute()
bool AutoShot::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void AutoShot::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoShot::Interrupted() {
}
