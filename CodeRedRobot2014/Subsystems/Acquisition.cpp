// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "Acquisition.h"
#include "../Robotmap.h"
#include "../Commands/Acquisition/RollerStop.h"

#define GEAR_TEETH 20 // May be 18 or 20 -- ensure you know which arm is in use

Acquisition::Acquisition() : Subsystem("Acquisition") {
	ballSensor = RobotMap::acquisitionballSensor;
	roller = RobotMap::acquisitionroller;
	raise = RobotMap::acquisitionraise;
	rollSpeed = new GearTooth(ACQ_DIN_GEAR);
	rollSpeed->Start();
	
	
	m_speed = 0;
}

void Acquisition::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new RollerStop());
}

void Acquisition::RollerRun() {
	roller->Set(m_speed);
}

void Acquisition::RollerSetTargetSpeed(double speed) {
	m_speed = speed;
}

void Acquisition::SetArm(bool raised) {
	raise->Set(raised);
}

bool Acquisition::HasBall() {
	return ballSensor->Get();
}

double Acquisition::GetSpeed(){
	return 1/rollSpeed->GetPeriod();
}
