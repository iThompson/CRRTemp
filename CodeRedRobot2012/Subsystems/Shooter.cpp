#include "Shooter.h"
#include "../Robotmap.h"

Shooter::Shooter() : Subsystem("Shooter") {
	sJagA = new CANJaguar(SHOOTER_A);
	sJagB = new CANJaguar(SHOOTER_B);
	sJagC = new CANJaguar(SHOOTER_C);
	sJagD = new CANJaguar(SHOOTER_D);
	
}
    
void Shooter::InitDefaultCommand() {

}


// Put methods for controlling this subsystem
// here. Call these from Commands.
