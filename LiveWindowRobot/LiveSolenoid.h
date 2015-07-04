#ifndef LIVESOLENOID_H_
#define LIVESOLENOID_H_

#include <Solenoid.h>
#include "LiveWindow/LiveWindowSendable.h"
#include "tables/ITableListener.h"

class LiveSolenoid : public Solenoid, public LiveWindowSendable, public ITableListener {
public:
	explicit LiveSolenoid(UINT32 channel);
	LiveSolenoid(UINT8 moduleNumber, UINT32 channel);

	virtual void ValueChanged(ITable* source, const UString& key, EntryValue value, bool isNew);
	void UpdateTable();
	void StartLiveWindowMode();
	void StopLiveWindowMode();
	std::string GetSmartDashboardType();
	void InitTable(ITable *subTable);
	ITable * GetTable();
	
private:
	ITable* m_table;
};

#endif /* LIVESOLENOID_H_ */
