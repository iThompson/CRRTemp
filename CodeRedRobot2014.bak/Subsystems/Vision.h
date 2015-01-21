#ifndef VISION_H
#define VISION_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author Programmer
 */
class Vision: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	DigitalInput* goalHot;
	Relay* LEDs;
public:
	Vision();
	void InitDefaultCommand();
	void SetLEDs(Relay::Value value);
	bool IsGoalHot();
};

#endif
