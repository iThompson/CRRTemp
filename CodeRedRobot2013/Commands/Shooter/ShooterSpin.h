#ifndef SHOOTERSPIN_H
#define SHOOTERSPIN_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

/**
 *
 *
 * @author Programmer
 * 
 * If set to user, set the speed to the control panel. Otherwise, set it to the default speed
 */
class ShooterSpin: public Command {
private:
	bool m_isUser;
public:
	ShooterSpin(bool user);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
