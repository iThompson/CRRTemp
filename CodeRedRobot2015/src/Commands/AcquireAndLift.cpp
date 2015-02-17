#include "AcquireAndLift.h"
#include "Acquisition/ToteIntake.h"
#include "ToteStacker/ChangeTotePosition.h"


AcquireAndLift::AcquireAndLift() {
	AddParallel(new ToteIntake());
	AddSequential(new ChangeTotePosition(1));
}
