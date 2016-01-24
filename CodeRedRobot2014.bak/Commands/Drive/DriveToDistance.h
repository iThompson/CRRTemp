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
	bool m_isForward;
public:
	DriveToDistance(double distance, bool isForward);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
