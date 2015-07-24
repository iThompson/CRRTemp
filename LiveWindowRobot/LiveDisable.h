#ifndef LIVEDISABLE_H_
#define LIVEDISABLE_H_

#include <LiveWindow/LiveWindowSendable.h>
#include <Commands/Subsystem.h>
#include "Commands/NullCommand.h"

class LiveDisable : public LiveWindowSendable
{
public:
	LiveDisable(Subsystem* system);
	
	// LiveWindowSendable interface
	void UpdateTable();
	void StartLiveWindowMode();
	void StopLiveWindowMode();
	void InitTable(ITable* subtable);
	ITable* GetTable();
	std::string GetSmartDashboardType();
	
private:
	NullCommand* m_cmd;
	ITable* m_table;
};

#endif /* LIVEDISABLE_H_ */
