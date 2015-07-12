#ifndef STING_H
#define STING_H

#include "../../CommandBase.h"

/**
 *
 *
 * @author Programmer
 */
class Sting: public CommandBase {
public:
	Sting();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
