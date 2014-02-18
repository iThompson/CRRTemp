// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "Drive.h"
#include "../Robotmap.h"
#include "../Commands/Drive/JoystickDrive.h"
#include "Math.h"

Drive::Drive() : Subsystem("Drive") {
	left = new TripleMotorOutput(RobotMap::driveleft1, RobotMap::driveleft2, 
								RobotMap::driveleft3, RobotMap::drivelEnc);
	right = new TripleMotorOutput(RobotMap::driveright1, RobotMap::driveright2, 
								RobotMap::driveright3, RobotMap::driverEnc);
	shift = RobotMap::driveshift;
	rangeFinder = RobotMap::driverangeFinder;
	goalSensor = RobotMap::drivegoalSensor;
	ultratest = RobotMap::testultrasonic;
	
	SmartDashboard::PutNumber("Thresh1", 0);
	SmartDashboard::PutNumber("Thresh1 End", 0);
	SmartDashboard::PutNumber("Thresh2", 0);
	SmartDashboard::PutNumber("Thresh2 End", 0);	
}
    
void Drive::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new JoystickDrive());
}

void Drive::TankDrive(double lSpeed, double rSpeed) {
	lSpeed = lSpeed * fabs(lSpeed); // Square values (preserving sign) for better driving
	rSpeed = rSpeed * fabs(rSpeed);
	int leftNum = left->GetNumMotors(lSpeed);
	int rightNum = right->GetNumMotors(rSpeed);
	if(leftNum > rightNum)
	{
		left->SetSpeed(lSpeed, leftNum);
		right->SetSpeed(rSpeed, leftNum);
	}
	else
	{
		left->SetSpeed(lSpeed, rightNum);
		right->SetSpeed(rSpeed, rightNum);
	}
	SmartDashboard::PutNumber("lSpeed", left->GetSpeed());
	SmartDashboard::PutNumber("rSpeed", right->GetSpeed());

	SmartDashboard::PutNumber("Left drive motors", left->MotorsEngaged());
	SmartDashboard::PutNumber("Right drive motors", right->MotorsEngaged());

	SmartDashboard::PutNumber("Left1 Current", left->GetCurrent1());
	SmartDashboard::PutNumber("Left2 Current", left->GetCurrent2());
	SmartDashboard::PutNumber("Left3 Current", left->GetCurrent3());
	SmartDashboard::PutNumber("Right1 Current", right->GetCurrent1());
	SmartDashboard::PutNumber("Right2 Current", right->GetCurrent2());
	SmartDashboard::PutNumber("Right3 Current", right->GetCurrent3());
	
	SmartDashboard::PutBoolean("Left Braked", left->IsBraked());
	SmartDashboard::PutBoolean("Right Braked", right->IsBraked());
	
	SmartDashboard::PutBoolean("Shoot Now!", Robot::vision->IsGoalHot());
	
	SmartDashboard::PutNumber("Short Dist", GetDistanceShort());
	SmartDashboard::PutNumber("Long Dist", GetDistanceLong());
	
	SmartDashboard::PutNumber("Ultrasonic Test", ultratest->GetAverageVoltage());
}

void Drive::Shift(bool high) {
	shift->Set(high);
}

double Drive::GetDistanceLong() {
	return rangeFinder->GetRangeInches()/12;
}

double Drive::GetDistanceShort() {
	return goalSensor->GetRangeInches()/12;
}
