#ifndef AIMLEFT_H
#define AIMLEFT_H

#include "../CommandBase.h"

/**
 *
 *
 * @author geoffrey.twardokus
 */
class AimLeft: public CommandBase {
public:
	AimLeft();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
