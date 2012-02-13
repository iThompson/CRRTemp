#include "Loader.h"
#include "../Robotmap.h"
#include "../Commands/Loader/LoaderLock.h"

Loader::Loader() : Subsystem("Loader"),
				   lockH(LDR_SOL_SHOOT_TOP),
				   lockL(LDR_SOL_SHOOT_BOT),
				   compTest(LDR_SOL_COMP_TEST),
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
