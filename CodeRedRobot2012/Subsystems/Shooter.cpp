#include "Shooter.h"
#include "../Robotmap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "../Commands/Shooter/ShootOff.h"
#include <math.h>

Shooter::Shooter() : PIDSubsystem("Shooter", Kp, Ki, Kd) {
	// Use these to get going:
	// SetSetpoint() -  Sets where the PID controller should move the system
	//                  to
	// Enable() - Enables the PID controller.
	
	sJagA = new CANJaguar(SHO_MTR_A);
	sJagB = new CANJaguar(SHO_MTR_B);
	sJagC = new CANJaguar(SHO_MTR_C);
	sJagD = new CANJaguar(SHO_MTR_D);
	
	m_speed = 0;
}
double Shooter::ReturnPIDInput() {
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;
	return 0.0;
}

void Shooter::InitDefaultCommand() {
	SetDefaultCommand(new ShootOff());
}

void Shooter::Stop() {
	PIDWrite(0);
	
}
/* author@geoffrey.twardokus */

void Shooter::Run() {
	PIDWrite(m_speed);
}

void Shooter::SetSpeed(double speed) {
	m_speed = speed;
}

double Shooter::GetDistance() {
	double x; //Placeholder for disHeight
	double disHeight; //This is the differential between the heights of the camera and the backboard
	m_distHeight = x; //At a later date, make x the difference between the camera height and the backboard
	m_dis0 = ((disHeight*(sin(180-(90+m_ang0)))/sin(m_ang0)));
	m_dis1 = ((disHeight*(sin(180-(90+m_ang1))))/sin(m_ang1));
	m_angleA = acos((576+(m_dis0*m_dis0)-(m_dis1*m_dis1))/(48*(m_dis0)));
	m_distAll = m_dis0*(sin(180-m_angleA));
	m_distAll = m_distance;
	
	return m_distance;
}

void Shooter::UsePIDOutput(double output) {
	/*Insert formula here using the predetermined distance and other variables (if needed) that determines the value of output*/
	
	sJagA->Set(output);
	sJagB->Set(output);
	sJagC->Set(output);
	sJagD->Set(output);
}
