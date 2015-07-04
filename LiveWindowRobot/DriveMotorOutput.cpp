/*
 * DriveMotorOutput.cpp
 *
 *  Created on: Nov 19, 2012
 *      Author: Ian
 */

#include "DriveMotorOutput.h"
#include "LiveWindow/LiveWindow.h"

DriveMotorOutput::DriveMotorOutput(CANJaguar* motorA, CANJaguar* motorB, Encoder* enc) :
	m_motorA(motorA),
	m_motorB(motorB),
	m_enc(enc),
	m_table(NULL)
{
}

void DriveMotorOutput::Set(double setpoint)
{
	m_motorA->Set(setpoint);
	m_motorB->Set(setpoint);
}

void DriveMotorOutput::ValueChanged(ITable* source, const UString& key, EntryValue value, bool isNew) {
	Set(value.f);
}

void DriveMotorOutput::UpdateTable()
{
	if (m_table != NULL)
	{
		m_table->PutNumber("Value", m_motorA->Get());
	}
}

void DriveMotorOutput::StartLiveWindowMode()
{
	Set(0); // Just to be safe
	m_motorA->SetSafetyEnabled(false);
	m_motorB->SetSafetyEnabled(false);
	
	m_table->AddTableListener("Value", this, true);
}

void DriveMotorOutput::StopLiveWindowMode()
{
	m_motorA->SetSafetyEnabled(true);
	m_motorB->SetSafetyEnabled(true);
	
	m_table->RemoveTableListener(this);
}

std::string DriveMotorOutput::GetSmartDashboardType() {
	return "Speed Controller";
}

void DriveMotorOutput::InitTable(ITable *subTable) {
	m_table = subTable;
	UpdateTable();
}

ITable * DriveMotorOutput::GetTable() {
	return m_table;
}
