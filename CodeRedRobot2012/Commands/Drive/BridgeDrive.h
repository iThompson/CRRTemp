#ifndef BRIDGEDRIVE_H
#define BRIDGEDRIVE_H

#include "../../CommandBase.h"

/**
 *
 *
 * @author Programmer
 */
class BridgeDrive: public CommandBase {
public:
	BridgeDrive();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
