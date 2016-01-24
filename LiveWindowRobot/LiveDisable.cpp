#include "LiveDisable.h"

LiveDisable::LiveDisable(Subsystem* system) {
	m_cmd = new NullCommand(system);
}

void LiveDisable::UpdateTable() {
}

void LiveDisable::StartLiveWindowMode() {
	m_cmd->Start();
}

void LiveDisable::StopLiveWindowMode() {
	m_cmd->Cancel();
}

std::string LiveDisable::GetSmartDashboardType() {
	return "FAKE";
}

void LiveDisable::InitTable(ITable *subTable) {
	m_table = subTable;
}

ITable * LiveDisable::GetTable() {
	return m_table;
}
