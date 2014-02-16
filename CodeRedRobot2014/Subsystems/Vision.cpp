#include "Vision.h"
#include "../Robotmap.h"
#include "../Commands/Vision/TurnLEDsOfF.h"

Vision::Vision() : Subsystem("Vision") {
	goalHot = RobotMap::visiongoalHot;
	LEDs = RobotMap::visionLEDs;
}

void Vision::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new TurnLEDsOff());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Vision::SetLEDs(Relay::Value value) {
	LEDs->Set(value);
}

bool Vision::IsGoalHot() {
	return goalHot->Get();
}
