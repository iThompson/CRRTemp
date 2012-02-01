#ifndef SHIFTHIGH_H
#define SHIFTHIGH_H

#include "../CommandBase.h"
#include "../OI.h"
#include "../Subsystems/Drive.h"


/**
 *
 *
 * @author geoffrey.twardokus
 */
class ShiftHigh: public CommandBase {
public:
	ShiftHigh();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
