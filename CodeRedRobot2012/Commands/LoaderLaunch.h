#ifndef LOADERLAUNCH_H
#define LOADERLAUNCH_H

#include "../CommandBase.h"

/**
 *
 *
 * @author devon.loehr
 */
class LoaderLaunch: public CommandBase {
public:
	LoaderLaunch();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
