#include "Vision.h"
#include "../Robotmap.h"
#include "../Commands/Vision/TurnLEDsOff.h"

Vision::Vision() : Subsystem("Vision") {
	goalHot = RobotMap::visiongoalHot;
	LEDs = RobotMap::visionLEDs;
}

void Vision::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new TurnLEDsOff());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Vision::SetLEDs(Relay::Value value) {
	LEDs->Set(value);
}

bool Vision::IsGoalHot() {
	return !goalHot->Get(); // Pin is pulled high, so a low indicates that the target is sighted
}
