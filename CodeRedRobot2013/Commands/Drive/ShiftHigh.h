#ifndef SHIFTHIGH_H
#define SHIFTHIGH_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

/**
 *
 *
 * @author Programmer
 * 
 * Shift the shifter into high gear
 */
class ShiftHigh: public Command {
public:
	ShiftHigh();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
