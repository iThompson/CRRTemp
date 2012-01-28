#ifndef SHOOT_H
#define SHOOT_H

#include "../CommandBase.h"

/**
 *
 *
 * @author geoffrey.twardokus
 */
class Shoot: public CommandBase {
public:
	Shoot();		//Declare functions for the class Shoot()
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
