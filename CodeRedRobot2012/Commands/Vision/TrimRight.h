#ifndef TRIMRIGHT_H
#define TRIMRIGHT_H

#include "../../CommandBase.h"

/**
 *
 *
 * @author Programmer
 */
class TrimRight: public CommandBase {
public:
	TrimRight();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
