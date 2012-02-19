#include "DriveMotorOutput.h"
#include "SmartDashboard/SmartDashboard.h"
#include "NetworkTables/NetworkTable.h"

// 1,250 low gear max
// 3,000 high gear max

// Names of NetworkTable fields for PIDController
static const char *kP = "p";
static const char *kI = "i";
static const char *kD = "d";
static const char *kEnabled = "enabled";

DriveMotorOutput::DriveMotorOutput(UINT8 motorA, UINT8 motorB, UINT8 encoderA, UINT8 encoderB, const char* name) :
	m_motorA(motorA),
	m_motorB(motorB),
	m_enc(encoderA, encoderB, true),
	b_displayEnc(false),
	m_name(name),
	m_isHigh(false)
{
	m_enc.Start();
	
	m_prefs = Preferences::GetInstance();
	
	// The PIDController is more convenient as a pointer
	m_pid = new SendablePIDController(0.0, 0.0, 0.0, this, this); // m_enc is the PIDSource, this is the PIDOutput
	
	// Load in the previous settings to the PIDController
	char buf[50];
	double p;
	double i;
	double d;
	bool enabled;
	
	snprintf(buf, 50, "%s_P", m_name);
	p = m_prefs->GetDouble(buf, 0.0);
	snprintf(buf, 50, "%s_I", m_name);
	i = m_prefs->GetDouble(buf, 0.0);
	snprintf(buf, 50, "%s_D", m_name);
	d = m_prefs->GetDouble(buf, 0.0);
	snprintf(buf, 50, "%s_PID_EN", m_name);
	enabled = m_prefs->GetBoolean(buf, false);
	
	m_pid->SetPID(p, i, d);
	
	if(enabled) {
		m_pid->Enable();
	}
	
	// Cache this since it could be used on every run of the main loop
	snprintf(m_encName, 50, "%s Encoder", m_name);
}



DriveMotorOutput::~DriveMotorOutput()
{
	// Will cause a crash if EnablePIDDashboard has been called
	delete m_pid;
}


void DriveMotorOutput::Set(double setpoint)
{
	m_lastSetpoint = setpoint;
	if (m_pid->IsEnabled()) {
		m_pid->SetSetpoint(setpoint);
	} else {
		PIDWrite(setpoint); // If PID is disabled, pass to the output function
	}
}



void DriveMotorOutput::Shift(bool high)
{
	m_isHigh = high;
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
		return m_lastSetpoint;
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
	
	// Will display the current output mode for the encoder
	if (b_displayEnc) {
		SmartDashboard::Log(PIDGet(), m_encName);
	}
}



double DriveMotorOutput::PIDGet()
{
	return m_enc.Get() / (m_isHigh ? 3000 : 1250);
}



void DriveMotorOutput::EnablePIDDashboard()
{
	SmartDashboard::GetInstance()->PutData(m_name, m_pid);
	m_pid->GetTable()->AddChangeListenerAny(this);
	b_displayEnc = true;
}

void DriveMotorOutput::ValueChanged(NetworkTable *table, const char *name, NetworkTables_Types type)
{
	char buf[50];
	// The PIDController is also listening for changes, so there is no need to push out the new settings here
	if (strcmp(name, kEnabled) == 0)
	{
		// Save the settings so that they persist across reboots
		snprintf(buf, 50, "%s_P", m_name);
		m_prefs->PutDouble(buf, /*table->GetDouble(kP)*/ 42.0);
		snprintf(buf, 50, "%s_I", m_name);
		m_prefs->PutDouble(buf, table->GetDouble(kI));
		snprintf(buf, 50, "%s_D", m_name);
		m_prefs->PutDouble(buf, table->GetDouble(kD));
		snprintf(buf, 50, "%s_PID_EN", m_name);
		m_prefs->PutBoolean(buf, table->GetBoolean(kEnabled));
		
		printf("p: %f i: %f d: %f", table->GetDouble(kP), table->GetDouble(kI), table->GetDouble(kD));
		
		m_prefs->Save();
	}
}
