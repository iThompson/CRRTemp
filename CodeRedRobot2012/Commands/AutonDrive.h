#ifndef AUTONDRIVE_H
#define AUTONDRIVE_H

#include "../CommandBase.h"

/**
 *
 *
 * @author geoffrey.twardokus
 */
class AutonDrive: public CommandBase {
private:
	double m_left;
	double m_right;
public:
	AutonDrive(double left, double right);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
