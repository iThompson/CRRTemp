#ifndef JOYSTICKDRIVE_H
#define JOYSTICKDRIVE_H


#include "Commands/Subsystem.h"
#include "../../Robot.h"

/**
 *
 *
 * @author Programmer
 * 
 * Drive using the Joysticks
 */
class JoystickDrive: public Command {
public:
	JoystickDrive();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
