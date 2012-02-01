#ifndef SHIFTLOW_H
#define SHIFTLOW_H

#include "../CommandBase.h"

/**
 *
 *
 * @author geoffrey.twardokus
 */
class ShiftLow: public CommandBase {
public:
	ShiftLow();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
