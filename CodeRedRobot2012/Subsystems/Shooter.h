#ifndef SHOOTER_H
#define SHOOTER_H

#include "Commands/PIDSubsystem.h"
#include "../GearToothEncoder.h"
#include "WPILib.h"

#define TABLE_SIZE 5

/**
 *
 *
 * @author geoffrey.twardokus
 */
class Shooter: public PIDSubsystem, public NetworkTableChangeListener {
private:
	
	// Calculated using motor curves, updated w/ experimental data
	static const double kMaxRate = 160.0;
	
	CANJaguar sJagA;
	CANJaguar sJagB;
	CANJaguar sJagC;
	CANJaguar sJagD;
	
	GearToothEncoder m_enc;
	
	double m_speed;

	void Output(double speed);
	
	Preferences *m_prefs;
	
public:
	Shooter();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
	void Stop();
	void Run();
	void SetSpeed(double speed);
	
	double LookUp(UINT16 value);
	
	// NetworkTableChangeListener interface
	virtual void ValueChanged(NetworkTable *table, const char *name, NetworkTables_Types type);
	virtual void ValueConfirmed(NetworkTable *table, const char *name, NetworkTables_Types type) {}
};

#endif
