/*
 * TripleMotorOutput.cpp
 * 
 * This is a class to handle a gearbox with three cims. 
 * It staggers their startup by 100 ms each in order to prevent huge amounts of current
 * from starting them all at the same time. If Hammer Drive is enabled, it will instead
 * turn on the motors based on load (and thus required torque)
 *
 *  Created on: Feb 15, 2014
 *      Author: Programmer
 */

#include "TripleMotorOutput.h"
#include "Robot.h"

#define HAMMER_DRIVE_ENABLE 0

#define CURRENT_THRESH_1 30 	//TODO: Replace dummy value // Current at which we go from 1 motor to 2 motors  (1->2)
#define CURRENT_THRESH_1_END 25 //TODO: Replace dummy value // Current at which we go from 2 motors to 1 motor  (2->1)
#define CURRENT_THRESH_2 40 	//TODO: Replace dummy value // Current at which we go from 2 motors to 3 motors (2->3)
#define CURRENT_THRESH_2_END 35 //TODO: Replace dummy value // Current at which we go from 3 motors to 2 motors (3->2)

#define TIME_THRESH_1 .1 //TODO: Replace semi-dummy value // Time before we turn on the second motor
#define TIME_THRESH_2 .2 //TODO: Replace sem-dummy value // Time before we turn on the third motor


TripleMotorOutput::TripleMotorOutput(CANJaguar* jag1, CANJaguar* jag2, CANJaguar* jag3, Encoder* enc):
	m_jag1(jag1),
	m_jag2(jag2),
	m_jag3(jag3),
	m_enc(enc)
{
	isFirstOn = false;
	isSecondOn = false;
	isThirdOn = false;
	
	m_jag1->ConfigNeutralMode(CANJaguar::kNeutralMode_Brake); // Jag 1 should always be braked
	m_jag2->ConfigNeutralMode(CANJaguar::kNeutralMode_Coast);
	m_jag3->ConfigNeutralMode(CANJaguar::kNeutralMode_Coast);
	
	mtrTime.Start();
	mtrTime.Reset();
	
	m_enc->Start();
}

TripleMotorOutput::~TripleMotorOutput() {
}
int TripleMotorOutput::GetNumMotors(double speed) {
#if HAMMER_DRIVE_ENABLE
	// If the motor direction is reversing or going from 0, we need to reset the timer so we don't turn on all the motors at once
	if(Robot::oi->AreMotorsForced()) 
	{
		isFirstOn = true;
		isSecondOn = true;
		isThirdOn = true;
	}
	else if (speed > -.001 && speed < .001) // Iff the side is being told to stop moving
	{
		isFirstOn = false;			// Register all motors as stationary
		isSecondOn = false;
		isThirdOn = false;
	}
	else if (!isFirstOn) 			// Run if the side is currently considered stationary
	{
		isFirstOn = true; 			// Start only the first motor on each side
	}
	else if (!isSecondOn && 
				(m_jag1->GetOutputCurrent() > SmartDashboard::GetNumber("Thresh1")))
	// Run if only one motor is running its current is above the threshold
	{
		isSecondOn = true;			// Run the first two motors on each side 
	}
	else if (isSecondOn && !isThirdOn && 
				m_jag1->GetOutputCurrent() < SmartDashboard::GetNumber("Thresh1 End"))
	// Run if two motors are running, but the current is small enough for only one
	{
		isSecondOn = false;			// Only run the first motor on each side
	}
	else if (!isThirdOn && 
				(m_jag1->GetOutputCurrent() > SmartDashboard::GetNumber("Thresh2")))
	// Run if only two motors are running and one is above the second threshold
	{
		isThirdOn = true;			// Run all three motors on each side
	} 
	else if (isThirdOn && 
				m_jag1->GetOutputCurrent() < SmartDashboard::GetNumber("Thresh2 End"))
	// Run if all motors are running, but the current is enough for just two
	{
		isThirdOn = false;			// Run only the first two motors on each side
	}
	
	int count = 0;
	if(isFirstOn) count++;
	if(isSecondOn) count++;
	if(isThirdOn) count++;
	return count;
#else
	return 3;
#endif
}
//int TripleMotorOutput::GetNumMotors(double speed) {
//#if HAMMER_DRIVE_ENABLE
//	// If the motor direction is reversing or going from 0, we need to reset the timer so we don't turn on all the motors at once
//	if(false) 
//	{
//		isFirstOn = true;
//		isSecondOn = true;
//		isThirdOn = true;
//	}
//	else if (speed > -.00001 && speed < .00001) // Iff the side is being told to stop moving
//	{
//		isFirstOn = false;			// Register all motors as stationary
//		isSecondOn = false;
//		isThirdOn = false;
//	}
//	else if (!isFirstOn) 			// Run if the side is currently considered stationary
//	{
//		isFirstOn = true; 			// Start only the first motor on each side
//	}
//	else if (!isSecondOn && 
//				(m_jag1->GetOutputCurrent() > CURRENT_THRESH_1))
//	// Run if only one motor is running its current is above the threshold
//	{
//		isSecondOn = true;			// Run the first two motors on each side 
//	}
//	else if (isSecondOn && !isThirdOn && 
//				m_jag1->GetOutputCurrent() < CURRENT_THRESH_1_END)
//	// Run if two motors are running, but the current is small enough for only one
//	{
//		isSecondOn = false;			// Only run the first motor on each side
//	}
//	else if (!isThirdOn && 
//				(m_jag1->GetOutputCurrent() > CURRENT_THRESH_2))
//	// Run if only two motors are running and one is above the second threshold
//	{
//		isThirdOn = true;			// Run all three motors on each side
//	} 
//	else if (isThirdOn && 
//				m_jag1->GetOutputCurrent() < CURRENT_THRESH_2_END)
//	// Run if all motors are running, but the current is enough for just two
//	{
//		isThirdOn = false;			// Run only the first two motors on each side
//	}
//	
//	int count = 0;
//	if(isFirstOn) count++;
//	if(isSecondOn) count++;
//	if(isThirdOn) count++;
//	return count;
//#else
//	return 3;
//#endif
//}

void TripleMotorOutput::SetSpeed(double speed, int numMotors)
{
#if HAMMER_DRIVE_ENABLE
	//Set the m_jaguars to brake or coast mode
	if(numMotors == 0)	// Robot's not moving -- brake
	{
		m_isBraked = true;
		m_jag2->ConfigNeutralMode(CANJaguar::kNeutralMode_Brake);
		m_jag3->ConfigNeutralMode(CANJaguar::kNeutralMode_Brake);
	}
	else  // Robot's moving, but not necessarily all the motors are running -- better not brake
	{
		m_isBraked = false;
		m_jag2->ConfigNeutralMode(CANJaguar::kNeutralMode_Coast);
		m_jag3->ConfigNeutralMode(CANJaguar::kNeutralMode_Coast);
	}
	
	// Run each motor pair if they were set to run above
	if(numMotors >= 1)
	{
		m_jag1->Set(speed);
	}
	else
	{
		m_jag1->Set(0);
	}
	if(numMotors >= 2) // Stagger the motor startup to prevent enormous current
	{
		m_jag2->Set(speed);
	}
	else
	{
		m_jag2->Set(0);
	}
	if(numMotors >= 3) // Stagger the motor startup to prevent enormous current
	{
		m_jag3->Set(speed);
	}
	else
	{
		m_jag3->Set(0);
	}
#else
	// If the motor direction is reversing or going from 0, we need to reset the timer so we don't turn on all the motors at once
	if(m_jag1->Get()*speed <= 0) mtrTime.Reset();
	if(speed > -.001 && speed < .001)
	{
		m_isBraked = true;
		m_jag2->ConfigNeutralMode(CANJaguar::kNeutralMode_Brake);
		m_jag3->ConfigNeutralMode(CANJaguar::kNeutralMode_Brake);	
	}
	else
	{
		m_isBraked = false;
		m_jag2->ConfigNeutralMode(CANJaguar::kNeutralMode_Coast);
		m_jag3->ConfigNeutralMode(CANJaguar::kNeutralMode_Coast);	
	}
	m_jag1->Set(speed);
	if(mtrTime.Get()> TIME_THRESH_1) // Stagger the motor startup to prevent enormous current
	{
		m_jag2->Set(speed);
	}
	else
	{
		m_jag2->Set(0);
	}
	if(mtrTime.Get() > TIME_THRESH_2 && Robot::oi->AreMotorsForced()) // Stagger the motor startup to prevent enormous current
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
	return 1/m_enc->GetPeriod();
}

double TripleMotorOutput::GetSetSpeed() {
	return m_jag1->Get();
}

double TripleMotorOutput::GetCurrent1()
{
	return m_jag1->GetOutputCurrent();
}

double TripleMotorOutput::GetCurrent2()
{
	return m_jag2->GetOutputCurrent();
}

double TripleMotorOutput::GetCurrent3()
{
	return m_jag3->GetOutputCurrent();
}

int TripleMotorOutput::MotorsEngaged() {
	if (m_jag3->Get() != 0) return 3;
	else if (m_jag2->Get() != 0) return 2;
	else if (m_jag1->Get() != 0) return 1;
	else return 0;
}

bool TripleMotorOutput::IsBraked() {
	return m_isBraked;
}
