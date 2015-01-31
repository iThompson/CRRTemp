#include "AcquireAndLift.h"
#include "Acquisition/ToteIntake.h"
#include "ToteStacker/ToteSetPos.h"
#include "../Subsystems/StackerActions.h"


AcquireAndLift::AcquireAndLift() {
	AddParallel(new ToteIntake());
	AddSequential(new ToteSetPos(StackerActions::ADD_TOTE));
}
