#include "ShootAuto.h"

ShootAuto::ShootAuto() : CommandBase("ShootAuto")
{
	Requires(shooter);
}

// Called just before this Command runs the first time
void ShootAuto::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void ShootAuto::Execute() {
	if (vision->IsTargetValid()) {
		shooter->SetSpeed(shooter->LookUp(vision->GetTargetAngle(), loader->GetCompression())/* + ((oi->GetDial() - 0.5) * 0.1)*/);
	} else {
		// Actually, we don't really want to spin down. Keep the last speed
//		shooter->SetSpeed(0.0);
	}
	shooter->Run();
}

// Make this return true when this Command no longer needs to run execute()
bool ShootAuto::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ShootAuto::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShootAuto::Interrupted() {
}
