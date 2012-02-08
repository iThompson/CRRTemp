#ifndef JOYSTICKHALFDRIVE_H
#define JOYSTICKHALFDRIVE_H

#include "../../CommandBase.h"

/**
 *
 *
 * @author Chris Evans
 */
class JoystickHalfDrive: public CommandBase {
public:
	JoystickHalfDrive();		//Declare functions for the class JoystickDrive()
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
