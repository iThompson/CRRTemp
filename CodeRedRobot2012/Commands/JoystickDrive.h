#ifndef JOYSTICKDRIVE_H
#define JOYSTICKDRIVE_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Ian
 */
class JoystickDrive: public CommandBase {
public:
	JoystickDrive();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
