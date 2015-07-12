#ifndef STOPBELT_H
#define STOPBELT_H

#include "../../CommandBase.h"

/**
 *
 *
 * @author Ian
 */
class StopBelt: public CommandBase {
public:
	StopBelt(bool isUserCmd);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
