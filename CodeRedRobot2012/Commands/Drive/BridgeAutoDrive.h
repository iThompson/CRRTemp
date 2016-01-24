#ifndef BRIDGEAUTODRIVE_H
#define BRIDGEAUTODRIVE_H

#include "../../CommandBase.h"

/**
 *
 *
 * @author Programmer
 */
class BridgeAutoDrive: public CommandBase {
public:
	BridgeAutoDrive(double left, double right);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	
private:
	double m_left;
	double m_right;
};

#endif
