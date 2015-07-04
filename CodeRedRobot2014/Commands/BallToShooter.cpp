#include "BallToShooter.h"
#include "Acquisition/RollerSpin.h"

#define BACK_TIME .1
#define FORWARD_TIME .3

BallToShooter::BallToShooter() {
	AddSequential(new RollerSpin(true, false), BACK_TIME);
	AddSequential(new RollerSpin(false, true), FORWARD_TIME);
}
