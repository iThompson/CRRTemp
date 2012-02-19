#ifndef _DUALMOTOROUTPUT_H
#define _DUALMOTOROUTPUT_H

#include "CANJaguar.h"
#include "PIDOutput.h"
#include "PIDSource.h"
#include "Encoder.h"
#include "Preferences.h"
#include "SmartDashboard/SendablePIDController.h"

class DriveMotorOutput : public PIDOutput, public PIDSource, public NetworkTableChangeListener
{
public:
	// If you change the name argument, the PID data will be orphaned in the prefs file
	DriveMotorOutput(UINT8 motorA, UINT8 motorB, UINT8 encoderA, UINT8 encoderB, const char* name);
	
	// If you called EnablePIDDashboard, DO NOT DELETE THIS OBJECT
	// SmartDashboard keeps a permenant reference to the PIDController
	// which cannot be removed. This WILL cause a crash if deleted
	virtual ~DriveMotorOutput();
	
	void Set(double setpoint);
	
	void Shift(bool high);
	
	void SetSpeedControl();
	void SetPositionControl();
	
	double GetSetpoint();
	double GetSpeed();
	double GetPosition();
	
	void ResetPosition();
	
	void PIDEnable(double p, double i, double d);
	void PIDDisable();
	
	// Read the message on the destructor. USE WITH CAUTION
	void EnablePIDDashboard();
	
	// PIDOutput interface
	virtual void PIDWrite(float output);
	
	// PIDSource interface
	virtual double PIDGet();
	
	// NetworkTablesChangeListener interface
	virtual void ValueChanged(NetworkTable *table, const char *name, NetworkTables_Types type);
	virtual void ValueConfirmed(NetworkTable *table, const char *name, NetworkTables_Types type) {}
	
private:
	CANJaguar m_motorA;
	CANJaguar m_motorB;
	Encoder m_enc;
	
	SendablePIDController* m_pid;
	
	Preferences* m_prefs;
	
	bool b_displayEnc;
	
	const char* m_name;
	
	char m_encName[50];
	
	double m_lastSetpoint;
	
	bool m_isHigh;
};

#endif // _DUALMOTOROUTPUT_H
