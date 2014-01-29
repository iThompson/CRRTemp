// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "RollerSpin.h"

RollerSpin::RollerSpin(bool isUser):
	m_isUser(isUser) 
{
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(Robot::acquisition);
}

// Called just before this Command runs the first time
void RollerSpin::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void RollerSpin::Execute() {
	if(m_isUser) 
	{
		if(Robot::oi->IsReversed()) 
			 Robot::acquisition->RollerSetSpeed(-1 * Robot::oi->GetRollerSpeed());
		else Robot::acquisition->RollerSetSpeed(Robot::oi->GetRollerSpeed());
	} 
	else 
	{
		if(Robot::oi->IsReversed()) 
			 Robot::acquisition->RollerSetSpeed(ACQ_REV_DEFAULT);
		else Robot::acquisition->RollerSetSpeed(ACQ_FOR_DEFAULT);
	}
	Robot::acquisition->RollerRun();
}

// Make this return true when this Command no longer needs to run execute()
bool RollerSpin::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void RollerSpin::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RollerSpin::Interrupted() {

}
