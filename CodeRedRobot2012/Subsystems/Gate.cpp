#include "Gate.h"
#include "../Robotmap.h"
#include "../Commands/Gate/Undeploy.h"

Gate::Gate() : Subsystem("Gate"),
			   gate(GTE_SOL_GATE)
{
	
}
    
void Gate::InitDefaultCommand() {
	SetDefaultCommand(new Undeploy());
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void Gate::SetState(bool closed) {
	gate.Set(closed);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
