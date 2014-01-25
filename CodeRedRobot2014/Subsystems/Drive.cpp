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

Drive::Drive() : Subsystem("Drive") {
	left1 = RobotMap::driveleft1;
	left2 = RobotMap::driveleft2;
	left3 = RobotMap::driveleft3;
	right1 = RobotMap::driveright1;
	right2 = RobotMap::driveright2;
	right3 = RobotMap::driveright3;
	shift = RobotMap::driveshift;
}
    
void Drive::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new JoystickDrive());
}

void Drive::TankDrive(double lSpeed, double rSpeed) {
	
}

void Drive::Shift(bool high) {
	
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

