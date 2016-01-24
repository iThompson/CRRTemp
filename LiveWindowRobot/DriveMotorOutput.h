#ifndef _DUALMOTOROUTPUT_H
#define _DUALMOTOROUTPUT_H

#include "CANJaguar.h"
#include "Encoder.h"

class DriveMotorOutput : public LiveWindowSendable, public ITableListener
{
public:
	DriveMotorOutput(CANJaguar* motorA, CANJaguar* motorB, Encoder* enc);
	
	void Set(double setpoint);
	
	// ITableListener interface
	void ValueChanged(ITable* source, const UString& key, EntryValue value, bool isNew);
	
	// LiveWindowSendable interface
	void UpdateTable();
	void StartLiveWindowMode();
	void StopLiveWindowMode();
	void InitTable(ITable* subtable);
	ITable* GetTable();
	std::string GetSmartDashboardType();
	
private:
	CANJaguar* m_motorA;
	CANJaguar* m_motorB;
	Encoder* m_enc;
	
	ITable* m_table;
};

#endif // _DUALMOTOROUTPUT_H
