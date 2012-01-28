#include "Shooter.h"
#include "../Robotmap.h"
#include "CANJaguar.h"

Shooter::Shooter() : Subsystem("Shooter") {		//Define the Jaguars to be used later for powering the shooter
	sJagA = new CANJaguar(SHOOTER_A);
	sJagB = new CANJaguar(SHOOTER_B);
	sJagC = new CANJaguar(SHOOTER_C);
	sJagD = new CANJaguar(SHOOTER_D);
}
    
void Shooter::InitDefaultCommand() {

}


// Put methods for controlling this subsystem
// here. Call these from Commands.
