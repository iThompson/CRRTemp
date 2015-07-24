#ifndef TOGGLELOWER_H
#define TOGGLELOWER_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Programmer
 */
class ToggleLower: public CommandBase {
private:
	Command* lock;
	Command* open;
	Command* load;
	Command* launch;
public:
	ToggleLower();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
