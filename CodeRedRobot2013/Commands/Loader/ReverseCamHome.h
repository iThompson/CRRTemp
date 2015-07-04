#ifndef REVERSECAMHOME_H
#define REVERSECAMHOME_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

/**
 *
 *
 * @author Programmer
 * 
 * Move the cam to the home position in reverse
 */
class ReverseCamHome: public Command {
public:
	ReverseCamHome();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
