#ifndef JOYSTICKDRIVE_H
#define JOYSTICKDRIVE_H

#include "../CommandBase.h"

/**
 *
 *
 * @author TechMan 2.0
 */
class JoystickDrive: public CommandBase {
public:
	JoystickDrive();		//Declare functions for the class JoystickDrive()
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
