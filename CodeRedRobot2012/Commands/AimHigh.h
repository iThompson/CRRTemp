#ifndef AIMHIGH_H
#define AIMHIGH_H

#include "../CommandBase.h"

/**
 *
 *
 * @author geoffrey.twardokus
 */
class AimHigh: public CommandBase {
public:
	AimHigh();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
