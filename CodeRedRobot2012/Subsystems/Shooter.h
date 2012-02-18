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
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	// set the P, I, and D constants here
	static const double Kp = 0.0;
	static const double Ki = 0.0;
	static const double Kd = 0.0;
	
	// Calculated using motor curves, update w/ experimental data
	static const double kMaxRate = 300.0;
	
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
