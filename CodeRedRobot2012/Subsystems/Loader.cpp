#include "Loader.h"
#include "../Robotmap.h"
#include "../Commands/Loader/LoaderLock.h"

Loader::Loader() : Subsystem("Loader"),
				   lockH(LDR_SOL_SHOOT_TOP),
				   lockL(LDR_SOL_SHOOT_BOT),
				   compTest(LDR_SOL_COMP_TEST),
				   belt(LDR_MTR_BELT),
				   gateLeft(LDR_ANA_GATE_LEFT),
				   gateRight(LDR_ANA_GATE_RIGHT),
				   ballHigh(LDR_ANA_LOCK_TOP),
				   ballLow(LDR_ANA_LOCK_BOT),
				   m_numberBalls(0)
{
}
    
void Loader::InitDefaultCommand() {
	SetDefaultCommand(new LoaderLock());
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void Loader::Lock() {
	lockH.Set(1);
	lockL.Set(1);
}

void Loader::Load() {
	lockH.Set(1);
	lockL.Set(0);
}

void Loader::Launch() {
	lockH.Set(0);
	lockL.Set(1);
}

void Loader::Rapidfire() {
	lockH.Set(0);
	lockL.Set(0);
}

void Loader::SetBallCount(int num) {
	// Make sure count remains sane
	if (num < 0) num = 0;
	if (num > 3) num = 3;
	
	m_numberBalls = num;
}

int Loader::GetBallCount() {
	return m_numberBalls;
}



void Loader::AddBall() {
	m_numberBalls++;
	if (m_numberBalls > 3) m_numberBalls = 3;
}



void Loader::RemoveBall() {
	m_numberBalls--;
	if (m_numberBalls < 0) m_numberBalls = 0;
}

void Loader::RunBelt() {
	belt.Set(1.0);
}

void Loader::ReverseBelt() {
	belt.Set(-1.0);
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
