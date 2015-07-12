#ifndef TRIMLEFT_H
#define TRIMLEFT_H

#include "../../CommandBase.h"

/**
 *
 *
 * @author Programmer
 */
class TrimLeft: public CommandBase {
public:
	TrimLeft();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
