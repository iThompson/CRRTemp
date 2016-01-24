#include "AutoAcquire.h"
#include "Acquisition/ToteIntake.h"
#include "Acquisition/ExtendArms.h"


AutoAcquire::AutoAcquire() {
	AddSequential(new ExtendArms(), .5);
	AddParallel(new ToteIntake(true));
}
