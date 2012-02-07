#ifndef SHOOTMANUAL_H
#define SHOOTMANUAL_H

#include "../CommandBase.h"

/**
 *
 *
 * @author geoffrey.twardokus
 */
class ShootManual: public CommandBase {
public:
	ShootManual();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
