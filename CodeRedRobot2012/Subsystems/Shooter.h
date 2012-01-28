#ifndef SHOOTER_H
#define SHOOTER_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author geoffrey.twardokus
 */
class Shooter: public Subsystem {
private:		//Declare the jaguars to be used later for this subsystem
	CANJaguar *sJagA;
	CANJaguar *sJagB;
	CANJaguar *sJagC;
	CANJaguar *sJagD;
	
	
public:
	Shooter(); //Declare the functions to be used in this subsystem
	void InitDefaultCommand();
	void Shoot(float power);
	void Spin(double speed);
	void Stop();
	
};

#endif
