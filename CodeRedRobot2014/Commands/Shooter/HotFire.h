#ifndef HOTFIRE_H
#define HOTFIRE_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

/**
 *
 *
 * @author Programmer
 */
class HotFire: public Command {
private:
	bool m_hasFired;
public:
	HotFire();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
