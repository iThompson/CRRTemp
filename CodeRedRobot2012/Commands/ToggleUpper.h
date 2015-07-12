#ifndef TOGGLEUPPER_H
#define TOGGLEUPPER_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Programmer
 */
class ToggleUpper: public CommandBase {
private:
	Command* lock;
	Command* open;
	Command* load;
	Command* launch;
public:
	ToggleUpper();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
