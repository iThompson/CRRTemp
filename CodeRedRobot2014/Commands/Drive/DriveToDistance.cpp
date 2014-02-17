#include "DriveToDistance.h"

DriveToDistance::DriveToDistance(double distance):
	m_distance(distance)
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
	Robot::drive->TankDrive(1, -1);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveToDistance::IsFinished() {
	return Robot::drive->GetDistanceLong() > m_distance;
}

// Called once after isFinished returns true
void DriveToDistance::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveToDistance::Interrupted() {
}
