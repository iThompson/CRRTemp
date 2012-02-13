#include "Drive.h"
#include "../Robotmap.h"
#include "../Commands/Drive/JoystickDrive.h"

// Can't use PIDSubsystem here since we need 2 PIDControllers :(

Drive::Drive() : Subsystem("Drive"),
				lDrive(DRV_MTR_LEFT_A, DRV_MTR_LEFT_B, DRV_ENC_LEFT, "Left Drive"),
				rDrive(DRV_MTR_RIGHT_A, DRV_MTR_RIGHT_B, DRV_ENC_RIGHT, "Right Drive"),
				shifter(DRV_SOL_SHIFT)
{
	lDrive.EnablePIDDashboard();
	rDrive.EnablePIDDashboard();
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
