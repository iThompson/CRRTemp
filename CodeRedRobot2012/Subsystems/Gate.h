#ifndef BRIDGE_H
#define BRIDGE_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author geoffrey.twardokus
 */
class Gate: public Subsystem {
private:
	Solenoid gate;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Gate();
	void InitDefaultCommand();
	void SetState(bool closed);
};

#endif
