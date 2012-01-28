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
private: //Declare the Jaguars for use on this subsystem
	CANJaguar *Jag1;
	CANJaguar *Jag2;
	CANJaguar *Jag3;
	CANJaguar *Jag4;
public:
	Acquirer();			//Declare functions for class Acquirer()
	void InitDefaultCommand();
	void Acquire();
	void Spin();
	void End();
};

#endif
