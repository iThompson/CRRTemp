#ifndef STINGER_H
#define STINGER_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author Programmer
 */
class Stinger: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Solenoid sol;
public:
	Stinger();
	void InitDefaultCommand();
	void SetState(bool state);
};

#endif
