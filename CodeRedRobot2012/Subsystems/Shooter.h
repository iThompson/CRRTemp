#ifndef SHOOTER_H
#define SHOOTER_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "Solenoid.h"

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
	Solenoid  *SolA ;
	Solenoid  *SolB ;
	double m_speed;
	
	
public:
	Shooter(double speed); //Declare the functions to be used in this subsystem
	void InitDefaultCommand();
	void Run();
	void SetSpeed(double speed);
	void Stop();
	
};

#endif
