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
	double disHeight; //This is the difference between the heights of the camera and the backboard
	if(m_dis0 < m_dis1) {
		m_initialTurnAngle =  atan(((480-pointOnBBY)/(240/tan(21.5)))+pointOnBBX);	
		m_distHeight = x; //At a later date, make x the difference between the camera height and the backboard
		m_dis0 = ((disHeight*(cos(m_ang0))/sin(m_ang0)));
		m_dis1 = ((disHeight*(cos(m_ang1)))/sin(m_ang1));
		m_angleA = acos((4/*feet*/+(m_dis0*m_dis0)-(m_dis1*m_dis1))/(4/*feet*/*(m_dis0)));
		m_angleB = 180-m_angleA;
		m_distAll = m_dis0*(sin(m_angleB));
		m_distDiff = (m_distAll*(sin(m_angleB)))/sin(m_angleB);
		double newDistAll = m_distAll + 1.25;
		double distReflection;
		distReflection = sqrt((m_distDiff*m_distDiff)+(newDistAll*newDistAll));
		m_distance = distReflection;
			
		m_distance = m_distDiff + 1;
		
	} else if(m_dis1 < m_dis0) {
		m_initialTurnAngle =  atan(((480-pointOnBBY)/(240/tan(21.5)))+pointOnBBX);	
		m_distHeight = x; //At a later date, make x the difference between the camera height and the backboard
		m_dis0 = ((disHeight*(cos(m_ang1))/sin(m_ang1)));
		m_dis1 = ((disHeight*(cos(m_ang0)))/sin(m_ang0));
		m_angleA = acos((4/*feet*/+(m_dis1*m_dis1)-(m_dis0*m_dis0))/(4/*feet*/*(m_dis1)));
		m_angleB = 180-m_angleA;
		m_distAll = m_dis1*(sin(m_angleB));
		m_distDiff = (m_distAll*(sin(m_angleB)))/sin(m_angleB);
		m_newDistAll = m_distAll + 1.25;
		double newDistAll = m_distAll + 1.25;
		double distReflection;
		distReflection = sqrt((m_distDiff*m_distDiff)+(newDistAll*newDistAll));
		m_distance = distReflection;
		
		m_distance = m_distDiff + 1;
		
	} else if(m_dis0 == m_dis1) {
		m_distance = sqrt((m_dis0*m_dis0)+1);
	}
	
	return m_distance;
}

double Shooter::SetAngle() {
	int x1;/*These represent coordinates*/
	int x2;/*of pixels from the Kinect.*/
	int x3;/*Ian (aka Techman 2.0) should*/
	int x4;/*fix this function later*/
	
	m_angle3 = atan((m_distDiff)/(m_distAll));
	m_angle4 = atan((m_distDiff)/(m_newDistAll));
	if(m_dis1 > m_dis0) {
		m_correctAngle = m_angle3 - m_angle4;
	} else if(m_dis0 > m_dis1) {
		m_correctAngle = -(m_angle3 - m_angle4);
	}
	m_returnedAngle = atan((((x1+x2+x3+x4)/4)-320)/(320/tan(28.5)));
	m_finalAngle = m_returnedAngle + m_correctAngle;
	
	return m_returnedAngle;
}

void Shooter::UsePIDOutput(double output) {
	/*Insert formula here using the predetermined distance and other variables (if needed) that determines the value of output*/
	
	sJagA->Set(output);
	sJagB->Set(output);
	sJagC->Set(output);
	sJagD->Set(output);
}
