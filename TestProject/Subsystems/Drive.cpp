#include "Drive.h"
#include "../Robotmap.h"
#include "../Commands/StickDrive.h"

Drive::Drive() : Subsystem("Drive") {
	lJagA = new CANJaguar(DRIVE_LEFT_A);
	lJagB = new CANJaguar(DRIVE_LEFT_B);
	rJagA = new CANJaguar(DRIVE_RIGHT_A);
	rJagB = new CANJaguar(DRIVE_RIGHT_B);
	
}
    
void Drive::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new StickDrive());
}

void Drive::TankDrive(double left, double right) {
	lJagA->Set(left);
	lJagB->Set(left);
	rJagA->Set(right);
	rJagB->Set(right);
}
