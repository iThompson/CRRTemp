#include "Shooter.h"
#include "../Robotmap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "CANJaguar.h"
#include "../Commands/ShootOff.h"

Shooter::Shooter() : PIDSubsystem("Shooter", Kp, Ki, Kd) {
	// Use these to get going:
	// SetSetpoint() -  Sets where the PID controller should move the system
	//                  to
	// Enable() - Enables the PID controller.
	
	sJagA = new CANJaguar(SHO_MTR_A);
	sJagB = new CANJaguar(SHO_MTR_B);
	sJagC = new CANJaguar(SHO_MTR_C);
	sJagD = new CANJaguar(SHO_MTR_D);
	
	m_speed = 0;
}

double Shooter::ReturnPIDInput() {
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;
	return 0.0;
}

void Shooter::UsePIDOutput(double output) {
	sJagA->Set(m_speed);
	sJagB->Set(m_speed);
	sJagC->Set(m_speed);
	sJagD->Set(m_speed);
}

void Shooter::InitDefaultCommand() {
	SetDefaultCommand(new ShootOff());
}
