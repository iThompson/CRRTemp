/*
 * PID.cpp
 *
 *  Created on: Jan 17, 2015
 *      Author: Programmer
 */

#include <PID.h>
#include <WPILib.h>

PID::PID(double p, double i, double d) {
	setPID(p, i, d);
	m_setpoint = 0;
	m_previous = 0;
	m_errorSum = 0;
}

PID::~PID() {
	// TODO Auto-generated destructor stub
}

void PID::setPID(double p, double i, double d) {
	m_p = p;
	m_i = i;
	m_d = d;
}

void PID::setSetpoint(double setpoint) {
	m_setpoint = setpoint;
}

void PID::reset() {
	m_errorSum = 0;
}

double PID::step(double feedback) {
	double result = 0;
	double error = feedback - m_setpoint;
	SmartDashboard::PutNumber("Error", error);
	SmartDashboard::PutNumber("ErrorSum", m_errorSum);
	result += error * m_p;
	m_errorSum += error;
	result += m_errorSum * m_i;
	result += m_d * (feedback - m_previous);
	m_previous = feedback;
	return result;
}
