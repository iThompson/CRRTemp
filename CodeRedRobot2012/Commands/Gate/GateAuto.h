#ifndef GATEAUTO_H
#define GATEAUTO_H

#include "../../CommandBase.h"

/**
 *
 *
 * @author Programmer
 */
class GateAuto: public CommandBase {
public:
	GateAuto();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
