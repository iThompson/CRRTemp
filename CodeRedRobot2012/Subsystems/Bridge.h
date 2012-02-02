#ifndef BRIDGE_H
#define BRIDGE_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author geoffrey.twardokus
 */
class Bridge: public Subsystem {
private:
	Solenoid *bridge;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Bridge();
	void InitDefaultCommand();
	void Deploy(bool deployed);
};

#endif
