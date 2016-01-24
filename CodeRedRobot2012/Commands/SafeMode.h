#ifndef SAFEMODE_H
#define SAFEMODE_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Ian
 */
class SafeMode: public CommandBase {
public:
	SafeMode();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	
private:
	int m_ballState;
};

#endif
