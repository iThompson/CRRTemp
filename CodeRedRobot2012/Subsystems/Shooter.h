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
	double m_distance;
	double m_velocity;
	double m_distDiff;
	double m_distAll;
	double m_distHeight;
	double m_dis0;
	double m_dis1;
	double m_angleA;
	double m_angleB;
	double m_ang1;
	double m_ang0;
	double m_angle3;
	double m_angle4;
	double m_correctAngle;
	double m_newDistAll;
	double m_initialTurnAngle;
	double m_returnedAngle;
	double m_finalAngle;
	double pointOnBBY;
	double pointOnBBX;
public:
	Shooter();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
	void Stop();
	void Run();
	void SetSpeed(double speed);
	double GetDistance();
	double SetAngle();
};

#endif
