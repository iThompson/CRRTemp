#ifndef ARMSHUTDOWN_H
#define ARMSHUTDOWN_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

/**
 *
 *
 * @author Ian
 */
class ArmShutdown: public Command {
public:
	ArmShutdown();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
