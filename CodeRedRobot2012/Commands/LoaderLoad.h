#ifndef LOADERLOAD_H
#define LOADERLOAD_H

#include "../CommandBase.h"

/**
 *
 *
 * @author devon.loehr
 */
class LoaderLoad: public CommandBase {
public:
	LoaderLoad();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
