#include "AutonDrive.h"
#include "../Subsystems/Drive.h"


AutonDrive::AutonDrive(double left, double right) : CommandBase("AutonDrive")
{
	Requires(drive);
	m_left = left;
	m_right = right;
}

// Called just before this Command runs the first time
void AutonDrive::Initialize() {
	m_runTime.Reset();
	m_runTime.Start();
}

// Called repeatedly when this Command is scheduled to run
void AutonDrive::Execute() {
	drive->TankDrive(m_left, m_right);
	
}

// Make this return true when this Command no longer needs to run execute()
bool AutonDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void AutonDrive::End() {
	printf("AutonDrive ran for %f", m_runTime.Get());
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonDrive::Interrupted() {
}
