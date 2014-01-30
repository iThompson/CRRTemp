#ifndef ARMUSERPOSITION_H
#define ARMUSERPOSITION_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

/**
 *
 *
 * @author Programmer
 * 
 * Set the elbow and wrist to the positions on the control panel
 */
class ArmUserPosition: public Command {
public:
	ArmUserPosition();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
