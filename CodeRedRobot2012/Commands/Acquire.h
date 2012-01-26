#ifndef ACQUIRE_H
#define ACQUIRE_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Devon Loehr
 */
class Acquire: public CommandBase {
public:
	Acquire();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
