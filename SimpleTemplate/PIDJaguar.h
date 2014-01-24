/*
 * PIDJaguar.h
 *
 *  Created on: Jan 26, 2013
 *      Author: Programmer
 */

#ifndef PIDJAGUAR_H_
#define PIDJAGUAR_H_

#include <CANJaguar.h>

class PIDJaguar: public CANJaguar {
public:
	explicit PIDJaguar(UINT8 deviceNumber, ControlMode controlMode = kPercentVbus);
	
	void WriteConfig();
	
	virtual void Set(float value, UINT8 syncGroup=0);
	
	void SetSpeedReference(SpeedReference reference);
	void SetPositionReference(PositionReference reference);
	void SetPID(double p, double i, double d);
	void EnableControl(double encoderInitialPosition = 0.0);
	void DisableControl();
	void ChangeControlMode(ControlMode controlMode);
	void SetVoltageRampRate(double rampRate);
	void ConfigNeutralMode(NeutralMode mode);
	void ConfigEncoderCodesPerRev(UINT16 codesPerRev);
	void ConfigPotentiometerTurns(UINT16 turns);
	void ConfigSoftPositionLimits(double forwardLimitPosition, double reverseLimitPosition);
	void DisableSoftPositionLimits();
	void ConfigMaxOutputVoltage(double voltage);
	void ConfigFaultTime(float faultTime);

	// LiveWindowSendable
	void ValueChanged(ITable* source, const std::string& key, EntryValue value, bool isNew);
	void UpdateTable();
	void StartLiveWindowMode();
	void StopLiveWindowMode();
	std::string GetSmartDashboardType();
	void InitTable(ITable *subTable);
	ITable * GetTable();
	
private:
	ControlMode m_controlMode;
	SpeedReference m_speedReference;
	bool m_bSpeedReference;
	PositionReference m_posReference;
	bool m_bPosReference;
	double m_p;
	double m_i;
	double m_d;
	bool m_bPID;
	double m_initialEnc;
	bool m_bControlEnabled;
	double m_rampRate;
	bool m_bRampRate;
	NeutralMode m_neutralMode;
	bool m_bNeutralMode;
	UINT16 m_codesPerRev;
	bool m_bCodesPerRev;
	UINT16 m_turns;
	bool m_bTurns;
	double m_forwardLimit;
	double m_reverseLimit;
	bool m_bSoftLimit;
	double m_maxVoltage;
	bool m_bMaxVoltage;
	float m_faultTime;
	bool m_bFaultTime;
	
	ITable *m_pidTable;
};

#endif /* PIDJAGUAR_H_ */
