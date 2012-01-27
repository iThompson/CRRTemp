#ifndef DRIVEFORWARD_H
#define DRIVEFORWARD_H

#include "../CommandBase.h"

/**
 *
 *
 * @author geoffrey.twardokus
 */
class DriveForward: public CommandBase {
public:
	DriveForward();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
