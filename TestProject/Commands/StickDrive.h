#ifndef STICKDRIVE_H
#define STICKDRIVE_H

#include "../CommandBase.h"

/**
 *
 * @author Ian
 */
class StickDrive: public CommandBase {
public:
	StickDrive();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
