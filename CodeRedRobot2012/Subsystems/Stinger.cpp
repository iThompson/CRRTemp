#include "Stinger.h"
#include "../Commands/Stinger/Unsting.h"
#include "../Robotmap.h"

Stinger::Stinger() : Subsystem("Stinger"),
					 sol(SNG_SOL_STING)
{
	
}
    
void Stinger::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new Unsting());
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
void Stinger::SetState(bool state)
{
	sol.Set(state);
}
