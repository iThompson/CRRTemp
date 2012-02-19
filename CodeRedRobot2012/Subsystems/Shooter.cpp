#include "Shooter.h"
#include "../Robotmap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "../Commands/Shooter/ShootOff.h"
#include <math.h>

// Names of NetworkTable fields for PIDController
static const char *kP = "p";
static const char *kI = "i";
static const char *kD = "d";
static const char *kEnabled = "enabled";

#define TABLE_SIZE 5
static double kLookUp[TABLE_SIZE] = {0.2, 0.4, 0.6, 0.8, 1.0};

Shooter::Shooter() : PIDSubsystem("Shooter", Kp, Ki, Kd),
					 sJagA(SHO_MTR_A),
					 sJagB(SHO_MTR_B),
					 sJagC(SHO_MTR_C),
					 sJagD(SHO_MTR_D),
					 m_enc(SHO_CNT_SPEED)
{
	double p;
	double i;
	double d;
	bool enabled;
	
	m_speed = 0;
	
	m_enc.Start();
	
	// Once tuning has been finished, these may be hard-coded
	m_prefs = Preferences::GetInstance();
	// If this is the first run, defaults of 0.0 and false will kick in
	p = m_prefs->GetDouble("SHO_P", 0.0);
	i = m_prefs->GetDouble("SHO_I", 0.0);
	d = m_prefs->GetDouble("SHO_D", 0.0);
	enabled = m_prefs->GetBoolean("SHO_PID_EN", false);
	
	// GetPIDController() returns a PIDController, which doesn't have the GetTable()
	// function we need to hook updates or to add it to the dashboard
	SendablePIDController* controller = (SendablePIDController*)GetPIDController();
	
	// Write the prefs into the PIDController
	GetPIDController()->SetPID(p, i, d);
	if (enabled) Enable();
	
	// Debugging mode:
	// Allows PID constants to be modified on the DS
	//SmartDashboard::GetInstance()->PutData("Shooter PID", controller);
	// Hook updates from the Dashboard so we can save them to prefs
	//controller->GetTable()->AddChangeListenerAny(this);
}
double Shooter::ReturnPIDInput() {
	// Scale speeds to 1.0 max
	// Makes jumping to manual control easier
	return m_enc.GetRate() / kMaxRate;
}

void Shooter::InitDefaultCommand() {
	SetDefaultCommand(new ShootOff());
}

void Shooter::Stop() {
	Output(0);
}
/* author@geoffrey.twardokus */

void Shooter::Run() {
	Output(m_speed);
}

void Shooter::Output(double speed) {
	// If PIDController is not active, run with raw speed
	if (GetPIDController()->IsEnabled()) {
		SetSetpoint(speed);
	} else {
		UsePIDOutput(speed);
	}
}

void Shooter::SetSpeed(double speed) {
	m_speed = speed;
	SmartDashboard::Log(m_speed, "Shooter Speed");
}

void Shooter::UsePIDOutput(double output) {
	sJagA.Set(output);
	sJagB.Set(output);
	sJagC.Set(-output);
	sJagD.Set(-output);
	
	SmartDashboard::Log(sJagA.GetOutputCurrent(), "Right Shooter");
	SmartDashboard::Log(sJagC.GetOutputCurrent(), "Left Shooter");
	
	SmartDashboard::Log(ReturnPIDInput(), "Gear Tooth");
}

double Shooter::LookUp(UINT16 value) {
	// Round to the nearest multiple of 4
	int index = (int) (value + 2) / 4;
	
	if (!(index < TABLE_SIZE)) index = TABLE_SIZE - 1;
	
	return kLookUp[index];
}

void Shooter::ValueChanged(NetworkTable *table, const char *name, NetworkTables_Types type)
{
	// The PIDController is also listening for changes, so there is no need to push out the new settings here
	if (strcmp(name, kP) == 0 || strcmp(name, kI) == 0 || strcmp(name, kD) == 0)
	{
		// Save the settings so that they persist across reboots
		m_prefs->PutDouble("SHO_P", table->GetDouble(kP));
		m_prefs->PutDouble("SHO_I", table->GetDouble(kI));
		m_prefs->PutDouble("SHO_D", table->GetDouble(kD));
	}
	else if (strcmp(name, kEnabled) == 0)
	{
		m_prefs->PutBoolean("SHO_PID_EN", table->GetBoolean(kEnabled));
	}
}
