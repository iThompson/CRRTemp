#ifndef SHIFTLOW_H
#define SHIFTLOW_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

/**
 *
 *
 * @author Programmer
 * 
 * Shift the shifter into low gear
 */
class ShiftLow: public Command {
public:
	ShiftLow();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
