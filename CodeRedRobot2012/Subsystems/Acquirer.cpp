#include "Acquirer.h"
#include "../Robotmap.h"
#include "../Commands/Acquirer/StopBelt.h"

#define ENTRY_THRESH_VERY_HIGH 0.8
#define ENTRY_THRESH_HIGH 0.5
#define ENTRY_THRESH_LOW 0.3

#define EXIT_THRESH_HIGH 2.0
#define EXIT_THRESH_LOW  1.0

static const char* kBallField = "Ball Count";

Acquirer::Acquirer() : Subsystem("Acquirer"),
	belt(AQS_MTR_BELT),
	gateLeft(AQS_ANA_GATE_LEFT),
	gateRight(AQS_ANA_GATE_RIGHT),
	ballHigh(AQS_ANA_LOCK_TOP),
	ballLow(AQS_ANA_LOCK_BOT),
	ballCount(0),
	m_speed(1.0),
	m_ballCountEntry(0),
	m_hasBallExit(false),
	m_countLock(NULL)
{
	m_countLock = semMCreate(SEM_Q_PRIORITY | SEM_INVERSION_SAFE | SEM_DELETE_SAFE);
	
	// Initialize the field we're going to track
	PostBallCount();
	
	// Now hook in a change listener on the field
	// This isn't the best idea in the world (implementation specific to SmartDashboard),
	// But it is more elegant than the "proper" method
	NetworkTable::GetTable("SmartDashboard")->AddChangeListener(kBallField, this);

}

void Acquirer::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new StopBelt());
}

void Acquirer::BeltRun() {
	belt.Set(m_speed);
	CheckCounters(true);
}

void Acquirer::BeltStop() {
	belt.Set(0.0);
}

void Acquirer::BeltReverse() {
	belt.Set(-m_speed);
	CheckCounters(false);
}

void Acquirer::BeltSpeed(double speed) {
	if (speed > 1.0) speed = 1.0;
	if (speed < 0.0) speed = 0.0;
	m_speed = speed;

	SmartDashboard::Log(m_speed, "Belt Speed");
}


void Acquirer::SetBallCount(int num) {
	// Initialize the scoped mutex
	Synchronized sync(m_countLock);
	
	// Make sure count remains sane
	if (num < 0) num = 0;
	if (num > 3) num = 3;

	ballCount = num;
	PostBallCount();
}

int Acquirer::GetBallCount() {
	return ballCount;
}



void Acquirer::AddBall() {
	// Initialize the scoped mutex
	Synchronized sync(m_countLock);
	
	ballCount++;
	if (ballCount > 3) ballCount = 3;
	PostBallCount();
}



void Acquirer::RemoveBall() {
	// Initialize the scoped mutex
	Synchronized sync(m_countLock);
	
	ballCount--;
	if (ballCount < 0) ballCount = 0;
	PostBallCount();
}


void Acquirer::PostBallCount() {
	// Post the new value to the SmartDashboard
	SmartDashboard::GetInstance()->PutInt(kBallField, ballCount);
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
	
	SmartDashboard::Log(ballHigh.GetVoltage(), "Ball High");
	SmartDashboard::Log(ballLow.GetVoltage(), "Ball Low");
	SmartDashboard::Log(gateLeft.GetVoltage(), "Gate Left");
	SmartDashboard::Log(gateRight.GetVoltage(), "Gate Right");
}


void Acquirer::ValueChanged(NetworkTable *table, const char *name, NetworkTables_Types type)
{
	// The user put a new value for the ball count into the Dashboard
	// We should update it...
	if (strcmp(name, kBallField) == 0)
	{
		SetBallCount(table->GetInt(kBallField));
	}
}
