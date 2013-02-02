// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.
#include "Arm.h"
#include "../Robotmap.h"

#include <math.h>

#define ELBOW_EPSILON 0.01f
#define WRIST_EPSILON 0.01f

Arm::Arm() : Subsystem("Arm") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	wrist = RobotMap::armWrist;
	elbow = RobotMap::armElbow;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}
    
void Arm::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void Arm::SetWrist(double pos)
{
	wrist->Set(pos);
}



void Arm::SetElbow(double pos)
{
	elbow->Set(pos);
}



bool Arm::IsElbowAtSetpoint()
{
	return fabs(elbow->GetPosition() - elbow->Get()) < ELBOW_EPSILON;
}



bool Arm::IsWristAtSetpoint()
{
	return fabs(wrist->GetPosition() - wrist->Get()) < WRIST_EPSILON;
}



// Put methods for controlling this subsystem
// here. Call these from Commands.
