#include "JoystickDrive.h"

JoystickDrive::JoystickDrive() : CommandBase( "JoystickDrive" )
{
	Requires(drive);
}

// Called just before this Command runs the first time
void JoystickDrive::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void JoystickDrive::Execute() {
	drive->TankDrive(oi->GetYLeft(), oi->GetYRight());
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
