#ifndef ACQUIRER_H
#define ACQUIRER_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author Ian
 */
//class Acquirer: public Subsystem, public NetworkTableChangeListener {
// BETA: Convert to ITable
class Acquirer : public Subsystem, public ITableListener {
private:
	Victor belt;
	
	AnalogChannel gateLeft;
	AnalogChannel gateRight;
	AnalogChannel ballHigh;
	AnalogChannel ballLow;
	
	int ballCount;
	
	double m_speed;

	int m_ballCountEntry;
	bool m_hasBallExit;
	
	SEM_ID m_countLock;
	
	void CheckCounters(bool forward);
	bool IsSingleEntry();
	bool IsDoubleEntry();
	void PostBallCount();
	
public:
	Acquirer();
	void InitDefaultCommand();
	
	void BeltRun();
	void BeltStop();
	void BeltReverse();
	void BeltSpeed(double speed);
	
	void SetBallCount(int num);
	int GetBallCount();
	void AddBall();
	void RemoveBall();
	
	bool IsExitReady();
	
//	// NetworkTableChangeListener interface
//	virtual void ValueChanged(NetworkTable *table, const char *name, NetworkTables_Types type);
//	virtual void ValueConfirmed(NetworkTable *table, const char *name, NetworkTables_Types type) {}
	
	virtual void ValueChanged(ITable* source, const std::string& key, EntryValue value, bool isNew);
};

#endif
