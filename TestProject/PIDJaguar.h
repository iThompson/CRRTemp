#ifndef _PIDJAGUAR_H
#define _PIDJAGUAR_H

#include "NetworkTables/NetworkTableChangeListener.h"
#include "CANJaguar.h"
#include "SmartDashboard/SmartDashboardData.h"

class PIDJaguar : public CANJaguar, public SmartDashboardData, public NetworkTableChangeListener
{
public:
	explicit PIDJaguar(UINT8 deviceNumber, ControlMode controlMode = kPercentVbus);
	virtual ~PIDJaguar();

	virtual void Set(float value, UINT8 syncGroup=0);
	virtual void SetPID(double p, double i, double d); 
	virtual void EnableControl();
	virtual void DisableControl();

	// SmartDashboardData interface
	virtual std::string GetType() {return "PIDController";}
	virtual NetworkTable *GetTable();

	// NetworkTableChangeListener interface
	virtual void ValueChanged(NetworkTable *table, const char *name, NetworkTables_Types type);
	virtual void ValueConfirmed(NetworkTable *table, const char *name, NetworkTables_Types type) {}

private:
	NetworkTable* m_table;
	bool m_bEnabled;
};

#endif // _PIDJAGUAR_H
