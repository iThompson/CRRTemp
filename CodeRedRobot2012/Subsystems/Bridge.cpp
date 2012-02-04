#include "Bridge.h"
#include "../Robotmap.h"
#include "../Commands/Undeploy.h"

Bridge::Bridge() : Subsystem("Bridge") {
	
}
    
void Bridge::InitDefaultCommand() {
	SetDefaultCommand(new Undeploy());
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void Bridge::Deploy(bool deployed)
{
	bridge->Set(deployed);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
