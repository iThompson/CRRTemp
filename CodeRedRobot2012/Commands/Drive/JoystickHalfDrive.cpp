#include "JoystickHalfDrive.h"

JoystickHalfDrive::JoystickHalfDrive() : CommandBase( "JoystickHalfDrive" )
{
	Requires(drive);
}

// Called just before this Command runs the first time
void JoystickHalfDrive::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void JoystickHalfDrive::Execute() {
	double l, r;
	l = oi->GetYLeft();
	l /= 2;
	r = oi->GetYRight();
	r /= 2;
	drive->TankDrive(l, r);
}

// Make this return true when this Command no longer needs to run execute()
bool JoystickHalfDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void JoystickHalfDrive::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void JoystickHalfDrive::Interrupted() {
}
