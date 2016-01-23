#include "Drive.h"
#include "../RobotMap.h"
#include "../Commands/Drive/JoystickDrive.h"

Drive::Drive() :
		Subsystem("Drive")
{
	Drive::lDrive1 = RobotMap::drivelDrive1;
	Drive::lDrive2 = RobotMap::drivelDrive2;
	Drive::rDrive1 = RobotMap::driverDrive1;
	Drive::rDrive2 = RobotMap::driverDrive2;
}

void Drive::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new JoystickDrive());
}

void Drive::TankDrive(double lSpeed, double rSpeed) {
	lDrive1->Set(lSpeed);
	lDrive2->Set(lSpeed);
	rDrive1->Set(rSpeed);
	rDrive2->Set(rSpeed);

}
// Put methods for controlling this subsystem
// here. Call these from Commands.
