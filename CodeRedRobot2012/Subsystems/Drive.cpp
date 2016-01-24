#include "Drive.h"
#include "../Robotmap.h"
#include "../Commands/Drive/JoystickDrive.h"

// Can't use PIDSubsystem here since we need 2 PIDControllers :(

Drive::Drive() : Subsystem("Drive"),
				lDrive(DRV_MTR_LEFT_A, DRV_MTR_LEFT_B, DRV_ENC_LEFT, "Left_Drive"),
				rDrive(DRV_MTR_RIGHT_A, DRV_MTR_RIGHT_B, DRV_ENC_RIGHT, "Right_Drive"),
				shifter(DRV_SOL_SHIFT),
				bridgeSense(DRV_ANA_BRG_SENSE)
{
	lDrive.EnablePIDDashboard();
//	rDrive.EnablePIDDashboard();
}
    
void Drive::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new JoystickDrive());
	
}

void Drive::TankDrive(double left, double right){ 		//Set the jaguars so that two are used for each tread
	lDrive.Set(left);
	rDrive.Set(-right);
}

void Drive::Shift(bool high) {
	shifter.Set(high);
	
	// Tell the drives for PID purposes
	lDrive.Shift(high);
	rDrive.Shift(high);
}


void Drive::SetMotorsCoasting() {
	lDrive.SetMotorCoasting();
	rDrive.SetMotorCoasting();
}


void Drive::SetMotorsDefault() {
	lDrive.SetMotorDefault();
	rDrive.SetMotorDefault();
}


bool Drive::HasBridge() {
	if (bridgeSense.GetVoltage() > 0.35) {
		return true;
	} else {
		return false;
	}
}
