/*
 * PID.h
 *
 *  Created on: Jan 17, 2015
 *      Author: Programmer
 */

#ifndef SRC_PID_H_
#define SRC_PID_H_

class PID {
public:
	PID(double p, double i, double d);
	virtual ~PID();
	void setPID(double p, double i, double d);
	void setSetpoint(double setpoint);
	void reset();
	double step(double feedback);
private:
	double m_p;
	double m_i;
	double m_d;
	double m_errorSum;
	double m_previous;
	double m_setpoint;
};

#endif /* SRC_PID_H_ */
