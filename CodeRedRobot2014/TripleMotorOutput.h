/*
 * TripleMotorOutput.h
 *
 * This is a class to handle a gearbox with three cims. 
 * It staggers their startup by 100 ms each in order to prevent huge amounts of current
 * from starting them all at the same time. If Hammer Drive is enabled, it will instead
 * turn on the motors based on load (and thus required torque)
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
	Encoder* m_enc;
	
	Timer mtrTime;
	
	bool isFirstOn;
	bool isSecondOn;
	bool isThirdOn;
public:
	TripleMotorOutput(CANJaguar* jag1, CANJaguar* jag2, CANJaguar* jag3, Encoder* enc);
	virtual ~TripleMotorOutput();
	void SetSpeed(double speed);
	double GetCurrent();
	double GetSpeed();
	double GetSetSpeed();
};

#endif /* TRIPLEMOTOROUTPUT_H_ */
