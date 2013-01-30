#ifndef SHOOTERSHOOT_H
#define SHOOTERSHOOT_H

#include "Commands/Subsystem.h"
#include "../../Robot.h"

/**
 *
 *
 * @author Programmer
 * 
 * Run the cam and spin the wheel
 */
class ShooterShoot: public Command {
public:
	ShooterShoot();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
