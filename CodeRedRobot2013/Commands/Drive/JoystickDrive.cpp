#include "JoystickDrive.h"

JoystickDrive::JoystickDrive() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(Robot::drive);
}
// Called just before this Command runs the first time
void JoystickDrive::Initialize() {
	
}
// Called repeatedly when this Command is scheduled to run
void JoystickDrive::Execute() {
	Robot::drive->TankDrive(Robot::oi->GetYLeft(), Robot::oi->GetYRight());
}
// Make this return true when this Command no longer needs to run execute()
bool JoystickDrive::IsFinished() {
	return false;
}
// Called once after isFinished returns true
void JoystickDrive::End() {
	
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void JoystickDrive::Interrupted() {
	
}
