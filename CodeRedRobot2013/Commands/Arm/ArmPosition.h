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
private:
	double m_elbowPos;
	double m_wristPos;
	bool m_bShouldFinish;
public:
	ArmPosition(double elbowPos, double wristPos, bool shouldFinish = false);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
