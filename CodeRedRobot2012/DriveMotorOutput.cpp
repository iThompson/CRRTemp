#include "DriveMotorOutput.h"
#include "SmartDashboard/SmartDashboard.h"

DriveMotorOutput::DriveMotorOutput(UINT8 motorA, UINT8 motorB, UINT8 encoderA, UINT8 encoderB) :
	m_motorA(motorA),
	m_motorB(motorB),
	m_enc(encoderA, encoderB)
{
	m_enc.Start();
	
	// The PIDController is more convenient as a pointer
	m_pid = new SendablePIDController(0.0, 0.0, 0.0, &m_enc, this); // m_enc is the PIDSource, this is the PIDOutput
}



DriveMotorOutput::~DriveMotorOutput()
{
	// Will cause a crash if EnablePIDDashboard has been called
	delete m_pid;
}


void DriveMotorOutput::Set(double setpoint)
{
	if (m_pid->IsEnabled()) {
		m_pid->SetSetpoint(setpoint);
	} else {
		PIDWrite(setpoint); // If PID is disabled, pass to the output function
	}
}



void DriveMotorOutput::SetSpeedControl()
{
	m_enc.SetPIDSourceParameter(Encoder::kRate);
}



void DriveMotorOutput::SetPositionControl()
{
	m_enc.SetPIDSourceParameter(Encoder::kDistance);
}



double DriveMotorOutput::GetSetpoint()
{
	if (m_pid->IsEnabled())
	{
		return m_pid->GetSetpoint();
	} else {
		// TODO: Should we save the setpoint when PID is disabled?
		// This calls out across the CAN bus to get the value
		return m_motorA.Get();
	}
}



double DriveMotorOutput::GetPosition()
{
	return m_enc.GetDistance();
}


double DriveMotorOutput::GetSpeed()
{
	return m_enc.GetRate();
}



void DriveMotorOutput::ResetPosition()
{
	m_enc.Reset();
	m_enc.Start();
}



void DriveMotorOutput::PIDEnable(double p, double i, double d)
{
	m_pid->SetPID(p, i, d);
	m_pid->Enable();
}



void DriveMotorOutput::PIDDisable()
{
	m_pid->Disable();
}


void DriveMotorOutput::PIDWrite(float output)
{
	m_motorA.Set(output);
	m_motorB.Set(output);
}



void DriveMotorOutput::EnablePIDDashboard()
{
	SmartDashboard::GetInstance()->PutData("DrivePIDController", m_pid);
}
