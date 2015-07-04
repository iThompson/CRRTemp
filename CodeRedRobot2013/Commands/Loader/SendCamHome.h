#ifndef SENDCAMHOME_H
#define SENDCAMHOME_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

/**
 *
 *
 * @author Programmer
 * 
 * Move the cam to the home position
 */
class SendCamHome: public Command {
public:
	SendCamHome();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
