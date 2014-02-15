/*
 * TripleMotorOutput.cpp
 *
 *  Created on: Feb 15, 2014
 *      Author: Programmer
 */

#include "TripleMotorOutput.h"

#define HAMMER_DRIVE_ENABLE 0

#define CURRENT_THRESH_1 100 	//TODO: Replace dummy value // Current at which we go from 1 motor to 2 motors  (1->2)
#define CURRENT_THRESH_1_END 45 //TODO: Replace dummy value // Current at which we go from 2 motors to 1 motor  (2->1)
#define CURRENT_THRESH_2 200 	//TODO: Replace dummy value // Current at which we go from 2 motors to 3 motors (2->3)
#define CURRENT_THRESH_2_END 95 //TODO: Replace dummy value // Current at which we go from 3 motors to 2 motors (3->2)

#define TIME_THRESH_1 .1 //TODO: Replace semi-dummy value // Time before we turn on the second motor
#define TIME_THRESH_2 .2 //TODO: Replace sem-dummy value // Time before we turn on the third motor


TripleMotorOutput::TripleMotorOutput(CANJaguar* jag1, CANJaguar* jag2, CANJaguar* jag3):
	m_jag1(m_jag1),
	m_jag2(m_jag2),
	m_jag3(m_jag3)
{
	isFirstOn = false;
	isSecondOn = false;
	isThirdOn = false;
	
	m_jag1->ConfigNeutralMode(CANJaguar::kNeutralMode_Coast);
	m_jag2->ConfigNeutralMode(CANJaguar::kNeutralMode_Coast);
	m_jag3->ConfigNeutralMode(CANJaguar::kNeutralMode_Coast);
	
	mtrTime.Start();
	mtrTime.Reset();
}

TripleMotorOutput::~TripleMotorOutput() {
	// TODO Auto-generated destructor stub
}

void TripleMotorOutput::SetSpeed(double speed)
{
#if HAMMER_DRIVE_ENABLE
	// If the motor direction is reversing or going from 0, we need to reset the timer so we don't turn on all the motors at once
	if(m_jag1->Get()*speed <= 0) mtrTime.Reset(); 
	if (speed == 0) // Run if the robot is being told to stop moving
	{
		isFirstOn = false;			// Register all motors as stationary
		isSecondOn = false;
		isThirdOn = false;
	}
	else if (!isFirstOn) 			// Run if the robot is currently considered stationary
	{
		isFirstOn = true; 			// Start only the first motor on each side
	}
	else if (!isSecondOn && 
				(m_jag1->GetOutputCurrent() > CURRENT_THRESH_1))
	// Run if only one motor is running and one side is above the threshold
	{
		isSecondOn = true;			// Run the first two motors on each side 
	}
	else if (isSecondOn && !isThirdOn && 
				m_jag1->GetOutputCurrent() < CURRENT_THRESH_1_END)
	// Run if two motors are running, but the current is small enough for only one
	{
		isSecondOn = false;			// Only run the first motor on each side
	}
	else if (!isThirdOn && 
				(m_jag1->GetOutputCurrent() > CURRENT_THRESH_2))
	// Run if only two motors are running and one side is above the second threshold
	{
		isThirdOn = true;			// Run all three motors on each side
	} 
	else if (isThirdOn && 
				m_jag1->GetOutputCurrent() < CURRENT_THRESH_2_END)
	// Run if all motors are running, but the current is enough for just two
	{
		isThirdOn = false;			// Run only the first two motors on each side
	}
	
	//Set the m_jaguars to brake or coast mode
	if(!isFirstOn)	// Robot's not moving -- brake
	{
		m_jag1->ConfigNeutralMode(CANJaguar::kNeutralMode_Brake);
		m_jag2->ConfigNeutralMode(CANJaguar::kNeutralMode_Brake);
		m_jag3->ConfigNeutralMode(CANJaguar::kNeutralMode_Brake);
	}
	else  // Robot's moving, but not necessarily all the motors are running -- better not brake
	{
		m_jag1->ConfigNeutralMode(CANJaguar::kNeutralMode_Coast);
		m_jag2->ConfigNeutralMode(CANJaguar::kNeutralMode_Coast);
		m_jag3->ConfigNeutralMode(CANJaguar::kNeutralMode_Coast);
	}
	
	// Run each motor pair if they were set to run above
	if(isFirstOn) 
	{
		m_jag1->Set(speed);
	}
	if(isSecondOn && mtrTime.Get() > TIME_THRESH_1) // Stagger the motor startup to prevent enormous current
	{
		m_jag2->Set(speed);
	}
	if(isThirdOn && mtrTime.Get() >TIME_THRESH_2) // Stagger the motor startup to prevent enormous current
	{
		m_jag3->Set(speed);
	}
	
#else
	// If the motor direction is reversing or going from 0, we need to reset the timer so we don't turn on all the motors at once
	if(m_jag1->Get()*speed <= 0) mtrTime.Reset();
	m_jag1->Set(speed);
	if(mtrTime.Get()> TIME_THRESH_1) // Stagger the motor startup to prevent enormous current
	{
		m_jag2->Set(speed);
	}
	else
	{
		m_jag2->Set(0);
	}
	if(mtrTime.Get() > TIME_THRESH_2) // Stagger the motor startup to prevent enormous current
	{
		m_jag3->Set(speed);
	}
	else
	{
		m_jag3->Set(0);
	}
#endif
}

double TripleMotorOutput::GetSpeed() {
	return m_jag1->Get();
}
