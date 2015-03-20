#include "Lift.h"
#include "ToteDriveToOffset.h"
#include "ToteDriveToRest.h"

#define PICK_UP 700

Lift::Lift() {
	AddSequential(new ToteDriveToOffset(PICK_UP),2);
	AddSequential(new ToteDriveToRest(),1);
}
