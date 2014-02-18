#include "BallToShooter.h"
#include "Acquisition/RollerSpin.h"

#define BACK_TIME .1
#define FORWARD_TIME .5

BallToShooter::BallToShooter() {
	AddSequential(new RollerSpin(false, true, false), BACK_TIME);
	AddSequential(new RollerSpin(false, false, true), FORWARD_TIME);
}
