/*
 * TripleMotorOutput.h
 *
 *  Created on: Feb 15, 2014
 *      Author: Programmer
 */
//TODO: Make nice description of this class
#ifndef TRIPLEMOTOROUTPUT_H_
#define TRIPLEMOTOROUTPUT_H_

#include <WPILib.h>

class TripleMotorOutput {
private:
	CANJaguar* m_jag1;
	CANJaguar* m_jag2;
	CANJaguar* m_jag3;
	
	Timer mtrTime;
	
	bool isFirstOn;
	bool isSecondOn;
	bool isThirdOn;
public:
	TripleMotorOutput(CANJaguar* jag1, CANJaguar* jag2, CANJaguar* jag3);
	virtual ~TripleMotorOutput();
	void SetSpeed(double speed);
	double GetSpeed(); 
};

#endif /* TRIPLEMOTOROUTPUT_H_ */
