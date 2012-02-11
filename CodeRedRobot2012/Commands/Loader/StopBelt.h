#ifndef STOPBELT_H
#define STOPBELT_H

#include "../../CommandBase.h"

/**
 *
 *
 * @author geoffrey.twardokus
 */
class StopBelt: public CommandBase {
public:
	StopBelt();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
