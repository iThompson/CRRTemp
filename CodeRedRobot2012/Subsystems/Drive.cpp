#include "Drive.h"
#include "../Robotmap.h"
#include "../Commands/JoystickDrive.h"

Drive::Drive() : Subsystem("Drive") {
	lJagA = new CANJaguar(DRV_MTR_LEFT_A);
	lJagB = new CANJaguar(DRV_MTR_LEFT_B);
	rJagA = new CANJaguar(DRV_MTR_RIGHT_A);
	rJagB = new CANJaguar(DRV_MTR_RIGHT_B);
	shifter = new Solenoid(DRV_SOL_SHIFT);
}
    
void Drive::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new JoystickDrive());
}

void Drive::TankDrive(double left, double right){ 		//Set the jaguars so that two are used for each tread
	lJagA->Set(left);
	lJagB->Set(left);
	rJagA->Set(right);
	rJagB->Set(right);
}

void Drive::Shift(bool high) {
	shifter->Set(high);
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
