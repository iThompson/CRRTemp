// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "ContainerStacker.h"
#include "../RobotMap.h"
#include "../Commands/ContainerStacker/RunClawToPos.h"

#define TOTE_DIFF 4000
#define POSITION_OFFSET 2000
#define PLATFORM_OFFSET 1000
#define RESTING_POINT 0
#define MAX 24000

#define LOWER_LIMIT 0
#define UPPER_LIMIT 24300
#define HALL_POINT 1275
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

ContainerStacker::ContainerStacker() : Subsystem("ContainerStacker") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	containerLift = RobotMap::containerStackercontainerLift;
	claw = RobotMap::containerStackerclaw;
	containerHall = RobotMap::containerStackerhall;
	m_targetHeight = -1; //TODO: Dummy Value Replace(Maybe)
	m_standingMode = true;
	m_platform = false;
	m_manualControl = false;
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}

void ContainerStacker::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	SetDefaultCommand(new RunClawToPos());
}

void ContainerStacker::SetClaw(bool closed) {
	if(closed && m_targetHeight == -1) {
		m_standingMode = true;
	}
	else if(closed && m_targetHeight == 0) {
		m_standingMode = false;
	}
	claw->Set(!closed);
}

bool ContainerStacker::IsAtHome() {
	return !containerLift->GetForwardLimitOK();
}

void ContainerStacker::DriveToPoint() {
	SmartDashboard::PutNumber("TargetPosition", m_targetHeight);
	int position = CalculatePos();

	double error = position - GetCurrentPos();
	SmartDashboard::PutNumber("error, can", error);
	SmartDashboard::PutNumber("current, can", GetCurrentPos());
	SmartDashboard::PutNumber("point, can", position);
	CheckSensors();

	if(error > 50){
		if(error > 1000) {
			containerLift->Set(-1);
		}
		else {
			containerLift->Set(-error/1000);
		}
	}
	else if(error < -50) {

		if(error < -1000) {
			containerLift->Set(1);
		}
		else {
			containerLift->Set(-error/1000);
		}
	}
	else {
		containerLift->Set(0);
	}

}

int ContainerStacker::GetTargetHeight() {
	return m_targetHeight;
}

void ContainerStacker::SetTargetHeight(int height) {
	if(height < -1) {
		height = -1;
	}
	else if(height > 6) {
		height = 6;
	}
	m_targetHeight = height;
	SmartDashboard::PutNumber("target height, can", m_targetHeight);
}

void ContainerStacker::SetStanding(bool standing) {
	m_standingMode = standing;
}

bool ContainerStacker::GetStanding() {
	return m_standingMode;
}

void ContainerStacker::SetPlatform(bool platform) {
	m_platform = platform;
}

bool ContainerStacker::GetPlatform() {
	return m_platform;
}

bool ContainerStacker::GetManual() {
	return m_manualControl;
}

void ContainerStacker::SetControlMode(bool manual) {
	m_manualControl = manual;
}

double ContainerStacker::GetCurrentPos() {
	return containerLift->GetEncPosition();
}

void ContainerStacker::SetSpeed(double speed) {
	containerLift->Set(speed);
}

int ContainerStacker::CalculatePos() {
	int height = 0;
	if(m_targetHeight == -1) {
		height = RESTING_POINT;
	}
	else if(m_targetHeight == 0) {
		height = RESTING_POINT + POSITION_OFFSET;
	}
	else if(m_targetHeight == 6) {
		height = MAX;
	}
	else {
		height = TOTE_DIFF * m_targetHeight;
		if(!m_standingMode) {
			height += POSITION_OFFSET;
		}
	}
	if(m_platform) {
		height += PLATFORM_OFFSET;
	}

	return height;
}

void ContainerStacker::RunToHome() {
	containerLift->Set(-1);
}

void ContainerStacker::DriveToPoint(int point) {
	double error = point - GetCurrentPos();
	SmartDashboard::PutNumber("error1, can", error);
	SmartDashboard::PutNumber("current1, can", GetCurrentPos());
	SmartDashboard::PutNumber("point1, can", point);
	CheckSensors();
	if(error > 50){
		if(error > 1000) {
			containerLift->Set(-1);
		}
		else {
			containerLift->Set(-error/1000);
		}
	}
	else if(error < -50) {
		if(error < -1000) {
			containerLift->Set(1);
		}
		else {
			containerLift->Set(-error/1000);
		}
	}
	else {
		containerLift->Set(0);
	}
}

bool ContainerStacker::GetHall() {
	return containerHall->Get();
}

void ContainerStacker::ZeroContainer() {
	containerLift->SetPosition(0);
}

void ContainerStacker::CheckSensors() {
	if(!containerLift->GetForwardLimitOK()) {
		containerLift->SetPosition(LOWER_LIMIT);
	}
//	else if(!containerLift->GetReverseLimitOK()) {
//		containerLift->SetPosition(UPPER_LIMIT);
//	}
	else if(!containerHall->Get()) {
		containerLift->SetPosition(HALL_POINT);
	}
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

