#include "DriveToDistance.h"

#define DRIVE_AUTO_SPEED .85

DriveToDistance::DriveToDistance(double distance, bool isForward):
	m_distance(distance),
	m_isForward(isForward)
{
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(Robot::drive); 
}

// Called just before this Command runs the first time
void DriveToDistance::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void DriveToDistance::Execute() {
	if(m_isForward)
		Robot::drive->TankDrive(DRIVE_AUTO_SPEED, -DRIVE_AUTO_SPEED);
	else
		Robot::drive->TankDrive(-DRIVE_AUTO_SPEED, DRIVE_AUTO_SPEED);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveToDistance::IsFinished() {
	if(m_isForward)
		return Robot::drive->GetDistanceLong() < m_distance;
	else
		return Robot::drive->GetDistanceShort() < m_distance;
}

// Called once after isFinished returns true
void DriveToDistance::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveToDistance::Interrupted() {
}
