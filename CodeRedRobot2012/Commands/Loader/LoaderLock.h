#ifndef LOADERLOCK_H
#define LOADERLOCK_H

#include "../../CommandBase.h"

/**
 *
 *
 * @author Devon Loehr
 */
class LoaderLock: public CommandBase {
public:
	LoaderLock();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
