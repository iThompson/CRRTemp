#include "Loader.h"
#include "../Robotmap.h"
#include "../Commands/LoaderLock.h"

Loader::Loader() : Subsystem("Loader") {
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

// Put methods for controlling this subsystem
// here. Call these from Commands.
