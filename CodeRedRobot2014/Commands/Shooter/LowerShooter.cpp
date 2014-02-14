#include "LowerShooter.h"

#define TIME_THRESH_1 .3 //TODO: Replace dummy value
#define TIME_THRESH_2 .6 //TODO: Replace dummy value
#define TIME_THRESH_END .65 //TODO: replace dummy value


LowerShooter::LowerShooter(double timeRaised):
	m_timeRaised(timeRaised)
{
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(Robot::shooter);
	
	shootTime.Start();
}

// Called just before this Command runs the first time
void LowerShooter::Initialize() {
	shootTime.Reset();
}

// Called repeatedly when this Command is scheduled to run
void LowerShooter::Execute() {
	if(shootTime.Get() < TIME_THRESH_1 * m_timeRaised) 	// Scale down the time to wait if the
		Robot::shooter->SetSolenoids(false);			// shooter didn't go all the way up
	else if(shootTime.Get() < TIME_THRESH_2 * m_timeRaised)
		Robot::shooter->SetSolenoids(true);
	else
		Robot::shooter->SetSolenoids(false);
}

// Make this return true when this Command no longer needs to run execute()
bool LowerShooter::IsFinished() {
	return shootTime.Get() > TIME_THRESH_END * m_timeRaised;
}

// Called once after isFinished returns true
void LowerShooter::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LowerShooter::Interrupted() {
}
