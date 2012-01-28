#ifndef AUTOACQUIRE_H
#define AUTOACQUIRE_H

#include "../CommandBase.h"

/**
 *
 *
 * @author geoffrey.twardokus
 */
class AutoAcquire: public CommandBase {
public:
	AutoAcquire();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
