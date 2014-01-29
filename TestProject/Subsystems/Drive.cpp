#include "Drive.h"
#include "../Robotmap.h"
#include "../Commands/StickDrive.h"

Drive::Drive() : Subsystem("Drive") {
	lJagA = new CANJaguar(DRIVE_LEFT_A);
	lJagB = new CANJaguar(DRIVE_LEFT_B);
	rJagA = new CANJaguar(DRIVE_RIGHT_A/*, CANJaguar::kCurrent*/);
	rJagB = new CANJaguar(DRIVE_RIGHT_B/*, CANJaguar::kCurrent*/);
//	
//	rJagA->SetPID(20.0, 0, 0);
//	rJagB->SetPID(20.0, 0, 0);
//	
//	rJagA->EnableControl();
//	rJagB->EnableControl();
}

void Drive::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new StickDrive());
}

void Drive::TankDrive(double left, double right) {
	lJagA->Set(-right);
	lJagB->Set(-right);
	rJagA->Set(left/* * 35.0f*/);
	rJagB->Set(left/* * 35.0f*/);
	
//	SmartDashboard::Log(rJagA->GetOutputCurrent(), "Current A");
}
