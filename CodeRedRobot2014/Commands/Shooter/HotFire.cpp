#include "HotFire.h"
#include "Fire.h"

HotFire::HotFire() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(Robot::shooter);
	m_isHot = false;
	waitTime.Start();
	waitTime.Reset();
}

// Called just before this Command runs the first time
void HotFire::Initialize() {
	if(Robot::vision->IsGoalHot()) m_isHot = true;
}

// Called repeatedly when this Command is scheduled to run
void HotFire::Execute() {
	if(Robot::vision->IsGoalHot())
	{
		Robot::shooter->SetSolenoids(true);
		waitTime.Reset();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool HotFire::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void HotFire::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void HotFire::Interrupted() {
}
