#ifndef SHOOTERSPIN_H
#define SHOOTERSPIN_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

/**
 *
 *
 * @author Programmer
 * 
 * Set the speed and run the wheel, move cam to home position
 */
class ShooterSpin: public Command {
public:
	ShooterSpin();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
