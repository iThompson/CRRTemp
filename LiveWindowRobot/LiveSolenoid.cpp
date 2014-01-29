#include "LiveSolenoid.h"

LiveSolenoid::LiveSolenoid(UINT32 channel) : Solenoid(channel)
{
}

LiveSolenoid::LiveSolenoid(UINT8 moduleNumber, UINT32 channel) : Solenoid(moduleNumber, channel)
{
}

void LiveSolenoid::ValueChanged(ITable* source, const UString& key, EntryValue value, bool isNew) {
	Set(value.b);
}

void LiveSolenoid::UpdateTable() {
	if (m_table != NULL)
	{
		m_table->PutNumber("Value", Get());
	}
}

void LiveSolenoid::StartLiveWindowMode() {
	m_table->AddTableListener("Value", this, true);
}

void LiveSolenoid::StopLiveWindowMode() {
	m_table->RemoveTableListener(this);
}

std::string LiveSolenoid::GetSmartDashboardType() {
	return "Digital Output";
}

void LiveSolenoid::InitTable(ITable *subTable) {
	m_table = subTable;
	UpdateTable();
}

ITable * LiveSolenoid::GetTable() {
	return m_table;
}
