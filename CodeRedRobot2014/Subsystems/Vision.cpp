#include "Vision.h"
#include "../Robotmap.h"

Vision::Vision() : Subsystem("Vision") {
	goalHot = RobotMap::visiongoalHot;
	LEDs = RobotMap::visionLEDs;
}
    
void Vision::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Vision::SetLEDs(Relay::Value value) {
	LEDs->Set(value);
}

bool Vision::IsGoalHot() {
	return goalHot->Get();
}
