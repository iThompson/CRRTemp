#ifndef LOADER_H
#define LOADER_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author Devon Loehr
 */
class Loader: public Subsystem {
private:
	Solenoid *lockH;
	Solenoid *lockL;
	Solenoid *compTest;
	
	int m_numberBalls;
	
	Victor belt;
	
	AnalogChannel *gateLeft;
	AnalogChannel *gateRight;
	AnalogChannel *ballHigh;
	AnalogChannel *ballLow;
	
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Loader();
	void InitDefaultCommand();
	void Lock();
	void Load();
	void Launch();
	void Rapidfire();
	void SetBallCount();
	int GetBallCount();
	void AddBall();
	void RemoveBall();
	void RunBelt();
	void StopBelt();
	void OpenGate();
	void CloseGate();
};

#endif
 
