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
private: //Declare the Victor for use on this subsystem
	Victor belt;
	Solenoid gate;
public:
	Acquirer();			//Declare functions for class Acquirer()
	void InitDefaultCommand();
	void RunBelt();
	void StopBelt();
	void OpenGate();
	void CloseGate();
};

#endif
