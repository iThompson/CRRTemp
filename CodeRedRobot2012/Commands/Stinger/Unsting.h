#ifndef UNSTING_H
#define UNSTING_H

#include "../../CommandBase.h"

/**
 *
 *
 * @author Programmer
 */
class Unsting: public CommandBase {
public:
	Unsting();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
