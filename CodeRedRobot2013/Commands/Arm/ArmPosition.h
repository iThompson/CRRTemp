#ifndef ARMPOSITION_H
#define ARMPOSITION_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"
/**
 *
 *
 * @author Programmer
 * 
 * Set the elbow and wrist to some positions
 */
class ArmPosition: public Command {
public:
	ArmPosition();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
