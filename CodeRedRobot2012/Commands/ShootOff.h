#ifndef SHOOTIDLE_H
#define SHOOTIDLE_H

#include "../CommandBase.h"

/**
 *
 *
 * @author devon.loehr
 */
class ShootOff: public CommandBase {
public:
	ShootOff();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
