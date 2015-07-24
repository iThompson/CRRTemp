#include "HotFire.h"
#include "Fire.h"

HotFire::HotFire() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(Robot::shooter);
}

// Called just before this Command runs the first time
void HotFire::Initialize() {
	m_hasFired = false;
}

// Called repeatedly when this Command is scheduled to run
void HotFire::Execute() {
	if(!m_hasFired && Robot::vision->IsGoalHot() &&
			Robot::acquisition->BallReady()) // Ball is in the shooter 
	{
		m_hasFired = true;
		Robot::shooter->SetSolenoids(true);
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
