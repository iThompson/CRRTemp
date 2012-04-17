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
	
	AnalogChannel compSense;
	
	double m_lastCompress;
	
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
	void CompressTest();
	void OpenGate();
	void CloseGate();
	
	bool GetUpper();
	bool GetLower();
	
	double GetCompression();
private:
	void SaveCompression();
};

#endif
 
