/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2011. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#include "PIDJaguar.h"

#include "NetworkTables/NetworkTable.h"

static const char *kP = "p";
static const char *kI = "i";
static const char *kD = "d";
static const char *kSetpoint = "setpoint";
static const char *kEnabled = "enabled";

/**
 * Allocate a PID object with the given constants for P, I, D, using a 50ms period.
 * @param p the proportional coefficient
 * @param i the integral coefficient
 * @param d the derivative coefficient
 * @param source The PIDSource object that is used to get values
 * @param output The PIDOutput object that is set to the output value
 */
PIDJaguar::PIDJaguar(UINT8 deviceNumber, ControlMode controlMode) :
		CANJaguar(deviceNumber, controlMode),
		m_table(NULL),
		m_bEnabled(false)
{
}

PIDJaguar::~PIDJaguar()
{
	if (m_table != NULL)
		m_table->RemoveChangeListenerAny(this);
}

/**
 * Set the setpoint for the PIDController
 * @param setpoint the desired setpoint
 */
void PIDJaguar::Set(float setpoint, UINT8 syncGroup)
{
	CANJaguar::Set(setpoint, syncGroup);

	if (m_table != NULL)
	{
		m_table->PutDouble(kSetpoint, setpoint);
	}
}

/**
 * Set the PID Controller gain parameters.
 * Set the proportional, integral, and differential coefficients.
 * @param p Proportional coefficient
 * @param i Integral coefficient
 * @param d Differential coefficient
 */
void PIDJaguar::SetPID(double p, double i, double d)
{
	CANJaguar::SetPID(p, i, d);

	if (m_table != NULL)
	{
		m_table->PutDouble(kP, p);
		m_table->PutDouble(kI, i);
		m_table->PutDouble(kD, d);
	}
}

/**
 * Begin running the PIDController
 */
void PIDJaguar::EnableControl()
{
	CANJaguar::EnableControl();
	
	m_bEnabled = true;

	if (m_table != NULL)
		m_table->PutBoolean(kEnabled, true);
}

/**
 * Stop running the PIDController, this sets the output to zero before stopping.
 */
void PIDJaguar::DisableControl()
{
	CANJaguar::DisableControl();
	
	m_bEnabled = false;

	if (m_table != NULL)
		m_table->PutBoolean(kEnabled, false);
}

NetworkTable* PIDJaguar::GetTable()
{
	if (m_table == NULL)
	{
		m_table = new NetworkTable();

		m_table->PutDouble(kP, GetP());
		m_table->PutDouble(kI, GetI());
		m_table->PutDouble(kD, GetD());
		m_table->PutDouble(kSetpoint, Get());
		m_table->PutBoolean(kEnabled, m_bEnabled);

		m_table->AddChangeListenerAny(this);
	}
	return m_table;
}

void PIDJaguar::ValueChanged(NetworkTable *table, const char *name, NetworkTables_Types type)
{
	if (strcmp(name, kP) == 0 || strcmp(name, kI) == 0 || strcmp(name, kD) == 0)
	{
		CANJaguar::SetPID(table->GetDouble(kP), table->GetDouble(kI),
			table->GetDouble(kD));
	}
	else if (strcmp(name, kSetpoint) == 0)
	{
		CANJaguar::Set(table->GetDouble(kSetpoint));
	}
	else if (strcmp(name, kEnabled) == 0)
	{
		if (table->GetBoolean(kEnabled))
			CANJaguar::EnableControl();
		else
			CANJaguar::DisableControl();
	}
}
