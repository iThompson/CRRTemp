#ifndef BRIDGEREVERSE_H
#define BRIDGEREVERSE_H

#include "../../CommandBase.h"

/**
 *
 *
 * @author Programmer
 */
class BridgeReverse: public CommandBase {
public:
	BridgeReverse();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
