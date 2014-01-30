#ifndef JOYSTICKAUTODRIVE_H
#define JOYSTICKAUTODRIVE_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

/**
 *
 *
 * @author Programmer
 * 
 * Run the drive at the speeds for autonomous
 */
class JoystickAutoDrive: public Command {
private:
	double m_lSpeed;
	double m_rSpeed;
public:
	JoystickAutoDrive(double lSpeed, double rSpeed);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
