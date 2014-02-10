// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#define DISTANCE_VOLTAGE_LOW 100 
#define DISTANCE_VOLTAGE_HIGH 200

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
	if(Robot::oi->IsAutoStop() &&
	   DISTANCE_VOLTAGE_LOW <= Robot::drive->GetDistance() &&
	   Robot::drive->GetDistance() <= DISTANCE_VOLTAGE_HIGH)
	{
		Robot::drive->TankDrive(0,0);
	}
	else
	{
	Robot::drive->TankDrive(Robot::oi->GetYLeft(), -Robot::oi->GetYRight());
	}
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
