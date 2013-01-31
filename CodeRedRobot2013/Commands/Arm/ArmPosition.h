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
public:
	ArmPosition(double elbowPos, double wristPos);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
