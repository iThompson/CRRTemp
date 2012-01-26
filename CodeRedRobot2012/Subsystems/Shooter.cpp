#include "Shooter.h"
#include "../Robotmap.h"

Shooter::Shooter() : Subsystem("Shooter") {
	
}
    
void Shooter::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void Shooter::Shoot(double power) {
	
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
