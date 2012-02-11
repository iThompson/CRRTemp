#ifndef AIMRIGHT_H
#define AIMRIGHT_H

#include "../../CommandBase.h"

/**
 *
 *
 * @author geoffrey.twardokus
 */
class AimRight: public CommandBase {
public:
	AimRight();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
