#ifndef ACQUIRER_H
#define ACQUIRER_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author geoffrey.twardokus
 */
class Acquirer: public Subsystem {
private:
	CANJaguar *Jag1;
	CANJaguar *Jag2;
	CANJaguar *Jag3;
	CANJaguar *Jag4;
public:
	Acquirer();
	void InitDefaultCommand();
	void Acquire(UINT32);
	void Spin();
	void End();
};

#endif
