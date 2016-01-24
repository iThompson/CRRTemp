#ifndef LOADEROPEN_H
#define LOADEROPEN_H

#include "../../CommandBase.h"

/**
 *
 *
 * @author Programmer
 */
class LoaderOpen: public CommandBase {
public:
	LoaderOpen();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
