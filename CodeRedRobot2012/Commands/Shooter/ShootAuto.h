#ifndef SHOOTAUTO_H
#define SHOOTAUTO_H

#include "../../CommandBase.h"

/**
 *
 *
 * @author devon.loehr
 */
class ShootAuto: public CommandBase {
public:
	ShootAuto();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
