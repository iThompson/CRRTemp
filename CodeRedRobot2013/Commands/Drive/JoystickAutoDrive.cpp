#include "JoystickAutoDrive.h"

JoystickAutoDrive::JoystickAutoDrive(double lSpeed, double rSpeed) : 
																	m_lSpeed(lSpeed),
																	m_rSpeed(rSpeed)
{
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(Robot::drive);
}

// Called just before this Command runs the first time
void JoystickAutoDrive::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void JoystickAutoDrive::Execute() {
	Robot::drive->TankDrive(m_lSpeed, m_rSpeed);
}

// Make this return true when this Command no longer needs to run execute()
bool JoystickAutoDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void JoystickAutoDrive::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void JoystickAutoDrive::Interrupted() {
	
}
