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
	Timer waitTime;
	bool m_isHot;
public:
	HotFire();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
