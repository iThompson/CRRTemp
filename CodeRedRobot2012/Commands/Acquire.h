#ifndef ACQUIRE_H
#define ACQUIRE_H

#include "../CommandBase.h"

/**
 *
 *
 * @author geoffrey.twardokus
 */
class Acquire: public CommandBase {
public:
	Acquire(UINT32);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
