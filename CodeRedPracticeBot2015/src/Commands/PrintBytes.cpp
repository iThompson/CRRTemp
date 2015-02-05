// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "PrintBytes.h"

PrintBytes::PrintBytes() {
	Requires(Robot::serialSensor);
}

// Called just before this Command runs the first time
void PrintBytes::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void PrintBytes::Execute() {
	Robot::serialSensor->update();
	packet_t* buffer = Robot::serialSensor->getState();
	printf("%d%d%d%d%d%d%d%d",
			buffer->chksum,
			buffer->tote1,
			buffer->tote2,
			buffer->tote3,
			buffer->tote4,
			buffer->tote5,
			buffer->padding);

}

// Make this return true when this Command no longer needs to run execute()
bool PrintBytes::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void PrintBytes::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PrintBytes::Interrupted() {

}
