// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "Fire.h"
#include "../Ejection/ExtendKicker.h"

Fire::Fire(double fireLength, bool useManual):
		m_fireLength(fireLength),
		m_useManual(useManual)
		
{
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(Robot::shooter);
	if(m_useManual) // Override the original fireLength (if useManual was true, fireLength should be 0 or negative
		{
			m_fireLength = Robot::oi->GetManualFire();
		}
}

// Called just before this Command runs the first time
void Fire::Initialize() {
	shootTime.Start();
	shootTime.Reset();	
}

// Called repeatedly when this Command is scheduled to run
void Fire::Execute() {
	SmartDashboard::PutNumber("Manual Fire", Robot::oi->GetManualFire());
	if(m_fireLength <= 0 || // Code for "do not fire"
			(!Robot::acquisition->BallReady() && // Ball isn't in the shooter 
			 !Robot::oi->OverrideShooter()))     // Not being told to override shooting manually 
	{
		Robot::shooter->SetSolenoids(false);
	}
	else if(shootTime.Get() < m_fireLength)
	{
		Robot::shooter->SetSolenoids(true);
	}
	else
	{
		Robot::shooter->SetSolenoids(false);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool Fire::IsFinished() {
	return shootTime.Get() > m_fireLength;
}

// Called once after isFinished returns true
void Fire::End() {
		new ExtendKicker();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Fire::Interrupted() {
	
}
