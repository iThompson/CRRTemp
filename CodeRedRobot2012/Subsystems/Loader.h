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
	Solenoid lockH;
	Solenoid lockL;
	Solenoid compTest;
	
	Victor belt;
	
	AnalogChannel gateLeft;
	AnalogChannel gateRight;
	AnalogChannel ballHigh;
	AnalogChannel ballLow;
	
	int m_numberBalls;
	
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Loader();
	void InitDefaultCommand();
	void Lock();
	void Load();
	void Launch();
	void Rapidfire();
	void SetBallCount(int num);
	int GetBallCount();
	void AddBall();
	void RemoveBall();
	void RunBelt();
	void StopBelt();
	void OpenGate();
	void CloseGate();
};

#endif
 
