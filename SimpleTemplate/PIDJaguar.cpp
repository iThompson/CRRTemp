/*
 * PIDJaguar.cpp
 *
 *  Created on: Jan 26, 2013
 *      Author: Programmer
 */

#include "PIDJaguar.h"

// LiveWindow interface
static const char *kP = "p";
static const char *kI = "i";
static const char *kD = "d";
static const char *kSetpoint = "setpoint";
static const char *kEnabled = "enabled";


PIDJaguar::PIDJaguar(UINT8 deviceNumber, ControlMode controlMode) : CANJaguar(deviceNumber, controlMode),
		m_controlMode(controlMode),
		m_bSpeedReference(false),
		m_bPosReference(false),
		m_bPID(false),
		m_bControlEnabled(false),
		m_bRampRate(false),
		m_bNeutralMode(false),
		m_bCodesPerRev(false),
		m_bTurns(false),
		m_bSoftLimit(false),
		m_bMaxVoltage(false),
		m_bFaultTime(false),
		m_pidTable(NULL)
{
	GetPowerCycled(); // Clear the power flag prior to initial config
	// Copypasta from CANJaguar.cpp
	switch (m_controlMode)
	{
	case kPercentVbus:
	case kVoltage:
		// No additional configuration required... start enabled.
		m_bControlEnabled = true;
		break;
	default:
		break;
	}
}

void PIDJaguar::WriteConfig()
{
	if (m_bControlEnabled)
	{
		CANJaguar::ChangeControlMode(m_controlMode);
		CANJaguar::EnableControl(m_initialEnc);
	}
	else
	{
		CANJaguar::DisableControl();
	}

	if (m_bSpeedReference)
		CANJaguar::SetSpeedReference(m_speedReference);

	if (m_bPosReference)
		CANJaguar::SetPositionReference(m_posReference);

	if (m_bPID)
		CANJaguar::SetPID(m_p, m_i, m_d);

	if (m_bRampRate)
		CANJaguar::SetVoltageRampRate(m_rampRate);

	if (m_bNeutralMode)
		CANJaguar::ConfigNeutralMode(m_neutralMode);

	if (m_bCodesPerRev)
		CANJaguar::ConfigEncoderCodesPerRev(m_codesPerRev);

	if (m_bTurns)
		CANJaguar::ConfigPotentiometerTurns(m_turns);

	if (m_bSoftLimit)
		CANJaguar::ConfigSoftPositionLimits(m_forwardLimit, m_reverseLimit);

	if (m_bMaxVoltage)
		CANJaguar::ConfigMaxOutputVoltage(m_maxVoltage);

	if (m_bFaultTime)
		CANJaguar::ConfigFaultTime(m_faultTime);
}

void PIDJaguar::Set(float value, UINT8 syncGroup)
{
	if (GetPowerCycled())
		WriteConfig();
	CANJaguar::Set(value, syncGroup);

	if (m_pidTable != NULL) {
		m_pidTable->PutNumber(kSetpoint, value);
	}
}

void PIDJaguar::SetPositionReference(PositionReference reference)
{
	m_posReference = reference;
	m_bPosReference = true;
	CANJaguar::SetPositionReference(reference);
}



void PIDJaguar::DisableSoftPositionLimits()
{
	m_bSoftLimit = false;
	CANJaguar::DisableSoftPositionLimits();
}



void PIDJaguar::SetPID(double p, double i, double d)
{
	m_p = p;
	m_i = i;
	m_d = d;
	m_bPID = true;
	CANJaguar::SetPID(p, i, d);

	if(m_pidTable!=NULL){
		m_pidTable->PutNumber(kP, p);
		m_pidTable->PutNumber(kI, i);
		m_pidTable->PutNumber(kD, d);
	}
}



void PIDJaguar::ConfigPotentiometerTurns(UINT16 turns)
{
	m_turns = turns;
	m_bTurns = true;
	CANJaguar::ConfigPotentiometerTurns(turns);
}



void PIDJaguar::ConfigEncoderCodesPerRev(UINT16 codesPerRev)
{
	m_codesPerRev = codesPerRev;
	m_bCodesPerRev = true;
	CANJaguar::ConfigEncoderCodesPerRev(codesPerRev);
}



void PIDJaguar::ChangeControlMode(ControlMode controlMode)
{
	m_controlMode = controlMode;
	m_bControlEnabled = false;
	CANJaguar::ChangeControlMode(controlMode);
	
	if (m_pidTable != NULL) {
		m_pidTable->PutBoolean(kEnabled, false);
	}
}



void PIDJaguar::SetSpeedReference(SpeedReference reference)
{
	m_speedReference = reference;
	m_bSpeedReference = true;
	CANJaguar::SetSpeedReference(reference);
}



void PIDJaguar::ConfigNeutralMode(NeutralMode mode)
{
	m_neutralMode = mode;
	m_bNeutralMode = true;
	CANJaguar::ConfigNeutralMode(mode);
}



void PIDJaguar::ConfigSoftPositionLimits(double forwardLimitPosition, double reverseLimitPosition)
{
	m_forwardLimit = forwardLimitPosition;
	m_reverseLimit = reverseLimitPosition;
	m_bSoftLimit = true;
	CANJaguar::ConfigSoftPositionLimits(forwardLimitPosition, reverseLimitPosition);
}



void PIDJaguar::SetVoltageRampRate(double rampRate)
{
	m_rampRate = rampRate;
	m_bRampRate = true;
	CANJaguar::SetVoltageRampRate(rampRate);
}



void PIDJaguar::EnableControl(double encoderInitialPosition)
{
	m_initialEnc = encoderInitialPosition;
	m_bControlEnabled = true;
	CANJaguar::EnableControl();

	if (m_pidTable != NULL) {
		m_pidTable->PutBoolean(kEnabled, true);
	}
}



void PIDJaguar::DisableControl()
{
	m_bControlEnabled = false;
	CANJaguar::DisableControl();

	if (m_pidTable != NULL) {
		m_pidTable->PutBoolean(kEnabled, false);
	}
}



void PIDJaguar::ConfigMaxOutputVoltage(double voltage)
{
	m_maxVoltage = voltage;
	m_bMaxVoltage = true;
	CANJaguar::ConfigMaxOutputVoltage(voltage);
}



void PIDJaguar::ConfigFaultTime(float faultTime)
{
	m_faultTime = faultTime;
	m_bFaultTime = true;
	CANJaguar::ConfigFaultTime(faultTime);
}


std::string PIDJaguar::GetSmartDashboardType(){
	return "PIDController";
}

void PIDJaguar::InitTable(ITable* table){
	if(m_pidTable!=NULL)
		m_pidTable->RemoveTableListener(this);
	m_pidTable = table;
	if(m_pidTable!=NULL){
		m_pidTable->PutNumber(kP, m_p);
		m_pidTable->PutNumber(kI, m_i);
		m_pidTable->PutNumber(kD, m_d);
		m_pidTable->PutNumber(kSetpoint, Get());
		m_pidTable->PutBoolean(kEnabled, m_bControlEnabled);
		m_pidTable->AddTableListener(this, false);
	}
}

ITable* PIDJaguar::GetTable(){
	return m_pidTable;
}

void PIDJaguar::ValueChanged(ITable* source, const std::string& key, EntryValue value, bool isNew){
	if (key==kP || key==kI || key==kD) {
		if (m_p != source->GetNumber(kP) || m_i != source->GetNumber(kI) || m_d != source->GetNumber(kD)) {
			SetPID(source->GetNumber(kP, 0.0), source->GetNumber(kI, 0.0), source->GetNumber(kD, 0.0));
		}
	} else if (key==kSetpoint) {
		Set(value.f);
	} else if (key==kEnabled && m_bControlEnabled != value.b) {
		if (value.b) {
			EnableControl(m_initialEnc);
		} else {
			DisableControl();
		}
	}
}

void PIDJaguar::UpdateTable() {

}

void PIDJaguar::StartLiveWindowMode() {

}

void PIDJaguar::StopLiveWindowMode() {

}
