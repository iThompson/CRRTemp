#ifndef TURNLEDSON_H
#define TURNLEDSON_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

/**
 *
 *
 * @author Programmer
 */
class TurnLEDsOn: public Command {
public:
	TurnLEDsOn();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
