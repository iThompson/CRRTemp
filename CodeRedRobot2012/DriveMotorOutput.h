#ifndef _DUALMOTOROUTPUT_H
#define _DUALMOTOROUTPUT_H

#include "CANJaguar.h"
#include "PIDOutput.h"
#include "Encoder.h"
#include "SmartDashboard/SendablePIDController.h"

class DriveMotorOutput : public PIDOutput
{
public:
	DriveMotorOutput(UINT8 motorA, UINT8 motorB, UINT8 encoderA, UINT8 encoderB);
	
	// If you called EnablePIDDashboard, DO NOT DELETE THIS OBJECT
	// SmartDashboard keeps a permenant reference to the PIDController
	// which cannot be removed. This WILL cause a crash if deleted
	virtual ~DriveMotorOutput();
	
	void Set(double setpoint);
	
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
	
private:
	CANJaguar m_motorA;
	CANJaguar m_motorB;
	Encoder m_enc;
	
	SendablePIDController* m_pid;
};

#endif // _DUALMOTOROUTPUT_H
