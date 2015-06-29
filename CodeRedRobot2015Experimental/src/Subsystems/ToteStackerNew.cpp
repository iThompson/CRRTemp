// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "ToteStackerNew.h"
#include "../RobotMap.h"
#include "../Commands/ToteStackerNew/ToteDriveToRest.h"
#define RESTING 11500

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

ToteStackerNew::ToteStackerNew() : Subsystem("ToteStackerNew") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	toteLift = RobotMap::toteStackertoteLift;
	brake = RobotMap::toteStackerbrake;
	toteHall = RobotMap::toteStackerhall;
	m_relativePosition = StackerRelative::GROUND; //TODO: Replace, Dummy value
	m_resting = true;
	m_offset = RESTING;
	m_manual = false;
	m_justMan = false;
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}
    
void ToteStackerNew::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	SetDefaultCommand(new ToteDriveToRest());
}

bool ToteStackerNew::IsAtHome() {
	return !toteLift->GetReverseLimitOK();
}

int ToteStackerNew::GetPos() {
	return toteLift->GetEncPosition();
}

void ToteStackerNew::SetRelative(StackerRelative position) {
	m_relativePosition = position;
}

StackerRelative ToteStackerNew::GetRelative() {
	return m_relativePosition;
}

bool ToteStackerNew::GetHall() {
	return toteHall->Get();
}

void ToteStackerNew::SetSpeed(double speed) {
	SmartDashboard::PutBoolean("Zak you are not crazy", true);
	if(speed != 0) brake->Set(false);
	else brake->Set(true);
	toteLift->SetControlMode(CANTalon::ControlMode::kPercentVbus);
	SmartDashboard::PutNumber("TOTE SPEED", speed);
	toteLift->Set(-speed);
}

void ToteStackerNew::DriveToHome() {
	brake->Set(false);
	toteLift->Set(-.3);
}

void ToteStackerNew::DriveToPoint() {
	if(!toteLift->GetReverseLimitOK()) {
		toteLift->SetPosition(0);
	}


	int position = ComputeSetPoint();
	double error = position - GetPos();
	bool brakeControl = true;

	if(!toteLift->GetForwardLimitOK() && error > 0) {
		brake->Set(true);
		brakeControl = false;
	}
	else if(!toteLift->GetForwardLimitOK() && error < 0) {
		brake->Set(false);
		brakeControl = false;
	}

	SmartDashboard::PutNumber("OFFSET", m_offset);
	SmartDashboard::PutNumber("REST", m_resting);
	SmartDashboard::PutNumber("TOTE TARTGET", position);
	SmartDashboard::PutNumber("error, tote", error);
	SmartDashboard::PutNumber("current, tote", GetPos());
	SmartDashboard::PutNumber("point, tote", position);


	if(error > 100){
		if(brakeControl) brake->Set(false);
		if(error > 1000) {
			toteLift->Set(1);
		}
		else {
			toteLift->Set((error/1000));
		}
	}
	else if(error < -100) {
		if(brakeControl) brake->Set(false);
		if(error < -1000) {
			toteLift->Set(-1);
		}
		else {
			toteLift->Set((error/1000));
		}
	}
	else {
		toteLift->Set(0);
		if(brakeControl) brake->Set(true);
	}
}

void ToteStackerNew::DriveToPoint(int position) {

	if(!toteLift->GetReverseLimitOK()) {
		toteLift->SetPosition(0);
	}
	bool brakeControl = true;
	double error = position - GetPos();

	if(!toteLift->GetForwardLimitOK() && error > 0) {
		brake->Set(true);
		brakeControl = false;
	}
	else if(!toteLift->GetForwardLimitOK() && error < 0) {
		brake->Set(false);
		brakeControl = false;
	}

	SmartDashboard::PutNumber("OFFSET", m_offset);
	SmartDashboard::PutNumber("REST", m_resting);
	SmartDashboard::PutNumber("TOTE TARTGET", position);
	SmartDashboard::PutNumber("error, tote", error);
	SmartDashboard::PutNumber("current, tote", GetPos());
	SmartDashboard::PutNumber("point, tote", position);


	if(error > 100){
		if(brakeControl) brake->Set(false);
		if(error > 1000) {
			toteLift->Set(1);
		}
		else {
			toteLift->Set((error/1000));
		}
	}
	else if(error < -100) {
		if(brakeControl) brake->Set(false);
		if(error < -1000) {
			toteLift->Set(-1);
		}
		else {
			toteLift->Set((error/1000));
		}
	}
	else {
		toteLift->Set(0);
		if(brakeControl) brake->Set(true);
	}
}

bool ToteStackerNew::IsAtSetPoint() {
	return abs(ComputeSetPoint() - GetPos()) < 100; //Not same as dead zone, but might need to change.
}

int ToteStackerNew::ComputeSetPoint() {
	int position = 0;
//	position += (int)m_relativePosition;
	if(m_resting) {
		position += RESTING;
	}
	else {
		position += m_offset;
	}
	return position;
}

void ToteStackerNew::ZeroTote() {
	toteLift->SetPosition(0);
}

void ToteStackerNew::SetResting(bool resting) {
	m_resting = resting;
}

void ToteStackerNew::SetOffset(int offset) {
	m_offset = offset;
}

void ToteStackerNew::SetManual(bool manual) {
	m_manual = manual;
}

bool ToteStackerNew::GetManual() {
	return m_manual;
}

void ToteStackerNew::SetJustManTote(bool justMan) {
	m_justMan = justMan;
}

bool ToteStackerNew::GetJustManTote() {
	return m_justMan;
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

