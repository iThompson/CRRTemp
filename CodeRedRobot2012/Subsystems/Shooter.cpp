#include "Shooter.h"
#include "../Robotmap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "../Commands/Shooter/ShootOff.h"
#include <math.h>

// It's desirable that everything possible under private except
// for methods that implement subsystem capabilities
// set the P, I, and D constants here
static const double Kp = 2.00;
static const double Ki = 0.75;
static const double Kd = 0.1;


// Names of NetworkTable fields for PIDController
static const char *kP = "p";
static const char *kI = "i";
static const char *kD = "d";
static const char *kEnabled = "enabled";

static const float kSoftA = 1.14129e-06;
static const float kSoftB = -3.27442e-03;
static const float kSoftC = 3.24477;
static const float kSoftComp = 1.634;
static const float kHardA = -2.42546e-06;
static const float kHardB = 8.84360e-03;
static const float kHardC = 6.61528;
static const float kHardComp = 1.51;

Shooter::Shooter() : PIDSubsystem("Shooter", Kp, Ki, Kd, 0.02),
					 sJagA(SHO_MTR_A),
					 sJagB(SHO_MTR_B),
					 sJagC(SHO_MTR_C),
					 sJagD(SHO_MTR_D),
					 m_enc(SHO_CNT_SPEED)
{
//	double p;
//	double i;
//	double d;
//	bool enabled;
	
	m_speed = 0;                                                                                                                                                           
	
	m_enc.Start();
	
	// Once tuning has been finished, these may be hard-coded
//	m_prefs = Preferences::GetInstance();
//	// If this is the first run, defaults of 0.0 and false will kick in
//	p = m_prefs->GetDouble("SHO_P", 0.0);
//	i = m_prefs->GetDouble("SHO_I", 0.0);
//	d = m_prefs->GetDouble("SHO_D", 0.0);
//	enabled = m_prefs->GetBoolean("SHO_PID_EN", false);
//	
	// GetPIDController() returns a PIDController, which doesn't have the GetTable()
	// function we need to hook updates or to add it to the dashboard
//	SendablePIDController* controller = (SendablePIDController*)GetPIDController();
	
	// Write the prefs into the PIDController
//	GetPIDController()->SetPID(p, i, d);
//	if (enabled) Enable();
	
	Enable();
	
	// Debugging mode:
	// Allows PID constants to be modified on the DS
//	SmartDashboard::GetInstance()->PutData("Shooter PID", controller);
	// Hook updates from the Dashboard so we can save them to prefs
//	controller->GetTable()->AddChangeListenerAny(this);
}
double Shooter::ReturnPIDInput() {
	// Scale speeds to 1.0 max
	// Makes jumping to manual control easier
	return m_enc.GetRate() / kMaxRate ;
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
	SmartDashboard::PutNumber("Shooter Speed", m_speed);
}

double Shooter::GetSpeed() {
	return m_speed;
}

void Shooter::UsePIDOutput(double output) {
	if (output < 0.0 | m_speed == 0.0) output = 0.0;
	sJagA.Set(output);
	sJagB.Set(output);
	sJagC.Set(-output);
	sJagD.Set(-output);
	
	SmartDashboard::PutNumber("Right Shooter", sJagA.GetOutputCurrent());
	SmartDashboard::PutNumber("Left Shooter", sJagC.GetOutputCurrent());
	
	SmartDashboard::PutNumber("Gear Tooth", ReturnPIDInput());
}

double Shooter::LookUp(UINT16 x, double compression) {	
	SmartDashboard::PutNumber("Lookup Distance", (double) x);
	double compRatio = (compression - kHardComp) / (kSoftComp - kHardComp);
	
	double speedSoft = (kSoftA * (x * x)) + kSoftB*x + kSoftC;
	double speedHard = (kHardA * (x * x)) + kHardB*x + kHardC;
	
	// Merge the two values
	return speedHard + (speedSoft - speedHard) * compRatio;
}

//void Shooter::ValueChanged(NetworkTable *table, const char *name, NetworkTables_Types type)
//{
//	// The PIDController is also listening for changes, so there is no need to push out the new settings here
//	if (strcmp(name, kP) == 0 || strcmp(name, kI) == 0 || strcmp(name, kD) == 0)
//	{
//		// Save the settings so that they persist across reboots
//		m_prefs->PutDouble("SHO_P", table->GetDouble(kP));
//		m_prefs->PutDouble("SHO_I", table->GetDouble(kI));
//		m_prefs->PutDouble("SHO_D", table->GetDouble(kD));
//	}
//	else if (strcmp(name, kEnabled) == 0)
//	{
//		m_prefs->PutBoolean("SHO_PID_EN", table->GetBoolean(kEnabled));
//	}
//}

void Shooter::ValueChanged(ITable* source, const std::string& key, EntryValue value, bool isNew)
{
	// The PIDController is also listening for changes, so there is no need to push out the new settings here
	if (key == kP || key == kI || key == kD)
	{
		// Save the settings so that they persist across reboots
		m_prefs->PutDouble("SHO_P", source->GetNumber(kP));
		m_prefs->PutDouble("SHO_I", source->GetNumber(kI));
		m_prefs->PutDouble("SHO_D", source->GetNumber(kD));
	}
	else if (key == kEnabled)
	{
		m_prefs->PutBoolean("SHO_PID_EN", source->GetBoolean(kEnabled));
	}
}
