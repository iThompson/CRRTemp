#include "Shooter.h"
#include "../Robotmap.h"
#include "CANJaguar.h"
#include "Solenoid.h"

Shooter::Shooter() : Subsystem("Shooter") {		//Define the Jaguars to be used later for powering the shooter
	sJagA = new CANJaguar(SHOOTER_A);
	sJagB = new CANJaguar(SHOOTER_B);
	sJagC = new CANJaguar(SHOOTER_C);
	sJagD = new CANJaguar(SHOOTER_D);
	SolA  = new Solenoid(GATE_TOP);
	SolB  = new Solenoid(GATE_BOT);
}
    
void Shooter::InitDefaultCommand() {
	

}

void Shooter::Shoot(float power) {
	
}
void Shooter::Spin(double speed) {
	sJagA->Set(speed);
	sJagB->Set(speed);
	sJagC->Set(speed);
	sJagD->Set(speed);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
