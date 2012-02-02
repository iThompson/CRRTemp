#ifndef AUTOSHOT_H
#define AUTOSHOT_H

#include "../CommandBase.h"

/**
 *
 *
 * @author geoffrey.twardokus
 */
class AutoShot: public CommandBase {
public:
	AutoShot();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
