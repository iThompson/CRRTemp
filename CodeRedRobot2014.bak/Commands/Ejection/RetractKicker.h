#ifndef RETRACTKICKER_H
#define RETRACTKICKER_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

/**
 *
 *
 * @author Devon Loehr
 */
class RetractKicker: public Command {
public:
	RetractKicker();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
