#include "Drive.h"
#include "../Robotmap.h"
#include "../Commands/JoystickDrive.h"

Drive::Drive() : Subsystem("Drive") {
	
}
    
void Drive::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new JoystickDrive());
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
