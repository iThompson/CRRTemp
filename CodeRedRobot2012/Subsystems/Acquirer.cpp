#include "Acquirer.h"
#include "../Robotmap.h"
#include "../Commands/Acquirer/StopBelt.h"

Acquirer::Acquirer() : Subsystem("Acquirer"),
					   belt(AQS_MTR_BELT),
					   gateLeft(AQS_ANA_GATE_LEFT),
					   gateRight(AQS_ANA_GATE_RIGHT),
					   ballHigh(AQS_ANA_LOCK_TOP),
					   ballLow(AQS_ANA_LOCK_BOT),
					   ballCount(0),
					   m_speed(1.0)
{
	
}
    
void Acquirer::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new StopBelt());
}

void Acquirer::BeltRun() {
	belt.Set(m_speed);
}

void Acquirer::BeltStop() {
	belt.Set(0.0);
}

void Acquirer::BeltReverse() {
	belt.Set(-m_speed);
}

void Acquirer::BeltSpeed(double speed) {
	if (speed > 1.0) speed = 1.0;
	if (speed < 0.0) speed = 0.0;
	m_speed = speed;
	
	SmartDashboard::Log(m_speed, "Belt Speed");
}


void Acquirer::SetBallCount(int num) {
	// Make sure count remains sane
	if (num < 0) num = 0;
	if (num > 3) num = 3;
	
	ballCount = num;
}

int Acquirer::GetBallCount() {
	return ballCount;
}



void Acquirer::AddBall() {
	ballCount++;
	if (ballCount > 3) ballCount = 3;
}



void Acquirer::RemoveBall() {
	ballCount--;
	if (ballCount < 0) ballCount = 0;
}
