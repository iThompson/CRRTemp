#include "Ejection.h"
#include "../Robotmap.h"
#include "../Commands/Ejection/RetractKicker.h"

Ejection::Ejection() : Subsystem("Ejection") {
	kicker = RobotMap::ejectionkicker;
}
    
void Ejection::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new RetractKicker());
}

void Ejection::SetKicker(bool extended) {
	kicker->Set(extended);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
