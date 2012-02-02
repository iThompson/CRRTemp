#ifndef LOCKLOADER_H
#define LOCKLOADER_H

#include "../CommandBase.h"

/**
 *
 *
 * @author devon.loehr
 */
class LockLoader: public CommandBase {
public:
	LockLoader();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
