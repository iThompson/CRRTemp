#ifndef DEPLOY_H
#define DEPLOY_H

#include "../../CommandBase.h"

/**
 *
 *
 * @author geoffrey.twardokus
 */
class Deploy: public CommandBase {
public:
	Deploy();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
