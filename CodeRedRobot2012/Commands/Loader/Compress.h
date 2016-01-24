#ifndef COMPRESS_H
#define COMPRESS_H

#include "../../CommandBase.h"
#include "../../ShotLogger.h"

/**
 *
 *
 * @author Programmer
 */
class Compress: public CommandBase {
public:
	Compress(bool shouldLog = false);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	
private:
	bool m_logging;
	
	ShotLogger* m_log;
};

#endif
