#include "Acquirer.h"
#include "../Robotmap.h"
#include "../Commands/Acquirer/StopBelt.h"

#define ENTRY_THRESH_VERY_HIGH 4.0
#define ENTRY_THRESH_HIGH 2.5
#define ENTRY_THRESH_LOW 2.0

#define EXIT_THRESH_HIGH 2.5
#define EXIT_THRESH_LOW  2.0

Acquirer::Acquirer() : Subsystem("Acquirer"),
	belt(AQS_MTR_BELT),
	gateLeft(AQS_ANA_GATE_LEFT),
	gateRight(AQS_ANA_GATE_RIGHT),
	ballHigh(AQS_ANA_LOCK_TOP),
	ballLow(AQS_ANA_LOCK_BOT),
	ballCount(0),
	m_speed(1.0),
	m_ballCountEntry(0),
	m_hasBallExit(false)
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

bool Acquirer::IsSingleEntry() {
	return gateLeft.GetVoltage() > ENTRY_THRESH_HIGH || gateRight.GetVoltage() > ENTRY_THRESH_HIGH;
}

bool Acquirer::IsDoubleEntry() {
	return gateLeft.GetVoltage() > ENTRY_THRESH_VERY_HIGH && gateRight.GetVoltage() > ENTRY_THRESH_VERY_HIGH;
}

void Acquirer::CheckCounters(bool forward) {
	// Check entry sensors
	if (forward) {
		if (m_ballCountEntry == 0) {
			// Had none in the system
			if (IsSingleEntry()) {
				AddBall();
				m_ballCountEntry = 1;
				
				if (IsDoubleEntry()) {
					AddBall();
					m_ballCountEntry = 2;
				}
			}
		} else if (m_ballCountEntry == 1) {
			// Had one in the system
			if (!IsSingleEntry()) {
				m_ballCountEntry = 0;
			} else if (IsDoubleEntry()) {
				AddBall();
				m_ballCountEntry = 2;
			}
		} else if (m_ballCountEntry == 2) {
			// Had two in the system
			if (IsSingleEntry()) {
				m_ballCountEntry = 1;
			} else {
				m_ballCountEntry = 0;
			}
		}
	} else { // In reverse
		if (m_ballCountEntry == 0) {
			if (IsSingleEntry()) {
				m_ballCountEntry = 1;

				if (IsDoubleEntry()) {
					m_ballCountEntry = 2;
				}
			}
		} else if (m_ballCountEntry == 1) {
			if (!IsSingleEntry()) {
				RemoveBall();
				m_ballCountEntry = 0;
			} else if (IsDoubleEntry()) {
				m_ballCountEntry = 2;
			}
		} else if (m_ballCountEntry == 2) {
			if (IsSingleEntry()) {
				RemoveBall();
				m_ballCountEntry = 1;
			} else {
				RemoveBall();
				RemoveBall(); // 2 balls, 2 removals
				m_ballCountEntry = 0;
			}
		}
	}

	// Check departure sensors
	if (forward) {
		if (m_hasBallExit) {
			if (ballHigh.GetVoltage() < EXIT_THRESH_LOW) {
				RemoveBall();
				m_hasBallExit = false;
			}
		} else {
			if (ballHigh.GetVoltage() > EXIT_THRESH_HIGH) {
				m_hasBallExit = true;
			}
		}
	} else { // In reverse
		if (m_hasBallExit) {
			if (ballHigh.GetVoltage() < EXIT_THRESH_LOW) {
				m_hasBallExit = false;
			}
		} else {
			if (ballHigh.GetVoltage() > EXIT_THRESH_HIGH) {
				m_hasBallExit = true;
			}
		}
	}
}
