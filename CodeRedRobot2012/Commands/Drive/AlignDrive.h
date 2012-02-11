#ifndef ALIGNDRIVE_H
#define ALIGNDRIVE_H

#include "../../CommandBase.h"

/**
 *
 *
 * @author devon.loehr
 */
class AlignDrive: public CommandBase {
public:
	AlignDrive();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
