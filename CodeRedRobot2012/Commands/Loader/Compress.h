#ifndef COMPRESS_H
#define COMPRESS_H

#include "../../CommandBase.h"

/**
 *
 *
 * @author Programmer
 */
class Compress: public CommandBase {
public:
	Compress();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
