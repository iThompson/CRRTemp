#ifndef SHOOTON_H
#define SHOOTON_H

#include "../../CommandBase.h"

/**
 *
 *
 * @author geoffrey.twardokus
 */
class ShootOn: public CommandBase {
public:
	ShootOn();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
