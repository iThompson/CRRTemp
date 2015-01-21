#ifndef TURNLEDSOFF_H
#define TURNLEDSOFF_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

/**
 *
 *
 * @author Programmer
 */
class TurnLEDsOff: public Command {
public:
	TurnLEDsOff();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
