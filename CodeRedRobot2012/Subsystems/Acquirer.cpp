#include "Acquirer.h"
#include "../Robotmap.h"

Acquirer::Acquirer() : Subsystem("Acquirer"),
						belt(AQS_MTR_BELT),
						gate(AQS_SOL_GATE)
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

void Acquirer::OpenGate() {
	gate.Set(0);
}

void Acquirer::CloseGate() {
	gate.Set(1);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
