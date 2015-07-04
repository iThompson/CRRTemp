#ifndef EJECTION_H
#define EJECTION_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author Devon Loehr
 */
class Ejection: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	
	Solenoid* kicker;
	
public:
	Ejection();
	void InitDefaultCommand();
	void SetKicker(bool extended);
};

#endif
