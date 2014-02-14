#ifndef LOWERSHOOTER_H
#define LOWERSHOOTER_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

/**
 *
 *
 * @author Devon Loehr
 */
class LowerShooter: public Command {
public:
	LowerShooter(double timeRaised);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	
	Timer shootTime;
	
	double m_timeRaised;
};

#endif
