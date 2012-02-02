#ifndef AIMLOW_H
#define AIMLOW_H

#include "../CommandBase.h"

/**
 *
 *
 * @author geoffrey.twardokus
 */
class AimLow: public CommandBase {
public:
	AimLow();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
