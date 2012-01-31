#ifndef SHOOTIDLE_H
#define SHOOTIDLE_H

#include "../CommandBase.h"

/**
 *
 *
 * @author devon.loehr
 */
class ShootIdle: public CommandBase {
public:
	ShootIdle();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
