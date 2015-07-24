#include "AutoAcquire.h"
#include "Acquisition/ToteIntake.h"
#include "Acquisition/RetractArms.h"


AutoAcquire::AutoAcquire() {
	AddParallel(new ToteIntake());
	AddParallel(new RetractArms());
}
