#include "Loader.h"
#include "../Robotmap.h"
#include "../Commands/LoaderLock.h"

Loader::Loader() : Subsystem("Loader"),
				   belt(LDR_MTR_BELT)
{
	lockH = new Solenoid(LDR_SOL_GATE_TOP);
	lockL = new Solenoid(LDR_SOL_GATE_BOT);
	compTest = new Solenoid(LDR_SOL_COMP_TEST);
}
    
void Loader::InitDefaultCommand() {
	SetDefaultCommand(new LoaderLock());
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void Loader::Lock() {
	lockH->Set(1);
	lockL->Set(1);
}

void Loader::Load() {
	lockH->Set(1);
	lockL->Set(0);
}

void Loader::Launch() {
	lockH->Set(0);
	lockL->Set(1);
}

void Loader::Rapidfire() {
	lockH->Set(0);
	lockL->Set(0);
}

void Loader::SetBallCount(int num)
{
}



int Loader::GetBallCount()
{
	return m_numberBalls;
}



void Loader::AddBall()
{
	m_numberBalls++;
}



void Loader::RemoveBall()
{
	m_numberBalls--;
}

void Loader::RunBelt() {
	belt.Set(1.0);
}

void Loader::StopBelt() {
	belt.Set(0.0);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
