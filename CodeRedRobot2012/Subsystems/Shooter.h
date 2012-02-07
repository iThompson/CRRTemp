#ifndef SHOOTER_H
#define SHOOTER_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"
#include "CANJaguar.h"

/**
 *
 *
 * @author geoffrey.twardokus
 */
class Shooter: public PIDSubsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	// set the P, I, and D constants here
	static const double Kp = 0.0;
	static const double Ki = 0.0;
	static const double Kd = 0.0;
	
	CANJaguar *sJagA;
	CANJaguar *sJagB;
	CANJaguar *sJagC;
	CANJaguar *sJagD;
	
	double m_speed;
	
public:
	Shooter();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
	void Stop();
	void Run();
	void SetSpeed(double speed);
};

#endif
