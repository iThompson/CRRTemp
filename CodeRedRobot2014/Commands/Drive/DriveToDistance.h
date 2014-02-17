#ifndef DRIVETODISTANCE_H
#define DRIVETODISTANCE_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

/**
 *
 *
 * @author Programmer
 */
class DriveToDistance: public Command {
private:
	double m_distance;
public:
	DriveToDistance(double distance);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
