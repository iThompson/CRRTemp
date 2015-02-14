#include "DropTotes.h"
#include "ToteSetPos.h"
#include "../../Subsystems/StackerActions.h"


DropTotes::DropTotes() {
	Wait(1);
	AddSequential(new ToteSetPos(StackerActions::DROP_TOTES));
}
