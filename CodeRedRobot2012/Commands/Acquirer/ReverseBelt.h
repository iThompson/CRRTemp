#ifndef RUNBELTBACK_H
#define RUNBELTBACK_H

#include "../../CommandBase.h"

/**
 *
 *
 * @author Devon Loehr
 */
class ReverseBelt: public CommandBase {
public:
	ReverseBelt(bool isUserCommand);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
