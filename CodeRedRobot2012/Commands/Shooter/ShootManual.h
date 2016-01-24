#ifndef SHOOTMANUAL_H
#define SHOOTMANUAL_H

#include "../../CommandBase.h"

/**
 *
 *
 * @author geoffrey.twardokus
 */
class ShootManual: public CommandBase {
private:
	double m_speed;
public:
	ShootManual(double speed = -1);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
