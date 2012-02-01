#ifndef SHIFTLOW_H
#define SHIFTLOW_H

#include "../CommandBase.h"
#include "../OI.h"
#include "../Subsystems/Drive.h"

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
