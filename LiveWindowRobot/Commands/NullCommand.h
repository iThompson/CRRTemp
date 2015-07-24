#ifndef NULLCOMMAND_H
#define NULLCOMMAND_H

#include "Commands/Command.h"

/**
 *
 *
 * @author Ian
 */
class NullCommand: public Command {
public:
	NullCommand(Subsystem* system);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
