#include "Lift.h"
#include "ToteDriveToOffset.h"
#include "ToteDriveToRest.h"

#define PICK_UP 700

Lift::Lift() {
	AddParallel(new ToteDriveToOffset(PICK_UP));
	AddSequential(new ToteDriveToRest());
}
