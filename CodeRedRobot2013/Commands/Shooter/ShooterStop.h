#ifndef SHOOTERSTOP_H
#define SHOOTERSTOP_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

/**
 *
 *
 * @author Programmer
 * 
 * Set the shooter speed to 0, move cam to home position
 */
class ShooterStop: public Command {
public:
	ShooterStop();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
