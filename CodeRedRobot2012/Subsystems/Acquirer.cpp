#include "Acquirer.h"
#include "../Robotmap.h"

Acquirer::Acquirer() : Subsystem("Acquirer"),
						belt(AQS_MTR_BELT)
{
}
    
void Acquirer::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void Acquirer::RunBelt() {
	belt.Set(1.0);
}

void Acquirer::StopBelt() {
	belt.Set(0.0);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
