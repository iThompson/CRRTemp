#include "Drive.h"
#include "../Robotmap.h"
#include "../Commands/JoystickDrive.h"

// Can't use PIDSubsystem here since we need 2 PIDControllers :(

Drive::Drive() : Subsystem("Drive"),
				lDrive(DRV_MTR_LEFT_A, DRV_MTR_LEFT_B, DRV_ENC_LEFT),
				rDrive(DRV_MTR_RIGHT_A, DRV_MTR_RIGHT_B, DRV_ENC_RIGHT),
				shifter(DRV_SOL_SHIFT)
{
	lJagA = new CANJaguar(DRV_MTR_LEFT_A);
	lJagB = new CANJaguar(DRV_MTR_LEFT_B);
	rJagA = new CANJaguar(DRV_MTR_RIGHT_A);
	rJagB = new CANJaguar(DRV_MTR_RIGHT_B);
}
    
void Drive::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new JoystickDrive());
}

void Drive::TankDrive(double left, double right){ 		//Set the jaguars so that two are used for each tread
	lDrive.Set(left);
	rDrive.Set(right);
}

void Drive::Shift(bool high) {
	shifter.Set(high);
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
