#ifndef UNDEPLOY_H
#define UNDEPLOY_H

#include "../CommandBase.h"

/**
 *
 *
 * @author geoffrey.twardokus
 */
class Undeploy: public CommandBase {
public:
	Undeploy();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
