#include "Shooter.h"
#include "../Robotmap.h"
#include "CANJaguar.h"
#include "../Commands/ShootIdle.h"


Shooter::Shooter() : Subsystem("Shooter") {		//Define the Jaguars to be used later for powering the shooter
	sJagA = new CANJaguar(SHOOTER_A);
	sJagB = new CANJaguar(SHOOTER_B);
	sJagC = new CANJaguar(SHOOTER_C);
	sJagD = new CANJaguar(SHOOTER_D);
	
	m_speed = 0;
}
    
void Shooter::InitDefaultCommand() {
	SetDefaultCommand(new ShootIdle());
};

void Shooter::SetSpeed(double speed) {
	m_speed = speed;
};

void Shooter::Run() { //TODO: Switch to PID subsystem in the future
	sJagA->Set(m_speed);
	sJagB->Set(m_speed);
	sJagC->Set(m_speed);
	sJagD->Set(m_speed);
};

void Shooter::Stop() {
	sJagA->Set(0);
	sJagB->Set(0);
	sJagC->Set(0);
	sJagD->Set(0);
};

// Put methods for controlling this subsystem
// here. Call these from Commands.
