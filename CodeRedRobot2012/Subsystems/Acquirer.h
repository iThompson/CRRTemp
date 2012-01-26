#ifndef ACQUIRER_H
#define ACQUIRER_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author Devon Loehr
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
	void Acquire();
	void Spin();
	void End();
};

#endif
