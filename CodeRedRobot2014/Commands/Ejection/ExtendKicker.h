#ifndef EXTENDKICKER_H
#define EXTENDKICKER_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

/**
 *
 *
 * @author Devon Loehr
 */
class ExtendKicker: public Command {
public:
	ExtendKicker();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
