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
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	
	CANJaguar *sJagA;
	CANJaguar *sJagB;
	CANJaguar *sJagC;
	CANJaguar *sJagD;
	
	
public:
	Shooter();
	void InitDefaultCommand();
	void Shoot(float power);
	void Spin(double speed);
	void Stop();
	
};

#endif
